/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private:
    unordered_map<Node*, Node*>node_map;
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return NULL;
        else if(node_map.count(head))
            return node_map[head];
        
        Node* new_node = new Node(head->val);
        node_map[head] = new_node;
        new_node->next = copyRandomList(head->next);
        new_node->random = copyRandomList(head->random);

        return new_node;
    }
};