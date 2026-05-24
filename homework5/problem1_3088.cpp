#include <iostream>
using namespace std;
int find(const int a[],int x,int left,int right)
{
    if(left > right) return 0;
    int mid = left + (right - left) / 2;
    if(x == a[mid]) 
    {
        while(mid > left and a[mid - 1] == a[mid])
        {
            mid --;
        }
        return mid;
    }
    else if(x < a[mid])
    {
        if(mid == left) return mid;
        if(mid > left and x > a[mid - 1]) return mid;
        return find(a,x,left,mid - 1);
    }
    else 
    {   
        if(mid == right) return 0;
        if(mid < right and x < a[mid + 1]) return mid + 1;
        return find(a,x,mid + 1,right);
    }
}
int main(){
    int n,q;
    cin >> n >> q;
    int *a = new int [n + 1];
    for(int i = 1;i <= n;i ++)
    {
        cin >> a[i];
    }
    for(int i = 1;i <= q;i++)
    {
        int x;
        cin >> x;
        int result = find(a,x,1,n);
        cout << result << endl;
    }
    delete []a;
    return 0;
}