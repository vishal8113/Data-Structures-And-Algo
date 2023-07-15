// Reverse a linked list

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

void reverse(Node* &head){
    Node* DummyNode = NULL;
    while(head != NULL)
    {
        Node* next = head -> next;
        head -> next = DummyNode;
        DummyNode = head;
        head = next;
    }

    print(DummyNode);
}

int main()
{
    Node* node1 = new Node(3);
    Node* head = node1;
    Node* tail = node1;

    insertAtHead(head,2);
    insertAtHead(head,1);

    insertAtTail(tail,4);
    insertAtTail(tail,5);

    print(head);

    reverse(head);
    return 0;

    // T.C => O(n)
    // S.C => O(1)
}
