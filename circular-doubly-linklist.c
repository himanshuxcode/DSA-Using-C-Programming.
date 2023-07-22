#include<stdio.h>
#include<stdlib.h>

///Defining Node
struct Node
{
    struct Node* prev;
    int data;
    struct Node* next;
};

///Main Function
void main(){
    printf("Circular Doubly LinkList\n");

    //Creating Nodes
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    //Addressing Nodes
    head = (struct Node*)malloc(sizeof(struct Node*));
    second = (struct Node*)malloc(sizeof(struct Node*));
    third = (struct Node*)malloc(sizeof(struct Node*));

    //Connecting Nodes & Assigning Data Values
    head->prev = third;
    head->data = 100;
    head->next = second;

    second->prev = head;
    second->data = 120;
    second->next = third;

    third->prev = second;
    third->data = 140;
    third->next = head;

    //Print LinkList in Forward Direction
    printf("Circular Linklist in Forward Direction.\n");
    traverseLinkListForward(head);

    //Print LinkList in Reverse Direction
    printf("Circular Linklist in Reverse Direction.\n");
    traverseLinkListReverse(third);
}

//Traverse Forward Function
void traverseLinkListForward(struct Node* Head){
    struct Node* current = Head;
    do{
        printf("Element: %d\n",current->data);
        current = current->next;
    }while (current != Head);
}

//Traverse Backward Function
void traverseLinkListReverse(struct Node* tail){
    struct Node* current = tail;
    do{
        printf("Element: %d\n",current->data);
        current = current->prev;
    }while (current != tail);
}