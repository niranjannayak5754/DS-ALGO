/**
 * ReOrder a Linked List as L0 -> Ln -> L1 -> Ln-1 -> L2 -> Ln-2 -> ..... [Medium]
 */
#include<iostream>
#include<vector>
#include<stack>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Stack {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return;
        stack<ListNode*> S;
        ListNode* curr = head;
        while(curr){
            S.push(curr);
            curr = curr->next;
        }
        int n = S.size();
        curr = head;
        ListNode* next;
        for(int i = 0; i<n/2; i++){
            next = curr->next;
            curr->next = S.top();
            S.pop();
            curr = curr->next;
            curr->next = next;
            curr = curr->next;
        }
        curr->next = nullptr;
    }
};

class Solution {
public:
    void reorderList(ListNode* head) {
        // return if there are less than two nodes
        if(!head || !head->next || !head->next->next) return;
        // getting the middle node of the list
        ListNode* slow = head, *fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        // reversing the latter half of the list
        ListNode* curr = slow, *prev = NULL, *next;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        // reordering the list
        ListNode* n1 = head, *n2 = prev;
        while(n2->next){
            next = n1->next;
            n1->next = n2;
            n1 = next;

            next = n2->next;
            n2->next = n1;
            n2 = next;
        }
    }
};

int main(){

    cout << "ReOrdering a singly Linked List" << endl;
    return 0;
}