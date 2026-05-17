// 多次查找，TLE，但是还可以
#include <iostream>
using namespace std;
struct node
{
        int left;
        int right;
        int height;
};
int count_child(node *array,int u)
{
    if(array[u].left == 0 and array[u].right == 0) return 1;
    if(array[u].left and array[u].right)
    {
        return 1 + count_child(array,array[u].left) + count_child(array,array[u].right);
    }
    else if(array[u].right)
    {
        return 1 + count_child(array,array[u].right);
    }
    else 
    {
        return 1 + count_child(array,array[u].left);
    }
}
bool search_yn(node *array,int u,int v)
{
    if(u == v) return true;
    if(array[u].left == 0 and array[u].right == 0) return false;
    else if(array[u].left and array[u].right)
    {
        return search_yn(array,array[u].left,v) or search_yn(array,array[u].right,v);
    }
    else if(array[u].left)
    {
        return search_yn(array,array[u].left,v);
    }
    else
    {
        return search_yn(array,array[u].right,v);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q;
    cin >> n >> q;
    node *people = new node[2 * n + 1]();
    people[1].height = 1;
    for(int i = 1;i <= n;i ++)
    {
        int l ,r;
        cin >> l >> r;
        if(l) 
        {
            people[i].left = l;
            people[l].height = people[i].height + 1;
        }
        if(r) 
        {
            people[i].right = r;
            people[r].height = people[i].height + 1;
        }
    }
    int num,u,v;
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
            int result = count_child(people,u) - 1;
            cout << result << endl;
        }
        if(num == 3)
        {
            cin >> u >> v;
            bool result = search_yn(people,u,v) or search_yn(people,v,u);
            if(result) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    return 0;
}