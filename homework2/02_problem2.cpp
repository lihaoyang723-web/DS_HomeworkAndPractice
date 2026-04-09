#include <iostream>
#include <vector>
#include <stack>
int main(){
    int n;
    std::cin >> n;
    std::vector<int> in_rank(n);
    std::vector<int> out_rank(n);
    int x;
    for(int i = 0;i < n;i++)
    {
        std::cin >> in_rank[i];
    }
    for(int i = 0;i < n;i++)
    {
        std::cin >> out_rank[i];
    }
    std::stack<int> tmp;
    int out_index = 0;
    for(auto it = in_rank.begin();it != in_rank.end();it++)
    {
        tmp.push(*it);
        while(!tmp.empty() and tmp.top() == out_rank[out_index] and out_index < n)
        {
            tmp.pop();
            out_index ++;
        }
    }
    if(tmp.empty()) std::cout << "YES";
    else std::cout << "NO";
    return 0;
}