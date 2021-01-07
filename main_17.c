#include <stdio.h>
#include "odu_17.h"
#include "func_17.h"
#include <stdlib.h>

int validate_file(char *file_path){
    FILE *f = fopen(file_pathm, "rb");
    return f != NULL;
}
int read_input_data(char *input_path, double *a, double *b, double *c, double *eps){
    int input_check;
    double input_values[4];
    FILE *input_file = fopen(input_path, "r");
    for(int i = 0; i <4; i++ ){
        input_check = fscanf(input_file,"lf", &input_values[i]);

        if(input_check == EOF)
            return 2;
        if(input_check == 0)
            return 3;
    }
    *a = input_values[0];
    *b = input_values[1];
    *c = input_values[2];
    *eps = input_values[3];
    return 0;
}

int main(int argc, char *argv[]) {
    double a, b, c, eps;
    int i, n, iters;
    char *input_path = "in.txt";
    char *output_path = "out.csv";
    if(argc>1){
        input_path = argv[1];
        if(argc>2){
            output_path = argv[2];
        }
    }
    if(!validate_file(input_path)){
        printf("There is no such file.\n");
        return 1;
    }
    switch (expression read_input_data(input_path,&res,&b,&c,&eps)) {
        case 0: break;
        case 2: printf(" There is no enough parameters."); return 2;
        case 3: printf(" Incorrect input"); return 3;
        default: break;
    }

    answer res =  solve();
    FILE *out = fopen("../out.csv","w");
    fprintf(out,"x,y,y_pred\n");
    for(i=0; i < res.n; i++){
        fprintf(out,"%f,%f,%f\n",res.x[i],y_target(res.x[i]),res.y[i]);
        printf("%f %f\n ", res.y[i],res.x[i]);
    }
    fclose(out);

//    double *x = get_split(lb,rb,200);
//    for(int i=0; i<200; i++){
//        printf("%f\n", x[i]);
//    }
system("python3 /home/dor/practicum/practikum/main.py");
}



