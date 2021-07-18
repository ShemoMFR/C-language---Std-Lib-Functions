/*--------------------------------------------------------

WorkSheet 3 (pointers & Arrays)
Developper : Moshé
Viewer : Tsivia
Status : Waiting for Approval

--------------------------------------------------------*/

#include <stdio.h> /* printf */
#include <stdlib.h> /* EXIT_SUCCESS*/
#include <stddef.h> /* site_t */
#include <assert.h> /*asser */

size_t Josephus(size_t *arr, size_t size);
void InitialisationArray(size_t *arr, size_t size);

int main(void)
{
  size_t tab[57];
  size_t size = sizeof(tab) / 8; 
  size_t lucky = 0;  
  
  InitialisationArray(tab, size);
  lucky = Josephus(tab, size);
    
  printf("The lucky soldier is number %lu\n", lucky);
    
  return (EXIT_SUCCESS);
  
}

size_t Josephus(size_t *arr, size_t size)
{
  size_t i = 0;
  size_t j = 0;
  size_t *killer = NULL;
  size_t *people = NULL;
  size_t alive = size;
  size_t lucky = 0;
  
  killer = arr;
  people = arr;
  
  assert(arr);
  assert(killer);
  assert(people);

    
    for(i = 0 ; alive > 1 ; i = i % size)    
    {
        if (killer[i] == 0)
        {
            if (j == size)
            {
                j = 0;
            }
            else
            {
                j = i + 1;
            }
        
            while (j != 0)
            {
                j = j % size;

                if (people[j] == 0)
                {
                    people[j] = 1;
                    --alive; 
                    break;
                }
                ++j;
            }
        }

        lucky = i;
        ++i;
    }   
    
    return lucky + 1;     

}

void InitialisationArray(size_t *arr, size_t size)
{

  size_t i = 0;
  
  while (i < size)
  {
   arr[i] = 0; 
   ++i;    
  }  


}








