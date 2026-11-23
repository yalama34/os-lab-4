#include "lib_manager.h"
#include <stdio.h>

int main(){
    if (init_library() != 0){
        return 1;
    }
    int command;
    int status = 0;
    
    while (scanf("%d", &command) == 1){
        switch (command){
            case 0: {
                if (switch_library() != 0){
                    status = 1;
                } else {
                    printf("Library switched\n");
                }
                break;
            }
            case 1: {
                int arg1_p, arg2_p;
                if (scanf("%d %d", &arg1_p, &arg2_p) != 2){
                    status = 1;
                    break;
                }
                int result_p = call_prime_count(arg1_p, arg2_p);
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
                float result_s = call_square(arg1_s, arg2_s);
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
    if (close_library() != 0){
        return 1;
    }
    return status;
}