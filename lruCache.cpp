/*
    ******* LRU Cache [ Medium ] *******************

    Use of doubly linked list and map
*/

#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
private:
    class Node{
        public:
            int key;
            int val;
            Node* next;
            Node* prev;

            Node(int _key, int _val): key(_key), val(_val), next(nullptr), prev(nullptr){} 
    };

    int capacity;
    unordered_map<int, Node*> cache;

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    void addnode(Node* newnode){
        Node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }

    void deletenode(Node* delnode){
        Node* delprev = delnode->prev;
        Node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }

public:
    LRUCache(int _capacity)
    {
        capacity = _capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int _key){
        if(cache.find(_key) == cache.end())
            return -1;
        
        Node* resnode = cache[_key];
        deletenode(resnode);
        addnode(resnode);
        cache[_key] = head->next;

        return resnode->val;
    }

    void put(int _key, int _val){
        if(cache.find(_key) != cache.end()){
            deletenode(cache[_key]);
            cache.erase(_key);
        }

        if(cache.size() == capacity){
            cache.erase(tail->prev->key);
            deletenode(tail->prev);
        }

        addnode(new Node(_key, _val));
        cache[_key] = head->next;
    }
};