#include<iostream>
#include<stack>
using namespace std;

struct node
{
	int data;
	node *left;
	node *right;
};
node *root = NULL;
stack <node*> s, s1;
void InOrder(node *root)
{
	node *temp = root;
	while(temp != NULL)
	{
		s.push(temp);
		temp = temp->left;
	}
	while(!s.empty())
	{
		temp = s.top();
		s.pop();
		cout<<temp->data<<" ";
		temp = temp->right;
		while(temp != NULL)
		{
			s.push(temp);
			temp = temp->left;
		}
	}
}
void PreOrder(node *root)
{
	node *temp = root;
	while(temp != NULL)
	{
		s.push(temp);
		cout<<temp->data<<" ";
		temp = temp->left;
	}
	while(!s.empty())
	{
		temp = s.top();
		s.pop();
		temp = temp->right;
		while(temp != NULL)
		{
			s.push(temp);
			cout<<temp->data<<" ";
			temp = temp->left;
		}
	}
}
void PostOrder(node *root)
{
	node *temp = root;
	while(temp != NULL)
	{
		s.push(temp);
		s1.push(temp);
		temp = temp->right;
	}
	while(!s.empty())
	{
		temp = s.top();
		s.pop();
		temp = temp->left;
		while(temp != NULL)
		{
			s.push(temp);
			s1.push(temp);
			temp = temp->right;
		}
	}
	while(!s1.empty())
	{
		temp = s1.top();
		cout<<temp->data<<" ";
		s1.pop();
	}
}

node *getNode(int value)
{
	node *newnode = new node();
	newnode->data = value;
	newnode->left = newnode->right = NULL;
	return newnode;
}
node *makeTree(node *root, int data)
{
	if(root == NULL)
		root = getNode(data);
	
	else if(data < root->data)
		root->left = makeTree(root->left, data);
		
	else 
		root->right = makeTree(root->right, data);
		
	return root;
}
int main()
{
	int n, i;
	cin>>n;
	int arr[n];
	for(i = 0; i < n; i++)
	{
		cin>>arr[i];
		root = makeTree(root, arr[i]);
    }
    cout<<"InOrder Traversal: ";
	InOrder(root);
    cout<<endl;
	cout<<"PreOrder Traversal: ";
	PreOrder(root);
	cout<<endl;
	cout<<"PostOrder Traversal: ";
	PostOrder(root);
	return 0;
}
