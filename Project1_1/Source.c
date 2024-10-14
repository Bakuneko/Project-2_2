#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
int main(void)
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);

    clock_t start, end;

    int i = 0, j = 0, r;
    int a[200][200], b[200][200], c[200][200], elem_c;

    long long op_count = 0; // счётчик операций

    srand(time(NULL));
    while (i < 200)
    {
        j = 0;
        while (j < 200)
        {
            a[i][j] = rand() % 100 + 1;
            j++;
            op_count++; // одна операция присвоения
        }
        i++;
    }

    srand(time(NULL));
    i = 0;
    j = 0;
    while (i < 200)
    {
        j = 0;
        while (j < 200)
        {
            b[i][j] = rand() % 100 + 1;
            j++;
            op_count++; // одна операция присвоения
        }
        i++;
    }

    // Умножение матриц
    for (i = 0; i < 200; i++)
    {
        for (j = 0; j < 200; j++)
        {
            elem_c = 0;
            for (r = 0; r < 200; r++)
            {
                elem_c = elem_c + a[i][r] * b[r][j];
                c[i][j] = elem_c;
                op_count += 3; // одна операция сложения, умножения и присвоения
            }
        }
    }

    printf("Кол-во операций: %lld\n", op_count);

    return 0;
}