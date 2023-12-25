/*
    Medium -> Deep Copy the Linked List having next and random pointer
*/
#include<iostream>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    // intuition : to remove space, need to insert copy nodes else easily done by hash map of <node>, <node>

    Node* copyRandomList(Node* head) {
        if(!head) return NULL;

        Node* curr = head;
        Node* front;
        // 1st step : make copy nodes and place in between two original nodes
        while(curr){
            front = curr->next;
            Node* copy = new Node(curr->val);
            curr->next = copy;
            copy->next = front;
            curr = front;
        }

        // 2nd step : set the random pointer of copied nodes
        curr = head;
        while(curr){
            if(curr->random){
                curr->next->random = curr->random->next;
            }

            curr = curr->next->next;
        }

        // 3rd step : reset the original list and set the next of copied nodes
        Node* dummy = new Node(0);
        Node* copy = dummy;
        curr = head;
        while(curr){
            front = curr->next->next;
            copy->next = curr->next;
            curr->next = front;
            curr = curr->next;
            copy = copy->next;
        }

        return dummy->next;
    }
};