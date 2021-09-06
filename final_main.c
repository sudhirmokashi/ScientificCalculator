#include "calc.h"

int main()
{
    int option;
    
    do
    {
        fflush(stdin);
        printf("Entering main function\n");
        printf("1.Standard Calculator\n");
        printf("2.Scientific Calculator\n");
        printf("3.Programmer Mode\n");
        printf("4.Matrix Operations\n");
        printf("5.Simultaneous Equations\n");
        printf("6. Date Difference Calculator\n");
        printf("7.Clear Screen\n");
        printf("8.Exit\n");
        printf("Enter the operation to be performed\n");
        scanf("%d",&option);
        switch (option)
        {
             case 1:
                    StandardCalculator();
                    break;
            case 2:
                    ScientificCalculator();
                    break;
            case 3:
                    ProgrammerMode();
                    break;
            case 4:
                    MatrixCalculate();
                    break;
            case 5:
                    SimultaneousEquation();
                    break;
            case 6:
                    calculateDateTime();
                    break;
            case 7:
                    system("cls");
                    break;
            case 8:
                    return (EXIT_SUCCESS);
                    break;
            default:    
                    printf("Invalid Option Entered\n");
                    break;
        }
    } while (1);
    
   
    printf("Exiting main function\n");
    return EXIT_SUCCESS;
}







