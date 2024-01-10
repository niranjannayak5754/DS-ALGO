/*
	Amount of Time for Binary Tree to be infected [ Medium / Hard ] [ BFS Traversal ] [ Modified DFS Traversal ]

	You are given the root of a binary tree with unique values, and an integer start. 
	At minute 0, an infection starts from the node with value start.

	Each minute, a node becomes infected if:

	The node is currently uninfected.
	The node is adjacent to an infected node.
	Return the number of minutes needed for the entire tree to be infected.
*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void convertTree(TreeNode* node, int parent, unordered_map<int, vector<int>>& graph){
        if(!node) return;
        
        vector<int>& adj = graph[node->val];

        if(parent != 0) adj.push_back(parent);
        if(node->left) adj.push_back(node->left->val);
        if(node->right) adj.push_back(node->right->val);

        convertTree(node->left, node->val, graph);
        convertTree(node->right, node->val, graph);
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> graph;
        convertTree(root, 0, graph);

        queue<int> q;
        q.push(start);

        unordered_set<int> visited;
        visited.insert(start);

        int minute = 0;

        while(!q.empty()){
            int size = q.size();

            while(size--){
                int node = q.front();
                q.pop();

                for(int val : graph[node]){
                    if(visited.find(val) == visited.end()){
                        visited.insert(val);
                        q.push(val);
                    }
                }
            }

            minute++;
        }

        return minute - 1;
    }
};

class OptimizedSolution {
public:
	int traverse(TreeNode* root, int& start, int& maxDistance){
		if(!root) return 0;
		
		int lh = traverse(root->left, start, maxDistance);
		int rh = traverse(root->right, start, maxDistance);
		
		int depth = 0;
		if(root->val == start){
			maxDistance = max(rh, lh);
			depth = -1;
		}
		else if(rh >= 0 && lh >= 0){
			depth = max(lh, rh) + 1;
		}
		else{
			maxDistance = max(maxDistance, abs(rh) + abs(lh));
			depth = min(lh, rh) - 1;
		}
		
		return depth;
	}

	int amountOfTime(TreeNode* root, int start){
		int maxDistance = 0;
		traverse(root, start, maxDistance);
		return maxDistance;
	}
};
