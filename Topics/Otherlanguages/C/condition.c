#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main_condition(void)
{
    int age = 15;
    if (age >= 20) {
        printf("adult");
    } else {
        printf("student");
    }

    printf("\n");

    int age2 = 12;
    if (age2 >= 8 && age2 <= 13) {
        printf("elementary");
    } else if (age2 >= 14 && age2 <= 16) {
        printf("middle");
    } else if (age2 >= 17 && age2 <= 19) {
        printf("high");
    }
    printf("\n");

    srand(time(NULL));
    int i  = rand() % 3;

    switch (i) {
        case 0: printf("rock\n"); break;
        case 1: printf("scissor\n"); break;
        case 2: printf("paper\n"); break;
        default:printf("I don't know");
    }

    srand(time(NULL));
    int num = rand() % 100 + 1;
    printf("number: %d\n", num);
    int answer = 0;
    int chance = 5;
    while (chance > 0) {
        printf("remainder : %d\n", chance--);
        printf("guess number(1-100): ");
        scanf("%d", &answer);
        if (answer > num) {
            printf("down\n");
        } else if (answer < num) {
            printf("up\n");
        } else if (answer == num) {
            printf("you're right\n");
            break;
        } else {
            printf("unknown error\n");
        }

        if (chance == 0) {
            printf("the remainder is 0\n");
        }
    }



    return 0;
}

