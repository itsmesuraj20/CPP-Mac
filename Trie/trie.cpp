#include<bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
private:
    TrieNode* root;
public: 
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (node->children[index] == nullptr) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isEndOfWord = true;
    }

    bool search(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (node->children[index] == nullptr) {
                return false;
            }
            node = node->children[index];
        }
        return node->isEndOfWord;
    }
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            int index = c - 'a';
            if (node->children[index] == nullptr) {
                return false;
            }
            node = node->children[index];
        }
        return true;
    }
    void remove(string word) {
        removeHelper(root, word, 0);
    }

    bool removeHelper(TrieNode* node, string word, int depth) {
        if (node == nullptr) {
            return false;
        }
        if (depth == word.size()) {
            if (node->isEndOfWord) {
                node->isEndOfWord = false;
                return node->isLeaf();
            }
            return false;
        }
        int index = word[depth] - 'a';
        if (removeHelper(node->children[index], word, depth + 1)) {
            delete node->children[index];
            node->children[index] = nullptr;
            return !node->isEndOfWord && node->isLeaf();
        }
        return false;
    }
    bool isLeaf() {
        for (int i = 0; i < 26; i++) {
            if (children[i] != nullptr) {
                return false;
            }
        }
        return true;
    }
    void display(TrieNode* node, string str) {
        if (node->isEndOfWord) {
            cout << str << endl;
        }
        for (int i = 0; i < 26; i++) {
            if (node->children[i] != nullptr) {
                display(node->children[i], str + char(i + 'a'));
            }
        }
    }