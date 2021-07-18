/*--------------------------------------------------------

WorkSheet 9 part 2 (Word Boundary Optimization)
Developper : Moshé
Viewer : 
Status : Dev

--------------------------------------------------------*/
#include <stdlib.h> /* abs */
#include <stdio.h>
#include <assert.h> /* assert */
#include <string.h> /* strcpy */
#include "atoi.h"

void swap(char *x, char *y);
char *ReverseArray(char *buffer, int i, int j);
void RemSpaces(char *str);

int Atoi(const char *string)
{
    int negatif = 0;
    int nbr = 0;
    int n = 0;
    char *s2 = (char *)malloc(sizeof(char) * (strlen(string) + 1));
    
    strcpy(s2, string);
    
    RemSpaces(s2);
    
    if (*s2 == '-')
    {
      negatif = 1;
      ++s2;
    }
    while (*s2 >= '0' && *s2 <= '9')
    {
      nbr = nbr * 10 + (*s2 - 48);   
      ++s2;
    }
    if (negatif)
    {
      return -nbr; 
    }
    else
    {
      return nbr;
    }
      
}

char *Itoa(int value, char *s, int base)
{
  	int nbr = value;
  	int negatif = 0;
  	int count = 1;
  	int i = 0;
  
  	if (value < 0)
  	{
    	value = value * (-1);
    	negatif = 1;
    	nbr = value;
  	}
  
  	while (value > -1)
  	{
  
    	while (nbr > base)
    	{
      		nbr = nbr / base;    
      		count *= 10;
    	}
  
    	if (negatif)
    	{
      		s[i] = '-';
      		s[i + 1] = nbr + 48;
      		++i;
      		negatif = 0;
    	}
    	else
    	{
      		s[i] = nbr + 48; 
    	}
    	if (value < base)
    	{
    		break;
    	}
    	nbr = nbr * count;
    	count = 1;
    	nbr = value - nbr;
    	value = nbr;
    	++i;
  	}
  
  	s[i + 1] = '\0';
  
	return s;


}

char *Itoa36(int value, char* buffer, int base)
{
	
    int n = 0;
    int i = 0;
    int r = 0;
        
    n = abs(value);   
	
    if (base < 2 || base > 36)
    {
    	return buffer;
    }        
 
    while (n)
    {
       	r = n % base; 
        if (r >= 10) 
        {
            buffer[i++] = 65 + (r - 10);
        }
        else
        {
            buffer[i++] = 48 + r;
        } 
        n = n / base;
    } 

    if (i == 0)
    {
        buffer[i++] = '0';
    }
 
    if (value < 0 && base == 10)
    {
        buffer[i++] = '-';
 	}
    buffer[i] = '\0';  
 
 	ReverseArray(buffer, 0, i - 1);
 	
    return buffer;
}

void swap(char *x, char *y) 
{
    char t;
    t = *x; 
    *x = *y; 
    *y = t;
}
 

char *ReverseArray(char *buffer, int i, int j)
{
    while (i < j)
    {
        swap(&buffer[i++], &buffer[j--]);
    }
 
    return buffer;
}

void RemSpaces(char *str)
{
    char *from = str;
    char *to   = str;
    
    assert(str != NULL); 
    
    while (*from == ' ' || *from == '\t')
    {
      from++;
    }
 
    while ( *from != '\0') 
    {
      *to = *from;
        to++;
        from++;
        if (*from == ' ' || *from == '\t') 
        {
            *to++ = ' ';
            while (*from == ' ' || *from == '\t')
            {
                from++;
            }
        }
    }
 
    if (to != str) 
    {
        if (to[-1] == ' ')
         {
            to[-1] = '\0';
         }
         
    }
}



