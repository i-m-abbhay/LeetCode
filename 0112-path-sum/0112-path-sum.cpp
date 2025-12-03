/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        queue<pair<TreeNode*, int>> q;
        q.push({root, targetSum-root->val});
       
        while(!q.empty()){
            int size = q.size();
            
            TreeNode* node = q.front().first;
            int target = q.front().second;
            if(target == 0 && !node->left && !node->right) return true;
            q.pop();
            if(node->left){
                q.push({node->left, target-node->left->val});
            }
            if(node->right){
                q.push({node->right, target-node->right->val});
        }
        }



        return false;
    }
};