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
    scanf("%u", &num_of_rows);
    matrix->num_of_rows = num_of_rows;
    matrix->table = (Row*)calloc(num_of_rows, sizeof(Row));
    if(matrix->table == NULL){
        return ERROR_OF_CREATING_MATRIX;
    }
    for (size_t i = 0; i < num_of_rows; i++){
        size_t num_of_cols = 0;
        printf("Enter the quantity of cols: ");
        scanf("%u", &num_of_cols);
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
    for (size_t i = 0; i < matrix->num_of_rows; i++){
        for (size_t j = 0; j < (matrix->table[i]).num_of_cols; j++){
            ((matrix->table[i]).array)[j] = 0;
        }
    }
    free(matrix);
    matrix = NULL;
    return NO_ERRORS;
}

Matrix_errors ask_user_for_sizes(size_t *num_of_rows, size_t* lens){
    assert(lens != NULL);
    if (lens == NULL){
        return ERROR_OF_CREATING_MATRIX;
    }
    printf("Enter the quantity of rows: ");
    scanf("%u", num_of_rows);
    lens = (size_t*)calloc(*num_of_rows, sizeof(size_t));
    if (lens == NULL){
        return ERROR_OF_CREATING_MATRIX;
    }
    printf("Enter the lens of rows:\n");
    for (size_t i = 0; i < *num_of_rows; i++){
        scanf("%u", &lens[i]);
    }
    return NO_ERRORS;
}


Matrix_errors create_an_empty_matrix(struct Matrix *matrix){
    if (matrix == NULL){
        return ERROR_OF_CREATING_MATRIX;
    }
    Matrix_errors error = NO_ERRORS;
    size_t num_of_rows = 0;
    size_t* lens = NULL;
    error = ask_user_for_sizes(&num_of_rows, lens);
    if (error != NO_ERRORS){
        return error;
    }
    matrix->num_of_rows = num_of_rows;
    matrix->table = (Row*)calloc(num_of_rows, sizeof(Row));
    error = matrix_create(matrix, num_of_rows, lens);
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



Matrix_errors matrix_add(struct Matrix *matrix1, struct Matrix *matrix2, struct Matrix *result_matrix){
    assert(matrix1 != NULL);
    assert(matrix2 != NULL);
    assert(result_matrix != NULL);

    if (matrix1->num_of_rows != matrix2->num_of_rows
        || matrix1 == NULL
        || matrix2 == NULL
        || result_matrix == NULL
        || matrix1->table == NULL
        || matrix2->table == NULL
        || result_matrix == NULL)
        {
        return ERROR_OF_ADDING_MATRIX;
        }
    size_t num_of_rows = matrix1->num_of_rows;
    size_t* lens = (size_t *)calloc(num_of_rows, sizeof(size_t));
    if (lens == NULL){
        return ERROR_OF_ADDING_MATRIX;
    }
    for (size_t i = 0; i < num_of_rows; i++){
        lens[i] = (matrix1->table[i]).num_of_cols;
    }
    Matrix_errors error = NO_ERRORS;
    result_matrix->num_of_rows = num_of_rows;
    result_matrix->table = (Row*)calloc(num_of_rows, sizeof(Row));
    error = matrix_create(result_matrix, num_of_rows, lens);
    for (size_t i = 0; i < num_of_rows; i++){
        for (size_t j = 0; j < (matrix1->table[i]).num_of_cols; j++){
            ((result_matrix->table[i]).array)[j] = ((matrix1->table[i]).array)[j] +
                                                   ((matrix2->table[i]).array)[j];
        }
    }
    if (error != NO_ERRORS){
        return error;
    }
    return NO_ERRORS;

}

