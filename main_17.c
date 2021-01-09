#include <stdio.h>
#include "odu_17.h"
#include "func_17.h"
#include <stdlib.h>

int main(int argc, char *argv[]) {
    double a, b, c, eps;
    int i;
    FILE *input;
    if((input=fopen("../in.txt", "r"))==NULL){
        printf("There is no such file");
        return 1;
    }

    fscanf(input, "%lf", &a);
    fscanf(input, "%lf", &b);
    fscanf(input, "%lf", &c);
    fscanf(input, "%lf", &eps);

    answer res =  solve(a,b,c,eps);
    FILE *out = fopen("../out.csv","w");
    fprintf(out,"%f",res.n);
    fprintf(out,"x,y,y_pred\n");
    for(i=0; i < res.n; i++){
        fprintf(out,"%f,%f,%f\n",res.x[i],y_target(res.x[i]),res.y[i]);
    }
    fclose(out);


// system("python3 /home/dor/practicum/practikum/main.py");
}



