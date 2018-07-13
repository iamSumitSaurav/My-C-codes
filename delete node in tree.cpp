#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


struct node
{
    int data;
    node *left;
    node *right;
};

int height(node *root)
{
    if(root == NULL)
        return 0;
    else
        return max(height(root->left), height(root->right))+1;
}
void inOrder(node *root)
{ 
    if(root == NULL)
        return;
    
    else
    {
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
}

int main() 
{
    queue <node *> Q1, Q2;
    int N, i, arr[1500];
    cin >> N;
    arr[0] = 1;
    for(int i = 1; i <= 2*N; i++)
    cin>>arr[i];
    //cout<<"Checkpoint 1"<<endl;
    node *root = new node();
    node *current1 = root;
    node *current2 = root;
    root->data = 1;
    Q1.push(root);
    int k = 1;
    while(!Q1.empty() && k <= 2*N)
    {
        node *current1 = Q1.front();
        if(arr[k] != -1)
        {
            current1->left = new node();
            current1->left->data = arr[k];
            Q1.push(current1->left);

        }
        else
            current1->left = NULL;
        k++;
        
        
        if(arr[k] != -1)
        {
            current1->right = new node();
            current1->right->data = arr[k];
            Q1.push(current1->right);
            
        }
        else
            current1->right = NULL;
        k++;
        Q1.pop();
    }
    node *nodeArr[1500];
    cout<<"Checkpoint 2"<<endl;
    Q2.push(root);
    nodeArr[0] = root;
    int j = 1;
    while(!Q2.empty() && j <= 2*N)
    {
        current2 = Q2.front();
        if(current2){
		
        if(arr[j] != -1)
        {
           // current2->left = new node();
            Q2.push(current2->left);
            nodeArr[j++] = current2->left;
        }
        else
        {
            Q2.push(NULL);
            nodeArr[j++] = NULL;
        }
        
        
        if(arr[j] != -1)
        {
           // current2->right = new node();
            Q2.push(current2->right);
            nodeArr[j++] = current2->right;
        }
        else
        {
            Q2.push(NULL);
            nodeArr[j++] = NULL;
        }
    }
        Q2.pop();
    }
    //cout<<"Checkpoint 3"<<endl;
   /* inOrder(root);
    cout<<endl;
    for(int i=0;i<=2*N;i++)
    {
    	cout<<arr[i]<<" ";
	}
	cout<<endl;
    for(int i=0;i<=2*N;i++)
    {
    	if(nodeArr[i])
    		cout<<nodeArr[i]->data<<" ";
    	else
    		cout<<"-1 ";
	}*/
    int T, h, c;
    cin>>T;
    while(T--)
    {
        cin>>h;
        c=1;
        while(h <= height(root))
        {
        	for(int range = pow(2, h-1)-1; range < pow(2, h)-1; range++)
        	{
            	node *temp;
            	if(!(nodeArr[range] == NULL || (nodeArr[range]->left == NULL && nodeArr[range]->right == NULL)))
            		{
            			temp = nodeArr[range]->left;
                		nodeArr[range]->left = nodeArr[range]->right;
                		nodeArr[range]->right = temp;
					}
        	}
            c++;
            h = h * c;
            cout<<"Checkpoint 4"<<endl;
        }
        inOrder(root);
        cout<<endl;
    }
    return 0;
}

