#pragma once

typedef struct {
    double *x;
    double *y;
    int n;
}answer;
void rk_4(double *x, double y_0, double *y_ans);
double nustrom(double *x , double  y_0, double *y_ans, int n);
answer solve();
double *get_split(double a, double b, double c, int n);

