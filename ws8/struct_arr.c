/*--------------------------------------------------------

WorkSheet 8 (Files)
Developper : Moshé
Viewer : 
Status : Dev

--------------------------------------------------------*/
#include <stdio.h> /* printf */
#include <stdlib.h> /* malloc */
#include <string.h> /* strcat strcpy*/
#include <assert.h> /* assert */
#include "struct_arr.h"

static void PrintInt(generic_type_t *int_struct);
static void PrintFloat(generic_type_t *int_struct);
static void PrintString(generic_type_t *int_struct);
static void CleanChar(generic_type_t *int_struct);
static void CleanInt(generic_type_t *int_struct);
static void CleanFloat(generic_type_t *int_struct);

int InitInt(generic_type_t *int_struct, int x)
{		

	assert(int_struct != NULL);
	
	*(int *)&int_struct->element = x;	
	int_struct->Print = PrintInt;
	int_struct->Add = AddInt;
	int_struct->Clean = CleanInt;		
	
	return 0;
}

int InitFloat(generic_type_t *int_struct, float y)
{
	assert(int_struct != NULL);
	
	*(float *)&int_struct->element = y;
	int_struct->Print = PrintFloat;
	int_struct->Add = AddFloat;
	int_struct->Clean = CleanFloat;	
	
	return 0;
}

int InitChar(generic_type_t *int_struct, char *str)
{
	size_t leng = 0;
	
	leng = strlen(str);
		
	int_struct->Print = PrintString;
	int_struct->Add = AddChar;
	int_struct->Clean = CleanChar;	
	int_struct->element = malloc(sizeof(char) * (leng + 1)); 	

	
	if (int_struct->element == NULL)
	{
		return 1;
	}
	
    strcpy((char *)int_struct->element, str);
    
    return 0;
}

void Print(generic_type_t arr[], size_t size)
{
	size_t i = 0;
	
	for (i = 0; i < size ; ++i)
	{
		arr[i].Print(&arr[i]);
	}
}

static void PrintInt(generic_type_t *int_struct)
{
	assert(int_struct != NULL);
	printf("%d\n", *(int *)&int_struct->element);
}

static void PrintFloat(generic_type_t *int_struct)
{
	assert(int_struct != NULL);
	printf("%f\n", *(float *)&int_struct->element);
}

static void PrintString(generic_type_t *int_struct)
{	
	assert(int_struct != NULL);
	printf("%s\n", (char *)(int_struct->element));
}

int AddInt(generic_type_t *int_struct, int to_add)
{
	assert(int_struct != NULL);
    *(int *)&(int_struct -> element) += to_add;    

    return 0;
}

int AddFloat(generic_type_t *int_struct, int to_add)
{
	assert(int_struct != NULL);
	*(float *)&(int_struct -> element) += to_add;    

    return 0;
}

int AddChar(generic_type_t *int_struct, int to_add)
{
	char printer[10] = "0";
	size_t leng_printer = 0; 	
	size_t leng_struct_element = 0;
	
	assert(int_struct != NULL);
	
	sprintf(printer, "%d", to_add);
	leng_printer = strlen(printer);
	leng_struct_element = strlen((char *)&int_struct->element);
	
	int_struct->element = realloc(int_struct->element, (leng_printer + leng_struct_element + 1));
	
	if (int_struct->element == NULL)
	{
		return 1;
	}
	
	strcat((char *)int_struct->element, printer);		

    return 0;
}

void Clean(generic_type_t arr[], size_t size)
{
    size_t i = 0;

    for (i = 0; i < size ; i++)
    {
        arr[i].Clean(&arr[i]);
    }
}

static void CleanInt(generic_type_t *int_struct)
{
	assert(int_struct != NULL);
	(void)int_struct;
	return;
}

static void CleanFloat(generic_type_t *int_struct)
{
	assert(int_struct != NULL);
	(void)int_struct;
	return;
}

static void CleanChar(generic_type_t *int_struct)
{
	assert(int_struct != NULL);
	free(int_struct->element);
	int_struct->element = NULL;
	
	return;
}

int Add(generic_type_t arr[], int to_add, size_t size)
{
	size_t i = 0;
	
	for (i = 0; i < size ; ++i)
	{
		arr[i].Add(&arr[i], to_add);
	}
	return 0;
}







