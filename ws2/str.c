/*--------------------------------------------------------

WorkSheet 2 part 2 (pointers)
Developper : Moshé
Viewer : Tsivia
Status : waiting for aproval

--------------------------------------------------------*/

#include <stdio.h> 			/*printf*/
#include <stdlib.h>        /* EXIT_SUCCESS*/
#include <assert.h>		   /* Assert*/
#include <ctype.h>		  /* Tolower*/
#include <stddef.h> 	  /* size_t*/
#include "str.h"

/*------------------FUNCTION STRSTR-----------------------*/
/*--------------------------------------------------------*/

char *StrStr(const char *haystack, const char *needle)
{    
    int i = 0;
    int result; 
           
    assert(haystack);
    assert(needle);
        
       while (*haystack != '\0')
       {
           if (*(haystack + i) == *(needle + 0))
           {
               result = Compare_Strings(haystack, needle);
               break;
           }
           
           ++haystack;          
       }  
          
          if (result == 0)
          {
            return (char *)haystack; 
          }
          else
          {
            return NULL; 
          }  
}

/*------------------FUNCTION compare_strings--------------*/
/*--------------------------------------------------------*/

int Compare_Strings(const char *src, const char *search)
{
    int leng = Strlen(search);
    int count = 0;
    int i = 0;
    int j = 0;
    
    assert(src);
    assert(search);
    
    while (src[i] != '\0' && src[i] != search[j])
    {
        i++;
    }
    
    for(j = 0, i = 0 ; j < leng; i++, j++)
    {
        if (src[i] == search[j])
        {
            count++;
        }    
    }
    
    if (count == leng)
    {
        return 0;
    }
    else
    {
        return 1; 
    }
    
    
}

/*------------------FUNCTION Strncpy-----------------------*/
/*--------------------------------------------------------*/


char *StrCpy(char *dest, const char *src)
{
    int i = 0;
    
    assert(dest != NULL);
    assert(src != NULL); 
    
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;    
    }
    
    dest[i] = '\0';
    
    return dest;

}

/*------------------FUNCTION Strncpy-----------------------*/
/*--------------------------------------------------------*/

char *StrnCpy(char *dest, const char *src, size_t n)
{

    size_t leng = Strlen(dest);
    size_t size = 0;
    size_t i;
    
    assert(dest);
    assert(src);
    
    if (leng < n)
    {
      size = leng;
    }
    else
    {
      size = n;
    }
    
    for (i = 0; i < size ; i++)
    {
        dest[i] = src[i];    
    }
    
    while (dest[i] != '\0')
    {
        dest[i] = '\0';
        i++;
    }

    return dest;

}

/*------------------FUNCTION Strchr-----------------------*/
/*--------------------------------------------------------*/

char *StrChr(const char *s, int c)
{
	
	assert(s);	
    while (*s)
    {
        if (*s == c)
        {
          return (char *)s;                  
        }
      
      ++s;
    }
    
    return NULL;

}

/*------------------FUNCTION Strspn-----------------------*/
/*--------------------------------------------------------*/

size_t StrSpn(const char *s, const char *accept)
{
    size_t count = 0;
    int i = 0;
    int j = 0;
    
    assert(s);
	assert(accept);
    
    while(*(accept + i) != '\0')
    {
      if (*(accept + i)  == *(s + j))
      {
        ++count;
        ++j;
        break;
      }
      ++i;
    }
    
    i = 0;
    
    while (*(s + j) != '\0' && *(accept + i) != '\0')
    {
      if (*(s + j) == *(accept + i))
      {
        ++count;
        ++j;
        i = 0;
        continue;
      }  
      i++;
      
    }  
    return count;
}

/*------------------FUNCTION Strncat----------------------*/
/*--------------------------------------------------------*/

char *StrnCat(char *dest, const char *src, size_t n)
{
	int leng = 0;
	size_t i = 0;
	
	leng = Strlen(dest);
	
	assert(dest != NULL);
	assert(src != NULL);
	
	while (i < n)
	{
		*(dest + leng + i) = *(src + i);
		i++;	
	}

	*(dest + leng + i) = '\0';
	
	return dest;

}

/*------------------FUNCTION Strcat----------------------*/
/*--------------------------------------------------------*/

char *StrCat(char *dest, const char *src)
{
	int leng = 0;
	int i = 0;
	
	leng = Strlen(dest);
	
	assert(dest != NULL);
	assert(src != NULL);
	
	while (*(dest + i) != '\0')
	{
		*(dest + leng + i) = *(src + i);
		i++;	
	}

	*(dest + leng + i) = '\0';
	
	return dest;

}

/*------------------FUNCTION Strlen----------------------*/
/*--------------------------------------------------------*/

size_t Strlen(const char *s)
{

    int i = 0;
            
    assert(s != NULL);
    
    while (s[i] != '\0')
    {
        i++;    
    } 

    return i;

}

/*------------------FUNCTION Strcmp----------------------*/
/*--------------------------------------------------------*/

int Strcmp(char *s1, char *s2)
{
    int i = 0;

   while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'))
   {        
           i++;         
   }
   
   return (s1[i] - s2[i]);
      
}

/*------------------FUNCTION StrCaseCmp----------------------*/
/*--------------------------------------------------------*/


int StrCaseCmp(const char *s1, const char *s2)
{
    int i = 0;
    
    char *s3 = (char *)malloc(sizeof(char) * 100);
    char *s4 = (char *)malloc(sizeof(char) * 100);
    
    assert(s1 != NULL);
    assert(s2 != NULL);
    assert(s3 != NULL);   
    assert(s4 != NULL);    
    
   	StrCpy(s3, s1);
   	StrCpy(s4, s2); 
    
    while (s3[i] != '\0' && s4[i] != '\0')
    {
    	s3[i] = tolower(s3[i]);
    	s4[i] = tolower(s4[i]);
    	i++; 
    }
    
	i = 0;
	
   	while ((s3[i] == s4[i]) && (s3[i] != '\0') && (s4[i] != '\0'))
  	{        
           i++;      
   	}
   
   return (s3[i] - s4[i]);
      
}

/*------------------FUNCTION StrDup----------------------*/
/*--------------------------------------------------------*/

char *StrDup(const char *s)
{
    int i = 0;
    int leng = Strlen(s);
    char *s2 = malloc(sizeof(char) * leng);
    
    assert(s != NULL);
    assert(s2 != NULL);
    
    while (*(s + i) != '\0')
    {
        *(s2 + i) = *(s + i);
        i++;    
    }
    
    *(s2 + leng) = '\0';
    
    return s2;

}

