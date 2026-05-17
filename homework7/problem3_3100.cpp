#include <iostream>
using namespace std;
struct node
{
        int left;
        int right;
        int height;
};
void dfs(node *array,int u,int *subtree_size,int *tin,int *tout,int &timer)
{
    subtree_size[u] = 1;
    tin[u] = ++timer;
    if(array[u].left)
    {
        array[array[u].left].height = array[u].height + 1;
        dfs(array,array[u].left,subtree_size,tin,tout,timer);
        subtree_size[u] += subtree_size[array[u].left];
    }
    if(array[u].right)
    {
        array[array[u].right].height = array[u].height + 1;
        dfs(array, array[u].right, subtree_size, tin, tout, timer);
        subtree_size[u] += subtree_size[array[u].right];
    }
    tout[u] = timer;
}
bool is_reletive(int u,int v,int *tin,int *tout)
{
    return (tin[u] <= tin[v] and tout[u] >= tout[v]) or (tin[u] >= tin[v] and tout[u] <= tout[v]);   
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q;
    cin >> n >> q;
    node *people = new node[n + 1]();
    people[1].height = 1;
   for(int i = 1; i <= n; i++)
    {
        cin >> people[i].left >> people[i].right;
    }
    int num,u,v;
    int *subtree_size = new int[n + 1]();
    int *tin = new int [n + 1]();
    int *tout = new int [n + 1]();
    int timer = 0;
    dfs(people, 1, subtree_size, tin, tout, timer);
    for(int i = 0;i < q;i++)
    {
        cin >> num;
        if(num == 1)
        {
            cin >> u;
            cout << people[u].height << endl;
        }
        if(num == 2)
        {
            cin >> u;
            cout << subtree_size[u] - 1 << endl;
        }
        if(num == 3)
        {
            cin >> u >> v;
            if(is_reletive(u,v,tin,tout)) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    delete[] people;
    delete[] subtree_size;
    delete[] tin;
    delete[] tout;
    return 0;
}