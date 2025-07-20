
// Converted sorted array to BST
#include <bits/stdc++.h>
using namespace std;

// TreeNode definition
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Solution class
class Solution
{
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return helper(nums, 0, nums.size() - 1);
    }

    TreeNode *helper(vector<int> &nums, int l, int r)
    {
        if (l > r)
            return NULL;
        int mid = (l + r) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = helper(nums, l, mid - 1);
        root->right = helper(nums, mid + 1, r);
        return root;
    }
};

// Function to print BST (inorder traversal)
void printInorder(TreeNode *root)
{
    if (!root)
        return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

// MAIN FUNCTION
int main()
{
    vector<int> nums = {-10, -3, 0, 5, 9};

    Solution sol;
    TreeNode *root = sol.sortedArrayToBST(nums);

    cout << "Inorder traversal of BST: ";
    printInorder(root);
    cout << endl;

    return 0;
}
