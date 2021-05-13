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
    vector<vector<int>> levelOrder(Node* root) {
        queue<pair<Node*, int>>q;
        vector<vector<int>>answer;
        
        q.push({root, 0});
        
        while(!q.empty()){
            auto now = q.front();
            q.pop();
            
            if(!(now.first)){
                continue;
            }
            
            if(now.second==answer.size()){
                answer.push_back(vector<int>());
            }
            answer.back().push_back(now.first->val);
            
            for(auto child : now.first->children){
                q.push({child, now.second+1});
            }
        }
        
        return answer;
    }
};