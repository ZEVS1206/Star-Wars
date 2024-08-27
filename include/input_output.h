#ifndef io_h
#define io_h
#include <stdio.h>

struct matrix
{
    int **table;
    size_t num_of_lines;
    size_t num_of_cols;
};

void get_sizes(FILE *fp, struct matrix* Matrix);
void Print(struct matrix* Matrix);
// codestyle!!!!!!!!!!!!! FIXME:
void get_values(FILE *fp, struct matrix* Matrix);
void Print_Triangle_table(struct matrix* Matrix);

#endif
