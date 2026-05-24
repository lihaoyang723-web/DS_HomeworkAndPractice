#include <iostream>
using namespace std;
struct node
{
    int id;
    int a;
    int b;
    int total;
    node(){}
    node(int id,int a,int b):id(id),a(a),b(b),total(a + b){}
};  
void merge(node a[],int left,int mid,int right)
{
    node *tmp = new node [right - left + 1];
    int i = left,j = mid,k = 0;
    while(i < mid and j <= right) 
    {
        if(a[i].total > a[j].total) tmp[k++] = a[i++];
        else if(a[i].total < a[j].total) tmp[k++] = a[j++];
        else 
        {
            if(a[i].b > a[j].b) tmp[k++] = a[i++];
            else if(a[i].b < a[j].b) tmp[k++] = a[j++];
            else
            {
                if(a[i].id < a[j].id) tmp[k++] = a[i++];
                else tmp[k++] = a[j++];
            }
        }
    }
    while(i < mid) tmp[k++] = a[i++];
    while(j <= right) tmp[k++] = a[j++];
    for(i = 0,k = left;k <=right;) a[k++] = tmp[i++];
    delete []tmp;
}
void mergeSort(node a[],int left,int right)
{
    if(left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(a,left,mid);
    mergeSort(a,mid + 1,right);
    merge(a,left,mid + 1,right);
}
int main()
{
    int n;
    cin >> n;
    int id,a,b;
    node *t = new node [n];
    for(int i = 0;i < n ;i++)
    {
        cin >> id >> a >> b;
        t[i] = node(id,a,b);
    }
    mergeSort(t,0,n - 1);
    for(int i = 0;i < n;i++)
    {
        cout << t[i].id << " " << t[i].total << endl;
    }
    cout << endl;
    return 0;
}