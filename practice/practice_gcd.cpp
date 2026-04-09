#include <iostream>
using namespace std;
int gcd(int x, int y){
    while(true)
    {
        int r = x % y;
        if (r == 0) break;
        x = y;
        y = r;
    }
    return y;
}