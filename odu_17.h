#pragma once

typedef struct {
    double *x;
    double *y;
    int n;
}answer;
void rk_4(double *x, double y_0, double *y_ans, int size);
double nustrom(double *x , double  y_0, double *y_ans, int size);
answer solve();
double *get_split(double lb, double rb, int n);

