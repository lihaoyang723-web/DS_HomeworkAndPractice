#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> a (n + 1);
    for(int i = 1;i <= n ;i++)
    {
        cin >> a[i];
    }
    vector<int> result(n + 1);
    stack<int> tmp;
    for(int i = n;i >= 1;i--)
    {
        while(!tmp.empty() and a[tmp.top()] <= a[i])
        {
            tmp.pop();
        }
        if(tmp.empty()) result[i] = 0;
        else result[i] = tmp.top();
        tmp.push(i);
    }
    for(int i = 1;i <= n;i++)
    {
        cout << result[i] << " ";
    }
    cout <<endl;
    return 0;
}