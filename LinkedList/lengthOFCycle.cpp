// Optimal Approach

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
void insertNode(node* &head,int val) {
    node* newNode = new node(val);
    
    if(head == NULL) {
        head = newNode;
        return;
    }
    
    node* temp = head;
    while(temp->next != NULL) temp = temp->next;
    
    temp->next = newNode;
    return;
}
void createCycle(node* &head,int a,int b) {
    int cnta = 0,cntb = 0;
    node* p1 = head;
    node* p2 = head;
    while(cnta != a || cntb != b) {
        if(cnta != a) p1 = p1->next, ++cnta;
        if(cntb != b) p2 = p2->next, ++cntb;
    }
    p2->next = p1;
}
int findLength(node* head) {
    if(head == NULL) return -1;
    node* fast = head;
    node* slow = head;
        
    while(fast->next != NULL && fast->next->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow) {
            int cnt = 1;
            node* p1 = slow;
            while(p1 -> next != slow){
                p1 = p1 -> next;
                cnt++;
            }
            return cnt;
        }
    }
    return -1;
}


int main() {
    node* head = NULL;
    insertNode(head,1);
    insertNode(head,2);
    insertNode(head,3);
    insertNode(head,4);
    createCycle(head,1,3);
    cout << findLength(head) << endl;
    // T.C => O(N)
    return 0;
}