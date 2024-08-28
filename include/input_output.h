#ifndef io_h
#define io_h
#include <stdio.h>
#include "matrix_operations.h"


Matrix_errors get_number_rows_from_file(FILE *fp, struct Matrix *matrix);
Matrix_errors get_number_cols_from_file(FILE *fp, struct Matrix *matrix);
Matrix_errors matrix_print(struct Matrix* matrix);
Matrix_errors get_values_from_file(FILE *fp, struct Matrix* matrix);
Matrix_errors print_triangle_table(struct Matrix* matrix);

#endif
