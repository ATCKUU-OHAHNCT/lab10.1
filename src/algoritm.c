#include "algoritm.h"
#include "interface.h"
#include "print_graph.h"
#include "stdio.h"
#include "stdlib.h"

int N_res;
int visited[10], res[10];
int A[10][10], max[1], sum[1], big[10];

//----------------------------------------------------------
void go(int curr, int b, int n)
{
    int i, k = 0;

    if (curr == b) {
        for (i = 0; i < N_res; i++) {
            //    printf("%d-", res[i] + 1);
            if (((i + 2) % 2) == 0)
                k += A[res[i - 1]][res[i]];
            else
                k += A[res[i]][res[i - 1]];
        }

        //    printf("%d\n", b + 1);

        if (N_res % 2 == 0)
            k += A[b][res[N_res - 1]];
        else
            k += A[res[N_res - 1]][b];

        if (k > max[0]) {
            max[0] = k;
            //    printf("\nCurrent max path is: ");
            for (i = 0; i < N_res; i++) {
                //        big[i] = res[i];
                //        printf("%d-", res[i] + 1);
            }
            //    printf("%d\n\n", b + 1);
            //    big[b] = b;
        }

        sum[0] += 1;

        return;
    }

    visited[curr] = 1;
    res[N_res++] = curr;

    for (i = 0; i < n; i++)
        if (A[curr][i] && !visited[i])
            go(i, b, n);

    visited[curr] = 0;
    N_res--;
}

//-----------------------------------------------------

void input_city(int* n)
{
    printf("\n\n\n\n\t\t\tInput number of cities (1 - 10)\n\n\t\t\t\t\t");
    scanf(" %d", n);
}
//-----------------------------------------------------

void input_ab(int* a, int* b)
{
    printf("\n\n\t\t\t\tInput 2 vertices:\n\n\t\t\t\t\t");
    scanf(" %d", a);
    scanf(" %d", b);
}
//----------------------------------------------------------

void clear()
{
    printf("\033[2J");
    printf("\033[0;0f");
}
//----------------------------------------------------------

int check_city(int n)
{
    if ((n < 2) || (n > 10))
        return 0;

    return 1;
}
//----------------------------------------------------------

int check_paths(int n)
{
    for (int i = 0; i < n; i++) {
        if (A[i][i] != 0)
            return 0;

        for (int j = 0; j < n; j++) {
            if ((A[i][j] != A[j][i]) || (A[i][j] < 0))
                return 0;
        }
    }

    return 1;
}
//----------------------------------------------------------

int check_ab(int a, int b, int n)
{
    if ((a < 1) || (a > n) || (b < 1) || (b > n) || (a == b))
        return 0;

    return 1;
}
//----------------------------------------------------------

int Deikstr(int n, int a, int b)
{
    int minMas[n]; // Минимальное расстояние
    int verMas[n]; // Посещенные вершины
    int tmp;
    int minindex, min;

    for (int i = 0; i < n; i++) {
        minMas[i] = 10000; //Инициализация вершин и расстояний
        verMas[i] = 1;
    }
    minMas[0] = 0;
    do {
        minindex = 10000;
        min = 10000;
        for (int i = 0; i < n; i++) {
            if ((verMas[i] == 1) && (minMas[i] < min)) {
                min = minMas[i];
                minindex = i;
            }
        }
        if (minindex != 10000) {
            for (int i = 0; i < n; i++) {
                if (A[minindex][i] > 0) {
                    tmp = min + A[minindex][i]; //Минимальный найденный вес
                    if (tmp < minMas[i]) { //
                        minMas[i] = tmp; // Сравниваем с минимальным весом
                                         // вершины
                    }
                }
            }
            verMas[minindex] = 0;
        }
    } while (minindex < 10000);

    int con = 10;
    while (con != 0) { // Восстановление пути
        int vertex[n]; // Массив посещенных вершин
        int endPoint;  // Индекс конечной вершины

        con = b;
        endPoint -= 1;
        int vend = minMas[endPoint + 1]; // vend-Для проверки на не
                                         // превышение значения 10000
        vertex[0] = endPoint + 1; // Начальный элемент - конечная вершина
        int k = 1; // Индекс предыдущей вершины
        int weight = minMas[endPoint]; // Вес конечной вершины

        while (endPoint > 0) // Пока не дошли до начальной вершины
        {
            if (vend == 10000)
                break;
            for (int i = 0; i < n; i++) // Просматриваем все вершины
                if (A[endPoint][i] != 0) // Если есть связь
                {
                    int tmp = weight - A[endPoint][i]; // Определяем вес
                                                       // вершины из предыдущей
                    if (tmp == minMas[i]) // Если вес совпал с рассчитанным
                    { // Значит из этой вершины был переход
                        weight = tmp; // Сохраняем новый вес
                        endPoint = i; // Сохраняем предыдущую вершину
                        vertex[k] = i + 1; // И записываем её в массив
                        k++;
                    }
                }
        }

        if (vend < 10000) { // Вывод пути (начальная вершина оказалась в
                            // конце массива из k - элементов)
            printf("\nВывод кратчайшего пути\n");
            printf("%3d", vertex[k - 1]);
            for (int i = k - 2; i >= 0; i--)
                printf("-->%3d ", vertex[i]);
            printf("\nРасстояние равное = %3d", vend);
        } else
            printf("Пути к этой вершине не существует");
    }
    return 0;
}
//----------------------------------------------------------