/*--------------------------------------------------------

WorkSheet 2 part 2 (pointers)
Developper : Moshé
Viewer : Jenia
Status : Approved

--------------------------------------------------------*/

#include <stdlib.h>
#include <stdio.h>

void swap(size_t *pnt_a, size_t *pnt_b);
void swap_pnt(size_t **pnt_pnt_a, size_t **pnt_pnt_b);

int main(void)
{
    size_t a = 5;
    size_t b = 10;  
     
    size_t *pa = &a;
    size_t *pb = &b;
    
    swap_pnt(&pa, &pb);
    
    
    printf("A = %lu, B = %lu", a, b);
    
   /* new part */
    
    size_t na = (size_t)pa;
    size_t nb = (size_t)pb;
    
    swap(&na, &nb);
    
    pa = (size_t *)na;
    pb = (size_t *)nb;
    
    swap(&a, &b);
    
    printf("The new value are %ld and %ld : \n", na, nb);
    printf("Values of pointers %p and %p :", pa, pb);
    
    
    return (EXIT_SUCCESS);

}

void swap(size_t *pnt_a, size_t *pnt_b)
{
    size_t tmp = 0;
    
    tmp = *pnt_a;
    *pnt_a = *pnt_b;
    *pnt_b = tmp;    

}

 void swap_pnt(size_t **pnt_pnt_a, size_t **pnt_pnt_b)
{
       
    size_t tmp = 0;
    
    tmp = **pnt_pnt_a;
    **pnt_pnt_a = **pnt_pnt_b;
    **pnt_pnt_b = tmp;
    
} 

