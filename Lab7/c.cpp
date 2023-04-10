#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *addNode(int *a, int i, int n)
{
    if (i >= n || a[i] == -1)
    {
        return NULL;
    }

    TreeNode *root = new TreeNode(a[i]);
    root->left = addNode(a, 2 * i + 1, n);
    root->right = addNode(a, 2 * i + 2, n);

    return root;
}

int addSum(TreeNode *curr, int target)
{
    if (curr == NULL)
    {
        return 0;
    }

    if (curr->left == NULL && curr->right == NULL)
    {
        if (curr->val == target)
        {
            return 1;
        }

        return 0;
    }

    return addSum(curr->left, target - curr->val) + addSum(curr->right, target - curr->val);
}

void inorder(TreeNode *root)
{

    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main()
{
    int n, m;
    cin >> n >> m;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    TreeNode *root = addNode(a, 0, n);

    // inorder(root);

    int f = addSum(root, m);
    cout << f << endl;
    return 0;
}
