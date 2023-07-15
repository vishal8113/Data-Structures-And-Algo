// Middle in a linked list

// Brute Force Approach

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

// int findLength(Node* &head){
//     Node* temp = head;
//     int len = 0;
//     while(temp != NULL)
//     {
//         temp = temp -> next;
//         len++;
//     }

//     return len;
// }

// Node* findMiddle(Node* &head,int mid)
// {
//     Node* temp = head;
//     int cnt = 1;
//     while(cnt < mid){
//         temp = temp -> next;
//         cnt++;
//     }

//     return temp;
// }

// void newPrint(Node* &temp)
// {
//     while(temp != NULL)
//     {
//         cout << temp -> data << "->";
//         temp = temp -> next;
//     }
//     cout << endl;
// }

void ans(Node* &head){
    Node* fast = head;
    Node* slow = head;

    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    // cout << slow -> data << endl;
    // cout << fast -> data << endl;

    while(slow != NULL)
    {
        cout << slow -> data << "->";
        slow = slow -> next;
    }
    cout << endl;
}

int main()
{
    Node *node1 = new Node(5);

    Node* head = node1;
    print(head);

    insertAtHead(head,8);
    print(head);

    Node* tail = node1;
    insertAtTail(tail,30);
    print(head);

    insertAtTail(tail,60);
    print(head);

    insertAtPosition(head,4,100);
    print(head);

    insertAtPosition(head,3,209);
    print(head);

    // int len = findLength(head);
    // int middle = (len/2) + 1;

    // // int ans = findMiddle(head,middle);
    // // cout << ans << endl;

    // Node* temp = findMiddle(head,middle);

    // newPrint(temp);

    // T.C => O(n) + O(n/2)
    // S.C => O(1)


    // we use tortoise and hare method for better T.C
    // Optimal Approach

    ans(head);

    // T.C => O(n)
    // S.C => O(1)
    return 0;
}
