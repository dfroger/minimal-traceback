#include "minimal_traceback.h"

void foo(int a, int b, int *c, MTB_T* tb) {
    if (b==0) {
        MTB_raise_ZeroDivisionError_V("value of b is zero")
    } else {
        *c = a / b;
    }
};

void bar(int a, int b, int *c, MTB_T* tb) {
    foo(a,b,c,tb); MTB_V
    *c += 10;
}


int main(int argc, char** argv) {
    int a = 2;
    int b = 0;
    int c;
    MTB_T* tb = MTB_new_tb();
    bar(a,b,&c,tb); MTB_S;
    printf("%d\n",c);
    free(tb);
}

