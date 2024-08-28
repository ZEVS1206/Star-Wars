#include <TXLib.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#include "input_output.h"
#include "matrix_operations.h"

void print(struct Matrix *matrix){
    assert (matrix != NULL);
    for (size_t i = 0; i < matrix->num_of_lines; i++){
        for (size_t j = 0; j < matrix->num_of_cols; j++){
            printf("%2d ", (matrix->table)[i][j]);
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

void get_sizes(FILE *fp, struct Matrix *matrix){
    assert(fp != NULL);
    assert(matrix != NULL);
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
    matrix->num_of_lines = nlines;
    matrix->num_of_cols = ncols;
    rewind(fp);
}

void get_values(FILE *fp, struct Matrix *matrix){
    assert(fp != NULL);
    assert(matrix != NULL);
    for (size_t i = 0; i < matrix->num_of_lines; i++){
        for (size_t j = 0; j < matrix->num_of_cols; j++){
            fscanf(fp, "%d", &((matrix->table)[i][j]));
        }
    }
}

void print_triangle_table(struct Matrix *matrix){
    assert(matrix != NULL);
    int cnt_of_elements = (matrix->num_of_lines) * (matrix->num_of_cols);
    int *elements = (int *)calloc(cnt_of_elements, sizeof(int));
    int k = 0;
    for (size_t i = 0; i < matrix->num_of_lines; i++){
        for (size_t j = 0; j < matrix->num_of_cols; j++){
            elements[k++] = (matrix->table)[i][j];
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


