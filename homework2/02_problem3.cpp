#include <iostream>
#include <deque>
int buy(char bought) {
    if (bought == 'a') return 3;
    if (bought == 'b') return 6;
    if (bought == 'c') return 9;
    return 0;
}
int main() {
    int id;
    char bought;
    int n;
    
    std::cin >> id >> bought >> n;
    
    int limit = buy(bought);
    std::deque<int> dq; 
    int current_success_in_window = 0;

    for (int i = 0; i < n; i++) 
    {
        int x;
        std::cin >> x;
        if (dq.size() == 10) {
            if (dq.front() == 1) {
                current_success_in_window--;
            }
            dq.pop_front();
        }
        if (x != id) 
        {
            std::cout << 0;
            dq.push_back(0); 
        } 
        else {
            if (current_success_in_window < limit) {
                std::cout << 1;
                dq.push_back(1); 
                current_success_in_window++;
            } else {
                std::cout << -1;
                dq.push_back(-1); 
            }
        }
        if (i < n - 1) std::cout << " ";
    }

    return 0;
}