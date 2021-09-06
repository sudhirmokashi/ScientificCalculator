#include "calc.h"

FILE *outputfile_ProgrammerMode = NULL;

void printInAllNumberSystemsMultiple(unsigned int num1, unsigned int num2, unsigned int result)
{
    printf("Hexadecimal Values-\n");
    printf("\tHexadecimal Value of input 1 = %X\n",num1);
    printf("\tHexadecimal Value of input 2 = %X\n",num2);
    printf("\tHexadecimal Value of result = %X\n",result);

    printf("Octal Values-\n");
    printf("\tOctal Value of input 1 = %o\n",num1);
    printf("\tOctal Value of input 2 = %o\n",num2);
    printf("\tOctal Value of result = %o\n",result);

    printf("Decimal Values-\n");
    printf("\tDecimal Value of input 1 = %d\n",num1);
    printf("\tDecimal Value of input 2 = %d\n",num2);
    printf("\tDecimal Value of result = %d\n",result);
    fprintf(outputfile_ProgrammerMode,"input 1 = %d input 2 = %d result = %d\n",num1,num2,result);
}
void printInAllNumberSystemsSingle(unsigned int num, unsigned int result)
{
    printf("Hexadecimal Values-\n");
    printf("\tHexadecimal Value of input = %X\n",num);
    printf("\tHexadecimal Value of result = %X\n",result);

    printf("Octal Values-\n");
    printf("\tOctal Value of input = %o\n",num);
    printf("\tOctal Value of result = %o\n",result);

    printf("Decimal Values-\n");
    printf("\tDecimal Value of input = %d\n",num);
    printf("\tDecimal Value of result = %d\n",result);
    fprintf(outputfile_ProgrammerMode,"input = %d result = %d\n",num,result);
}
int ProgrammerMode()
{
    unsigned int num1,num2,numberOfBits,result,choice;
    
    outputfile_ProgrammerMode = fopen("F://ProjectsUsingC//ScientificCalculator//Logs//log_programmer_mode.txt","a");

    if(outputfile_ProgrammerMode == NULL)
    {
        printf("Error while opening log file:\n");
        return EXIT_FAILURE;
    }
    fprintf(outputfile_ProgrammerMode,"Opening log file....\n");
    printf("Note-\n");
    printf("\t1)Enter all the inputs and choices only in integer format\n");
    printf("\t2)The outputs will be displayed in all number systems\n");
    printf("Choice of Operations:\n");
    printf("\t1) Bitwise AND of two numbers\n");
    printf("\t2) Bitwise OR of two numbers\n");
    printf("\t3) Bitwise XOR of two numbers\n");
    printf("\t4) Bitwise Complement of a number\n");
    printf("\t5) Bitwise Left Shift of a number\n");
    printf("\t6) Bitwise Right Shift of a number\n");
    printf("Enter choice:\n");
    scanf("%u",&choice);
    switch(choice)
    {
        case 1:
            fflush(stdin);
            printf("Enter num1:\n");
            scanf("%u",&num1);
            fflush(stdin);
            printf("Enter num2:\n");
            scanf("%u",&num2);
            fflush(stdin);
            result = num1 & num2;
            printInAllNumberSystemsMultiple(num1,num2,result);
            break;
        case 2:
            fflush(stdin);
            printf("Enter num1:\n");
            scanf("%u",&num1);
            fflush(stdin);
            printf("Enter num2:\n");
            scanf("%u",&num2);
            fflush(stdin);
            result = num1 | num2;
            printInAllNumberSystemsMultiple(num1,num2,result);
            break;
        case 3:
            fflush(stdin);
            printf("Enter num1:\n");
            scanf("%u",&num1);
            fflush(stdin);
            printf("Enter num2:\n");
            scanf("%u",&num2);
            fflush(stdin);
            result = num1 ^ num2;
            printInAllNumberSystemsMultiple(num1,num2,result);
            break;
        case 4:
            fflush(stdin);
            printf("Enter num1:\n");
            scanf("%u",&num1);
            fflush(stdin);
            result = ~num1;
            printInAllNumberSystemsSingle(num1,result);
            break;
        case 5:
            fflush(stdin);
            printf("Enter num1:\n");
            scanf("%u",&num1);
            fflush(stdin);
            printf("Enter number of bits:\n");
            scanf("%u",&numberOfBits);
            fflush(stdin);
            result = num1 << numberOfBits;
            printInAllNumberSystemsSingle(num1,result);
            fflush(stdin);
            break;
        case 6:
            fflush(stdin);
            printf("Enter num1:\n");
            scanf("%u",&num1);
            fflush(stdin);
            printf("Enter number of bits:\n");
            scanf("%u",&numberOfBits);
            fflush(stdin);
            result = num1 >> numberOfBits;
            printInAllNumberSystemsSingle(num1,result);
            fflush(stdin);
            break;
        default:
            printf("Please enter valid input! Exiting program execution abruptly!!");
            fprintf(outputfile_ProgrammerMode,"INVALID INPUT\n");
            return EXIT_FAILURE;
            break;
    }
    fprintf(outputfile_ProgrammerMode,"Closing log file...\n");
    fclose(outputfile_ProgrammerMode);
    outputfile_ProgrammerMode = NULL;
    return EXIT_SUCCESS; 
}