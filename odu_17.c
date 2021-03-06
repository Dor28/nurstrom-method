#include "func_17.h"
#include "malloc.h"
#include "odu_17.h"

double y_0 =1;
double *x;
/*  rk_4  вычисляет разгоночные точки для nustroma так как их там 3-4
   он вычисляет первые три точки
  */
void rk_4(double *x, double y_0, double *y_ans) {
    y_ans[0] = y_0;
    double k1, k2, k3, k4;
    double h = x[1] - x[0];
    for (int i = 0; i < 2; i++) {
        k1 = dy_dx(x[i], y_ans[i]);
        k2 = dy_dx(x[i] + h / 2.0, y_ans[i] + h / 2.0 * k1);
        k3 = dy_dx(x[i] + h / 2.0, y_ans[i] + h / 2.0 * k2);
        k4 = dy_dx(x[i] + h, y_ans[i] + h * k3);
        y_ans[i + 1] = y_ans[i] + h / 6.0 * (k1 + 2 * k2 + 2 * k3 + k4);
    }

}

//double *get_split(double lb, double rb, int n) {
//    double *x = (double *)malloc(n*sizeof(double ));
//    for (int i =0 ; i < n; i++)
//        x[i] = lb + ( (rb - lb)/ (n-1) ) * i ;
//
//    return  x;
//}

double *get_split(double a, double b, double c, int n){

    double *x = (double *)malloc(n*sizeof(double ));
    for (int i =0; i<n;i++){
        x[i] = a + n*i;
    }
    return x;
}



double nustrom(double *x, double y_0, double *y_ans, int n) {
    double h = x[1] - x[0];
    rk_4(x,y_0,y_ans);
    double f_n, f_n_1, f_n_2;
    for(int i=3; i<n; i++){
        f_n = dy_dx(x[i-1], y_ans[i-1]);
        f_n_1 = dy_dx(x[i-2], y_ans[i-2]);
        f_n_2 = dy_dx(x[i-3], y_ans[i-3]);
        y_ans[i] = y_ans[i-2] + h * (f_n*7.0/3.0 - f_n_1*2.0/3.0 + f_n_2*1.0/3.0 );
   }

}



double err_calc(double *y1, double *y2, double n){
    double error = 0;
    for(int i=0; i<n; i++){
        error += (y1[i]-y2[2*i]) *(y1[i]-y2[2*i]);
    }
    return error / n;
}

answer solve(double a, double b, double c, double eps){
// TODO решить вопрос с с и n
    int n = (int)((b-a)/c)+1;
    double c_1 = c;
    double *x_n, *x_2n;
    double *y_n, *y_2n;

    do {


//        free(x_n);
//        free(x_2n);
//        free(y_n);
//        free(y_2n);

        x_n = get_split(a,b,c_1,n);
        x_2n = get_split(a, b,c_1, 2 * n);
        y_n = get_split(a, b,c_1, n);
        y_2n = get_split(a, b,c_1, 2 * n);

        nustrom(x_n,y_0,y_n,n);
        nustrom(x_2n,y_0,y_2n,2*n);



    }while (err_calc(y_n,y_2n,n)>eps);

    free(x_n);
    free(y_n);
    return (answer){x_2n, y_2n, 2*n};

}


