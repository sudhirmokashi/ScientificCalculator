#include "calc.h"

FILE *outputfile_standardCalc = NULL;

void Addition(double num1,double num2)
{
    double res = num1 + num2;
    printf("Result of addition = %lf\n",res);
    fprintf(outputfile_standardCalc,"%lf + %lf = %lf\n",num1,num2,res);
}
void Difference(double num1,double num2)
{
    double res = num1 - num2;
    printf("Result of Subtraction = %lf\n",res);
    fprintf(outputfile_standardCalc,"%lf - %lf = %lf\n",num1,num2,res);
}
void Product(double num1,double num2)
{
    double res = num1 * num2;
    printf("Result of Multiplication = %lf\n",res);
    fprintf(outputfile_standardCalc,"%lf * %lf = %lf\n",num1,num2,res);
}
void Division(double num1,double num2)
{
    double res = num1 / num2;
    printf("Result of division = %lf\n",res);
    fprintf(outputfile_standardCalc,"%lf / %lf = %lf\n",num1,num2,res);
}

int StandardCalculator()
{
    char choice,*eptr;
    double input1,input2;
    char num1[100] = {'\0'},num2[100] = {'\0'};

    outputfile_standardCalc = fopen("F://ProjectsUsingC//ScientificCalculator//Logs//log_standard_calculator.txt", "a");

    if(outputfile_standardCalc == NULL)
    {
        printf("log file could not be opened\n");
        return EXIT_FAILURE;
    }    
    fprintf(outputfile_standardCalc,"Opening Log File.............\n");
    fflush(stdin);
    printf("Enter num1:\n");
    scanf("%[^\n]s",num1);
    fflush(stdin);
    printf("Enter num2:\n");
    scanf("%[^\n]s",num2);

    input1 = strtod(num1,&eptr);
    if (input1 == 0)
    {
        if (errno == ERANGE)
        {
            printf("The value for input1 provided was out of range\n");
            printf("Exiting Program execution abruptly\n");
            fprintf(outputfile_standardCalc,"The value for input1 provided was out of range\n");
            return EXIT_FAILURE;
        }
    }
    input2 = strtod(num2,&eptr);
    if (input2 == 0)
    {
        if (errno == ERANGE)
        {
            printf("The value for input2 provided was out of range\n");
            printf("Exiting Program execution abruptly\n");
            fprintf(outputfile_standardCalc,"The value for input2 provided was out of range\n");
            return EXIT_FAILURE;
        }
    }
    printf("Enter choice of Operation:\n");
    printf("\tA - Addition of the inputs\n");
    printf("\tS - Subtraction of the second input from first\n");
    printf("\tM - Product of the two inputs\n");
    printf("\tD - Division of the first input by second input\n");
    //clearing the screen
    fflush(stdin);
    scanf("%c",&choice);
    if(choice == 'A')
        Addition(input1,input2);
    else if(choice == 'S')
        Difference(input1,input2);
    else if(choice == 'M')
        Product(input1,input2);
    else if(choice == 'D')
        Division(input1,input2);
    else
    {
        printf("Enter a valid choice! Only choices are A,S,M or D. Check the choice given, Exiting Program abruptly\n");
        fprintf(outputfile_standardCalc,"Invalid Choice\n");
        return EXIT_FAILURE;
    }

    fprintf(outputfile_standardCalc,"Closing Log File..........\n");

    fclose(outputfile_standardCalc);
    outputfile_standardCalc = NULL;
    return EXIT_SUCCESS;
}