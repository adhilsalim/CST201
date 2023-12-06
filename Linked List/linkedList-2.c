/*
This program performs the following operations on a linked list:
1. Insertion at the beginning
2. Insertion at the end
3. Insertion after an element
4. Insertion before an element
5. Deletion at the beginning
6. Deletion at the end
7. Deletion of a specified element
Author: Aaron Samuel Mathew
*/
#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *link;
};
//*******************************************node creation
struct Node *node_cre(struct Node *newn)
{
	newn = (struct Node *)malloc(sizeof(struct Node));

	printf("enter the element to insert");
	int b;
	scanf("%d", &b);
	newn->data = b;
	newn->link = NULL;
	return newn;
}
//************************************************insert begi
struct Node *insertbeginning(struct Node *head)
{
	struct Node *newn;
	newn = node_cre(newn);
	if (head == NULL)
	{
		head = newn;
	}

	else
	{
		newn->link = head;
		head = newn;
	}

	return head;
}
//************************************************delete beginning
struct Node *deletebeginning(struct Node *head)
{

	struct Node *temp;
	struct Node *temp1;
	if (head == NULL)
	{
		printf("List is Empty");
	}

	else
	{
		temp = head;
		temp1 = temp->link;
		free(temp);
		head = temp1;
	}

	return head;
}
//************************************************delete ending
struct Node *deleteending(struct Node *head)
{

	struct Node *temp;
	struct Node *temp1;
	if (head == NULL)
	{
		printf("List is Empty");
	}
	temp = head;
	temp1 = head;
	temp = temp->link;
	while (temp->link != NULL)
	{
		temp = temp->link;
		temp1 = temp1->link;
	}
	temp1->link = NULL;
	free(temp);

	return head;
}

//************************************************insert end

struct Node *insertending(struct Node *head)
{
	struct Node *temp;
	struct Node *newn;
	temp = head;
	newn = node_cre(newn);
	if (head == NULL)
	{
		head = newn;
	}

	else
	{
		while (temp->link != NULL)
		{
			temp = temp->link;
		}

		temp->link = newn;
	}

	return head;
}

//************************************************print

int print(struct Node *head)

{
	struct Node *temp;
	temp = head;
	if (head == NULL)
	{
		printf("The List Is Empty");
	}
	while (temp != NULL)
	{
		printf("%d\t", temp->data);
		temp = temp->link;
	}
	printf("\n");
}
//************************************************insert after element

struct Node *insertafterelement(struct Node *head)
{
	struct Node *temp;
	struct Node *temp1;
	struct Node *newn;
	newn = node_cre(newn);

	printf("Enter the element after which you want to enter");
	int c;
	int flag = 0;
	scanf("%d", &c);
	temp = head;
	if (temp->data == c)
	{
		temp1 = temp->link;
		temp->link = newn;
		newn->link = temp1;
		flag = 1;
	}

	while (temp->link != NULL)
	{
		temp = temp->link;
		if (temp->data == c)
		{
			temp1 = temp->link;
			temp->link = newn;
			newn->link = temp1;
			flag = 1;
			break;
		}

		else
		{
			continue;
		}
	}
	if (flag == 0)
	{
		printf("\nThe element does not exist :(\n");
	}

	return head;
}

//************************************************delete  element

struct Node *deleteelement(struct Node *head)
{
	struct Node *temp;
	struct Node *temp1;
	struct Node *temp2;
	printf("Enter the element which you want to delete");
	int c;
	int flag = 0;
	scanf("%d", &c);
	if (head == NULL)
	{
		printf("Empty List");
	}
	temp = head;
	temp1 = head;
	if (temp->data == c)
	{
		head = temp->link;
		free(temp);
		flag = 1;
	}
	else
	{

		while (temp->link != NULL)

		{
			temp = temp->link;

			if (temp->data == c)
			{
				temp2 = temp->link;
				temp1->link = temp2;
				free(temp);
				flag = 1;
				break;
			}

			else
			{
				continue;
			}
		}
	}

	if (temp->data == c)
	{
		temp1->link = NULL;
		free(temp);
		flag = 1;
	}
	if (flag == 0)
	{
		printf("\nThe element does not exist :(\n");
	}

	return head;
}

//************************************************insert before element

struct Node *insertbeforeelement(struct Node *head)
{
	struct Node *temp;
	struct Node *temp1;
	struct Node *newn;
	newn = node_cre(newn);
	printf("Enter the element for which you want to enter before ");
	int c;
	int flag = 0;
	scanf("%d", &c);
	temp = head;
	temp1 = temp->link;
	if (temp->data == c)
	{
		newn->link = temp;
		head = newn;
		flag = 1;
	}
	if (temp1->data == c)
	{
		newn->link = temp1;
		temp->link = newn;
		flag = 1;
	}
	while (temp1->link != NULL)
	{
		temp1 = temp1->link;
		temp = temp->link;
		if (temp1->data == c)
		{
			temp->link = newn;
			newn->link = temp1;
			flag = 1;
			break;
		}
	}

	if (flag == 0)
	{
		printf("\nThe element does not exist :(\n");
	}

	return head;
}

//************************************************main

void main()
{
	struct Node *head = NULL;
	int ch;

	while (1)
	{

		printf("\n 1. Insert element at the beginning\n");
		printf("\n 2. Insert element at the ending\n");
		printf("\n 3. Insert element after an element\n");
		printf("\n 4. Insert element before an element\n");
		printf("\n 5. Delete element at the beginning\n");
		printf("\n 6. Delete element at the ending\n");
		printf("\n 7. Delete specified element \n");
		printf("\n 8. Exit \n");

		printf("\n Enter you choice ");
		scanf("%d", &ch);
		if (ch == 1)
		{
			head = insertbeginning(head);
			print(head);
		}

		else if (ch == 2)
		{
			head = insertending(head);
			print(head);
		}
		else if (ch == 3)
		{
			head = insertafterelement(head);
			print(head);
		}
		else if (ch == 4)
		{
			head = insertbeforeelement(head);
			print(head);
		}
		else if (ch == 5)
		{
			head = deletebeginning(head);
			print(head);
		}
		else if (ch == 6)
		{
			head = deleteending(head);
			print(head);
		}
		else if (ch == 7)
		{
			head = deleteelement(head);
			print(head);
		}
		else if (ch == 8)
		{
			break;
		}
		else
		{
			printf("Wrong Choice Please try again");
			continue;
		}
	}
}
