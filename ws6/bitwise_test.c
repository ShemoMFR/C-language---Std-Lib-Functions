/*--------------------------------------------------------

WorkSheet 6 (Bitwise)
Developper : Moshé
Viewer : Rina
Status : Dev

--------------------------------------------------------*/

#include <stdio.h> /* printf */
#include "bitwise.h" 

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"

int main(void)
{
	 unsigned int c[] = {7, 4, 11, 20};
	 unsigned char ch = '2';  
	 int number1 = 4;
     int number2 = 4;
     int result = 0;      
     unsigned int a = 10;
     unsigned int b = 68;
     unsigned int nbr = 31;
     unsigned int nbr2 = 32;
     float x = 0.15625; 
     
/*---------------------- Test Pow2 ------------------------------*/     

     result = Pow2(number1,number2);  
     printf("Result : %d\n",result);
     printf("----------------------------------------------------\n");
     
/*---------------------- Test IsPow2Loop ------------------------------*/     

	 printf("IsPow2Loop Test \n");
     result = IsPow2Loop(nbr);
     printf("%d is not Pow2, result expected : 0. Result = %d\n", nbr, result);
     result = IsPow2Loop(nbr2);
     printf("%d is Pow2, result expected : 1. Result = %d\n", nbr2, result);
     printf("----------------------------------------------------\n");
     

/*---------------------- Test IsPow2 ------------------------------*/     

	printf("IsPow2 Test \n");
	printf("Numbers are : %d, %d\n", nbr, nbr2);
	printf("nbr 1 : %d nbr 2 : %d\n", IsPow2(nbr), IsPow2(nbr2));
    printf("----------------------------------------------------\n");
	
	
/*---------------------- Swapp 2 values ------------------------------*/     
     
     printf("Swapp 2 values Test \n");
     printf("Swap 2 values a = %d and b = %d\n", a, b);
     Swapp(&a, &b);
     printf("Result expected : a = %d and b = %d\n", a, b);
     printf("----------------------------------------------------\n");

/*---------------------- Test CountBitsLoop ------------------------------*/     

	printf("CountBitLoop Test \n");
	printf("The numbers are : %d and %d\n", a, b);
	printf("Expected results are : 2 and 2 \n");
	printf("Results = %d and %d\n", CountBitsLoop(a), CountBitsLoop(b)); 
	printf("----------------------------------------------------\n");

/*---------------------- Test CountBits ------------------------------*/     

	printf("CountBit Test \n");
	printf("The numbers are : %d and %d\n", a, b);
	printf("Expected results are : 2 and 2 \n");
	printf("Results = %d and %d\n", CountBits(a), CountBits(b)); 
	printf("----------------------------------------------------\n");
/*---------------------- Test AddOne ------------------------------*/   

	printf("AddOne Test \n");
	printf("Number test is : 0\n");
	printf("result : %d\n", AddOne(0));
	printf("----------------------------------------------------\n");
	
	/*---------------------- Test Count3Bits ------------------------------*/   
	  
	printf("Count3Bits Test \n");
	printf("Test Count 3 Bits with 7, 4, 11, 20 \n");
	printf("result expected : Only 7 and 11 are 3 bits\n"); 
	Count3Bits(c, 4);
	printf("----------------------------------------------------\n");
	
	/*---------------------- Test Count3Bits ------------------------------*/   
	
	printf("Divibisble 16 Test \n");
	printf("First number is %d, second is %d\n", nbr, nbr2);
	printf("Result expected : 16 and 32\n");
	printf("Firt %d and second %d\n", Divisible16(nbr), Divisible16(nbr2));
	printf("----------------------------------------------------\n");
	

   	/*---------------------- Test ByteMirrorLoop ------------------------------*/   
   	
   	printf("ByteMirrorLoop Test \n");
   	printf("ByteMirror, result expcected : -2147483648\n");
   	printf("%d\n", ByteMirrorLoop(1));
   	printf("----------------------------------------------------\n");
   	
   	/*---------------------- Test ByteMirror ------------------------------*/   
   	
   	printf("ByteMirror Test \n");
   	printf("ByteMirror, result expcected : -2147483648\n");
   	printf("%d\n", ByteMirror(1));
   	printf("----------------------------------------------------\n");
   	
   	/*---------------------- Test Check1 ------------------------------*/   
   	
   	printf("Test if there are bit 2 and 6. \n");
   	printf("Result expected : 1\n");
   	printf("Result : %d\n",Check1(ch));
   	printf("----------------------------------------------------\n");
   	
   	/*---------------------- Test Check2 ------------------------------*/   
   	
   	printf("Test if there are bit 2 OR 6. \n");
   	printf("Result expected : 1\n");
   	printf("Result : %d\n",Check1(ch));
   	printf("----------------------------------------------------\n");
   	
   /*---------------------- SwappBits------------------------------*/   
   
   printf("SwappBits test. \n");
   printf("Number 2 in the begenning\n");
   printf("Result after : %d\n", SwappBits(ch));   
   printf("----------------------------------------------------\n");
   	
   /*---------------------- Test Float Bits ------------------------------*/   
   
   printf("Float Bits counter. \n");
   printf("Result Expected : 6 bits\n");
   FloatBits(x);
   printf("----------------------------------------------------\n");
   
   	
   	
   	
     return 0;

}
