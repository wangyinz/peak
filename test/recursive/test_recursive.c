#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "test_cblas.h"

#define N 80

int functionA(int num);

__attribute__((noinline)) int functionC(int num)
{
    usleep(1);
    // printf("B: %d \n", num);
    return num - 1;
}

__attribute__((noinline)) int functionB(int num)
{
    //  usleep(200000);
    // printf("B: %d \n", num);
    // usleep(1);
    if (num > 1) {
        return functionA(functionC(num));
    }
    return 0;
}

__attribute__((noinline)) int functionA(int num)
{
    // usleep(200000);
    // printf("A: %d \n", num);
    usleep(1);
    if (num > 1) {
        return functionB(num - 1);
    }
    return 0;
}

int main(int argc, char* argv[])
{
    int input;
    //  if(argc<2) {printf("error: no argument\n"); exit(0);}
    //  input=atoi(argv[1]);
    input = 100000;
    printf("input=%d\n", input);
    int a = functionA(input);
    printf("a=%d\n", a);
    float x[N], y[N];
    for (int i = 0; i < N; i++) {
        x[i] = i;
        y[i] = i + 1;
    }
    float dot_product;
    for (int i = 0; i < 1000; i++) {
        dot_product = cblas_sdot(N, x, 1, y, 1);
    }
    printf("Dot product: %f\n", dot_product);
    return 0;
}