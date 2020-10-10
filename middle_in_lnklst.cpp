#include<iostream>

using namespace std;

class Node{
    int data;
    Node *next;
    friend class LinkedList;
    Node(int data)
    {
        this->data=data;
        next=NULL;
    }
};

class LinkedList{
    public:
    Node * insert(Node *head,int data)
    {
        if(head==NULL)
        return new Node(data);

        Node *curr=head;
        while(curr->next!=NULL)
        {
            curr=curr->next;
        }
        curr->next=new Node(data);
        return head;
    
    }

    void display(Node *head){
        Node *temp=head;
        while(temp->next!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<temp->data<<endl;

    }

    // void middle(Node *head)
    // {
    //     int count=1;
    //      Node *temp=head;
    //     while(temp->next!=NULL)
    //     {
    //         count++;
    //         temp=temp->next;
    //     }
    //     temp=head;
    //     int i=0;
       
    //     count/=2;
    //     while(temp->next!=NULL)
    //     {

    //         if(i==count)
    //         {
    //             cout<<"Middle element is "<<temp->data<<endl;
    //             break;
    //         }
    //         temp=temp->next;
    //         i++;
    //     }
    // }

    void middle(Node *head)
    {
        Node *slow=head,*fast=head;
    if(head!=NULL)
    {
        while(fast->next!=NULL )
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        cout<<"Middle element is "<<slow->data<<endl;
    }

    }
};
int main()
{
    Node *head=NULL;
    LinkedList l;
    head=l.insert(head,1);
    head=l.insert(head,2);
    head=l.insert(head,3);
    head=l.insert(head,4);
    head=l.insert(head,5);
    // head=l.insert(head,6);
    // head=l.insert(head,6);
    // head=l.insert(head,6);
    l.display(head);
    l.middle(head);
    return 0;
}