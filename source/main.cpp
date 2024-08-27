#include <TXLib.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "input_output.h"
#include "matrix_operations.h"

int main(){
    FILE *fp = fopen("source//Matrix.txt", "r");
    // FIXME: проверка??? if (fp == NULL) { ошибка, return}
    struct matrix Matrix = {0};
    /*MatrixError error = */Create_matrix(fp, &Matrix); // ошибка???
    //Print_Triangle_table(&Matrix);
    Print(&Matrix);
    return 0;
}





