/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int findTilt(TreeNode* root) {
        int wholeTilt = 0;
        this->postOrder(root, wholeTilt);
        return wholeTilt;
    }
    
    int postOrder(TreeNode* node, int &wholeTilt){
        if(node == NULL) return 0;
        int leftSum = this->postOrder(node->left, wholeTilt);
        int rightSum = this->postOrder(node->right, wholeTilt);
        wholeTilt += abs(leftSum - rightSum);
        return leftSum + rightSum + node->val;
    }
};
