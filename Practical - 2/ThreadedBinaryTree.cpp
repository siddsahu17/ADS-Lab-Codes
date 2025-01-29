#include <bits/stdc++.h>
using namespace std;

struct Tree {
    int data;
    Tree *left, *right;
    bool leftThread, rightThread; // Flags for threading
};

// Create a new Tree
Tree* createTree(int data) {
    Tree* newTree = new Tree();
    newTree->data = data;
    newTree->left = newTree->right = NULL;
    newTree->leftThread = newTree->rightThread = true;
    return newTree;
}

// Insert a Tree into a threaded binary tree
Tree* Insert(Tree* Root, int key) {
    if (!Root) {
        return createTree(key);
    }

    Tree* current = Root;
    Tree* parent = NULL;

    while (current) {
        if (key == current->data) {
            cout << "Duplicate keys are not allowed." << endl;
            return Root;
        }

        parent = current;

        if (key < current->data) {
            if (current->leftThread) break;
            current = current->left;
        } else {
            if (current->rightThread) break;
            current = current->right;
        }
    }

    Tree* newTree = createTree(key);

    if (key < parent->data) {
        newTree->left = parent->left;
        newTree->right = parent;
        parent->leftThread = false;
        parent->left = newTree;
    } else {
        newTree->right = parent->right;
        newTree->left = parent;
        parent->rightThread = false;
        parent->right = newTree;
    }

    return Root;
}

// Find the leftmost Tree in the tree
Tree* leftmost(Tree* Tree) {
    while (Tree && !Tree->leftThread) {
        Tree = Tree->left;
    }
    return Tree;
}

// In-order traversal (non-recursive)
void inOrderNonRecursive(Tree* Root) {
    Tree* current = leftmost(Root);

    while (current) {
        cout << current->data << " ";

        if (current->rightThread) {
            current = current->right;
        } else {
            current = leftmost(current->right);
        }
    }
    cout << endl;
}

// Pre-order traversal (non-recursive)
void preOrderNonRecursive(Tree* Root) {
    Tree* current = Root;

    while (current) {
        cout << current->data << " ";

        if (!current->leftThread) {
            current = current->left;
        } else if (!current->rightThread) {
            current = current->right;
        } else {
            while (current && current->rightThread) {
                current = current->right;
            }
            if (current) {
                current = current->right;
            }
        }
    }
    cout << endl;
}

// Recursive in-order traversal
void inOrderRecursive(Tree* Root) {
    if (!Root) return;

    if (!Root->leftThread) inOrderRecursive(Root->left);
    cout << Root->data << " ";
    if (!Root->rightThread) inOrderRecursive(Root->right);
}

// Recursive pre-order traversal
void preOrderRecursive(Tree* Root) {
    if (!Root) return;

    cout << Root->data << " ";
    if (!Root->leftThread) preOrderRecursive(Root->left);
    if (!Root->rightThread) preOrderRecursive(Root->right);
}

// Recursive post-order traversal
void postOrderRecursive(Tree* Root) {
    if (!Root) return;

    if (!Root->leftThread) postOrderRecursive(Root->left);
    if (!Root->rightThread) postOrderRecursive(Root->right);
    cout << Root->data << " ";
}

// Post-order traversal (non-recursive)
void postOrderNonRecursive(Tree* Root) {
    stack<Tree*> s1, s2;

    if (!Root) return;
    s1.push(Root);

    while (!s1.empty()) {
        Tree* current = s1.top();
        s1.pop();
        s2.push(current);

        if (!current->leftThread && current->left) {
            s1.push(current->left);
        }
        if (!current->rightThread && current->right) {
            s1.push(current->right);
        }
    }

    while (!s2.empty()) {
        cout << s2.top()->data << " ";
        s2.pop();
    }
    cout << endl;
}

int main() {
    Tree* Root = NULL;
    Root = Insert(Root,45);
    Root = Insert(Root,50);
    Root = Insert(Root,10);
    Root = Insert(Root,30);
    Root = Insert(Root,5);
    Root = Insert(Root,55);
    Root = Insert(Root,48);
    Root = Insert(Root,60);
    int choice, value;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert Tree\n";
        cout << "2. In-Order Traversal (Recursive)\n";
        cout << "3. Pre-Order Traversal (Recursive)\n";
        cout << "4. Post-Order Traversal (Recursive)\n";
        cout << "5. In-Order Traversal (Non-Recursive)\n";
        cout << "6. Pre-Order Traversal (Non-Recursive)\n";
        cout << "7. Post-Order Traversal (Non-Recursive)\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                Root = Insert(Root, value);
                break;

            case 2:
                cout << "In-Order Traversal (Recursive): ";
                inOrderRecursive(Root);
                cout << endl;
                break;

            case 3:
                cout << "Pre-Order Traversal (Recursive): ";
                preOrderRecursive(Root);
                cout << endl;
                break;

            case 4:
                cout << "Post-Order Traversal (Recursive): ";
                postOrderRecursive(Root);
                cout << endl;
                break;

            case 5:
                cout << "In-Order Traversal (Non-Recursive): ";
                inOrderNonRecursive(Root);
                cout << endl;
                break;

            case 6:
                cout << "Pre-Order Traversal (Non-Recursive): ";
                preOrderNonRecursive(Root);
                cout << endl;
                break;

            case 7:
                cout << "Post-Order Traversal (Non-Recursive): ";
                postOrderNonRecursive(Root);
                cout << endl;
                break;

            case 8:
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 8);

    return 0;
}
