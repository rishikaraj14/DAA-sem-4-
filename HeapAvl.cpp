#include <iostream>
using namespace std;

/* ---------------- HEAP SORT ---------------- */
// Heapify function to maintain Max Heap property
void heapify(int arr[], int n, int i) {
    int largest = i;          // Assume root is largest
    int l = 2*i + 1;          // Left child
    int r = 2*i + 2;          // Right child

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest); // Recursively heapify affected subtree
    }
}

// Heap Sort function
void heapSort(int arr[], int n) {
    // Step 1: Build Max Heap
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Step 2: Delete max repeatedly
    for (int i = n-1; i > 0; i--) {
        swap(arr[0], arr[i]);     // Move current max to end
        heapify(arr, i, 0);       // Heapify reduced heap
    }
}

/* ---------------- AVL TREE ---------------- */

// Structure of AVL Tree Node
struct Node {
    int key;          // Data value
    int height;       // Height of node
    Node *left;       // Pointer to left child
    Node *right;      // Pointer to right child
};

// Function to get height of a node
int height(Node* n) {
    return n ? n->height : 0;     // If node exists return height else 0
}

// Create a new AVL node
Node* newNode(int key) {
    Node* node = new Node();
    node->key = key;              // Assign data
    node->left = node->right = NULL;
    node->height = 1;             // New node is initially a leaf
    return node;
}

// Right rotation (LL case)
Node* rightRotate(Node* y) {
    Node* x = y->left;            // New root
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;                     // Return new root
}

// Left rotation (RR case)
Node* leftRotate(Node* x) {
    Node* y = x->right;           // New root
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;                     // Return new root
}

// Get balance factor of node
int getBalance(Node* n) {
    if (!n) return 0;
    return height(n->left) - height(n->right);
}

// Insert a key into AVL Tree
Node* insertAVL(Node* node, int key) {

    // 1. Perform normal BST insertion
    if (!node)
        return newNode(key);

    if (key < node->key)
        node->left = insertAVL(node->left, key);
    else
        node->right = insertAVL(node->right, key);

    // 2. Update height of current node
    node->height = 1 + max(height(node->left), height(node->right));

    // 3. Check balance factor
    int balance = getBalance(node);

    // 4. Perform rotations if unbalanced

    // LL Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // RR Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // LR Case
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // RL Case
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;   // Return unchanged node pointer
}

// Inorder traversal (gives sorted order)
void inorder(Node* root) {
    if (root) {
        inorder(root->left);      // Visit left subtree
        cout << root->key << " "; // Print node
        inorder(root->right);     // Visit right subtree
    }
}

/* ---------------- MAIN ---------------- */
int main() {
    int n, choice;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[50];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "\n1. Heap Sort\n2. AVL Tree Sort\nEnter choice: ";
    cin >> choice;

    if (choice == 1) {
        heapSort(arr, n);
        cout << "Sorted using Heap:\n";
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
    }
    else if (choice == 2) {
        Node* root = NULL;
        for (int i = 0; i < n; i++)
            root = insertAVL(root, arr[i]);

        cout << "Sorted using AVL Tree:\n";
        inorder(root);
    }
    else {
        cout << "Invalid Choice!";
    }
    return 0;
}