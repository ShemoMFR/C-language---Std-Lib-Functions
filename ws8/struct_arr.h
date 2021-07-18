/*--------------------------------------------------------

WorkSheet 8 (Files)
Developper : Moshé
Viewer : 
Status : Dev

--------------------------------------------------------*/
#include <stddef.h>

#ifndef __STRUCT_ARR_H___
#define __STRUCT_ARR_H___

typedef struct generic_type_t generic_type_t;

struct generic_type_t
{
    void *element;
    void (*Print)(generic_type_t *int_struct);
	int (*Add)(generic_type_t *generic_struct, int to_add);
    void (*Clean)(generic_type_t *int_struct);
};

void Print(generic_type_t arr[], size_t size);

int Add(generic_type_t arr[], int to_add, size_t size);

int AddChar(generic_type_t *int_struct, int to_add);

int AddInt(generic_type_t *int_struct, int to_add);

int AddFloat(generic_type_t *int_struct, int to_add);

void Clean(generic_type_t arr[], size_t size);

int InitInt(generic_type_t *generic_struct, int x);

int InitFloat(generic_type_t *generic_struct, float y);

int InitChar(generic_type_t *int_struct, char *str);

#endif  /* __STRUCT_ARR_H___*/




