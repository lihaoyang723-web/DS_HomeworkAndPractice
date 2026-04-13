#include <iostream>
int main(){
    int n;
    std::cin >> n;
    int *result = new int [n + 1];
    int val,lva,rva;
    for(int i = 0;i < n;i++)  std::cin >> val >> lva >> rva;
    int num = 2;
    for(int i = 1;i <= n;i++)
    {
        if(i == num - 1)
        {
            std::cout << 0 << std::endl;
            num *= 2;
        }
        else std::cout << i + 1 << std::endl;
    }
    delete []result;
    return 0;   
}