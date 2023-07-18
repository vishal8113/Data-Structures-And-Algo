#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertNode(Node* &head,int val)
{
    Node* node1 = new Node(val);
    if(head == NULL)
    {
        head = node1;
        return;
    }

    Node* temp = head;
    while(temp -> next != NULL)
    {
        temp = temp -> next;
    }

    temp -> next = node1;
}

void createCycle(Node* &head,int a,int b)
{
    int cnt1 = 0;
    int cnt2 = 0;
    Node* p1 = head;
    Node* p2 = head;

    while(cnt1 != a || cnt2 != b)
    {
        if(cnt1 != a)
        {
            p1 = p1 -> next;
            cnt1++;
        }

        if(cnt2 != b)
        {
            p2 = p2 -> next;
            cnt2++;
        }
    }

    p2 -> next = p1;
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

void removeCycle(Node* &head)
{
    Node* slow = head;
    Node* fast = head;

    // Find the meeting point of the two pointers
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            break;
        }
    }

    // Check if a cycle exists
    if (fast == NULL || fast->next == NULL)
    {
        cout << "No cycle found in the linked list." << endl;
        return;
    }

    // Move one pointer to the head and keep the other at the meeting point
    slow = head;
    while (slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }

    // Break the cycle by setting the next pointer of the last node to NULL
    fast->next = NULL;

    cout << "Cycle removed from the linked list." << endl;
}


int main()
{
    Node* head = NULL;
    insertNode(head,1);
    insertNode(head,2);
    insertNode(head,3);
    insertNode(head,4);

    createCycle(head,1,3);
    removeCycle(head);

    // print(head);
    print(head);

    // T.C => O(N) + O(N)
    // S.C => O(1)
    return 0;
}
