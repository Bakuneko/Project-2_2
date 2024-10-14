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
    int helping = 100;
    int a[100][100], b[100][100], c[100][100], elem_c;

    long long op_count = 0; // счётчик операций

    srand(time(NULL));
    while (i < helping)
    {
        j = 0;
        while (j < helping)
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
    while (i < helping)
    {
        j = 0;
        while (j < helping)
        {
            b[i][j] = rand() % 100 + 1;
            j++;
            op_count++; // одна операция присвоения
        }
        i++;
    }

    // Умножение матриц
    for (i = 0; i < helping; i++)
    {
        for (j = 0; j < helping; j++)
        {
            elem_c = 0;
            for (r = 0; r < helping; r++)
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