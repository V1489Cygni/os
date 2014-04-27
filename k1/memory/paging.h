#ifndef MEMORY_PAGING_H
#define MEMORY_PAGING_H

static int MF_PRESENT = 1;
static int MF_RW = 2;

extern void set_paging_on();

void set_page_dir_entry(int, void**, int);
void** get_page_table(int);
void set_page_table_entry(int, int, void*, int);
void* get_page(void**, int);
void init_tables();
void init_paging();

#endif
