#include<iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};
node *newNode(int value)
{
    node *newnode = new node();
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

node *makeTree(node *root, int value)
{
    if(root == NULL)
        root = newNode(value);
        
    else if(value < root->data)
        root->left = makeTree(root->left, value);
        
    else
        root->right = makeTree(root->right, value);
        
    return root;
}

int monkFunc(node *root, int mx, int mn)
{
    if(mx < root->data && root->left != NULL && root->left->data != mx)
        monkFunc(root->left, mx, mn);
    
    else if(mn > root->data && root->right != NULL)
        monkFunc(root->right, mx, mn);
        
    else if(root->left != NULL && root->left->data == mx)
        return root->data;
        
    else if(mx == root->data)
        return mx;
        
    else
    {
        if(mx > root->data && root->right != NULL)
            monkFunc(root->right, mx, mn);
            
        else if(root->left->data != mx)
            monkFunc(root->left, mx, mn);
    }
}

int main()
{
    int N, value, a, b;
    cin>>N;
    int arr[N];
    node *root = NULL;
    for(int i = 0; i < N; i++)
    {
        cin>>arr[i];
        value = arr[i];
        root = makeTree(root, value);
    }
    cin>>a>>b;
    int mx = max(a, b);
    int mn = min(a, b);
    int number = monkFunc(root, mx, mn);
    cout<<number;
    return 0;
}

