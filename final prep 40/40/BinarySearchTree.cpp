#include <iostream>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;

    Node(int val){
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

struct BST{
    private:
      Node *root;

      void in_order(Node* node){
        if(!node) return;
        in_order(node->left);
        cout<<node->val<<" ";
        in_order(node->right);
      }

      void pre_order(Node* node){
        if(!node) return;
        cout<<node->val<<" ";
        pre_order(node->left);
        pre_order(node->right);
      }

      void post_order(Node* node){
        if(!node) return;
        post_order(node->left);
        post_order(node->right);
        cout<<node->val<<" ";
      }

      Node* insert(Node* curr, int val){
        if(!curr){
            return new Node(val);
        }
        if(val>curr->val){
            curr->right = insert(curr->right, val);
        }
        if(val<curr->val){
            curr->left = insert(curr->left, val);
        }
        return curr;

      }

        int rightmost(Node* curr){
            if(!curr) return -1;
            if(!curr->right) return curr->val;
            return rightmost(curr->right);
            }

        int leftmost(Node* curr){
            if(!curr) return -1;
            if(!curr->left) return curr->val;
            return leftmost(curr->left);
            }

        
	Node* _remove(Node* cur, int target) {
		if (!cur) return nullptr;
		if (cur->val == target) {
			if (!cur->right && !cur->left) {
				delete cur;
				return nullptr;
			} else if (cur->left && !cur->right) {
				Node* temp = cur->left;
				delete cur;
				return temp;
			} else if (cur->right && !cur->left) {
				Node* temp = cur->right;
				delete cur;
				return temp;
			} else if (cur->right && cur->left) {
				cur->val = rightmost(cur->left);
				cur->left = _remove(cur->left, cur->val);
				// cur->val = _leftmost(cur->right);
				// cur->right = _remove(cur->right, cur->val);
			}
		} else if (cur->val < target) {
			cur->right = _remove(cur->right, target);
			return cur;
		} else if (cur->val > target) {
			cur->left = _remove(cur->left, target);
			return cur;
		}
		return cur;
	}



};


struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val = val;
        left = right = NULL;
    }
};
class BST{
    Node * root;

    Node* push(Node * cur, int val){
        if (cur == NULL) {
            return new Node(val);
        }
        if (val < cur -> val) cur -> left = push(cur -> left, val);
        if (val > cur -> val) cur -> right = push(cur -> right, val);
        return cur;
    }
};