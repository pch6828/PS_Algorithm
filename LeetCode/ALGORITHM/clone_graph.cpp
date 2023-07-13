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
private:
    unordered_map<int, Node*>node_map;
public:
    Node* cloneGraph(Node* node) {
        if(!node)
            return nullptr;
        if(node_map.count(node->val))
            return node_map[node->val];
        
        Node* new_node = new Node(node->val);
        node_map[node->val] = new_node;
        for(Node* neighbor : node->neighbors)
            new_node->neighbors.push_back(cloneGraph(neighbor));

        return new_node;
    }
};