#include <TXLib.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "matrix_operations.h"
#include "input_output.h"

Matrix_errors create_matrix_from_file(FILE *fp, struct Matrix *matrix){
    if (fp == NULL){
        return ERROR_OF_CREATING;
    }
    get_number_rows(fp, matrix);
    matrix->table = (Row*)calloc(matrix->num_of_rows, sizeof(Row));
    if (matrix->table == NULL){
        return ERROR_OF_CREATING;
    }
    get_number_cols(fp, matrix);
    for (size_t i = 0; i < matrix->num_of_rows; i++){
        (matrix->table[i]).array = (int *)calloc((matrix->table[i]).num_of_cols, sizeof(int));
    }
    get_values(fp, matrix);
    return NO_ERRORS;
}


Matrix_errors create_matrix_from_console(struct Matrix *matrix){
    size_t num_of_rows = 0;
    printf("Enter the quantity of rows: ");
    scanf("%d", &num_of_rows);
    matrix->num_of_rows = num_of_rows;
    matrix->table = (Row*)calloc(num_of_rows, sizeof(Row));
    if(matrix->table == NULL){
        return ERROR_OF_CREATING;
    }
    for (size_t i = 0; i < num_of_rows; i++){
        size_t num_of_cols = 0;
        printf("Enter the quantity of cols: ");
        scanf("%d", &num_of_cols);
        (matrix->table[i]).array = (int*)calloc(num_of_cols, sizeof(int*));
        if ((matrix->table[i]).array == NULL){
            return ERROR_OF_CREATING;
        }
        (matrix->table[i]).num_of_cols = num_of_cols;
        printf("Enter elements of row:\n");
        for (size_t j = 0; j < num_of_cols; j++){
            scanf("%d", &(((matrix->table[i]).array)[j]));
        }
    }
    return NO_ERRORS;
}


//matrix_create(&matrix, 9, {1, 3, 5, 3, 6, 7, 5, 3, 5})


/*
Matrix_errors add_matrix(struct Matrix *matrix1, struct Matrix *matrix2, struct Matrix *result_matrix){
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

