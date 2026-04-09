#include <climits>
#include <iostream>
#include <string>

#include "board.h"

using namespace std;

bool isInputValid(const string &input)
{
    return input.size() == 1 and input[0] >= '1' and input[0] <= 5;
}
int main() {
    while (true) {
        cout << "How many disks do you want? (1 ~ 5)" << endl;
        string input;
        getline(cin, input);
        if (input == "Q") {
            break;
        }

        // TODO
        if(!isInputValid (input))
        {
            continue;
        }
        else
        {
            
        }
    }
    return 0;
}
