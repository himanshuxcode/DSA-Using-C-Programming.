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

    //Insertion Methods Calls
    insertionAtBegining(&head, 200);
    insertionAtIndex(&head, 2, 210);
    insertionAtEnd(head, 220);

    //Print LinkList
    traverseLinkList(head);

    //Deletion Method Calls
    deleteAtBegining(&head);
    deleteAtEnd(head);

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

//Insertion at Begining
void insertionAtBegining(struct Node** head, int value){
    //Creation of New Node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node*));

    //Assigning Value to them
    newNode->data = value;
    newNode->next = *head;

    //Made new node Head
    *head = newNode;
}

//Insertion at End
void insertionAtEnd(struct Node* head, int value){
    //Creation of New Node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node*));

    //Assigning Value to them
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }
    

    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

//Insertion at Index
void insertionAtIndex(struct Node** head,int index, int value){

    if (head == NULL) 
    {
        insertionAtBegining(&head, value);
        return;
    }
    

    //Creation of New Node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node*));

    //Assigning Value to them
    newNode->data = value;

    struct Node* current = *head;
    int count = 0;
    while (count < index)
    {
        current = current->next;
        count++;
    }
    newNode->next = current->next;
    current->next = newNode;
}

//Deletion at Begining
void deleteAtBegining(struct Node** head){
    if (*head == NULL)
    {
        return;
    }
    struct Node* temp = *head;
    *head = temp->next;
    free(temp);
    temp = NULL;
    printf("Deleted First Element\n");
}

//Deletion at End
void deleteAtEnd(struct Node* head){
    if (head == NULL)
    {
        return;
    }
    struct Node* prev = head;
    while (prev->next->next != NULL)
    {
        prev = prev->next;
    }
    struct Node* temp = prev->next;
    prev->next = NULL;

    free(temp);
    temp = NULL;
    printf("Deleted Last Element\n");
}

//Deltion at Index
void deleteAtIndex(struct Node* head,int index){
    if (head == NULL)
    {
        return;
    }
    struct Node* prev = head;
    int count = 0;
    while (count <  index)
    {
        prev = prev->next;
        count++;
    }
    struct Node* temp = prev->next;
}