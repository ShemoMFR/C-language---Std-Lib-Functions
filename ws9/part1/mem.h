/*--------------------------------------------------------

WorkSheet 9 (Word Boundary Optimization)
Developper : Moshé
Viewer : 
Status : Dev

--------------------------------------------------------*/

#include <stddef.h> /* size_t */

#ifndef __MEM_H___
#define __MEM_H___

void *Memset(void *pointer, int value, size_t count);
void *Memcpy(void *dest, const void *src, size_t n);
void PrintString(char *s, size_t n);
void PrintArr(int *arr, size_t n);
void *Memmove(void *dest, const void *src, size_t n);

#endif  /* __MEM_H___*/
