/*
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
*/

class Solution {
    Node* cloneUtil(Node* node, unordered_map<Node*, Node*>&old_new){
        Node* newNode = new Node(node->val);
        old_new[node]=newNode;
        for(auto neighbor: node->neighbors){
            if(old_new.find(neighbor)==old_new.end()){
                (newNode->neighbors).push_back(cloneUtil(neighbor, old_new));       
            } else {
                (newNode->neighbors).push_back(old_new[neighbor]);
            }
        }
        return newNode;
    }
public:
    Node* cloneGraph(Node* node) {
        if (!node) return node;
        unordered_map<Node*, Node*> old_new;
        return cloneUtil(node, old_new);
    }
};