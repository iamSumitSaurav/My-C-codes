#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*next;
};
struct node*start= NULL;
struct node*Create(struct node*);
struct node*Display(struct node*);
struct node*Add_beg(struct node*);
struct node*Add_last(struct node*);
struct node*Add_after(struct node*);
struct node*Add_before(struct node*);

int main()
{
	int choice;
	printf("\n......Main Menu......");
	printf("\n 1. Create a new node");
	printf("\n 2. Display a new node");
	printf("\n 3. Add a new node to the beginning of the linklist");
	printf("\n 4. Add a new node at the end of the linklist");
	printf("\n 5. Add a new node after a given node");
	printf("\n 6. Add a new node before a given node");
	printf("\n 7. Delete the entire linklist");
	label:printf("\n Enter the choice from 1-7");
	scanf("%d",&choice);
	if((choice>=1)&&(choice<=7))
	{
	
    switch(choice)
	{
		case 1:
			start=Create(start);
			printf("\n New node created");
			break;
	    case 2:
	    	start=Display(start);
	    	break;
	    case 3:
	    	start=Add_beg(start);
	    	break;
	    case 4:
	    	start=Add_last(start);
			break;
		case 5:
		    start=Add_after(start);
		    break;
		case 6:
			start=Add_before(start);
			break;
		case 7:
			start=Delete(start);
			printf("\n The linklist is deleted");
			break;
    }
					
   }
   else
   {
   	printf("\n Enter the correct choice");
   	goto label;
   }
   getch;
   return 0;
   
}

struct node*Create(struct node*start)
{
	int num;
	printf("\n Enter -1 to finish entering data.");
	printf("\n Enter the data");
	scanf("%d",&num);
	while(num!=-1)
	{
	  struct node*new_node,*ptr;
	  start= (struct node*)malloc(sizeof(struct node));
	  new_node->data=num;
	  if(start==NULL)
	  {
	  	new_node->next=NULL;
	  	start=new_node;
      }
      else
      {
      	ptr=start;
      	while(ptr->next!=NULL)
      	ptr=ptr->next;
      	ptr->next=new_node;
      	new_node->next=NULL;
	  }
	  printf("\n Enter the data");
	  scanf("%d",&num);
    }
    return start;
}
struct node*Display(struct node*start)
{
	struct node*ptr;
	ptr=start;
	while(start!=NULL)
	{
		printf("\n %d, ptr->data");
		ptr=ptr->next;
	}
	return start;
}
struct node*Add_Beg(struct node*start)
{
	int num;
	printf("\n Enter the data of the new node");
	scanf("%d",&num);
	struct node*new_node;
	new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=num;
	new_node->next=start;
	start=new_node;
	return start;
}
struct node*Add_last(struct node*start)
{
	int num;
	printf("\n Enter the data of the new node");
	scanf("%d",&num);
	struct node*new_node,*ptr;
	new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=num;
	ptr=start;
	while(ptr->next!=NULL)
	ptr=ptr->next;
	ptr->next=new_node;
	new_node->next=NULL;
	return start;
}
struct node*Add_after(struct node*start)
{
	int num,data;
	printf("\n Enter the data of the new node");
	scanf("%d",&data);
	printf("\n Enter the data of the node after which the new node is to be added");
	scanf("%d",&num);
	struct node*new_node,*ptr,*preptr;
	new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=data;
	ptr=start;
	preptr=ptr;
	while(preptr->data!=num);
	{
		ptr=ptr->next;
		preptr=ptr;
	}
	preptr->next=new_node;
	new_node->next=ptr;
	return start;
}
struct node*Add_before(struct node*start)
{
	int num,data;
	printf("\n Enter the data of the new node");
	scanf("%d",&data);
	printf("\n Enter the data of the node after which the new node is to be added");
	scanf("%d",&num);
	struct node*new_node,*ptr,*preptr;
	new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=data;
	ptr=start;
	preptr=ptr;
	while(ptr->data!=num)
	{
		ptr=ptr->next;
		preptr=ptr;
	}
	preptr->next=new_node;
	new_node->next=ptr;
	return start;
}
struct node*Delete_beg(struct node*start)
{
	struct node*ptr;
	ptr=start;
	start=start->next;
	free(ptr);
	return start;
}
struct node*Delete_last(start node*start)
{
	struct node*ptr,*preptr;
	ptr=start;
	preptr=ptr;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
		preptr=ptr;
	}
	preptr->next=NULL;
	free(ptr);
	return start;
}
struct node*Delete_after(struct node*start)
{
	struct node*ptr,*preptr;
	int num;
	printf("\n Enter the data of the node after which the node is to be deleted");
	scanf("%d",&num);
	ptr=start;
	preptr=ptr;
	while(preptr->data!=num)
	{
		ptr=ptr->next;
		preptr=ptr;
	}
	preptr->next=ptr->next;
	free(ptr);
	return start;
}
