#ifndef matrix_h
#define matrix_h

struct Matrix
{
    int **table;
    size_t num_of_lines;
    size_t num_of_cols;
};

enum Matrix_errors
{
    ERROR_OF_CREATING           = -1,
    ERROR_OF_ADDING_MATRIX      =  0,
    NO_ERRORS                   =  1,
    ERROR_OF_MULTYPLYING_MATRIX =  2
};

Matrix_errors create_matrix(FILE *fp, struct Matrix *matrix);
Matrix_errors add_matrix(struct Matrix *matrix1,
               struct Matrix *matrix2,
               struct Matrix *result_matrix);

#endif
