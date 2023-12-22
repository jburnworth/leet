#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> preorderTraversalRecursive(TreeNode* root) {
    static vector<int> preorderList;

    if (root != nullptr) {
        preorderList.push_back(root->val);

        preorderTraversalRecursive(root->left);
        preorderTraversalRecursive(root->right);
    }

    return preorderList;
}

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> preorderList;

    if (root == nullptr) {
        return {};
    }
    vector<TreeNode*> stack = {root};

    while (!stack.empty()) {
        // Pop the top of the stack into current.
        TreeNode* current = stack.back();
        stack.pop_back();
        if (current != nullptr) {
            // Add the value of current to our list
            preorderList.push_back(current->val);

            // Because of FILO, push the right node first.
            stack.push_back(current->right);

            // Because of FILO, push the left node second.
            stack.push_back(current->left);
        }
    }

    return preorderList;
}

vector<int> inorderTraversalRecursive(TreeNode* root) {
    static vector<int> inorderList;

    if (root != nullptr) {
        inorderTraversalRecursive(root->left);

        inorderList.push_back(root->val);

        inorderTraversalRecursive(root->right);
    }

    return inorderList;
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> inorderList;

    TreeNode* current = root;
    vector<TreeNode*> stack;
    // If current is null, pop it and go right
    // if current isn't null push it and go left

    while (current != nullptr || !stack.empty()) {
        // Traverse left
        if (current) {
            stack.push_back(current);
            current = current->left;
            continue;
        }
        current = stack.back();
        stack.pop_back();
        //cout << current->val << " ";
        inorderList.push_back(current->val);
        current = current->right;
    }
    //cout << endl;
    return inorderList;
}

vector<int> postorderTraversalRecursive(TreeNode* root) {
    static vector<int> postorderList;

    if (root != nullptr) {
        postorderTraversalRecursive(root->left);
        postorderTraversalRecursive(root->right);

        postorderList.push_back(root->val);
    }

    return postorderList;
}

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> postorderList;

    if (!root) {
        return {};
    }

    vector<TreeNode*> stack = {root};
    TreeNode* current;

    // walk the tree t->b l->r
    while(!stack.empty()) {
        current = stack.back();
        stack.pop_back();
        postorderList.push_back(current->val);

        if (current->left) {
            stack.push_back(current->left);
        }
        if (current->right) {
            stack.push_back(current->right);
        }
    }

    // Reverse the output since postorder is b->t l->r
    reverse(postorderList.begin(), postorderList.end());

    return postorderList;
}

vector<vector<int>> levelOrder(TreeNode* root) {
    if (root == nullptr) {
        return {};
    }
    vector<vector<int>> levelList;
    queue<pair<TreeNode*, int>> nodeQueue;
    nodeQueue.push(make_pair(root, 0));

    while(!nodeQueue.empty()) {
        pair<TreeNode*, int> currentPair = nodeQueue.front();
        nodeQueue.pop();

        //cout << currentPair.first->val << ", level: " << currentPair.second << endl;
        //levelList.push_back(current->val);
        if (levelList.size() < (currentPair.second + 1)) {
            levelList.push_back({});
        }
        levelList[currentPair.second].push_back(currentPair.first->val);

        if (currentPair.first->left) {
            nodeQueue.push(make_pair(currentPair.first->left, currentPair.second + 1));
        }
        if (currentPair.first->right) {
            nodeQueue.push(make_pair(currentPair.first->right, currentPair.second + 1));
        }
    }

    return levelList;
}

int main()
{
    TreeNode* seven = new TreeNode(7, nullptr, nullptr);
    TreeNode* six = new TreeNode(6, nullptr, nullptr);
    TreeNode* five = new TreeNode(5, nullptr, nullptr);
    TreeNode* four = new TreeNode(4, nullptr, nullptr);
    TreeNode* three = new TreeNode(3, six, seven);
    TreeNode* two = new TreeNode(2, four, five);
    TreeNode* one = new TreeNode(1, two, three);

    /*
    TreeNode* three = new TreeNode(3, nullptr, nullptr);
    TreeNode* two = new TreeNode(2, three, nullptr);
    TreeNode* one = new TreeNode(1, nullptr, two);
    */

    vector<vector<int>> traversal = levelOrder(one);
    for (auto level: traversal) {
        for (auto i: level) {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;
}