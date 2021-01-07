#include "func_17.h"
double dy_dx(double x, double y){
    return y*(1-x);
}

double y_target(double x){
    double  arg = x - (x*x)/2.0;
    return 1 + arg + arg * arg / 2. + arg * arg * arg / 6. + arg*arg*arg*arg/24;
}
