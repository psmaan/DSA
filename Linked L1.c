#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*next;
};
int main()
{
	struct node*head=NULL;
	struct node*node1=NULL;
	struct node*node2=NULL;
	
	head=(struct node*)malloc(sizeof(struct node));
	node1=(struct node*)malloc(sizeof(struct node));
	node2=(struct node*)malloc(sizeof(struct node));
	
	head->data=2;
	head->next=node1;
	node1->data=3;
	node1->next=node2;
	node2->data=5;
	node2->next=NULL;
	
	printf("Head data:%d\n",head->data);
	printf("Node1 data:%d\n",node1->data);
	printf("Node2 data:%d",node2->data);
	return 0;

}
