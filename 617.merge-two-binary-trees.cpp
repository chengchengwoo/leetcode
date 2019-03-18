/*
 * @lc app=leetcode id=617 lang=cpp
 *
 * [617] Merge Two Binary Trees
 *
 * https://leetcode.com/problems/merge-two-binary-trees/description/
 *
 * algorithms
 * Easy (69.12%)
 * Total Accepted:    153.6K
 * Total Submissions: 222.1K
 * Testcase Example:  '[1,3,2,5]\n[2,1,3,null,4,null,7]'
 *
 * Given two binary trees and imagine that when you put one of them to cover
 * the other, some nodes of the two trees are overlapped while the others are
 * not.
 * 
 * You need to merge them into a new binary tree. The merge rule is that if two
 * nodes overlap, then sum node values up as the new value of the merged node.
 * Otherwise, the NOT null node will be used as the node of new tree.
 * 
 * Example 1:
 * 
 * 
 * Input: 
 * Tree 1                     Tree 2                  
 * ⁠         1                         2                             
 * ⁠        / \                       / \                            
 * ⁠       3   2                     1   3                        
 * ⁠      /                           \   \                      
 * ⁠     5                             4   7                  
 * Output: 
 * Merged tree:
 * 3
 * / \
 * 4   5
 * / \   \ 
 * 5   4   7
 * 
 * 
 * 
 * 
 * Note: The merging process must start from the root nodes of both trees.
 * 
 */
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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        //return mergeTreesRecursive(t1, t2);
        return mergeTreesIterative(t1, t2);
    }
    // T: O(n) S: O(n)
    TreeNode* mergeTreesRecursive(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) return nullptr;
        int val = (t1 ? t1->val : 0) + (t2 ? t2->val : 0);
        TreeNode* node = new TreeNode(val);
        node->left = mergeTreesRecursive(t1 ? t1->left : nullptr, t2 ? t2->left : nullptr);
        node->right = mergeTreesRecursive(t1 ? t1->right : nullptr, t2 ? t2->right : nullptr);
        return node;
    }
    // T: O(n) S: O(n)
    TreeNode* mergeTreesIterative(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) return nullptr;

        struct Item {
            TreeNode* root;
            TreeNode* t1;
            TreeNode* t2;
            bool left;
        };
        stack<Item> st;
        TreeNode dummy(0);
        st.push(Item{&dummy, t1, t2, true});
        while (!st.empty()) {
            Item s = st.top(); st.pop();
            if (!s.t1 && !s.t2) continue;
            int val = (s.t1 ? s.t1->val : 0) + (s.t2 ? s.t2->val : 0);
            TreeNode* node = new TreeNode(val);
            if (s.left) {
                s.root->left = node;
            } else {
                s.root->right = node;
            }
            st.push(Item{node, (s.t1 ? s.t1->left : nullptr), (s.t2 ? s.t2->left : nullptr), true});
            st.push(Item{node, (s.t1 ? s.t1->right : nullptr), (s.t2 ? s.t2->right : nullptr), false});
        }
        return dummy.left;
    }
};

