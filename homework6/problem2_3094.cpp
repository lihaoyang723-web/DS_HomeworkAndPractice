#include <iostream>
using namespace std;
void merge(int a[],int left,int mid,int right)
{
    int *tmp = new int [right - left + 1];
    int i = left,j = mid,k = 0;
    while(i < mid and j <= right)
    {
        if(a[i] <= a[j]) tmp[k++] = a[i++];
        else tmp[k++] = a[j++];
    }
    while(i < mid) tmp[k++] = a[i++];
    while(j <= right) tmp[k++] = a[j++];
    for(i = 0,k = left;k <= right;) a[k++] = tmp[i++];
    delete []tmp;
}
void mergeSort(int a[],int left,int right)
{
    if(left >= right) return ;
    int mid = left + (right - left) / 2;
    mergeSort(a,left,mid);
    mergeSort(a,mid + 1,right);
    merge(a,left,mid + 1,right);
}
int find(int a[],int x,int left,int right)
{
    if(left > right) return -1;
    int mid = left + (right - left) / 2;
    if(x == a[mid]) return mid;
    else if(x < a[mid]) return find(a,x,left,mid - 1);
    else return find(a,x,mid + 1,right);
}
int main()
{
    int n;
    cin >> n;
    int *a = new int [n];
    int *b = new int [n];
    for(int i = 0;i < n;i ++)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    mergeSort(b,0,n - 1);
    // for(int i = 0;i < n;i++)
    // {
    //     cout << b[i] << " ";
    // }
    int *c = new int [n];
    c[0] = b[0];
    int i = 1,j = 0;
    for(;i < n;i++)
    {
        if(c[j] != b[i]) c[++j] = b[i];
    }
    for(int i = 0;i < n;i++)
    {
        int result = find(c,a[i],0,j);
        cout << result + 1 << " ";
    }
    cout << endl;
    return 0;   
}