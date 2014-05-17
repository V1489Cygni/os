#include <output.h>
#include <service.h>

short *textmemptr = (short*)0xB8000;
int cols = 80, rows = 24;
int attrib = 0x0F;
int csr_x = 0, csr_y = 0;

void k0_scroll() {
    if(csr_y >= rows) {
        memcpy ((char*)textmemptr, (const char*)textmemptr + 2 * cols, (rows - 1) * cols * 2);
        memsetw (textmemptr + (rows - 1) * cols, 0x20 | (attrib << 8), cols);
        csr_y--;
    }
}

void k0_move_csr() {
    unsigned int temp = csr_y * cols + csr_x;
    outportb(0x3D4, 14);
    outportb(0x3D5, temp >> 8);
    outportb(0x3D4, 15);
    outportb(0x3D5, temp);
}

void k0_cls() {
    for(int i = 0; i < rows; i++) {
        memsetw (textmemptr + i * cols, 0x20 | (attrib << 8), cols);
    }
    csr_x = 0;
    csr_y = 0;
    k0_move_csr();
}

void k0_print_char(char c) {
    if(c == 0x08) {
        if(csr_x != 0) { 
            csr_x--;
            k0_print_char(' ');
            csr_x--;
        }
    } else if(c == 0x09) {
        csr_x = (csr_x + 8) & ~(8 - 1);
    } else if(c == '\r') {
        csr_x = 0;
    } else if(c == '\n') {
        csr_x = 0;
        csr_y++;
    } else if(c >= ' ') {
        *(textmemptr + (csr_y * cols + csr_x)) = c | (attrib << 8);
        csr_x++;
    }
    if(csr_x >= cols) {
        csr_x = 0;
        csr_y++;
    }
    k0_scroll();
    k0_move_csr();
}

void k0_print(char *text) {
    for (int i = 0; i < strlen((const char*)text); i++) {
        k0_print_char(text[i]);
    }
}

void k0_print_int(int i) {
    for(int d = 1e9; d > 0; d /= 10) {
        k0_print_char('0' + (i / d) % 10);
    }
}
