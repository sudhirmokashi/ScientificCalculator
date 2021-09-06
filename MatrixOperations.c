#include "calc.h"

FILE *outputfile_MatrixOperations = NULL;

int MatrixCalculate()
{
    outputfile_MatrixOperations = fopen("F://ProjectsUsingC//ScientificCalculator//Logs//log_matrix_calculations.txt","a");
    if(outputfile_MatrixOperations == NULL)
    {
        printf("Error while opening log file! Exiting program execution abruptly!\n");
        return EXIT_FAILURE;
    }
    fprintf(outputfile_MatrixOperations,"Opening log file for matrix operations...\n");

	int i,j,row,column;

    printf("Enter no.of rows:\n");
    scanf("%d",&row);
    printf("Enter no.of columns:\n");
    scanf("%d",&column);

    int inv[row][column],choice;
    int product[row][column],k;
    int res[row][column];
    int sum[row][column];
	int array1[row][column],array2[row][column];
	int option = 0;

	printf("\n\n");

//initializing the matrix elements to 0
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < column; j++)
		{
			array1[i][j] = 0;
			array2[i][j] = 0;
		}
	}

	printf("Enter the elements of matrix 1:\n");
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < column; j++)
		{
			printf("Enter value for matrix1[%d][%d]:\n",i,j);
			scanf("%d", &array1[i][j]);
		}
	}

	printf("Enter the elements of matrix 2:\n");
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < column; j++)
		{
			printf("Enter value for matrix2[%d][%d]:\n",i,j);
			scanf("%d", &array2[i][j]);
		}
	}
	
	printf("\n\n");
	printf("Elements of matrix 1 and 2:\n");
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < column; j++)
		{
			printf("Value for matrix1[%d][%d]:	%d\n",i,j,array1[i][j]);
            fprintf(outputfile_MatrixOperations,"Value for matrix1[%d][%d]:	%d\n",i,j,array1[i][j]);
		}
	}

	printf("\n\n");
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < column; j++)
		{
			printf("Value for matrix2[%d][%d]:	%d\n", i, j, array2[i][j]);
            fprintf(outputfile_MatrixOperations,"Value for matrix2[%d][%d]:	%d\n", i, j, array2[i][j]);
		}
	}

	printf("Enter:\n");
	printf("1)If you want to add the 2 matrices\n");
	printf("2)If you want to subtract 2nd matrix from 1st matrix and get the result\n");
	printf("3)If you want to multiply the 2 matrices and get the result\n");
	printf("4)If you want the inverse of a matrix\n");
	scanf("%d", &option);

	switch (option)
	{
	    case 1:
		    printf("\n");
		    //initializing summation matrix to 0
		    //int sum[row][column];
		    for (i = 0; i < row; i++)
		    {
			    for (j = 0; j < column; j++)
			    {
				    sum[i][j] = 0;
			    }
		    }

		    for (i = 0; i < row; i++)
		    {
			    for (j = 0; j < column; j++)
			    {
				    sum[i][j] = array1[i][j] + array2[i][j];
			    }
		    }

		    printf("The summation matrix:\n");

		    for (i = 0; i < row; i++)
		    {
			    for (j = 0; j < column; j++)
			    {
				    printf("Result of matrix1[%d][%d]: %d +	matrix2[%d][%d]: %d = sum[%d][%d]: %d\n",i,j,array1[i][j], i, j, array2[i][j], i, j, sum[i][j]);
                    fprintf(outputfile_MatrixOperations,"Result of matrix1[%d][%d]: %d +	matrix2[%d][%d]: %d = sum[%d][%d]: %d\n",i,j,array1[i][j], i, j, array2[i][j], i, j, sum[i][j]);
			    }
		    }

		    //NULL-ing all the matrices
		    for (i = 0; i < row; i++)
		    {   
			    for (j = 0; j < column; j++)
			    {
				    array1[i][j] = 0;
				    array2[i][j] = 0;
				    sum[i][j] = 0;
			    }
		    }
		    break;
	    case 2:
		    //int res[row][column];
		    //initializing res matrix to 0
		    for (i = 0; i < row; i++)
		    {
			    for (j = 0; j < column; j++)
			    {
				    res[i][j] = 0;
			    }
		    }

		    printf("\n");

		    for (i = 0; i < row; i++)
		    {
			    for (j = 0; j < column; j++)
			    {
				    res[i][j] = array1[i][j] - array2[i][j];
			    }
		    }

		    for (i = 0; i < row; i++)
		    {
			    for (j = 0; j < column; j++)
			    {
				    printf("Result of matrix1[%d][%d]: %d -	matrix2[%d][%d]: %d = res[%d][%d]: %d\n", i, j, array1[i][j], i, j, array2[i][j], i, j, res[i][j]);
                    fprintf(outputfile_MatrixOperations,"Result of matrix1[%d][%d]: %d -	matrix2[%d][%d]: %d = res[%d][%d]: %d\n", i, j, array1[i][j], i, j, array2[i][j], i, j, res[i][j]);
			    }
		    }

		    //NULL-ing all the matrices
		    for (i = 0; i < row; i++)
		    {
			    for (j = 0; j < column; j++)
			    {
				    array1[i][j] = 0;
				    array2[i][j] = 0;
				    res[i][j] = 0;
			    }
		    }
		    break;
	    case 3:
		    //int product[row][column],k;

		    //initializing product matrix to 0
		    for (i = 0; i < row; i++)
		    {
			    for (j = 0; j < column; j++)
			    {
				    product[i][j] = 0;
			    }
		    }

		    for (i = 0; i < row; i++)
		    {
			    for (j = 0; j < column; j++)
			    {
				    product[i][j] = 0;
				    for (k = 0; k < column; k++)
				    {
					    product[i][j] = product[i][j] + (array1[i][k] * array2[k][j]);
				    }
			    }
		    }

		    for (i = 0; i < row; i++)
		    {
			    for (j = 0; j < column; j++)
			    {
				    printf("Result of matrix1[%d][%d]: %d *	matrix2[%d][%d]: %d = product[%d][%d]: %d\n", i, j, array1[i][j], i, j, array2[i][j], i, j, product[i][j]);
                    fprintf(outputfile_MatrixOperations,"Result of matrix1[%d][%d]: %d *	matrix2[%d][%d]: %d = product[%d][%d]: %d\n", i, j, array1[i][j], i, j, array2[i][j], i, j, product[i][j]);
			    }
		    }

		    //NULL-ing all the matrices
		    for (i = 0; i < row; i++)
		    {
			    for (j = 0; j < column; j++)
			    {
				    array1[i][j] = 0;
				    array2[i][j] = 0;
				    product[i][j] = 0;
			    }
		    }
		    break;

	    case 4:
		    //int inv[row][column],choice;
		    //initializing product matrix to 0
		    for (i = 0; i < row; i++)
		    {
			    for (j = 0; j < column; j++)
			    {
				    inv[i][j] = 0;
			    }
		    }

		    printf("\n");
		    printf("Enter:\n");
		    printf("1)If you want inverse of matrix1\n");
		    printf("2)If you want inverse of matrix2\n");
		    scanf("%d", &choice);
		    switch (choice)
		    {
		        case 1:
			        for (i = 0; i < row; i++)
			        {
				        for (j = 0; j < column; j++)
				        {
					        inv[i][j] = array1[j][i];
				        }
			        }       
			        printf("Inverted matrix:\n");
			        for (i = 0; i < row; i++)
			        {
				        for (j = 0; j < column; j++)
				        {
					        printf("inv[%d][%d]: %d\n", i, j, inv[i][j]);
                            fprintf(outputfile_MatrixOperations,"inv[%d][%d]: %d\n", i, j, inv[i][j]);
				        }
			        }
			        break;
		        case 2:
			        for (i = 0; i < row; i++)
			        {
				        for (j = 0; j < column; j++)
				        {
					        inv[i][j] = array2[j][i];
				        }
			        }
			        printf("Inverted matrix:\n");
			        for (i = 0; i < row; i++)
			        {
				        for (j = 0; j < column; j++)
				        {
					        printf("inv[%d][%d]: %d\n", i, j, inv[i][j]);
                            fprintf(outputfile_MatrixOperations,"inv[%d][%d]: %d\n", i, j, inv[i][j]);
				        }
			        }
			        break;
		        default:
			        printf("Enter a valid option\n");
			        break;
		    }
		    break;
	    default:
		    printf("Enter a valid option\n");
            fprintf(outputfile_MatrixOperations,"INVALID OPTION\n");
		    break;
	}
    fprintf(outputfile_MatrixOperations,"Closing log file for matrix operations...\n");
    fclose(outputfile_MatrixOperations);
    outputfile_MatrixOperations = NULL;
}

int SimultaneousEquation()
{
    outputfile_MatrixOperations = fopen("F://ProjectsUsingC//ScientificCalculator//Logs//log_matrix_calculations.txt","a");
    if(outputfile_MatrixOperations == NULL)
    {
        printf("Error while opening log file! Exiting program execution abruptly!\n");
        return EXIT_FAILURE;
    }
    fprintf(outputfile_MatrixOperations,"Opening log file for simulataneous equations...\n");

    int i, j, k, n ; 
    float a[20][20], x[20] ; 
    double s, p ;  
    printf("Enter the number of equations : ") ; 
    scanf("%d", &n) ; 
    printf("\nEnter the co-efficients of the equations :\n\n") ; 
    for(i = 0 ; i < n ; i++) 
    { 
        for(j = 0 ; j < n ; j++) 
        { 
            printf("a[%d][%d] = ", i + 1, j + 1) ; 
            scanf("%f", &a[i][j]) ; 
            fprintf(outputfile_MatrixOperations,"a[%d][%d] = %f\n",i+1,j+1,a[i][j]);
        } 
        printf("b[%d] = ", i + 1) ; 
        scanf("%f", &a[i][n]) ; 
        fprintf(outputfile_MatrixOperations,"b[%d] = %f\n",i+1,a[i][n]);
    } 
    for(k = 0 ; k < n - 1 ; k++) 
    { 
        for(i = k + 1 ; i < n ; i++) 
        { 
            p = a[i][k] / a[k][k] ; 
            for(j = k ; j < n + 1 ; j++) 
                a[i][j] = a[i][j] - p * a[k][j] ; 
        } 
    } 
    x[n-1] = a[n-1][n] / a[n-1][n-1] ; 
    for(i = n - 2 ; i >= 0 ; i--) 
    { 
        s = 0 ; 
        for(j = i + 1 ; j < n ; j++) 
        { 
            s += (a[i][j] * x[j]) ; 
            x[i] = (a[i][n] - s) / a[i][i] ; 
        } 
    } 
    printf("\nThe result is :\n") ; 
    fprintf(outputfile_MatrixOperations,"\n The result is:\n");
    for(i = 0 ; i < n ; i++) 
    {
        printf("\nx[%d] = %.2f\n", i + 1, x[i]) ;  
        fprintf(outputfile_MatrixOperations,"\nx[%d] = %.2f\n", i + 1, x[i]);

    }
    fprintf(outputfile_MatrixOperations,"Closing log file simultaneous equations...\n");
    fclose(outputfile_MatrixOperations);
    outputfile_MatrixOperations = NULL;
}



