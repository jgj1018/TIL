#include <stdio.h>

int main_prinf_scanf(void)
{
    printf("Hello World\n");
    int age = 12;
    printf("%d\n", age);
    age = 13;
    printf("%d\n", age);

    float f = 46.5;
    printf("%f\n", f);
    printf("%.2f\n", f);

    double d = 4.428;
    printf("%.2lf\n", d);

    const int YEAR = 2000;
    printf("birth : %d\n", YEAR);

    int add = 3 + 7;
    printf("3 + 7 %d\n", add);
    printf("%d + %d = %d\n", 30, 79, 30 + 79);

    int input;
    printf("input value: ");
    scanf("%d", &input);
    printf("value : %d\n", input);

    int one, two, three;
    printf("3 input values");
    scanf("%d %d %d", &one, &two, &three);
    printf("%d\n", one);
    printf("%d\n", two);
    printf("%d\n", three);

    char A = 'A';
    char str[256];
    scanf("%s", str, sizeof(str));
    printf("%s\n", str);

    return 0;
}
