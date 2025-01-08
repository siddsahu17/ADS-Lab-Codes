#include <bits/stdc++.h>
using namespace std;

struct Tree{
    int data; // to store data of the tree
    Tree *left, *right; //Pointers for Tree0
};

Tree* Create(int a){
    Tree *Root = new(Tree);

    Root->data = a;
    Root->left = NULL;
    Root->right = NULL;

    return Root;
}

Tree* Insert(Tree* Root, int a){
    if(Root == NULL){
        return Create(a); //if root is empty we create a node
    }
    if(a > Root->data){
        Root->right = Insert(Root->right , a); // if data is greater than node data we go to right
    }
    if(a < Root->data){
        Root->left = Insert(Root->left , a); // if data is lesser than node data we go to left
    }

    return Root;
}

void InOrder(Tree* Root){
    if(Root == NULL){
        return;
    }

    InOrder(Root->left);
    cout << Root->data << " ";
    InOrder(Root->right);
}

void PreOrder(Tree* Root){
    if(Root == NULL){
        return;
    }

    cout << Root->data << " ";
    PreOrder(Root->left);
    PreOrder(Root->right);
}

void PostOrder(Tree* Root){
    if(Root == NULL){
        return;
    }
    
    PostOrder(Root->right);
    PostOrder(Root->left);
    cout << Root->data << " ";
}

int main(){
    Tree* Root = NULL;
    Root = Insert(Root,45);
    Root = Insert(Root,50);
    Root = Insert(Root,10);
    Root = Insert(Root,30);
    Root = Insert(Root,5);
    Root = Insert(Root,55);
    Root = Insert(Root,48);
    Root = Insert(Root,60);

    cout << "In-Order Traversal of the TREE" << endl;
    InOrder(Root);
    cout << endl;

    cout << "Pre-Order Traversal of the TREE" << endl;
    PreOrder(Root);
    cout << endl;

    cout << "Post-Order Traversal of the TREE" << endl;
    PostOrder(Root);
    cout << endl;

    return 0;
}