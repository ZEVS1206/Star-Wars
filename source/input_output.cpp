#include <TXLib.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#include "input_output.h"
#include "matrix_operations.h"

Matrix_errors matrix_print(struct Matrix *matrix){
    assert (matrix != NULL);
    if (matrix == NULL){
        return ERROR_OF_PRINTING_MATRIX;
    }
    for (size_t i = 0; i < matrix->num_of_rows; i++){
        size_t num_of_cols = (matrix->table[i]).num_of_cols;
        for (size_t j = 0; j < num_of_cols; j++){
            printf("%2d ", ((matrix->table[i]).array)[j]);
        }
        printf("\n");
    }
    return NO_ERRORS;
}
static int comparison(double a, double b){
    double eps = 1e-6;
    if (b >= a + eps){
        return -1;
    } else if (b < (a + eps) && b > (a - eps)){
        return 0;
    } else {
        return 1;
    }
}

Matrix_errors get_number_rows_from_file(FILE *fp, struct Matrix *matrix){
    //assert(fp != NULL);
    //assert(matrix != NULL);
    if (fp == NULL || matrix == NULL){
        return ERROR_OF_READING_FROM_FILE;
    }
    int nlines = 0;
    int symbol = 0;
    while ((symbol = getc(fp)) != EOF){
        if (symbol == '\n'){
            nlines++;
        }
    }
    matrix->num_of_rows = nlines;
    rewind(fp);
    return NO_ERRORS;
}

Matrix_errors get_number_cols_from_file(FILE *fp, struct Matrix *matrix){
    //assert(fp != NULL);
    //assert(matrix != NULL);
    if (fp == NULL || matrix == NULL){
        return ERROR_OF_READING_FROM_FILE;
    }
    int ncols = 0;
    size_t i = 0;
    int symbol = 0;
    while ((symbol = getc(fp)) != EOF){
        if (i == matrix->num_of_rows){
            break;
        }
        if (symbol == '\n'){
            (matrix->table[i]).num_of_cols = ncols + 1;
            ncols = 0;
            i++;
        }

        if (isspace(symbol) && symbol != '\n'){
            ncols++;
        }
    }
    rewind(fp);
    return NO_ERRORS;
}

Matrix_errors get_values_from_file(FILE *fp, struct Matrix *matrix){
    //assert(fp != NULL);
    //assert(matrix != NULL);
    if (fp == NULL || matrix == NULL){
        return ERROR_OF_READING_FROM_FILE;
    }
    for (size_t i = 0; i < matrix->num_of_rows; i++){
        for (size_t j = 0; j < (matrix->table[i]).num_of_cols; j++){
            fscanf(fp, "%d", &(((matrix->table[i]).array)[j]));
        }
    }
    return NO_ERRORS;
}

Matrix_errors print_triangle_table(struct Matrix *matrix){
    //assert(matrix != NULL);
    if (matrix == NULL){
        return ERROR_OF_PRINTING_MATRIX;
    }
    int cnt_of_elements = (matrix->num_of_rows) * ((matrix->table[0]).num_of_cols);
    int *elements = (int *)calloc(cnt_of_elements, sizeof(int));
    int k = 0;
    for (size_t i = 0; i < matrix->num_of_rows; i++){
        for (size_t j = 0; j < (matrix->table[i]).num_of_cols; j++){
            elements[k++] = ((matrix->table[i]).array)[j];
        }
    }

    double quantity_of_full_strings_double = (sqrt(1 + 8 * cnt_of_elements) - 1) / 2;
    int quantity_of_full_strings_int = (int)floor(quantity_of_full_strings_double);
    int i = 1;
    for (;i <= quantity_of_full_strings_int; i++){
        for (int j = 0; j < i; j++){
            printf("%d ", elements[i * (i - 1) / 2 + j]);
        }
        printf("\n");
    }

    if (comparison(quantity_of_full_strings_int,
                   quantity_of_full_strings_double) != 0){
        for (int j = 0; (i * (i - 1) / 2 + j) < cnt_of_elements; j++){
            printf("%d ", elements[i * (i - 1) / 2 + j]);
        }
    }
    return NO_ERRORS;
}


