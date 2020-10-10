#include<iostream>

using namespace std;

class Node{
    int data;
    Node *next;
    friend class stack;    
    public:
        
        Node(int data){
            this->data=data;
            next=NULL;
        }
};
Node *head=NULL;
class stack{
    int top;
    public: stack(){
        top=-1;
    }

    void push(int data){
        Node *newnode=new Node(data);
        if(head==NULL)
        {
            head=newnode;
            cout<<"Pushed element is "<<newnode->data<<endl;
        }
        else
        {
            Node *temp=head;
            while(temp->next!=NULL)
            temp=temp->next;
            cout<<"Pushed element is "<<newnode->data<<endl;
            temp->next=newnode;
        }

    }

    void pop(){
            if(head==NULL)
            cout<<"Stack is empty...\n";
            else
            {
                Node *temp=head,*prev;
                if(temp->next==NULL)
                {
                    cout<<"Popped element is "<<temp->data<<endl;
                    head=NULL;
                }
                else
                {
                while(temp->next!=NULL)
                {
                    prev=temp;
                    temp=temp->next;
                }
                cout<<"Popped element is "<<temp->data<<endl;
                prev->next=NULL;
                }
            }
            

    }

    void display()
    {
            if(head==NULL)
            cout<<"Stack is empty"<<endl;
            else
            {
                Node *temp=head;//,*tail,*t;
                while(temp->next!=NULL)
                {
                    cout<<temp->data<<" ";
                    temp=temp->next;
                }
                cout<<temp->data<<" "<<endl;
            }
            
    }
};

int main()
{
    stack s;
    
    s.display();
    s.push(3);
    s.push(2);
    s.push(2);
    s.push(2);
    s.pop();
    s.display();
    s.push(5);
    s.display();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.display();
    s.push(123);
    s.display();
    s.push(34);
    s.push(7);
    s.display();
    return 0;
}