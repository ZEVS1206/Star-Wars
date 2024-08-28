#include <TXLib.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "matrix_operations.h"
#include "input_output.h"

Matrix_errors create_matrix(FILE *fp, struct Matrix *matrix){
    int type = 0;
    if (fp == NULL){
        type = 1;
    }
    if (type == 0){
        get_sizes(fp, matrix);
        matrix->table = (int**)calloc(matrix->num_of_lines, sizeof(int*));
        if (matrix->table == NULL){
            return ERROR_OF_CREATING;
        }
        for (size_t i = 0; i < matrix->num_of_lines; i++){
            matrix->table[i] = (int *)calloc(matrix->num_of_cols, sizeof(int));
        }
        get_values(fp, matrix);
    } else {
        matrix->table = (int**)calloc(matrix->num_of_lines, sizeof(int*));
        if (matrix->table == NULL){
            return ERROR_OF_CREATING;
        }
        for (size_t i = 0; i < matrix->num_of_lines; i++){
            matrix->table[i] = (int *)calloc(matrix->num_of_cols, sizeof(int));
        }
    }
    return NO_ERRORS;
}

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

}

