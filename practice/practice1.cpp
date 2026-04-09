#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    if (n == 1) 
    {
        cout << "No" << endl;
        return 0;
    }
    if (n == 2)
    {
        cout << "Yes" << endl;
        return 0;
    }
    for(int i = 3;i * i < n;i += 2)
    {
        if (n % i == 0) 
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}