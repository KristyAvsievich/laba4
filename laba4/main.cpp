#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

using namespace std;

typedef struct node {                   //стурктура дереве
    int value;
    struct node *left;                  //меньше
    struct node *right;                 //больше
} node;
typedef node* list;


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    list root;
    return 0;
}
