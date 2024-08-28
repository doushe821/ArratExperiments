#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "getInputInt.h"

struct matrixInfo GetMatrix ()
{
    printf("Enter matrix' dimensions:");
    int X = getInputInt();
    int Y = getInputInt();
    printf("Now enter values: ");
    struct matrixInfo outputMatrix = {};
    int* values = (int*) calloc(X*Y, sizeof(int));
    if(!values)
    {
        outputMatrix.error = NO_ACCESIBLE_MEMORY;
        return outputMatrix;
    }
    for(int i = 0; i < X*Y; i++)
        values[i] = getInputInt();
    initializeMatrix(values, X, Y);
}