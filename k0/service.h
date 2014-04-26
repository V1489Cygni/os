#ifndef K0_SERVICE_H
#define K0_SERVICE_H

void memcpy(char*, const char*, int);

void memset(char*, char, int);
void memsetw(short*, short, int);
void memsetd(int*, int, int);

int strlen(const char*);

unsigned char inportb (unsigned short);
void outportb (unsigned short, unsigned char);

#endif
