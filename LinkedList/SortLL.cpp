#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

void insertNode(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) temp = temp->next;

    temp->next = newNode;
    return;
}

void print(Node* &head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;

}

Node* merge(Node* l1, Node* l2) {
       if(l1 == NULL)
       {
           return l2;
       }

       if(l2 == NULL)
       {
           return l1;
       }

       if(l1 -> data > l2 -> data)
       {
           swap(l1,l2);
       }

       Node* res = l1;

       while(l1 != NULL && l2 != NULL)
       {
           Node* temp = NULL;

           while(l1 != NULL && l1 -> data <= l2 -> data){
               temp = l1;
               l1 = l1 -> next;
           }

           temp -> next = l2;
           swap(l1,l2);
       }

       return res;
    }

Node* sort(Node* head)
{
    if(head == NULL || head -> next == NULL)
    {
        return head;
    }

    Node* temp = NULL;
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast -> next != NULL){
        temp = slow;
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    temp -> next = NULL;

    Node* l1 = sort(head);
    Node* l2 = sort(slow);

    return merge(l1,l2);
}

int main()
{
    Node* head = NULL;
    insertNode(head,4);
    insertNode(head,2);
    insertNode(head,1);
    insertNode(head,3);

    print(head);

    Node* ans = sort(head);
    print(ans);
    return 0;
}