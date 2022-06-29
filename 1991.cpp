#include <iostream>
#include <map>
#include <utility>

using namespace std;


void preorder(char Node, map<char, pair<char,char>> tree);
void inorder(char Node, map<char, pair<char,char>> tree);
void postorder(char Node, map<char, pair<char,char>> tree);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testNumber;
    char parent, child1, child2;
    map<char, pair<char,char>> tree;
    char root;
    cin >> testNumber;
    for(int i = 0; i < testNumber; i++){
        cin >> parent >> child1 >> child2;
        if(i == 0){
            root = parent;
        }
        tree[parent] = make_pair(child1, child2);
    }
    preorder(root, tree);
    cout << endl;
    inorder(root, tree);
    cout << endl;
    postorder(root, tree);
    cout << endl;

    return 0;
}
void preorder(char Node, map<char, pair<char,char>> tree){
    cout << Node;
    if(tree[Node].first != '.'){
        preorder(tree[Node].first, tree);
    }
    if(tree[Node].second != '.'){
        preorder(tree[Node].second, tree);
    }
}
void inorder(char Node, map<char, pair<char,char>> tree){
    if(tree[Node].first != '.'){
        inorder(tree[Node].first, tree);
    }
    cout << Node;
    if(tree[Node].second != '.'){
        inorder(tree[Node].second, tree);
    }
}
void postorder(char Node, map<char, pair<char,char>> tree){
    if(tree[Node].first != '.'){
        postorder(tree[Node].first, tree);
    }
    if(tree[Node].second != '.'){
        postorder(tree[Node].second, tree);
    }
    cout << Node;
}

