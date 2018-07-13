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

int main()
{
    int N, value, a, b;
    int array[100], k = 0;
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
    while(root->data != mx)
    {
        if(mx < root->data && root->left != NULL)
            root = root->left;
            
        else if(mn > root->data && root->right != NULL)
            root = root->right;
            
        else if(mx >= root->data && mn <= root->data)
        {
            array[k++] = root->data;
            root = root->right;
        }
    }
    
    int maximum = array[0];
    
    for(int i = 0; i < k; i++)
        if(array[i] >= maximum)
            maximum = array[i];
            
    if(maximum > mx)
        cout<< maximum;
    else
        cout<< mx;    	
    return 0;
}

