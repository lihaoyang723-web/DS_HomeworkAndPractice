#include <iostream>
using namespace std;
class BinarySearchTree
{
public:
    struct node
    {
        int value;
        node *left;
        node *right;
        node():value(0),left(nullptr),right(nullptr){}
        node(int x,node *left = nullptr,node *right = nullptr):value(x),left(left),right(right){}
    };
    node *root;
    BinarySearchTree(){root = nullptr;}
    ~BinarySearchTree(){delete []root;}
    void insert(node *&t,int x);
};
void BinarySearchTree::insert(node *&t,int x)
{
    if(t == nullptr)
    {
        t = new node(x);
        return ;
    }
    if(x < t->value) insert(t->left,x);
    else insert(t->right,x);
}
void search(BinarySearchTree::node *&t,int k)
{
    cout << t->value << " ";
    if(t->value == k) 
    {
        return ;
    }
    else if(t->left == nullptr and t->right == nullptr)
    {
        cout << -1;
        return ;
    }
    if(k < t->value) 
    {   
        search(t->left,k);
    }
    else 
    {
        search(t->right,k);
    }
}
int main()
{
    int n,k;
    cin >> n >> k;
    BinarySearchTree t;
    for(int i = 0;i < n;i++)
    {
        int a;
        cin >> a;
        t.insert(t.root,a);
    }
    search(t.root,k);
    cout << endl;
    return 0;
}