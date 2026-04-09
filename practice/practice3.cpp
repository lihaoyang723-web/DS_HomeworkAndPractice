#include <iostream>
using namespace std;
int factorial(int k)
{
    if (k == 0 or k == 1) return 1;
    if (k < 0) 
    {
        throw invalid_argument("k must be greater than 0!");
        return 0;
    }
    return k * factorial(k - 1);
}
int main(){
    int k;
    cin >> k;
    int sum = 0,start = 1;
    for(int i = 1;i <= k;i++)
    {   
        start *= i;
        sum += start;
    }
    cout << sum << endl;
    return 0;
}