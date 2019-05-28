#include "../src/algoritm.h"
#include "../src/print_graph.h"
#include "../thirdparty/ctest.h"
#include <stdio.h>
#include <stdlib.h>

int A[10][10];

//-------------------------------------------------------------

CTEST(InputData, AmountOfWays) // Тест ввода количества городов
{
    int F;
    F = 11; // Ввод неправильного количества городов (> 10)
    int c1 = check_city(F);

    F = 1; // Ввод неправильного количества городов (2 <)
    int c2 = check_city(F);

    F = 5; // Ввод правильного количества городов
    int c3 = check_city(F);

    F = 'A'; // Ввод неправильного формата данных
    int c4 = check_city(F);

    const int exp1 = 0;
    const int exp2 = 0;
    const int exp3 = 1;
    const int exp4 = 0;

    ASSERT_EQUAL(exp1, c1);
    ASSERT_EQUAL(exp2, c2);
    ASSERT_EQUAL(exp3, c3);
    ASSERT_EQUAL(exp4, c4);
}

//-------------------------------------------------------------

CTEST(InputData, PathsItselves) // Тест матрицы смежности
{
    for (int i = 0; i < 5; i++) // Ввод неправильной матрицы смежности
        for (int j = 0; j < 5; j++)
            A[i][j] = 25;
    int c1 = check_paths(5);

    // Ввод матрицы смежности без нулей на гл. диагонали
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++) {
            A[i][j] = i + 1;
            A[j][i] = A[i][j];
        }
    int c2 = check_paths(5);

    // Ввод неправильной матрицы смежности c нулями на гл. диагонали
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++)
            A[i][j] = i + 1;
        A[i][i] = 0;
    }
    int c3 = check_paths(5);

    for (int i = 0; i < 5; i++) { // Ввод правильной матрицы смежности
        for (int j = 0; j < 5; j++) {
            A[i][j] = i + 1;
            A[j][i] = A[i][j];
        }
        A[i][i] = 0;
    }
    int c4 = check_paths(5);

    const int exp1 = 0;
    const int exp2 = 0;
    const int exp3 = 0;
    const int exp4 = 1;

    ASSERT_EQUAL(exp1, c1);
    ASSERT_EQUAL(exp2, c2);
    ASSERT_EQUAL(exp3, c3);
    ASSERT_EQUAL(exp4, c4);
}

//-------------------------------------------------------------

CTEST(InputData, Input2Vertices) // Тест ввода количества городов
{
    int n, m;

    // Ввод неправильной вершины n
    n = 0, m = 5;
    int c1 = check_ab(n, m, 10);

    // Ввод неверной вершины
    n = 5, m = 0;
    int c2 = check_ab(n, m, 10);

    // Ввод двух неверных вершин (меньше 2)
    n = 0, m = 0;
    int c3 = check_ab(n, m, 10);

    // Ввод двух неверных вершин (меньше 0)
    n = -2, m = 5;
    int c4 = check_ab(n, m, 10);

    // Ввод неверного типа вершины n
    n = 5, m = 5.0;
    int c5 = check_ab(n, m, 10);

    // Мусор
    n = 'A', m = '<';
    int c6 = check_ab(n, m, 10);

    // Ввод двух неверных вершин (больше 10)
    n = 17, m = 25;
    int c7 = check_ab(n, m, 10);

    // Ввод двух одинаковых вершин
    n = 5, m = 5;
    int c8 = check_ab(n, m, 10);

    // Ввод вверных вершин
    n = 2, m = 7;
    int c9 = check_ab(n, m, 10);

    // Ввод неверной вершины m (больше n)
    n = 5, m = 8;
    int c10 = check_ab(n, m, 6);

    const int exp1 = 0;
    const int exp2 = 0;
    const int exp3 = 0;
    const int exp4 = 0;
    const int exp5 = 0;
    const int exp6 = 0;
    const int exp7 = 0;
    const int exp8 = 0;
    const int exp9 = 1;
    const int exp10 = 0;

    ASSERT_EQUAL(exp1, c1);
    ASSERT_EQUAL(exp2, c2);
    ASSERT_EQUAL(exp3, c3);
    ASSERT_EQUAL(exp4, c4);
    ASSERT_EQUAL(exp5, c5);
    ASSERT_EQUAL(exp6, c6);
    ASSERT_EQUAL(exp7, c7);
    ASSERT_EQUAL(exp8, c8);
    ASSERT_EQUAL(exp9, c9);
    ASSERT_EQUAL(exp10, c10);
}

//-------------------------------------------------------------