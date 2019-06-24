#include <stdio.h>

int main_loop(void)
{
    int a = 10;
    printf("a is %d\n", a);
    a++;
    printf("a is %d\n", a);

    int b = 20;
    printf("a is %d\n", ++b);
    printf("a is %d\n", b++);
    printf("a is %d\n", b);

    for (int i = 1; i <= 5; i++)
    {
        printf("Hello World %d\n", i);
    }

    int i = 1;
    while(i <= 5)
    {
        printf("Hello World %d\n", i++);
    }

    i  = 1;
    do {
        printf("Hello World %d\n", i++);
    } while (i <= 5);

    char star = '*';
    for (int j = 1; j <= 5; j++)
    {
        for (int k = 1; k <= j; k++)
        {
            printf("%c", star);
        }
        printf("\n");
    }


    int floor;

    printf("how tall?");
    scanf("%d", &floor);

    for (int f = 1; f <= floor; f++)
    {
        int empty_num = floor - f;
        int star_num = 2 * f - 1;

        for (a = 0; a < empty_num; a++)
        {
            printf("%c", ' ');
        }

        for (a = 0; a < star_num; a++)
        {
            printf("%c", '*');
        }

        for (a = 0; a < empty_num; a++)
        {
            printf("%c", ' ');
        }
        printf("\n");
    }


    return 0;
}

