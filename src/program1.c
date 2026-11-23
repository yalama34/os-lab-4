#include "contracts.h"
#include <stdio.h>

int main(){
    int command;
    int status = 0;

    while (scanf("%d", &command) == 1){
        switch (command){
            case 1: {
                int arg1_p, arg2_p;
                if (scanf("%d %d", &arg1_p, &arg2_p) != 2){
                    status = 1;
                    break;
                }

                int result_p = PrimeCount(arg1_p, arg2_p);
                if (result_p == -1){
                    fprintf(stderr, "PrimeCount error\n");
                } else {
                    printf("%d\n", result_p);
                }
                break;
            }
            case 2: {
                float arg1_s, arg2_s;
                if (scanf("%f %f", &arg1_s, &arg2_s) != 2){
                    status = 1;
                    break;
                }

                float result_s = Square(arg1_s, arg2_s);
                printf("%f\n", result_s);
                break;
            }
            default: {
                fprintf(stderr, "Unknown command\n");
                break;
            }
        }
        if (status != 0) break;
    }

    return status;
}