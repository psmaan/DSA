#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*next;
};
struct node*add_beg(struct node*head,int d)
{
	struct node*ptr=(struct node*)malloc(sizeof(struct node));
	ptr->data=d;
	ptr->next=NULL;
	ptr->next=head;
	head=ptr;
	return head;
}
int main()
{
	struct node*head=NULL;
	struct node*ptr=NULL;
	head=(struct node*)malloc(sizeof(struct node));
	head->data=2;
	head->next=NULL;
	ptr=(struct node*)malloc(sizeof(struct node));
	ptr->data=4;
	ptr->next=NULL;
	
	head->next=ptr;
	int data=3;
	head=add_beg(head,data);
	ptr=head;
	while(ptr!=NULL)
	{
		printf("%d\n",ptr->data);
		ptr=ptr->next;
	}
	return 0;
}
