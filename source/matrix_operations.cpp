#include <TXLib.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "matrix_operations.h"
#include "input_output.h"

void Create_matrix(FILE *fp, struct matrix *Matrix){
    int type = 0;
    if (fp == NULL){
        type = 1;
    }
    if (type == 0){
        get_sizes(fp, Matrix);
        Matrix->table = (int**)calloc(Matrix->num_of_lines, sizeof(int*));
        for (size_t i = 0; i < Matrix->num_of_lines; i++){
            Matrix->table[i] = (int *)calloc(Matrix->num_of_cols, sizeof(int));
        }
        get_values(fp, Matrix);
    } else {
        Matrix->table = (int**)calloc(Matrix->num_of_lines, sizeof(int*));
        for (size_t i = 0; i < Matrix->num_of_lines; i++){
            Matrix->table[i] = (int *)calloc(Matrix->num_of_cols, sizeof(int));
        }
    }
}

void Add_matrixs(struct matrix *Matrix1, struct matrix *Matrix2, struct matrix *Result_Matrix){
    if (Matrix1->num_of_lines != Matrix2->num_of_lines
        || Matrix1->num_of_cols != Matrix2->num_of_cols)
        {
        return 1;
        }
    Result_Matrix->num_of_lines = Matrix1->num_of_lines;
    Result_Matrix->num_of_cols = Matrix1->num_of_cols;
    Create_matrix(NULL, Result_Matrix);
    for (size_t i = 0; i < Matrix1->num_of_lines; i++){
        for (size_t j = 0; j < Matrix1->num_of_cols; j++){
            (Result_Matrix->table)[i][j] = (Matrix1->table)[i][j]+
                                           (Matrix2->table)[i][j];
        }
    }

}

