/*
Given two SORTED Circular Linked Lists ,
Write a function to merge those two linked lists .
The First Linked List head should point to the final merged linked list .
The Final merged linked list should also be in SORTED order and a Circular Linked List.
You need to return the Length of Final SLL.

*********
The First linked list head should now point to the Final sorted(Ascending) Linked list First Node
*********
Ex : A: 0->3->5->10->20 (and 20 now pointing back to 0,instead of Null )
B: 1->2->6->11->21->50->70 (70 Pointing back to 1).

The Final Linked List is A:0->1->2->3->5->6->10->11->20->21->50->70 .

Note : Dont use Malloc or create any new nodes ,Only pointers need to be interchanged,
You can use temp pointers although.
Note : The Final Linked List should be  also be a circular Linked List where Last node is
pointing towards the first node.
Note : Return -1 for Invalid Inputs like NULL;

Input : head1 and head2 are Addresses of Two Circular Linked Lists heads .
Output :Return Length of New SLL .Modify the head1 value, such that it now points to 
Merged Sorted Circular SLL .

Difficulty : Medium
*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	int data;
	struct node *next;
};
void insaf(node **h, int data1, int itr)
{
	node *temp1, *temp;
	int i = 0;
	temp = (node*)malloc(sizeof(node));
	temp->data = data1;
	temp-> = next;
	if (*h == NULL)
	{
		*h = temp;
	}
	else
	{
		temp1 = *h;
		while (temp1->next != *h&&i < itr - 1)
		{
			temp1 = temp1->next;
			i++;
		}
		temp->next = temp1->next;
		temp1->next = temp;
	}
}
void mergmethd2(node **h1, node **h2)
{
	node *pointerh1, *pointerh2, *prev;
	int i = 0, j = 0;
	pointerh1 = *h1;
	pointerh2 = *h2;
	prev = *h1;
	while (pointerh1->next != *h1&&pointerh2->next != *h2)
	{
		if (pointerh1->data < pointerh2->data)
		{
			pointerh1 = pointerh1->next;
			i = i + 1;
		}
		else if (pointerh1->data > pointerh2->data)
		{
			j = pointerh2->data;
			insaf(&prev, j, i);
			pointerh2 = pointerh2->next;
			i = i + 1;
		}
		else if (pointerh1->data == pointerh2->data)
		{
			pointerh1 = pointerh1->next;
			pointerh2 = pointerh2->next;
			i = i + 1;
		}
	}
}
int dis(struct node **h)
{
	node *pointer;
	pointer = *h;
	int i = 0;
	while (pointer != *h)
	{
		
		i++;
	}
	return i;
}
int merge_circularlists(struct node **head1, struct node **head2){
	//Returns Length of merged Sorted circular SLL and also points *head1 to final SLL .
	if (*head1==NULL&&*head2==NULL)
	return -1;
	else
	{
		int i = 0;
		mergmethd2(head1, head2);
		i=dis(head1);
		return i;
	}
}