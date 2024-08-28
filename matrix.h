#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

enum errorFlags
{
    WRONG_SIZE = 1,
    NEGATIVE_DIMENSIONS = 2,
    NO_ACCESIBLE_MEMORY = 3

};

struct matrixInfo
{
    int* matrix;
    int x;
    int y;
    enum errorFlags error;
};


struct matrixInfo* initializeMatrix(int* values, int mX, int mY);
struct matrixInfo MultiplicateMatrix (struct matrixInfo m1, struct matrixInfo m2);

#endif // MATRIX_H_INCLUDED
