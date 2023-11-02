/*
    REVERSED LINKED LIST
    INPUT:
    1 -> 2 -> 3 -> 4 -> 5 -> NULL
    OUTPUT:
    5 -> 4 -> 3 -> 2 -> 1 -> NULL
*/

/*
APPROACH:
    1. create a dummy node as NULL
    2. create a next node as head->next
    3. detach head->next and point it to dummy node
    4. make dummy node as head, head as next and continue the detaching until head == NULL
*/

#include<iostream>

using namespace std;

struct Node
{
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node *next) : val(x), next(next) {}
};

void printLinkedList(Node* node){
    while(node != NULL){
        cout << node->val << "->";
        node = node->next;
    }
    cout << "NULL" << endl;
}

Node *reversedLinkedList(Node* head){
    Node* newHead = NULL;
    while(head != NULL){
        Node *next = head->next;
        head->next = newHead;
        newHead = head;
        head = next;
    }
    return newHead;
}

int main(){
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    printLinkedList(head);
    head = reversedLinkedList(head);
    printLinkedList(head);
    return 0;
}