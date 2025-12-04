#include<stdio.h>
#include<string.h>
// using namespace std;/
int a = 200;
int main(){
    float a = 345;
    float *p = &a;
    float **q = &p;

    printf("%f\n", (**q));
    a= 200;
    printf("%.2f\n", (**q));
    

    return 0;

}