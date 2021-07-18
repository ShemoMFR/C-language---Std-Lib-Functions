/*--------------------------------------------------------

WorkSheet 5 (Files)
Developper : Moshé
Viewer : Benjamin
Status : Approved

--------------------------------------------------------*/

#include <stdio.h> /* printf */
#include <stdlib.h> /* exit_success */
#include <string.h> /* strcmp*/

#define MAX 200

enum end_process
{
	SUCCESS = 0, FAILED = 1, EXIT_PROG = 2
};

static int Cmp_Remove(char *input, char *string_compare);
static int Cmp_Exit(char *input, char *string_compare);
static int Cmp_Count(char *input, char *string_compare);
static int Cmp_Char(char *input, char *string_compare);
static int Cmp_Default(char *input, char *string_compare);
static enum end_process Move_To_Top(char *filename, FILE *p, char *input);
static enum end_process Count_Lines(char *filename, FILE *p, char *input);
static enum end_process Remove_File(char *filename, FILE *p, char *input);
static enum end_process Exit_Prog(char *filename, FILE *p, char *input);
static enum end_process Print_In_File(char *filename, FILE *p, char *input);

typedef struct commands commands_t;
struct commands
{
    char *string;
    int (*Pnt_compare)(char *input, char *string_compare);
    enum end_process (*Pnt_operation)(char *filename, FILE *p, char *input);
};

int main(int argc, char *argv[])
{	
	char string[MAX] = "0";
	int i = 0;	
	enum end_process flag = SUCCESS;
	
	FILE *file = NULL;
	
	commands_t array[5] = 
	{{"-remove\n", Cmp_Remove, Remove_File}, 
	{"-exit\n", Cmp_Exit, Exit_Prog}, 
	{"-count\n", Cmp_Count, Count_Lines}, 
	{"<", Cmp_Char, Move_To_Top}, 
	{"test", Cmp_Default, Print_In_File}};	
	
	if (argc < 2)
	{
		printf("Error with the argument argc");
		return FAILED;
	}
			
	
	while (flag != EXIT_PROG)
    {		
    
    	printf("Please write a sentence [MAX 200 CHARACTERS] : \n");
   		fgets(string, MAX, stdin);
   		
		for (i = 0; i < 5; ++i)
		{	   
			if (array[i].Pnt_compare(string, array[i].string) == SUCCESS)   
    		{
    			flag = array[i].Pnt_operation(argv[1], file, string);  	
    	  		break;
    		}    	    	    		
    	}
    }
				
	return (EXIT_SUCCESS);
}

enum end_process Print_In_File(char *filename, FILE *p, char *input)
{
	p = fopen(filename, "a+");
	
	if (p == NULL)
	{
		printf("Problem with the opening of the file!");
		return 2;
	}
	
	fputs(input, p);		
	fclose(p);
	
	return SUCCESS;
}

int Cmp_Remove(char *input, char *string_compare)
{
	
	if (strcmp(input, string_compare) == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}

}

int Cmp_Exit(char *input, char *string_compare)
{
	
	if (strcmp(input, string_compare) == 0)
	{	
		return 0;
	}
	else
	{
		return 1;
	}

}

enum end_process Remove_File(char *filename, FILE *p, char *input)
{
    remove(filename);	
    printf("File deleted\n");
    (void)(p);
    (void)(input);
    
    return 2;
        
}

enum end_process Exit_Prog(char *filename, FILE *p, char *input)
{	
	
	(void)filename;
	(void)p;
	(void)input;
	
	return EXIT_PROG;

}

int Cmp_Count(char *input, char *string_compare)
{
	if (strcmp(input, string_compare) == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}

}

enum end_process Count_Lines(char *filename, FILE *p, char *input)
{
	int lines_counter = 0;
	char c; 
	p = fopen(filename, "a+");
	
	if (p == NULL)
	{
		printf("Problem with the opening of the file!");
		exit(1);
	}
	
	while (c != EOF)
	{
		c = fgetc(p);
		if (c == '\n')
		{
			++lines_counter;
		}
	} 
	
	fclose(p);
	printf("The number of lines is : %d\n\n", lines_counter);
	
	(void)input;
	(void)filename;

	return SUCCESS;
} 

int Cmp_Char(char *input, char *string_compare)
{
	
	if (strncmp(input, string_compare, 1) == 0)
	{	
		return 0;
	}
	else
	{
		return 1;
	}

}

enum end_process Move_To_Top(char *filename, FILE *p, char *input)
{
	FILE *temp_file;
    char ch;
      
    p = fopen(filename, "r");
    temp_file = fopen("file2.txt", "a+");
    
    if (p == NULL || temp_file == NULL)
	{
		printf("Problem with the opening of the file!");
		return 2;
	}
    
    ++input;
   	fputs(input, temp_file);   	
   	
   	rewind(p);
   	
    while((ch = getc(p)) != EOF)
    {
        putc(ch, temp_file);
  	}
  	
  	fclose(p);
  	fclose(temp_file);
  	
  	p = fopen(filename, "w+");
    temp_file = fopen("file2.txt", "r");
    
     if (p == NULL || temp_file == NULL)
	{
		printf("Problem with the opening of the file!");
		return 2;
	}
    
    rewind(temp_file);
  	
  	while ((ch = getc(temp_file)) != EOF)
  	{
  		putc(ch, p);
  	}
  	
    fclose(p);
    fclose(temp_file);
    remove("file2.txt");
    
    return SUCCESS;
    
}

int Cmp_Default(char *input, char *string_compare)
{
	return 0;
	
	(void)input;
	(void)string_compare;
}












