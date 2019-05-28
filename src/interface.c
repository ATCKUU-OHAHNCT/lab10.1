#include "interface.h"
#include "algoritm.h"
#include "print_graph.h"
#include "stdio.h"
#include "stdlib.h"

int N_res;
int A[10][10], max[1] = {0}, sum[1] = {0}, big[10];

void Welcome_window()
{
    clear();
    start_window();
    while (1) {
        Input();
        break;
    }
}

void Input()
{
    char l;
    clear();
    start_window();
    while ((l != '1') && (l != '2') && (l != '3')) {
        scanf(" %c", &l);
        switch (l) {
        case '1':
            IloveTomatos();
            break;
        case '2':
            Info();
            break;
        case '3':
            exit(0);
            break;
        default:
            printf("Error.. Try again\n");
        }
    }
}

void Info()
{
    char l;
    clear();
    info();
    while ((l != '1') && (l != '2')) {
        scanf(" %c", &l);
        switch (l) {
        case '1':
            Welcome_window();
            break;
        case '2':
            exit(0);
        default:
            printf("Error.. Try again\n");
        }
    }
}

void IloveTomatos()
{
    char l;
    srand(0);
    clear();
    options();
    while ((l != '1') && (l != '2') && (l != '3')) {
        scanf(" %c", &l);
        switch (l) {
        case '1':
            handgraph();
            break;

        case '2':
            randgraph();
            break;

        case '3':
            Input();
            break;
        default:
            printf("Error.. Try again\n");
        }
    };
}

void handgraph()
{
    clear();

    int i = 0, j = 0, n = 0;
    int a, b, g = 0;
    char c;

    do {
        clear();
        input_city(&n);
    } while (!check_city(n));

    do {
        if (g == 1)
            printf("\n\t\t\t%s %d %s %d %s\n\n",
                   "Error.. Please, enter",
                   n,
                   "vertices per string",
                   n,
                   "times");
        else
            printf("\n\t\t\t%s %d %s %d %s\n\n",
                   "Enter",
                   n,
                   "vertices per string",
                   n,
                   "times");

        for (i = 0; i < n; i++) {
            printf("\t\t\t\t\t");
            for (j = 0; j < n; j++)
                scanf(" %d", &A[i][j]);
        }
        g = 1;
    } while (!check_paths(n));
    g = 0;

    do {
        input_ab(&a, &b);
    } while (!check_ab(a, b, n));

    clear();
    printf("\n\n\n\n");
    print_graph(n);
    go(a - 1, b - 1, n);

    printf("\n\t\t\tAmount of ways: %d\n\n", sum[0]);
    printf("\t\t\tLongest way: %d\n", max[0]);

    //    Deikstr(n, a, b);

    printf("\n\n\n\n\n\n\nPress any button to continue or Q "
           "for "
           "exit\t");

    scanf(" %c", &c);
    if ((c == 'Q') || (c == 'q'))
        exit(0);

    IloveTomatos();
}

void randgraph()
{
    clear();

    int i = 0, j = 0, n = 0;
    int a, b;
    char c;

    do {
        clear();
        input_city(&n);
    } while (!check_city(n));

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            A[i][j] = rand() % 101;
            A[j][i] = A[i][j];
        }
        A[i][i] = 0;
    }

    do {
        clear();
        printf("\n\n\n\n\n");
        print_graph(n);
        input_ab(&a, &b);
    } while (!check_ab(a, b, n));

    clear();
    printf("\n\n\n\n");
    print_graph(n);
    go(a - 1, b - 1, n);

    printf("\n\t\t\tAmount of ways: %d\n\n", sum[0]);
    printf("\t\t\tLongest way: %d\n", max[0]);
    /*    for (int i = 0; i < 10; i++)
            printf("%d ", big[i]);*/

    //    Deikstr(n, a, b);

    printf("\n\n\n\n\n\n\nPress any button to continue or Q "
           "for "
           "exit\t");

    scanf(" %c", &c);
    if ((c == 'Q') || (c == 'q'))
        exit(0);

    IloveTomatos();
}

int File_input(char* fname)
{
    FILE* file;
    char result_string[322];
    file = fopen(fname, "r");
    if (file == NULL) {
        printf("Error opening file '%s'", fname);
        return 0;
    }
    while (fgets(result_string, sizeof(result_string), file)) {
        printf("%s\n", result_string);
    }
    fclose(file);
    return 1;
}
