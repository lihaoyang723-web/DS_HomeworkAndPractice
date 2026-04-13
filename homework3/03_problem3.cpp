#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct node{
    int val;
    node *left;
    node *right;
    node *back;
    node():val(0),left(nullptr),right(nullptr),back(nullptr){}
    node(int val):val(val),left(nullptr),right(nullptr),back(nullptr){}
};

void f(node* t, queue<int> &que)
{
    que.push(t->val);
    //cout << t->val << " ";
    if(t->back) {
        f(t->back, que);
    }
}

int main(){
    int n;
    cin >> n;
    vector<node*> tree(n + 1, nullptr);
    vector<node*> leaves(n + 1, nullptr);

    for(int i=1; i<=n; i++)
    {
        int val, lva, rva;
        cin >> val >> lva >> rva;
        if (!tree[i]) tree[i] = new node(val);

        if(lva == 0 && rva == 0) {
            leaves[i] = tree[i];
        }

        if(lva) {
            if (!tree[lva]) tree[lva] = new node(lva);
            tree[i]->left = tree[lva];
            tree[lva]->back = tree[i];
        }
        if(rva) {
            if (!tree[rva]) tree[rva] = new node(rva);
            tree[i]->right = tree[rva];
            tree[rva]->back = tree[i];
        }
    }

    int result = 0;
    for(int i=1; i<=n; i++)
    {
        if(leaves[i]) {
            queue<int> que;
            f(leaves[i], que);
            int num = 1;
            while(!que.empty()) {
                result += que.front() * num;
                que.pop();
                num *= 10;
            }
        }
    }
    cout << result << endl;
    return 0;
}