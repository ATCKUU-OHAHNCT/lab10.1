#include "print_graph.h"
#include "algoritm.h"
#include "interface.h"
#include "stdio.h"
#include "stdlib.h"

extern int A[10][10];

#define KNRM "\x1B[0m"
#define KRED "\x1B[31m"
#define KGRN "\x1B[32m"
#define KYEL "\x1B[33m"
#define KBLU "\x1B[34m"
#define KMAG "\x1B[35m"
#define KCYN "\x1B[36m"
#define KWHT "\x1B[37m"

void print_graph(int n)
{
    printf("  ");
    for (int i = 0; i < n; i++) {
        printf("%s%d ", KRED, i + 1);
    }
    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("%s%d ", KRED, i + 1);

        for (int j = 0; j < n; j++) {
            printf("%s%d ", KNRM, A[i][j]);
        }
        printf("\n");
    }
}