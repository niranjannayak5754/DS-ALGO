/*
    ********** Word Search II [ Hard ] ***************8

Given an m x n board of characters and a list of strings words, return all words on the board.

Each word must be constructed from letters of sequentially adjacent cells,
where adjacent cells are horizontally or vertically neighboring. 
The same letter cell may not be used more than once in a word.
*/


#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    unordered_map<char, TrieNode *> children;
    bool isWord;

    TrieNode() : isWord(false) {}
};

class Trie
{
public:
    TrieNode *root;

    Trie() : root(new TrieNode()) {}

    void addWord(string word)
    {
        TrieNode *node = root;

        for (char ch : word)
        {
            if (node->children.find(ch) == node->children.end())
                node->children[ch] = new TrieNode();
            node = node->children[ch];
        }

        node->isWord = true;
    }
};

class Solution
{
private:
    void dfs(vector<vector<char>> &board, int i, int j, TrieNode *node, vector<string> &res, string word)
    {
        char ch = board[i][j];

        if (ch == '#' || !node->children.count(ch))
            return;

        node = node->children[ch];
        word += ch;

        if (node->isWord)
        {
            res.push_back(word);
            node->isWord = false; // to avoid duplicates
        }

        board[i][j] = '#'; // mark the cell as visited

        if (i > 0)
            dfs(board, i - 1, j, node, res, word);
        if (i < board.size() - 1)
            dfs(board, i + 1, j, node, res, word);
        if (j > 0)
            dfs(board, i, j - 1, node, res, word);
        if (j < board[0].size() - 1)
            dfs(board, i, j + 1, node, res, word);

        board[i][j] = ch; // restoring the cell
    }

public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        vector<string> res;
        Trie trie;

        for (string word : words)
            trie.addWord(word);

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                dfs(board, i, j, trie.root, res, "");
            }
        }

        return res;
    }
};