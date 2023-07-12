#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* head;
void Insert(int data, int n){}
void Print(){}

int main(){
    head  = NULL;
    Insert(1,1);
    Insert(2,2);
    Insert(3,3);
    Print();
}