#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*next;
};
void display(struct node*head)
{
	if(head==NULL)
	{
		printf("Empty");
	}
	struct node*ptr=NULL;
	ptr=head;
	while(ptr!=NULL)
	{
	printf("%d\n",ptr->data);
	ptr=ptr->next;
	}
}
struct node*delete_beg(struct node*head)
{
	if(head==NULL)
	{
		printf("Empty");
	}
	else
	{
	struct node*temp=NULL;
	temp=head;
	head=head->next;
	free(temp);
	temp=NULL;
	}
	return head;
}

int main()
{
	struct node*head=(struct node*)malloc(sizeof(struct node));
	head->data=1;
	head->next=NULL;
	struct node*node1=(struct node*)malloc(sizeof(struct node));
	node1->data=2;
	node1->next=NULL;
	struct node*node2=(struct node*)malloc(sizeof(struct node));
	node2->data=3;
	node2->next=NULL;
	
	head->next=node1;
	node1->next=node2;
	printf("List before:\n");
	display(head);
	head=delete_beg(head);
	printf("List after:\n");
	display(head);
}
