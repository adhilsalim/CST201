#include <stdio.h>
#include <stdlib.h>

//***********************************************************************************************************node1
struct Node
	{
		int coeff;
		int pow;
		struct Node * link;
	};
//*******************************************node creation
struct Node* node_cre(struct Node *newn)
{
	newn= (struct Node*)malloc(sizeof(struct Node));

	printf("enter the coeffiecent");
	int b;
	scanf("%d",&b);
	printf("enter the power");
	int c;
	scanf("%d",&c);
	newn->coeff=b;
	newn->pow=c;
	newn->link=NULL;
	return newn;
}
//************************************************insert end
struct Node* insertending(struct Node* head)
{
	struct Node* temp;
	struct Node *newn;
	temp=head;
	newn=node_cre(newn);
	if(head==NULL)
	{
		head=newn;

	}

	else
	{
		while(temp->link!=NULL)
		{
			temp=temp->link;

		}

		temp->link=newn;
	}

	return head;
}

//**************************************************print
void print(struct Node * head)

	{
		struct Node* temp;
		temp=head;
		if(head==NULL)
        	{
            	printf("The List Is Empty");
        	}
		while(temp!=NULL)
		{
			printf("%dx^%d+",temp->coeff,temp->pow);
			temp=temp->link;
		}
		printf("\b");
		printf("\n");



	}

//**********************************************************************************************************node2

//*******************************************node creation
struct Node* node_cre1(struct Node *newn1)
{
	newn1= (struct Node*)malloc(sizeof(struct Node));
	printf("enter the coeffiecent");
	int b;
	scanf("%d",&b);
	printf("enter the power");
	int c;
	scanf("%d",&c);
	newn1->coeff=b;
	newn1->pow=c;
	newn1->link=NULL;
	return newn1;
}
//************************************************insert end
struct Node* insertending1(struct Node* head1)
{
	struct Node* temp;
	struct Node *newn1;
	temp=head1;
	newn1=node_cre1(newn1);
	if(head1==NULL)
	{
		head1=newn1;
	}

	else
	{
		while(temp->link!=NULL)
		{
			temp=temp->link;
		}

		temp->link=newn1;
	}

	return head1;
}

//********************************************************************main


void main()
	{
		struct Node* newn2;
		struct Node *head=NULL;
		struct Node *head1=NULL;
		struct Node *head2=NULL;
		struct Node* temp;
		struct Node* temp1;
		struct Node* temp2;
		int ch,ch1;
		printf("Enter the no of terms in 1st polynomial\n");
		scanf("%d",&ch);
		for(int i=0;i<ch;i++)
		{

			head=insertending(head);

		}

		printf("\nThe 1st polynomial is\n");
		print(head);

		printf("Enter the no of terms in 2nd polynomial\n");
		scanf("%d",&ch1);
		for(int i=0;i<ch1;i++)
		{

			head1=insertending1(head1);
		}



		printf("\nThe 2nd polynomial is \n");
		print(head1);


		int i=0,j=0,k=0;
		temp=head;
		temp1=head1;
		temp2=head2;
		while(i<ch&&j<ch1)
		{
		if(temp->pow==temp1->pow)
		{
			newn2= (struct Node*)malloc(sizeof(struct Node));
			newn2->coeff=temp->coeff+temp1->coeff;
			printf("%d\n",temp->coeff);
			newn2->pow=temp->pow;
			newn2->link=NULL;
			temp2=head2;
			if(head2==NULL)
			{
				head2=newn2;
			}

			else
			{
				while(temp2->link!=NULL)
				{
					temp2=temp2->link;
				}

				temp2->link=newn2;
			}
			temp=temp->link;
			temp1=temp1->link;
			i++;
			k++;
			j++;

		}
		else if(temp->pow>temp1->pow)
		{
			newn2= (struct Node*)malloc(sizeof(struct Node));
			newn2->coeff=temp->coeff;
			printf("%d\n",temp->coeff);
			newn2->pow=temp->pow;
			newn2->link=NULL;
			temp2=head2;
			if(head2==NULL)
			{
				head2=newn2;
			}

			else
			{
				while(temp2->link!=NULL)
				{
					temp2=temp2->link;
				}

				temp2->link=newn2;
			}
			temp=temp->link;
			i++;
			k++;

		}
		else
		{
			newn2= (struct Node*)malloc(sizeof(struct Node));
			newn2->coeff=temp1->coeff;
			printf("%d\n",temp->coeff);
			newn2->pow=temp1->pow;
			newn2->link=NULL;
			temp2=head2;
			if(head2==NULL)
			{
				head2=newn2;
			}

			else
			{
				while(temp2->link!=NULL)
				{
					temp2=temp2->link;
				}

				temp2->link=newn2;
			}
			temp1=temp1->link;
			j++;
			k++;
		}
	}
	while(i<ch)
	{

		newn2= (struct Node*)malloc(sizeof(struct Node));
		newn2->coeff=temp->coeff;
		newn2->pow=temp->pow;
		newn2->link=NULL;
		temp2=head2;
		if(head2==NULL)
		{
			head2=newn2;
		}

		else
		{
			while(temp2->link!=NULL)
			{
				temp2=temp2->link;
			}

			temp2->link=newn2;
		}
		temp=temp->link;
		i++;
		k++;

	}
	while(j<ch1)
	{
		newn2= (struct Node*)malloc(sizeof(struct Node));
		newn2->coeff=temp1->coeff;
		newn2->pow=temp1->pow;
		newn2->link=NULL;
		temp2=head2;
		if(head2==NULL)
		{
			head2=newn2;
		}

		else
		{
			while(temp2->link!=NULL)
			{
				temp2=temp2->link;
			}
			temp2->link=newn2;
		}
		temp1=temp1->link;
		j++;
		k++;

	}





	printf("\n\npolynomial after addition\n");

	print(head2);


}





































