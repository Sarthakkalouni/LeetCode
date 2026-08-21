class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        // Dono NULL hain
        if (p == NULL && q == NULL)
            return true;
        
        // Ek NULL hai, doosra nahi
        if (p == NULL || q == NULL)
            return false;
        
        // Values different hain
        if (p->val != q->val)
            return false;
        
        // Left aur right dono same hone chahiye
        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};