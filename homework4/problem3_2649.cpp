#include <iostream>
using namespace std;
struct node
{
    int data;
    node *left;
    node* right;
    node* father;
    node(){}
    node(int data,node *left = nullptr,node *right = nullptr):data(data),left(left),right(right){}
};

bool find(node *r,int y)
{
    if(r->data == y) return true;
    if(r->left and r->right) 
        return (find(r->left,y) or find(r->right,y));
    if(r->left) return find(r->left,y);
    if(r->right) return find(r->right,y);
    return false;
}

int main(){
    int n,x,y;
    cin >> n >> x >> y;
    node *t = new node [n + 1];
    node *f;
    t[1] = node(1);
    t[1].father = nullptr;
    for(int i = 1;i <= n;i++)
    {
        int a,b;
        cin >> a >> b;
        if(a != 0)
        {  
            t[i].left = &t[a];
            t[a].data = a;
            t[a].father = &t[i];
        }

        if(b != 0)
        {
            t[i].right = &t[b];
            t[b].data = b;
            t[b].father = &t[i];
        }
        if(a == x) f = t[i].left;
        else if(b == x) f = t[i].right;
    }
    f = f->father;
    while(!find(f,y))
    {
        f = f->father;
    }
    cout << f->data << endl;
    return 0;   
}