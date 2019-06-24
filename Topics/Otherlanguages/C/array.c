#include <stdio.h>

int main(void)
{
    int subway_array[3];

    subway_array[0] = 30;
    subway_array[1] = 40;
    subway_array[2] = 50;

    int arr[10] = {1,2,3,4,5,6,7,8,9,10};

    for (int i = 0; i < 10; i++) {
        printf("%d\n", arr[i]);
    }

    int arr_2[10] = {1, 2};

    for (int i = 0; i < 10; i++) {
        printf("%d\n", arr_2[i]);
    }

    int arr_3[] = { 1, 2 };
    float arr_f[5] = {1.0f, 2.0f, 3.0f};

    char c = 'A';
    printf("%c\n", c);

    char str[6] = "coding";
    printf("%s\n", str);
    printf("%d\n", sizeof(str));


    char c_array[7] = {'c', 'o', 'd', 'i', 'n', 'g', '\0'};
    printf("%s\n", c_array);

    printf("%c\n", 'a');
    printf("%d\n", 'a');
    return 0;
}

