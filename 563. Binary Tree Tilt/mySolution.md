Problem link: https://leetcode.com/problems/binary-tree-tilt/#/description

#### My code:
```c++
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
```

#### Discussion:
According to the problem description, we can find out that the Post Order Traverse would be the most suitable solution because we should visit the left and right child node first to work out the sum and tilt of current node.<br>
The only difference between my code and the provided sloution is the `NULL` judgement of `root`. In C++, it is always necessary to do `NULL` judgement before using a pointer. Unfortunatelly, I ignored it in my code.
