// Insertion In Singly Linked List

#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

void insertAtHead(Node* &head,int d){
    Node* temp = new Node(d);

    temp -> next = head;
    head = temp;
}

void insertAtTail(Node* &tail,int d){
    Node* temp = new Node(d);

    tail -> next = temp;
    tail = tail -> next;

}

void insertAtPosition(Node* &head,int position,int d){
    Node* temp = head;
    int cnt = 1;
    while(cnt < position-1){
        temp = temp -> next;
        cnt++;
    }

    Node* newNode = new Node(d);
    newNode -> next = temp -> next;
    temp -> next = newNode;
}

void print(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp -> data << "->";
        temp = temp -> next;
    }
    cout << endl;
}

int main()
{
    Node *node1 = new Node(5);
    // cout << node1 -> data << endl;
    // cout << node1 -> next << endl;

    Node* head = node1;
    print(head);

    insertAtHead(head,8);
    print(head);

    insertAtHead(head,10);
    print(head);

    insertAtHead(head,20);
    print(head);

    Node* tail = node1;
    insertAtTail(tail,30);
    print(head);

    insertAtTail(tail,60);
    print(head);

    insertAtHead(head,35);
    print(head);

    insertAtPosition(head,4,100);
    print(head);

    insertAtPosition(head,2,1008);
    print(head);

    // cout << head -> data << endl;
    return 0;
}