#include <stdio.h>

void p(int num);
void function_without_return();
int function_with_return();
void function_with_parameters(int num1, int num2, int num3);

int main(void) {
    int num = 2;
    p(num);
    function_without_return();
    int ret = function_with_return();
    p(ret);
    function_with_parameters(1, 2, 3);
    return 0;
}

void p(int num)
{
    printf("num is %d \n", num);
}

void function_without_return()
{
    printf("no return \n");
}

int function_with_return()
{
    return 10;
}

void function_with_parameters(int num1, int num2, int num3)
{
    printf("%d %d %d \n", num1, num2, num3);
}