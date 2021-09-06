#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <string.h>

#define e 2.718281828459045

//standardCalculator Functions
void Addition(double num1,double num2);
void Difference(double num1,double num2);
void Product(double num1,double num2);
void Division(double num1,double num2);
int StandardCalculator();

//scientificCalculator Functions
void mySine(double num);
void myCosine(double num);
void myTan(double num);
void myInvSine(double num);
void myInvCosine(double num);
void myInvTan(double num);
void myHypSine(double num);
void myHypTan(double num);
void myInvHypSine(double num);
void myInvHypCosine(double num);
void myInvHypTan(double num);
void myExpo(double num);
void myLogE(double num);
void myLog10(double num);
void myNthRoot(double num,double root);
void myXRaisedToY(double num,double power);
void my10RaisedToX(double num);
void myModX(double num);
void myFactorial(double num);
int ScientificCalculator();

//ProgrammerMode Functions
void printInAllNumberSystemsMultiple(unsigned int num1, unsigned int num2, unsigned int result);
void printInAllNumberSystemsSingle(unsigned int num, unsigned int result);
int ProgrammerMode();

//calculateDateTime Functions
int valid_date(int day, int mon, int year);
int calculateDateTime();

//matrixOperations Functions
int MatrixCalculate();
int SimultaneousEquation();


