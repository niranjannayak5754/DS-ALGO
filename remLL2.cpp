/*
    ******* Remove duplicates from a sorted linked list II [ MEDIUM ] ************88
    Given the head of a sorted linked list, 
    delete all nodes that have duplicate numbers, 
    leaving only distinct numbers from the original list. Return the linked list sorted as well.

Example 1:

    Input: head = [1,1,2,2,3,4,4,5,6,6]
    Output: [3,5]
*/
#include<iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return NULL;

        ListNode* curr = head;
        ListNode* prev = NULL;

        bool flag = false;

        while(curr){
            while(curr->next && curr->val == curr->next->val){
                flag = true;
                curr = curr->next;
            }

            if(flag == true){
                flag = false;
                if(!prev)
                    head = curr->next;
                else
                    prev->next = curr->next;
            }
            else{
                prev = curr;
            }

            curr = curr->next; 
        }

        return head;
    }
};