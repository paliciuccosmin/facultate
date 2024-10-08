#include<stdio.h>

void swap(int*a,int*b)
{
    int aux=*a;
    printf("%d \n",aux);
    *a=*b;
    *b=aux;
}

int main()
{
    int a=4,b=2;
    swap(&a,&b);
    printf("%d %d",a,b);

}