/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Codec {
    void serializeNode(Node* const node, string& msg) {
        msg += to_string(node->val);
        msg += "#";
        msg += to_string((int)node->children.size());
        msg += ',';
    }
    
    Node* deserializeNode(string const& data, int& offset) {
        int end = data.find(',', offset);
        if(end == string::npos) {
            end = data.length();
        }
        int delimeter = data.find('#', offset);
        int nodeValue = stoi(data.substr(offset, delimeter - offset));
        offset = delimeter + 1;
        int nodeChildrenCount = stoi(data.substr(offset, end - offset));
        offset = end + 1;
        vector<Node*> children(nodeChildrenCount);
        
        return new Node(nodeValue, children);
    }
public:

    // Encodes a tree to a single string.
    string serialize(Node* root) { 
        string result = "";
        if(!root) return result;
        queue <Node*> Q;
        Q.push(root);
        serializeNode(root, result);
        while(!Q.empty()) {
            Node* node = Q.front();
            for (Node* child : node->children) {
                serializeNode(child, result);
                Q.push(child);   
            }
            Q.pop();
        }
        return result.erase((int)result.length() - 1, 1); 
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        Node* root = nullptr;
        if(data.empty()) return root;
        queue<Node*> Q;
        int offset = 0;
        root = deserializeNode(data, offset);
        Q.push(root);
        while(!Q.empty()) {
            Node* node = Q.front();
            for (int i = 0; i < (int)node->children.size(); i++) {
                Node* child = deserializeNode(data, offset);
                node->children[i] = child;
                Q.push(child);
            }
            Q.pop();
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));