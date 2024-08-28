#include <stdio.h>
#include <stdlib.h>
#include "ArythmProgression.h"
#include "matrix.h"

#include <assert.h>

// Tournament grid

void CreateGrid(const int* grid, int matches);

int ArythmProgression(int a, int d);

int UnitTest();

int main ()
{
    int errs = UnitTest();
    printf("%d errors", errs);
    return 0;
}

int UnitTest()
{
    int ar1[6] = {1, 2, 3, 4, 5, 6};
    int ar2[6] = {1, 2, 4, 5, 5, 8};
    int ar1Xar2[4] = {24, 36, 54, 81};
    int ar3[10] = {1, 2, 3, 4, 5, 6, 7, 88, 11, 30};
    int ar4[10] = {1, 2, 4, 5, 5, 8, 90, 809, 22, 228};

    struct matrixInfo mx1 = *(initializeMatrix(ar1, 2, 3));
    struct matrixInfo mx2 = *(initializeMatrix(ar2, 3, 2));

    struct matrixInfo AnsMatrix = MultiplicateMatrix(mx1, mx2);

    for (int i = 0; i < mx1.x; i++)
    {
        for (int j = 0; j < mx2.y; j++)
        {
            printf("%10d ", *(AnsMatrix.matrix + i*mx2.y + j));
        }
        printf("\n\n\n\n");
    }
    int errCount = 0;
    for(int i = 0; i < AnsMatrix.x*AnsMatrix.y; i++)
    {
        if(AnsMatrix.matrix[i] != ar1Xar2[i])
            errCount++;
    }

    free(AnsMatrix.matrix);
    free(mx1.matrix);
    free(mx2.matrix);
    return errCount;

}




//const int ar[18]= {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};
//CreateGrid(ar, sizeof(ar)/sizeof(ar[0]));

/*void CreateGrid(const int* grid, int matches)
{
    int ap = 0;
    int c = 0;
    while (matches - ap > 0)
    {
        c++;
        for (int i = 0; i < c; i++)
        {
            if ((ap+i) > matches-1)
                printf("%3d ", 0);
            else
                printf("%3d ", *(grid + ap + i));
        }
        printf("\n");
        ap = ArythmProgressionSum(1, 1, c);
    }
}    */
