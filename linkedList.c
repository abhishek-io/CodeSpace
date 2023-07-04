#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    typedef struct node
    {
        int data;
        struct node *next;
    }node;

    node *A = NULL;
    node *temp = malloc(sizeof(node));
    (*temp).data=2;
    (*temp).next=NULL;
    A= temp;
    printf("%i\n",A->data);
}