#include "matrix.h"
#include <stdlib.h>
#include <stdio.h>

struct matrixInfo* initializeMatrix(int* values, int mX, int mY)
{
    struct matrixInfo outputMatrix = {};

   /* if(sizeof(values)/sizeof(int) != mX*mY)
    {
        outputMatrix.error = WRONG_SIZE;
        return &outputMatrix;
    } */

    if(mX < 0 || mY < 0)
    {
        outputMatrix.error = NEGATIVE_DIMENSIONS;
    }

    outputMatrix.matrix = (int*) calloc(mX*mY, sizeof(int));

    if(values == NULL)
    {
        for(int i = 0; i<mX*mY; i++)
        {
            outputMatrix.matrix[i] = 0;
            return &outputMatrix;
        }
    }

    for(int i = 0; i < mX*mY; i++)
        outputMatrix.matrix[i] = values[i] ;

    outputMatrix.x = mX;
    outputMatrix.y = mY;

    return &outputMatrix;
}
