#include <iostream>
using namespace std;

struct node
{
    int left;
    long long weight;
    int right;
    node(){}
    node(int left,long long weight,int right):left(left),weight(weight),right(right){}
};

node *hf_tree;
long long result = 0;

void countWPL(int root, int distance)
{
    if(root == 0) return;

    if(hf_tree[root].left == 0 && hf_tree[root].right == 0)
    {
        result += hf_tree[root].weight * distance;
        return;
    }

    countWPL(hf_tree[root].left, distance + 1);
    countWPL(hf_tree[root].right, distance + 1);
}

int main(){
    int n;
    cin >> n;

    hf_tree = new node [n + 1];
    bool *hasParent = new bool [n + 1]();

    for(int i = 1;i <= n;i++)
    {
        int left,right;
        long long weight;

        cin >> left >> weight >> right;

        hf_tree[i] = node(left,weight,right);

        if(left != 0) hasParent[left] = true;
        if(right != 0) hasParent[right] = true;
    }

    int root = 1;
    for(int i = 1;i <= n;i++)
    {
        if(!hasParent[i])
        {
            root = i;
            break;
        }
    }

    countWPL(root, 0);

    cout << result << endl;

    delete[] hf_tree;
    delete[] hasParent;

    return 0;
}