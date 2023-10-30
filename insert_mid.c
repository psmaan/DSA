#include <stdio.h>
#include <stdlib.h>
 struct node{
    int data;
    struct node * next;

 };

 void linkedlisttraversal(struct node * ptr)
 {
    while(ptr != NULL)
    {
        printf("element: %d\n",ptr->data);
        ptr = ptr->next;
    }
 }

 struct node * insertatindex(struct node *head,int data,int index){
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    struct node * p = head;
    int i = 0;

    while(i!=index - 1){
      p = p->next;
        i++;
    }

    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;

 }   
 
  int main(){
    struct node * head;
    struct node * second;
    struct node * third;
    struct node * fourth;

    head = (struct node * )malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = ( struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));


    head->data = 7;
    head->next = second;

    second->data = 11;
    second->next = third;

    third ->data=41;
    third->next=fourth;

    fourth->data = 66;
    fourth->next = NULL;

    head = insertatindex(head, 56 , 2);
    linkedlisttraversal(head);



    return 0;

  }
