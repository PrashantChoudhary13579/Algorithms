#include<stdio.h>
#include<string.h>
int main(){

    char a[4] ={ 'B', 'C', 'D' ,'E'};
    char *q = &a[0];
    printf("The first value of q - %c ", *q);
    int c = *q++;
    printf("\nInteger (ASCII value) = %d ", c);

    printf("\nAdding up (*++q) + (*q) + c - %d", (*++q)+(*q)+c);
    return 0;
}