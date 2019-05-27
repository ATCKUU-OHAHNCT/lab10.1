#ifndef ALGORITM_H
#define ALGORITM_H

void go(int curr, int b, int n);
void input_city(int* n);
void input_ab(int* a, int* b);
void clear();

int check_city(int n);
int check_paths(int n);
int check_ab(int a, int b, int n);
int Deikstr(int n, int a, int b);

#endif