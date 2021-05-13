/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void traversal(Node* now, vector<int>& answer){
        if(!now){
            return;
        }
        answer.push_back(now->val);
        for(auto child : now->children){
            traversal(child, answer);
        }
    }
    
    vector<int> preorder(Node* root) {
        vector<int>answer;
        traversal(root, answer);
        return answer;
    }
};