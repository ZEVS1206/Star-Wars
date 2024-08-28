#ifndef matrix_h
#define matrix_h

/*struct Matrix
{
    int **table;
    size_t num_of_lines;
    size_t num_of_cols;
};*/

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
    ERROR_OF_CREATING           = -1,
    ERROR_OF_ADDING_MATRIX      =  0,
    NO_ERRORS                   =  1,
    ERROR_OF_MULTYPLYING_MATRIX =  2,
    ERROR_OF_CLEANING_MATRIX    =  3
};

// matrix_free
Matrix_errors free_matrix(struct Matrix *matrix);
Matrix_errors create_matrix_from_console(struct Matrix *matrix);
Matrix_errors create_matrix_from_file(FILE *fp, struct Matrix *matrix);
Matrix_errors add_matrix(struct Matrix *matrix1,
                         struct Matrix *matrix2,
                         struct Matrix *result_matrix);

#endif
