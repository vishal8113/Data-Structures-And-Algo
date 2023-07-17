// segregate even and odd notes in linked list

#include<bits/stdc++.h>
using namespace std;

class node {
public:
    int num;
    node* next;
    node(int val) {
        num = val;
        next = NULL;
    }
};

void insertNode(node* &head, int val) {
    node* newNode = new node(val);

    if (head == NULL) {
        head = newNode;
        return;
    }

    node* temp = head;
    while (temp->next != NULL) temp = temp->next;

    temp->next = newNode;
    return;
}

void print(node* head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->num << " ";
        temp = temp->next;
    }
    cout << endl;
}

node* combine(node* &head) {
    node* dummyEven = new node(-1);
    node* dummyOdd = new node(-1);

    node* evenTail = dummyEven;
    node* oddTail = dummyOdd;

    node* curr = head;

    while (curr != NULL) {
        if (curr->num % 2 != 0) {
            oddTail->next = curr;
            oddTail = oddTail->next;
        }
        else {
            evenTail->next = curr;
            evenTail = evenTail->next;
        }
        curr = curr->next;
    }

    evenTail->next = dummyOdd->next;
    oddTail->next = NULL;

    head = dummyEven->next;
    return head;
}

int main() {
    node* head = NULL;
    insertNode(head, 20);
    insertNode(head, 18);
    insertNode(head, 15);
    insertNode(head, 4);
    insertNode(head, 23);
    insertNode(head, 56);
    insertNode(head, 7);

    cout << "Original list: ";
    print(head);

    cout << "Modified list: ";
    head = combine(head);
    print(head);

    // T.C => O(N)
    // S.C => O(1)

    return 0;
}
