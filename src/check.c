#include "check.h"
#include "algoritm.h"
#include "print_graph.h"
#include "stdio.h"

int A[10][10];

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