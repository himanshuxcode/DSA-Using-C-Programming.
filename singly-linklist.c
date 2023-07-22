#include<stdio.h>
#include<stdlib.h>

///Defining Node
struct Node
{
    int data;
    struct Node* next;
};

///Main Function
void main(){
    printf("Singly LinkList\n");

    //Creating Nodes
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    //Addressing Nodes
    head = (struct Node*)malloc(sizeof(struct Node*));
    second = (struct Node*)malloc(sizeof(struct Node*));
    third = (struct Node*)malloc(sizeof(struct Node*));

    //Connecting Nodes & Assigning Data Values
    head->data = 100;
    head->next = second;

    second->data = 120;
    second->next = third;

    third->data = 140;
    third->next = NULL;

    //Print LinkList
    traverseLinkList(head);
}

//Traverse Function
void traverseLinkList(struct Node* Head){
    struct Node* current = Head;
    while (current != NULL)
    {
        printf("Element: %d\n",current->data);
        current = current->next;
    }
}