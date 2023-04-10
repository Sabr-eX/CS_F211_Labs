#include <iostream>

using namespace std;

typedef struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* addNode(int* inorder, int* preorder, int start, int end, int* no){
    if(start >= end){
        return NULL;
    }
    TreeNode* root = new TreeNode(preorder[(*no)++]);

    root->left = addNode(inorder, preorder, start, end, no);

}