#include <iostream>
#include<stack>
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
    newnode->left = newnode->right = NULL;
    return newnode;
}

void InOrder(node *root)
{
    if(root == NULL)
        return;
    
    InOrder(root->left);
    cout<<root->data<<" ";
    InOrder(root->right);
}

int main()
{ 
    stack <node *> s;
    int n,i;
    cin>>n;
    int array[n];
    for(i = 0; i < n; i++)
        cin>>array[i];
    root = getNode(array[0]);
    node *originalRoot = root;
    s.push(root);
    int j = 1;
    while(j < n) 
    {
        if(array[j] > s.top()->data)
        {
            s.pop();
            node *temp1 = getNode(array[j]);
            s.push(temp1);
            root->right = temp1;
            root = temp1;
            j++;
        }
        else if(array[j] < s.top()->data)
        {
            s.pop();
            node *temp2 = getNode(array[j]);
            s.push(temp2);
            root->left = temp2;
            root = temp2;
            j++;
        }
    }
    InOrder(originalRoot);
    return 0;
}

