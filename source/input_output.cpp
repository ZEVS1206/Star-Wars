#include <TXLib.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#include "input_output.h"
#include "matrix_operations.h"

// он должен выводить матрицу красиво
/*
1 2 3
2 3 4
3 4 5
*/
void Print(struct matrix *Matrix){
    assert (Matrix != NULL);
    for (size_t i = 0; i < Matrix->num_of_lines; i++){
        for (size_t j = 0; j < Matrix->num_of_cols; j++){
            printf("data[%d][%d] = %d\n", i, j,
                                        (Matrix->table)[i][j]);
        }
        printf("\n");
    }
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

void get_sizes(FILE *fp, struct matrix *Matrix){
    assert(fp != NULL);
    assert(Matrix != NULL);
    int c = 0;
    bool flag = false;
    int nlines = 0;
    int ncols = 0;
    while ((c = getc(fp)) != EOF){
        if (c == '\n'){
            nlines++;
            flag = true;
        }
        if (!flag && isspace(c)){
            ncols++;
        }
    }
    ncols++;
    Matrix->num_of_lines = nlines;
    Matrix->num_of_cols = ncols;
    rewind(fp);
}

void get_values(FILE *fp, struct matrix *Matrix){
    assert(fp != NULL);
    assert(Matrix != NULL);
    for (size_t i = 0; i < Matrix->num_of_lines; i++){
        for (size_t j = 0; j < Matrix->num_of_cols; j++){
            fscanf(fp, "%d", &((Matrix->table)[i][j]));
        }
    }
}

void Print_Triangle_table(struct matrix *Matrix){
    assert(Matrix != NULL);
    int cnt_of_elements = (Matrix->num_of_lines) * (Matrix->num_of_cols);
    int *elements = (int *)calloc(cnt_of_elements, sizeof(int));
    int k = 0;
    for (size_t i = 0; i < Matrix->num_of_lines; i++){
        for (size_t j = 0; j < Matrix->num_of_cols; j++){
            elements[k++] = (Matrix->table)[i][j];
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
}


