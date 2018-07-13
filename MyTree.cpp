#include<iostream>
using namespace std;

struct node
{
	int data;
	node *left;
	node *right;
};
node *root = NULL;

node *getNode(int value)
{
	node *newnode = new node();
	newnode->data = value;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

node *constructTree(node *root, int value)
{
	if(root == NULL)
		root = getNode(value);
			
	else if(value <= root->data)
		root->left = constructTree(root->left, value);
		
	else
		root->right = constructTree(root->right, value);
		
	return root;
}
 
node* displayTree(node *root)
{
	if(root == NULL)
		return 0;
	
	else
	{
		displayTree(root->left);
		cout<<root->data<<" ";
		displayTree(root->right);
	}
}

int main()
{
	int n, data;
	cin>>n;
	while(n--)
	{
		cin>>data;
		root = constructTree(root, data);
		displayTree(root);
	}
	return 0;
}

