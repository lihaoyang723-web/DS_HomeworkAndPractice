#include <iostream>
#include <queue>
using namespace std;
struct node
{
    int x;
    int val;
    int l;
    int r;
    node(){}
    node(int x,int val,int l,int r):x(x),val(val),l(l),r(r){}
};
int main(){
    int n;
    cin >> n;
    node *a = new node [n + 1];
    int x,val,l,r;
    for(int i = 1;i <= n;i ++)
    {
        cin >> x >> val >> l >> r;
        a[x] = node(x,val,l,r);
    }
   queue<int>q;
   q.push(1);
   int max = -1001;
   while(!q.empty())
   {
        int size = q.size();
        for(int i = 1;i <= size;i++)
        {
            int cur = q.front();
            q.pop();

            if(a[cur].val > max)
            {
                max = a[cur].val;
            }

            if(a[cur].l != -1) q.push(a[cur].l);
            if(a[cur].r != -1) q.push(a[cur].r);
        }
        cout << max << " ";
        max = -1001;
   }
    cout << endl;
    return 0;
}