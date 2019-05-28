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
    if (n == 10) {
        printf(" ");
        for (int i = 0; i < n; i++) {
            printf("%s%d\t", KRED, i + 1);
        }
        printf("\n");

        for (int i = 0; i < n; i++) {
            printf("%s%d ", KRED, i + 1);

            for (int j = 0; j < n; j++) {
                printf("%s%d\t", KNRM, A[i][j]);
            }
            printf("\n");
        }
    }

    if (n == 9) {
        printf("\t ");
        for (int i = 0; i < n; i++) {
            printf("%s%d\t", KRED, i + 1);
        }
        printf("\n\t");

        for (int i = 0; i < n; i++) {
            printf("%s%d ", KRED, i + 1);

            for (int j = 0; j < n; j++) {
                printf("%s%d\t", KNRM, A[i][j]);
            }
            printf("\n\t");
        }
    }

    if ((n == 7) || (n == 8)) {
        printf("\t\t ");
        for (int i = 0; i < n; i++) {
            printf("%s%d\t", KRED, i + 1);
        }
        printf("\n\t\t");

        for (int i = 0; i < n; i++) {
            printf("%s%d ", KRED, i + 1);

            for (int j = 0; j < n; j++) {
                printf("%s%d\t", KNRM, A[i][j]);
            }
            printf("\n\t\t");
        }
    }

    if ((n >= 5) && (n < 7)) {
        printf("\t\t\t  ");
        for (int i = 0; i < n; i++) {
            printf("%s%d\t", KRED, i + 1);
        }
        printf("\n\t\t\t");

        for (int i = 0; i < n; i++) {
            printf("%s%d ", KRED, i + 1);

            for (int j = 0; j < n; j++) {
                printf("%s%d\t", KNRM, A[i][j]);
            }
            printf("\n\t\t\t");
        }
    }

    if (n < 5) {
        printf("\t\t\t\t  ");
        for (int i = 0; i < n; i++) {
            printf("%s%d\t", KRED, i + 1);
        }
        printf("\n\t\t\t\t");

        for (int i = 0; i < n; i++) {
            printf("%s%d ", KRED, i + 1);

            for (int j = 0; j < n; j++) {
                printf("%s%d\t", KNRM, A[i][j]);
            }
            printf("\n\t\t\t\t");
        }
    }
}

void start_window()
{
    printf("\n\t\t\t   Welcome to the Graphs!\n");
    printf("\n");
    printf("\t\t\t    1)       Start\n");
    printf("\t\t\t    2)       Info\n\n\n\n");
    printf("\t\t\t    3)       Exit\n\n");
}

void info()
{
    printf("\n\t\t\t\t  Info\n");
    printf("\n");
    printf("\t    Graph is a diagram showing the relation between\n");
    printf("\t    variable quantities, typically of two variables,\n");
    printf("\t each measured along one of a pair of axes at right angles.\n\n");
    printf("\t    This program is designed to solve problems on graphs:\n");
    printf("\t the shortest path between two vertices, the number of "
           "different\n");
    printf("\troutes between two vertices, the longest path between two "
           "vertices\n\n\n");
    printf("\t\t   1) Previous page\t\t 2) Exit\n\n");
}

void options()
{
    printf("\n\t\t\t   Choose the option!\n");
    printf("\n");
    printf("\t\t\t    1) Make a graph\n");
    printf("\t\t\t    2) Random graph\n\n\n\n");
    printf("\t\t\t    3) Previous page\n\n");
}