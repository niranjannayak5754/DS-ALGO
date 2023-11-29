/*
    Cloned Graph [Medium] [BFS or DFS]
*/
#include<bits/stdc++.h>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class BFS{
    public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        unordered_map<Node*, Node*> copies;
        Node* copy = new Node(node->val);
        copies[node] = copy;
        queue<Node*> q;
        q.push(node);

        while(!q.empty()){
            Node* cur = q.front();
            q.pop();

            for(auto neighbor : cur->neighbors){
                if(copies.find(neighbor) == copies.end()){
                    copies[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                copies[cur]->neighbors.push_back(copies[neighbor]);
            }
        }
        return copy;
    }
};

class DFS {
public:
    unordered_map<Node*, Node*> copies;
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        if(copies.find(node) == copies.end()){
            copies[node] = new Node(node->val);
            for(auto neighbor : node->neighbors){
                copies[node]->neighbors.push_back(cloneGraph(neighbor));
            }
        }
        return copies[node];
    }
};