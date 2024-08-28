#include <stdio.h>
#include "matrix.h"

static int searchBiggestInt(int* ar);

static int defineDigitsInt(int a);

void printMatrix(struct matrixInfo matrix)
{
    for (int i = 0; i < matrix.x; i++)
    {
        for (int j = 0; j < matrix.y; j++)
        {
            printf("%10d ", *(matrix.matrix + i*matrix.y + j));
        }
            printf("\n\n\n\n");
    }
}

static int searchBiggestInt(int* ar, int arSize)
{
    int tempBiggest = 0;
    for(int i = 0; i < arSize - 1; i++)
    {

        if(*(ar + i) > *(ar + i + 1))
            tempBiggest = *(ar + i);
        else
            tempBiggest = *(ar + i + 1);

    }
    return tempBiggest;
}

static int defineDigitsInt(int a)
{
    int tenPower = 10;
    int digits = 0;
    do
    {
        digits++;
    } while((tenPower*=tenPower) < a);

    return digits;
}
