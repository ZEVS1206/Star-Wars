#ifndef matrix_h
#define matrix_h

void Create_matrix(FILE *fp, struct matrix *Matrix);
void Add_matrix(struct matrix *Matrix1,
               struct matrix *Matrix2,
               struct matrix *Result_Matrix);

#endif
