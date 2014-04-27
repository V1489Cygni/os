#include "paging.h"

#include "../../k0/output.h"

void** page_dir[1024]__attribute__((aligned(4096)));
void* page_tables[1024 * 1024]__attribute__((aligned(4096)));

void set_page_dir_entry(int num, void** addr, int flags) {
    page_dir[num] = (void**)((int)addr | flags);
}

void** get_page_table(int num) {
    return (void**)((int)page_dir[num] &  0xfffff000);
}

void set_page_table_entry(int table_num, int num, void* addr, int flags) {
    get_page_table(table_num)[num] = (void*)((int)addr | flags);
}

void* get_page(void** page_table, int num) {
    return (void*)((int)page_table[num] & 0xfffff000);
}

void init_tables() {
    for(int i = 0; i < 1024; i++) {
        set_page_dir_entry(i, page_tables + i * 1024, MF_PRESENT | MF_RW);
        for(int j = 0; j < 1024; j++) {
            set_page_table_entry(i, j, (void*)(4096 * 1024 * i + 4096 * j), MF_PRESENT | MF_RW);
        }
    }
}

void init_paging() {
    init_tables();
    set_paging_on();
}
