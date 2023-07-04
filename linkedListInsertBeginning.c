#include <stdio.h>
#include <stdlib.h>

 

struct node
{
    int data;
    struct node* next;
};

struct node* head;
void Insert(int x)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    (*temp).data = x;
    (*temp).next = head;
    head = temp;
}
void Print()
{
    struct node* temp = head;
    printf("list is: ");
    while(temp !=NULL){
        printf(" %d",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

 


int main() 
{
    head = NULL;
    printf("how many numbers?\n");
    int n,i,x;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("enter the numbers \n");
        scanf("%d",&x);
        Insert(x);
        Print();
    }
}