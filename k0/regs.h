#ifndef K0_REGS_H
#define K0_REGS_H

typedef struct {
    unsigned int gs, fs, es, ds;
    unsigned int edi, esi, ebp, esp, ebx, edx, ecx, eax; 
    unsigned int int_no, err_code; 
    unsigned int eip, cs, eflags, useresp, ss;
} regs;

#endif

