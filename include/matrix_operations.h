#ifndef matrix_h
#define matrix_h


struct Row
{
    int *array;
    size_t num_of_cols;
};

struct Matrix
{
    Row *table;
    size_t num_of_rows;
};

enum Matrix_errors
{
    ERROR_OF_CREATING_MATRIX    = -1,
    ERROR_OF_ADDING_MATRIX      =  0,
    NO_ERRORS                   =  1,
    ERROR_OF_MULTYPLYING_MATRIX =  2,
    ERROR_OF_CLEANING_MATRIX    =  3,
    ERROR_OF_PRINTING_MATRIX    =  4,
    ERROR_OF_READING_FROM_FILE  =  5,
};


Matrix_errors matrix_free(struct Matrix *matrix);
Matrix_errors matrix_create_from_console(struct Matrix *matrix);
Matrix_errors matrix_create_from_file(FILE *fp, struct Matrix *matrix);
Matrix_errors matrix_create(struct Matrix *matrix, size_t num_of_rows, size_t *lens);
Matrix_errors create_an_empty_matrix(struct Matrix *matrix);
Matrix_errors matrix_add(struct Matrix *matrix1,
                         struct Matrix *matrix2,
                         struct Matrix *result_matrix);

#endif
