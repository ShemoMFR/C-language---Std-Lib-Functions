/*--------------------------------------------------------
WorkSheet 6 (bitwise)
Developper : Moshé
Viewer : Rina
Status : Dev

--------------------------------------------------------*/
#include <stddef.h>

#ifndef BITWISE_H
#define BITWISE_H


long Pow2(unsigned int x, unsigned int y);	
int IsPow2Loop(unsigned int x);	
int IsPow2(unsigned int x);
int AddOne(int x);
void Swapp(unsigned int *a, unsigned int *b);
int CountBitsLoop(int n);
int CountBits(int n);
void Count3Bits(unsigned int *arr, size_t size);
unsigned int Divisible16(unsigned int n);
int Check1(unsigned char ch);
int Check2(unsigned char ch);
int ByteMirrorLoop(unsigned int num);
int ByteMirror(unsigned int num);
unsigned char SwappBits(unsigned char c);
void FloatBits(float x);
unsigned int countSetBitsChar(char n);



#endif 
