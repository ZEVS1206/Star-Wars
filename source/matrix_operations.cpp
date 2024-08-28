#include <TXLib.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "matrix_operations.h"
#include "input_output.h"

Matrix_errors matrix_create_from_file(FILE *fp, struct Matrix *matrix){
    if (fp == NULL){
        return ERROR_OF_CREATING_MATRIX;
    }
    Matrix_errors error = NO_ERRORS;
    error = get_number_rows_from_file(fp, matrix);
    if (error != NO_ERRORS){
        return error;
    }
    matrix->table = (Row*)calloc(matrix->num_of_rows, sizeof(Row));
    if (matrix->table == NULL){
        return ERROR_OF_CREATING_MATRIX;
    }
    error = get_number_cols_from_file(fp, matrix);
    if (error != NO_ERRORS){
        return error;
    }
    for (size_t i = 0; i < matrix->num_of_rows; i++){
        assert(matrix->table != NULL);
        (matrix->table[i]).array = (int *)calloc((matrix->table[i]).num_of_cols, sizeof(int));
    }
    error = get_values_from_file(fp, matrix);
    if (error != NO_ERRORS){
        return error;
    }
    return NO_ERRORS;
}


Matrix_errors matrix_create_from_console(struct Matrix *matrix){
    if (matrix == NULL){
        return ERROR_OF_CREATING_MATRIX;
    }
    size_t num_of_rows = 0;
    printf("Enter the quantity of rows: ");
    scanf("%d", &num_of_rows);
    matrix->num_of_rows = num_of_rows;
    matrix->table = (Row*)calloc(num_of_rows, sizeof(Row));
    if(matrix->table == NULL){
        return ERROR_OF_CREATING_MATRIX;
    }
    for (size_t i = 0; i < num_of_rows; i++){
        size_t num_of_cols = 0;
        printf("Enter the quantity of cols: ");
        scanf("%d", &num_of_cols);
        (matrix->table[i]).array = (int*)calloc(num_of_cols, sizeof(int*));
        if ((matrix->table[i]).array == NULL){
            return ERROR_OF_CREATING_MATRIX;
        }
        (matrix->table[i]).num_of_cols = num_of_cols;
        printf("Enter elements of row:\n");
        for (size_t j = 0; j < num_of_cols; j++){
            scanf("%d", &(((matrix->table[i]).array)[j]));
        }
    }
    return NO_ERRORS;
}

Matrix_errors matrix_free(struct Matrix *matrix){
    if (matrix == NULL){
        return ERROR_OF_CLEANING_MATRIX;
    }
    free(matrix);
    matrix = NULL;
    return NO_ERRORS;
}


Matrix_errors create_an_empty_matrix(struct Matrix *matrix){
    if (matrix == NULL){
        return ERROR_OF_CREATING_MATRIX;
    }
    size_t num_of_rows = 0;
    printf("Enter the quantity of rows: ");
    scanf("%d", &num_of_rows);
    size_t* lens = (size_t*)calloc(num_of_rows, sizeof(size_t));
    matrix->table = (Row*)calloc(num_of_rows, sizeof(Row));
    if (lens == 0){
        return ERROR_OF_CREATING_MATRIX;
    }
    printf("Enter the lens of rows:\n");
    for (size_t i = 0; i < num_of_rows; i++){
        scanf("%d", &lens[i]);
    }
    Matrix_errors error = matrix_create(matrix, num_of_rows, lens);
    if (error != NO_ERRORS){
        return error;
    }
    return NO_ERRORS;
}



Matrix_errors matrix_create(struct Matrix *matrix, size_t num_of_rows, size_t *lens){
    if (matrix == NULL || lens == NULL){
        return ERROR_OF_CREATING_MATRIX;
    }
    for (size_t i = 0; i < num_of_rows; i++){
        assert((matrix->table) != NULL);
        (matrix->table[i]).num_of_cols = lens[i];
        (matrix->table[i]).array = (int*)calloc(lens[i], sizeof(int));
        for (size_t j = 0; j < lens[i]; j++){
            ((matrix->table[i]).array)[j] = 0;
        }
    }
    return NO_ERRORS;
}


/*
Matrix_errors matrix_add(struct Matrix *matrix1, struct Matrix *matrix2, struct Matrix *result_matrix){
    if (matrix1->num_of_lines != matrix2->num_of_lines
        || matrix1->num_of_cols != matrix2->num_of_cols)
        {
        return ERROR_OF_ADDING_MATRIX;
        }
    result_matrix->num_of_lines = matrix1->num_of_lines;
    result_matrix->num_of_cols = matrix1->num_of_cols;
    create_matrix(NULL, result_matrix);
    for (size_t i = 0; i < matrix1->num_of_lines; i++){
        for (size_t j = 0; j < matrix1->num_of_cols; j++){
            (result_matrix->table)[i][j] = (matrix1->table)[i][j]+
                                           (matrix2->table)[i][j];
        }
    }
    return NO_ERRORS;

}*/

