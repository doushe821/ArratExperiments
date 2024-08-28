#include <stdio.h>
#include "getInputInt.h"

int getInputInt()
{
    int outputValue = 0;
    int ch = 0;
    while(1)
    {
        while (scanf("%d", outputValue) && (ch = getchar()) == '\n')
            return outputValue;
        printf("It's not a number, try again.\n");
    }
}