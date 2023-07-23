// Reverse a doubly linked list

#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int val)
    {
        data=val;
        next=NULL;
        prev=NULL;
    }

};
int LLlength(Node* head)
{
    Node* temp =head;
    int cnt=0;
    while(temp!=NULL)
    {
        cnt++;
        temp=temp->next;
    }
    return cnt;
}
void InsertAtHead(Node* &head,int data)
{
    Node* temp=new Node(data);
    temp->next=head;
    head->prev=temp;
    head=temp;
}
void InsertAtTail(Node* &tail,int data)
{
    Node* temp=new Node(data);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
   
}
void InsertAtPosition(Node* &head,int data,int pos,Node* &tail)
{
    int n=LLlength(head);
    if(pos==1)
    {
        InsertAtHead(head,data);
        return;
    }
    else if(pos==n+1)
    {
        InsertAtTail(tail,data);
    }
    else{
        Node* newnode=new Node(data);
        Node *tem2=head;
        int cnt=1;
        while( cnt<pos-1)
        {
             tem2=tem2->next;
             cnt++;
        }
        newnode->next=tem2->next;
        Node* nex = tem2 -> next;
        nex -> prev = newnode;
        newnode->prev=tem2;
        tem2->next=newnode;
    }

}
void print(Node* &head)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void reverse(Node* &head)
{
    Node* curr = head;
    Node* temp = NULL;
    while(curr != NULL)
    {
        temp = curr -> prev;
        curr -> prev = curr -> next;
        curr -> next = temp;
        curr = curr -> prev;
    }

    temp = temp -> prev;
    

    print(temp);

}

int main()
{
    Node* node1=new Node(3);
    Node* head=node1;
    print(head);
    InsertAtHead(head,4);
    print(head);
    Node* tail=node1;

    InsertAtTail(tail,5);
    print(head);

    InsertAtPosition(head,2,2,tail);
    print(head);

    InsertAtPosition(head,1,5,tail);
    print(head);

    reverse(head);
    return 0;
}