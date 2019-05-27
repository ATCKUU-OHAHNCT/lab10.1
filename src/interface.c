#include "interface.h"
#include "algoritm.h"
#include "print_graph.h"
#include "stdio.h"
#include "stdlib.h"

int N_res;
int A[10][10], max[1] = {0}, sum[1] = {0};

void Welcome_window()
{
    clear();
    File_input("../txtFiles/welcome.txt");
    while (1) {
        Input();
        break;
    }
}

void Input()
{
    clear();
    File_input("../txtFiles/welcome.txt");
    int l = 0;
    while ((l != 1) && (l != 2) && (l != 3)) {
        scanf("%d", &l);
        switch (l) {
        case 1:
            IloveTomatos();
            break;
        case 2:
            Info();
            break;
        case 3:
            exit(0);
            break;
        default:
            clear();
            Input();
        }
    }
}

void Info()
{
    int l;
    clear();
    File_input("../txtFiles/info.txt");
    while ((l != 1) && (l != 2)) {
        scanf("%d", &l);
        switch (l) {
        case 1:
            Welcome_window();
            break;
        case 2:
            exit(0);
        default:
            clear();
            Info();
        }
    }
}

void IloveTomatos()
{
    int l;
    clear();
    File_input("../txtFiles/topics.txt");
    while ((l != 1) && (l != 2) && (l != 3)) {
        scanf("%d", &l);
        switch (l) {
        case 1: {
            clear();

            int i = 0, j = 0, n = 0;
            int a, b;

            do {
                clear();
                input_city(&n);
            } while (!check_city(n));

            do {
                printf("\n%s %d %s %d %s\n\n",
                       "Enter",
                       n,
                       "vertices per string",
                       n,
                       "times");

                for (i = 0; i < n; i++)
                    for (j = 0; j < n; j++)
                        scanf(" %d", &A[i][j]);
            } while (!check_paths(n));

            do {
                input_ab(&a, &b);
            } while (!check_ab(a, b, n));

            printf("\n\n");
            print_graph(n);

            go(a - 1, b - 1, n);

            printf("\nAmount of ways: %d\n", sum[0]);
            printf("Longest way: %d\n", max[0]);
            //    Deikstr(n, a, b);

            system("pause");

            IloveTomatos();
            break;
        }
        case 2: {
            clear();

            IloveTomatos();
            break;
        }
        case 3:
            Input();
            break;
        default:
            clear();
            IloveTomatos();
        }
    };
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
