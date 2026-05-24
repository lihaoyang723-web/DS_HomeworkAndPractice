#include <iostream>
using namespace std;
int main(){
    int n,m,q;
    cin >> n >> m >> q;
    int *a = new int[n + 1];
    int *b = new int[m + 1];
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    for(int i = 1;i <= m;i++)
    {
        cin >> b[i];
    }
    int *c = new int [m + n + 1];
    int ap =1,bp = 1,cp = 1;
    while(ap <= n and bp <= m)
    {
        if(a[ap] <= b[bp]) 
        {
            c[cp] = a[ap];
            ap ++;
            cp ++;
        }
        else 
        {
            c[cp] = b[bp];
            bp ++;
            cp ++;
        }
    }
    while(ap <= n)
    {
        c[cp] = a[ap];
        ap ++;
        cp ++;
    }
    while(bp <= m)
    {
        c[cp] = b[bp];
        cp ++;
        bp ++;
    }
    for(int i = 0;i < q;i++)
    {
        int k;
        cin >> k;
        int result = c[k];
        cout << result << endl;
    }
    return 0;
}