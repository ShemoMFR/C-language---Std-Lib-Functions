/*--------------------------------------------------------

WorkSheet 9 (Word Boundary Optimization)
Developper : Moshé
Viewer : 
Status : Dev

--------------------------------------------------------*/
#include <stdio.h> /* printf */
#include <assert.h> /* assert */
#include "mem.h"

#define WORD_SIZE sizeof(size_t)

void *Memcpy(void *dest, const void *src, size_t n)
{
    unsigned long *p = dest;
    const unsigned long *p2 = src;
    unsigned char *p5 = dest;
    const unsigned char *p6 = src;
        
    assert(dest != NULL);
    assert(src != NULL);
    assert(p != NULL);
    assert(p2 != NULL);
    assert(p5 != NULL);
    assert(p6 != NULL);
    
    while (n > 0)
    {
      if (n > WORD_SIZE)
      {
      	*p = *p2;
      	n = n - WORD_SIZE;    
      	++p;
      	++p2; 
      	p5 = (unsigned char *)p;
      	p6 = (unsigned char *)p2;
      }
      else
      {
      	*p5 = *p6;
      	n = n - 1;    
      	++p5;
      	++p6;    
      }  
      
    }
    return dest;    
    
}
    

void *Memset(void *str, int c, size_t n)
{
    unsigned long *long_ptr = (unsigned long *)str;
    unsigned char *char_ptr = NULL;
    unsigned long mask = 0;
    size_t i = 0;
    
    assert(str != NULL);
    assert(long_ptr != NULL);
    
/* Initialisation of the mask with 8 bytes */
    
    for (i = 0; i < WORD_SIZE; ++i)
    {
        mask = (mask << WORD_SIZE) + (unsigned char)c;
    }       

/* Use the mask if there are more than 8 bytes*/    
    
    for (i = 0; i < n / WORD_SIZE; ++i)
    {
        *long_ptr = mask;
        ++long_ptr;
    }

    char_ptr = (unsigned char *)long_ptr;

/* Else, doing the set byte by byte */
    
    for (i = 0; i < n % WORD_SIZE; ++i)
    {
        *char_ptr = (char)mask;
        ++char_ptr;
        
    }
    
    return str;
}

void PrintArr(int *arr, size_t n)
{
	size_t i = 0;
	
	assert(arr != NULL);
	
	for(; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    
    printf("\n");

}


void PrintString(char *s, size_t n)
{
	size_t i = 0;
	
	assert(s != NULL);
	
	for(; i < n; i++) 
    {
        printf("%c ", s[i]);
    }
    
    printf("\n");

}

void *Memmove(void *dest, const void *src, size_t n) 
{
  long i = 0;
    
  assert(dest != NULL);
  assert(src != NULL);

  if (dest != src) 
  {
    if (dest < src)
    {
       Memcpy(dest, src, n);
    } 
    else 
    {
       for (i = n - 1; i != -1; --i) 
       {
          *(((unsigned char *)dest) + i) = *(((unsigned char *)src) + i);
       }
    }
  }
  return dest;
}








