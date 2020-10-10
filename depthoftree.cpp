#include<iostream>

using namespace std;
class Node{
    int data;
    Node *left;
    Node *right;
    friend class tree;
    public:
    Node(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};
class tree{
    public:
    Node * insertnode(Node *root,int data)
    {
        if(root==NULL)
        return new Node(data);

        Node *curr;
        if(data<=root->data)
        {
            curr=insertnode(root->left,data);
            root->left=curr;
        }
        else
        {
            curr=insertnode(root->right,data);
            root->right=curr;
        }
        return root;
    }    

    void display(Node *root)
    {
        if(root==NULL)
        return;

        display(root->left);
        cout<<root->data<<" ";
        display(root->right);
        
    }


    int depth(Node *root)
    {
        if(root==NULL)
        return -1;

        int left=depth(root->left);
        int right=depth(root->right);
        return ((left>right)?left:right)+1;

    }
};



int main() 
{
    Node *root=NULL;
    tree t;
    root=t.insertnode(root,5);
    root=t.insertnode(root,3);
    root=t.insertnode(root,4);
    root=t.insertnode(root,6);
    root=t.insertnode(root,1);
    root=t.insertnode(root,20);
    root=t.insertnode(root,17);
    t.display(root);
    cout<<"depth of binary tree is "<<t.depth(root)<<endl;
    return 0;
}