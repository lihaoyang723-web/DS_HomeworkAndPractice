#include <iostream>
using namespace std;
struct node
{
    int level;
    int time;
    int num;
    node(){}
    node(int level,int time,int num):level(level),time(time),num(num){}
};
void merge(node a[],int left,int mid,int right)
{
    node *tmp = new node [right - left + 1];

    int i = left,j = mid,k = 0;
    while(i < mid and j <= right)
    {
        if(a[i].level > a[j].level) tmp[k ++] = a[i++];
        else if(a[i].level < a[j].level) tmp[k++] = a[j++];
        else 
        {
            if(a[i].time <= a[j].time) tmp[k++] = a[i++];
            else tmp[k++] = a[j++];
        }
    }
    while (i < mid) tmp[k++] = a[i++];
    while(j <= right) tmp [k++] = a[j++];
    for(i = 0,k = left;k <= right;) a[k++] = tmp[i++];
    delete []tmp;
}
void mergeSort(node a[],int left,int right)
{
    if(left >= right) return ;
    int mid = left + (right - left) / 2;
    mergeSort(a,left,mid);
    mergeSort(a,mid + 1,right);
    merge(a,left,mid + 1,right);
}    
int main()
{
    int n;
    cin >> n;
    node *arr = new node[n];
    for(int i = 0;i < n;i++)
    {
        int l,t;
        cin >> l >> t;
        arr[i] = node(l,t,i + 1);
    }
    mergeSort(arr,0,n - 1);
    for(int i = 0;i < n ;i++) cout << arr[i].num << endl;
    return 0;
}