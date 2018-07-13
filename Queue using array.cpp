#include<stdio.h>
#define max 10
int insert(int);
int Delete();
int peek();
int display();
int main()
{
	int queue[max];int front;int rear=-1,ch,no;
	printf("Welcome\n");
	printf("Main Menu\n 1. Insert an element\n 2. Delete an element\n 3. Peek\n 4. Display\n Choose an option\n");
	scanf("%d",&ch);
	do
	{
		switch(ch)
		{
			case 1:printf("Enter the element to be inserted\n");
	               scanf("%d",&no);
				   insert(no);
				   printf("The number is inserted in the queue\n");
			
			case 2:printf("The number deleted is =%d\n",Delete());
			
			case 3:printf("The topmost element of the queue is =%d\n",peek());
			
			case 4:printf("The elements of the queue are: \n",display());
			
			default: printf("Enter correct option\n");  		
		}
	while(ch!=5);	
	}
return (0);	
}
int insert(int data)
{
	if(rear==max-1)
	printf("Overflow\n");
	else if(front==-1&&rear==-1)
	front=rear=0;
	else
	rear++;
	queue[rear]=data;	
}
int Delete()
{
	int val;
	if(front==-1||front>rear){
	printf("Underflow \n");
	return -1;}
	else
	val=queue[front];
	front++;
	if(front>rear)
	front=rear=-1;
	return val;
}
int peek()
{
	if(front==-1||front>rear){
	printf("Queue is empty\n");
	return -1;}
	else
	return queue[front];
}
int display()
{
	if(front==-1||front>rear)
	printf("Queue is empty\n");
	else
	for(int i=front;i<=rear;i++)
	printf("%d  ",&queue[i]);
}

