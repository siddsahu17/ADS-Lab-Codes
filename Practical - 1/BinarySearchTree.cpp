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

// Recursive Calling
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

#define N 100

// class Stack{
// //	implmentation in either linked list or array
// 	public:
// 		string s1[N];
// 		int top;
// 		Stack(){
// 			top == -1;
// 		}
// 		bool isFull(){
// 			if(top == N-1){
// 				return true;
// 			}else{
// 				return false;
// 			}
// 		}
		
// 		bool isEmpty(){
// 			if(top == -1){
// 				return true;
// 			}else{
// 				return false;
// 			}
// 		}
	
// 		void push(int s){
// 			if(isFull()){
// 				cout << "Insertion not possible \nOverflow";
// 			}else{
// 				top = top+1;
// 				s1[top] = s;
// 			}
// 		}
		
// 		string pop(string s){
// 			if(isEmpty()){
// 				cout << "Stack is Empty\nPop not possible";
// 			}else{
// 				string temp = s1[top];
// 				top = top-1;
// 				return temp;
// 			}
// 		}	
// };

// Non Recursive Calling
void InOrderNR(Tree* Root){
    Tree *curr = Root;
    stack<Tree*> s;
    while(curr != NULL || s.empty() == false){
        while(curr != NULL){
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();

        cout << curr->data << " ";
        curr = curr->right;
    }
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

    cout << "IN-Order NON RECURSIVE Traversal of the TREE" << endl;
    InOrderNR(Root);
    cout << endl;

    return 0;
}