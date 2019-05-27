#include "../src/algoritm.h"
#include "../src/print_graph.h"
#include "../thirdparty/ctest.h"
#include <stdio.h>
#include <stdlib.h>
/*
extern int A[10][10];
extern FILE* tf;

//-------------------------------------------------------------

CTEST(InputData, amountofways) // Тест ввода количества городов
{
    int F;
    F = 11; // Ввод неправильного количества городов (> 10)
    int c1 = input(F);

    F = 1; // Ввод неправильного количества городов (2 <)
    int c2 = input(F);

    F = 5; // Ввод правильного количества городов
    int c3 = input(F);

    //    F = 'A'; // Ввод неправильного формата данных
    //    int c4 = input(F);

    const int exp1 = 0;
    const int exp2 = 0;
    const int exp3 = 1;
    //    const int exp4 = 0;

    ASSERT_EQUAL(exp1, c1);
    ASSERT_EQUAL(exp2, c2);
    ASSERT_EQUAL(exp3, c3);
    //    ASSERT_EQUAL(exp4, c4);
}

//-------------------------------------------------------------

CTEST(InputData, pathsitselves) // Тест матрицы смежности
{
    int A[10][10];

    for (int i = 0; i < 5; i++) // Ввод неправильной матрицы смежности
        for (int j = 0; j < 5; j++)
            A[i][j] = i + 1;
    int c1 = check_input(5);

    for (int i = 0; i < 5;
         i++) // Ввод матрицы смежности без нулей на гл. диагонали

        for (int j = 0; j < 5; j++) {
            A[i][j] = i + 1;
            A[j][i] = A[i][j];
        }
    int c2 = check_input(5);

    for (int i = 0; i < 5;
         i++) { // Ввод неправильной матрицы смежности c нулями на гл. диагонали
        for (int j = 0; j < 5; j++)
            A[i][j] = i + 1;
        A[i][i] = 0;
    }
    int c3 = check_input(5);

    for (int i = 0; i < 5; i++) { // Ввод правильной матрицы смежности
        for (int j = 0; j < 5; j++) {
            A[i][j] = i + 1;
            A[j][i] = A[i][j];
        }
        A[i][i] = 0;
    }
    int c4 = check_input(5);

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
*/