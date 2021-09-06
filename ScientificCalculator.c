#include "calc.h"

FILE *outputfile_scientificCalculator = NULL;

void mySine(double num)
{
    double res = sin(num);
    printf("sin(%lf) = %lf\n",num,res);
    fprintf(outputfile_scientificCalculator,"sin(%lf) = %lf\n",num,res);
}
void myCosine(double num)
{
    double res = cos(num);
    printf("cos(%lf) = %lf\n",num,res);
    fprintf(outputfile_scientificCalculator,"cos(%lf) = %lf\n",num,res);
}
void myTan(double num)
{
    double res = tan(num);
    printf("tan(%lf) = %lf\n",num,res);
    fprintf(outputfile_scientificCalculator,"tan(%lf) = %lf\n",num,res);
}
void myInvSine(double num)
{
    double res = asin(num);
    printf("sin_inv(%lf) = %lf\n",num,res);
    fprintf(outputfile_scientificCalculator,"sin_inv(%lf) = %lf\n",num,res);
}
void myInvCosine(double num)
{
    double res = acos(num);
    printf("acos(%lf) = %lf\n",num,res);
    fprintf(outputfile_scientificCalculator,"acos(%lf) = %lf\n",num,res);
}
void myInvTan(double num)
{
    double res = atan(num);
    printf("atan(%lf) = %lf\n",num,res);
    fprintf(outputfile_scientificCalculator,"atan(%lf) = %lf\n",num,res);
}
void myHypSine(double num)
{
    double res = sinh(num);
    printf("sinh(%lf) = %lf\n",num,res);
    fprintf(outputfile_scientificCalculator,"sinh(%lf) = %lf\n",num,res);
}
void myHypCosine(double num)
{
    double res = cosh(num);
    printf("cosh(%lf) = %lf\n",num,res);
    fprintf(outputfile_scientificCalculator,"cosh(%lf) = %lf\n",num,res);
}
void myHypTan(double num)
{
    double res = tanh(num);
    printf("tanh(%lf) = %lf\n",num,res);
    fprintf(outputfile_scientificCalculator,"tanh(%lf) = %lf\n",num,res);
}
void myInvHypSine(double num)
{
    double res = asinh(num);
    printf("asinh(%lf) = %lf\n",num,res);
    fprintf(outputfile_scientificCalculator,"asinh(%lf) = %lf\n",num,res);
}
void myInvHypCosine(double num)
{
    double res = acosh(num);
    printf("acosh(%lf) = %lf\n",num,res);
    fprintf(outputfile_scientificCalculator,"acosh(%lf) = %lf\n",num,res);
}
void myInvHypTan(double num)
{
    double res = atanh(num);
    printf("atanh(%lf) = %lf\n",num,res);
    fprintf(outputfile_scientificCalculator,"atanh(%lf) = %lf\n",num,res);
}
void myExpo(double num)
{
    double res = pow(e,num);
    printf("e^(%lf) = %lf\n",num,res);
    fprintf(outputfile_scientificCalculator,"e^(%lf) = %lf\n",num,res);
}
void myLogE(double num)
{
    double res = log(num);
    printf("logE(%lf) = %lf\n",num,res);
    fprintf(outputfile_scientificCalculator,"logE(%lf) = %lf\n",num,res);
}
void myLog10(double num)
{
    double res = log10(num);
    printf("log10(%lf) = %lf\n",num,res);
    fprintf(outputfile_scientificCalculator,"log10(%lf) = %lf\n",num,res);
}
void myNthRoot(double num,double root)
{
    double res = pow(num,(1/root));
    printf("%lf root of (%lf) = %lf\n",root,num,res);
    fprintf(outputfile_scientificCalculator,"%lf root of (%lf) = %lf\n",root,num,res);
}
void myXRaisedToY(double num,double power)
{
    double res = pow(num,power);
    printf("%lf raised to (%lf) = %lf\n",num,power,res);
    fprintf(outputfile_scientificCalculator,"%lf raised to (%lf) = %lf\n",num,power,res);
}
void my10RaisedToX(double num)
{
    double res = pow(10,num);
    printf("10 raised to (%lf) = %lf\n",num,res);
    fprintf(outputfile_scientificCalculator,"10 raised to (%lf) = %lf\n",num,res);
}
void myModX(double num)
{
    double res = fabs(num);
    printf("|(%lf)| = %lf\n",num,res);
    fprintf(outputfile_scientificCalculator,"|(%lf)| = %lf\n",num,res);
}
void myFactorial(double num)
{
    double res = 1;
    double i;
    for(i=0;i<num;i++)
    {
        res = res * (num - i);
    }
    printf("%lf! = %lf\n",num,res);
    fprintf(outputfile_scientificCalculator,"%lf! = %lf\n",num,res);
}

int ScientificCalculator()
{
    int choice;
    double input1,root,power;
    
    outputfile_scientificCalculator = fopen("F://ProjectsUsingC//ScientificCalculator//Logs//log_scientific_calculator.txt","a");

    if(outputfile_scientificCalculator == NULL)
    {
        printf("log file could not be opened\n");
        return EXIT_FAILURE;
    }    
    fprintf(outputfile_scientificCalculator,"Opening Log File.............\n");
    printf("For trigonometric calculations, enter the input in radians\n");
    printf("Choice of operations:\n");
    printf("\t1) To calculate sin(x)\n");
    printf("\t2) To calculate cos(x)\n");
    printf("\t3) To calculate tan(x)\n");
    printf("\t4) To calculate sin-1(x)\n");
    printf("\t5) To calculate cos-1(x)\n");
    printf("\t6) To calculate tan-1(x)\n");
    printf("\t7) To calculate sinh(x)\n");
    printf("\t8) To calculate cosh(x)\n");
    printf("\t9) To calculate tanh(x)\n");
    printf("\t10) To calculate sinh-1(x)\n");
    printf("\t11) To calculate cosh-1(x)\n");
    printf("\t12) To calculate tanh-1(x)\n");
    printf("\t13) To calculate e^(x)\n");
    printf("\t14) To calculate ln(x)\n");
    printf("\t15) To calculate log10(x)\n");
    printf("\t16) To calculate nth root(x)\n");
    printf("\t17) To calculate x^(y)\n");
    printf("\t18) To calculate 10^(x)\n");
    printf("\t19) To calculate |x|\n");
    printf("\t20) To calculate x!\n");
    printf("Enter the input:\n");
    scanf("%lf",&input1);
    printf("Enter the choice:\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            mySine(input1);
            break;
        case 2:
            myCosine(input1);
            break;
        case 3:
            myTan(input1);
            break;
        case 4:
            myInvSine(input1);
            break;
        case 5:
            myInvCosine(input1);
            break;
        case 6:
            myInvTan(input1);
            break;
        case 7:
            myHypSine(input1);
            break;
        case 8:
            myHypCosine(input1);
            break;
        case 9:
            myHypTan(input1);
            break;
        case 10:
            myInvHypSine(input1);
            break;
        case 11:
             myInvHypCosine(input1);
            break;
        case 12:
            myInvHypTan(input1);
            break;
        case 13:
            myExpo(input1);
            break;
        case 14:
            myLogE(input1);
            break;
        case 15:
            myLog10(input1);
            break;
        case 16:
            fflush(stdin);
            printf("Enter root number:\n");
            scanf("%lf",&root);
            myNthRoot(input1,root);
            break;
        case 17:
            fflush(stdin);
            printf("Enter power number:\n");
            scanf("%lf",&power);
            myXRaisedToY(input1,power);
            break;
        case 18:
            my10RaisedToX(input1);
            break;
        case 19:
            myModX(input1);
            break;
        case 20:
            myFactorial(input1);
            break;
        default:
            printf("Please enter valid input! Exiting program execution abruptly!!");
            fprintf(outputfile_scientificCalculator,"INVALID INPUT\n");
            return EXIT_FAILURE;
            break;
    }
    fprintf(outputfile_scientificCalculator,"Closing log file...\n");
    fclose(outputfile_scientificCalculator);
    outputfile_scientificCalculator = NULL;
    return EXIT_SUCCESS;
}
