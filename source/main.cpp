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
    Matrix_errors error = create_matrix(fp, &matrix);
    if (error != NO_ERRORS){
        return -1;
    }
    print(&matrix);
    return 0;
}





