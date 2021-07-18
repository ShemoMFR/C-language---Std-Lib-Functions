/*--------------------------------------------------------

WorkSheet 6 (Bitwise)
Developper : Moshé
Viewer : Rina
Status : Dev

--------------------------------------------------------*/

#include <stdio.h>
#include <stddef.h>
#include "bitwise.h"


long Pow2(unsigned int x, unsigned int y)
{
	x = x << y;

   	return x; 
}

int IsPow2Loop(unsigned int x)
{
	while (((x & 1) == 0) && x > 1) 
 	{
   		x = x >> 1;
 	}
 
 return (x == 1);
 
}

int AddOne(int x) 
{ 
    int m = 1; 
       
    while ( x & m ) 
    
    { 
        x = x ^ m; 
        m = m << 1; 
    } 
       
    x = x ^ m; 
    return x; 
} 

int IsPow2(unsigned int x)
{
	
	unsigned result;
	
	result = x - (x & 1);
	
	if (result == x)
	{
		return 1;
	}
	
		return 0;
}

void Swapp(unsigned int *a, unsigned int *b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;

}

int CountBitsLoop(int n)
{

    int count = 0;
    unsigned int j = 0;
    
    for(j = 0; j < sizeof(n) * 8; j++) 
    {
        if (n & (1 << j))
        {
            ++count;
        }
    }
    return count;

}

int CountBits(int n)
{
    n = n - ((n >> 1) & 0x55555555);
    n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
    n = (n + (n >> 4)) & 0x0F0F0F0F;
    n = n + (n >> 8);
    n = n + (n >> 16);

    return n & 0x0000003F;    
}


void Count3Bits(unsigned int *arr, size_t size)
{

    size_t i = 0;
    size_t j = 1;
    size_t count = 0;
          
        while (i < size)
        {
          while (j <= 32)
          {
            if (arr[i] & (1 << j))
            {
                ++count;
            }          
            ++j;
          }
            if (count == 3)
            {
              printf("%d The number has 3 bits\n", arr[i]);           
            }  
            
          j = 0;
          count = 0;
          ++i;
        }
    
}

unsigned int Divisible16(unsigned int n)
{
	
	unsigned int result = 15;
	
	n = n - (result & n);
	
	return n;
}

int Check1(unsigned char c)
{
	int goal = 34;
	
	int check = (goal & c);
	
	while (check == goal)
	{
		return 1;
	}
	
	return 0;
}

int Check2(unsigned char c)
{
    int test_bit1 = 2;
    int test_bit2 = 32;
    
    if ((test_bit1 & c) || (test_bit2 & c))
    {
        return 1;
    }
    
    return 0;
}

unsigned char SwappBits(unsigned char c)
{
    int flipper = 0, bit_3 = 0, bit_5 = 0;
    
    bit_3 = (c >> 3) & 1;
    bit_5 = (c >> 5) & 1;
    
    flipper = bit_5 ^ bit_3; /* 1 if bit 3 and 5 are different */
    
    c ^= (flipper << 5);
    c ^= (flipper << 3);
    
    return c;    
}

int ByteMirrorLoop(unsigned int num)
{
	int newValue = 0, bits = 1;
	size_t i = 1;
	
	while (i < (sizeof(unsigned int) * 8))
	{
		bits = bits * 2;
		++i;
	}
	
	while (num > 0)
	{
		if (1 & num)
		{
			newValue = newValue + bits;
		}
		
		bits = bits / 2;
		num = num >> 1;
	}
	
	return newValue;
}

int ByteMirror(unsigned int num)
{

    num = ((num & 0xFFFF0000) >> 16) | ((num & 0x0000FFFF) << 16);
    num = ((num & 0xFF00FF00) >> 8) | ((num & 0x00FF00FF) << 8);	
    num = ((num & 0xF0F0F0F0) >> 4) | ((num & 0x0F0F0F0F) << 4);

    return num;
}

unsigned int countSetBitsChar(char n) 
{ 
    unsigned int count = 0; 
    while (n) 
    { 
      n &= (n-1); 
      count++; 
    } 
    return count; 
} 
  
void FloatBits(float x) 
{ 
    unsigned int n = sizeof(float)/sizeof(char); 
  
    char *ptr = (char *) & x;   
    unsigned int i = 0;
  
    int count = 0;   
    for (i = 0; i < n; i++) 
    { 
         count += countSetBitsChar(*ptr); 
         ptr++; 
    } 
    
    printf("The float has %d bits. \n", count);
} 







