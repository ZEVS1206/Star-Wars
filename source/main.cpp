#include <TXLib.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "input_output.h"
#include "matrix_operations.h"

int main(){
    FILE *fp = fopen("source//Matrix.txt", "r");
    if (fp == NULL){
        return -1;
    }
    struct Matrix matrix = {0};
    Matrix_errors error = NO_ERRORS;
    //error = matrix_create_from_file(fp, &matrix);
    //error = create_matrix_from_console(&matrix);
    error = create_an_empty_matrix(&matrix);
    if (error != NO_ERRORS){
        return -1;
    }
    error = matrix_print(&matrix);
    //error = print_triangle_table(&matrix);
    if (error != NO_ERRORS){
        matrix_free(&matrix);
        return -1;
    }
    matrix_free(&matrix);
    return 0;
}





