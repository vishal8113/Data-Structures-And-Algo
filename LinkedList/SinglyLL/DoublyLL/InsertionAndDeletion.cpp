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
        tem2->prev=newnode;
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

void DeleteFromHead(Node* &head)
{
    Node* temp=head;
    head=temp->next;
    temp->next=NULL;
}

void DeleteFromTail(Node* &tail)
{
    Node* temp = tail -> prev;
    tail -> prev = NULL;
    tail = temp;
    tail -> next = NULL;
}

void DeleteFromPosition(Node* &head,int pos,Node* &tail)
{
    if(pos==1)
    {
        DeleteFromHead(head);
        return;
    }
    else if(pos==LLlength(head)){
        DeleteFromTail(tail);
        return;
    }
    else{
        Node* temp=head;
        int cnt=1;
        while(cnt<pos-1)
        {
            temp=temp->next;
            cnt++;
        }
        Node* temp2=temp->next;
        temp->next=temp2->next;
        temp2->prev=NULL;
    }
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

    DeleteFromHead(head);
    print(head);

    DeleteFromTail(tail);
    print(head);

    DeleteFromPosition(head,3,tail);
    print(head);
    return 0;
}
