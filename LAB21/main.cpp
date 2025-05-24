#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
    char data;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* insert(TreeNode* root, char key) {
    if (!root) {
        TreeNode* newNode = new TreeNode{key, nullptr, nullptr};
        return newNode;
    }
    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}

TreeNode* findMin(TreeNode* root) {
    while (root && root->left) root = root->left;
    return root;
}

TreeNode* remove(TreeNode* root, char key) {
    if (!root) return nullptr;
    if (key < root->data)
        root->left = remove(root->left, key);
    else if (key > root->data)
        root->right = remove(root->right, key);
    else {
        if (!root->left) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }
        if (!root->right) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        TreeNode* temp = findMin(root->right);
        root->data = temp->data;
        root->right = remove(root->right, temp->data);
    }
    return root;
}

TreeNode* search(TreeNode* root, char key) {
    if (!root || root->data == key) return root;
    if (key < root->data) return search(root->left, key);
    return search(root->right, key);
}

void preorder(TreeNode* root) {
    if (root) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(TreeNode* root) {
    if (root) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void postorder(TreeNode* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

void storeInorder(TreeNode* root, vector<char>& elems) {
    if (!root) return;
    storeInorder(root->left, elems);
    elems.push_back(root->data);
    storeInorder(root->right, elems);
}

TreeNode* buildBalancedBST(vector<char>& elems, int start, int end) {
    if (start > end) return nullptr;
    int mid = (start + end) / 2;
    TreeNode* root = new TreeNode{elems[mid], nullptr, nullptr};
    root->left = buildBalancedBST(elems, start, mid - 1);
    root->right = buildBalancedBST(elems, mid + 1, end);
    return root;
}

TreeNode* balanceTree(TreeNode* root) {
    vector<char> elems;
    storeInorder(root, elems);
    return buildBalancedBST(elems, 0, elems.size() - 1);
}

void visualizeTree(TreeNode* root, string prefix = "", bool isLeft = true) {
    if (root != nullptr) {
        cout << prefix;
        cout << (isLeft ? "├──" : "└──");
        cout << root->data << endl;
        visualizeTree(root->left, prefix + (isLeft ? "│   " : "    "), true);
        visualizeTree(root->right, prefix + (isLeft ? "│   " : "    "), false);
    }
}

void verticalPrint(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int count = q.size();
        while (count--) {
            TreeNode* node = q.front();
            q.pop();
            cout << node->data << " ";
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        cout << endl;
    }
}

int main() {
    TreeNode* root = nullptr;
    int n;
    cout << "Введите количество узлов: ";
    cin >> n;

    cout << "Введите символы:\n";
    for (int i = 0; i < n; ++i) {
        char ch;
        cin >> ch;
        root = insert(root, ch);
    }

    cout << "\nСимметричный обход (in-order): ";
    inorder(root);
    cout << "\nПрямой обход (pre-order): ";
    preorder(root);
    cout << "\nОбратный обход (post-order): ";
    postorder(root);

    cout << "\n\nГоризонтальная визуализация:\n";
    visualizeTree(root);

    cout << "\nВертикальная визуализация:\n";
    verticalPrint(root);

    char key;
    cout << "\nВведите ключ для поиска: ";
    cin >> key;
    TreeNode* found = search(root, key);
    if (found)
        cout << "Элемент найден: " << found->data << endl;
    else
        cout << "Элемент не найден\n";

    cout << "\nБалансировка дерева...\n";
    root = balanceTree(root);

    cout << "\nПосле балансировки:\n";
    visualizeTree(root);

    cout << "\nУдалить элемент: ";
    cin >> key;
    root = remove(root, key);
    cout << "\nПосле удаления:\n";
    visualizeTree(root);

    return 0;
}
