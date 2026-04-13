#include <iostream>
#include <vector>

struct node{
    int data;
    node *left;    
    node *right;
    node(int data):data(data),left(nullptr),right(nullptr){}
    
    static node* create(int n)
    {
        std::vector<node*> nodes(n + 1, nullptr);
        std::vector<bool> isChild(n + 1, false);

        for (int i = 1; i <= n; ++i) {
            nodes[i] = new node(0);
        }

        for (int i = 1; i <= n; ++i) {
            int val, leftVal, rightVal;
            std::cin >> val >> leftVal >> rightVal;

            nodes[i]->data = val;

            if (leftVal != 0) {
                nodes[i]->left = nodes[leftVal];
                isChild[leftVal] = true;
            }

            if (rightVal != 0) {
                nodes[i]->right = nodes[rightVal];
                isChild[rightVal] = true;
            }
        }

        for (int i = 1; i <= n; ++i) {
            if (!isChild[i]) {
                return nodes[i];
            }
        }

        return nullptr;
    }

    static void preorder(node *t, std::vector<int>& out)
    {
        if (t == nullptr) return;
        out.push_back(t->data);
        preorder(t->left, out);
        preorder(t->right, out);
    }
};
int main(){
    int n;
    std::cin >> n;

    node *tree = node::create(n);
    std::vector<int> ans;
    node::preorder(tree, ans);
    for (size_t i = 0; i < ans.size(); ++i) {
        if (i) std::cout << ' ';
        std::cout << ans[i];
    }
    std::cout << std::endl;
    return  0;
}