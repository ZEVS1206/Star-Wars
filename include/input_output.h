#ifndef io_h
#define io_h
#include <stdio.h>


void get_number_rows(FILE *fp, struct Matrix *matrix);
void get_number_cols(FILE *fp, struct Matrix *matrix);
void print(struct Matrix* matrix);
void get_values(FILE *fp, struct Matrix* matrix);
void print_triangle_table(struct Matrix* matrix);

#endif
