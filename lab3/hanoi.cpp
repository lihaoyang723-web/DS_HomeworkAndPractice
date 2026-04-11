#include <climits>
#include <iostream>
#include <limits>
#include <string>
#include "board.h"

using namespace std;

bool isInputValid(const string &input)
{
    return input.size() == 1 and input[0] >= '1' and input[0] <= '5';
}

int main() {
    while (true) {
        cout << "How many disks do you want? (1 ~ 5)" << endl;
        string input;
        if (!getline(cin, input)) {
            break;
        }
        
        if (input == "Q") {
            break;
        }

        if(!isInputValid (input)) {
            continue;
        }
        
        Board board(input[0] - '0');
        board.draw();
        
        while(true) {
            cout << "Move a disk. Format: x y" << endl;
            int x,y;
            
            if (!(cin >> x >> y)) {
                if (cin.eof()) {
                    return 0; 
                }
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                board.draw();
                continue;
            }
            
            if(x == 0 and y == 0) {
                board.autoplay();
                cout << "Congratulations! You win!" << endl;
                break;
            }
            if(!(x > 0 and x <= 3 and y > 0 and y <= 3 and x != y)) {
                board.draw();
                continue;
            }
            board.move(x,y);
            board.draw();
            
            if(board.win()) {
                cout << "Congratulations! You win!" << endl;
                break;
            }
        }
        // 修复3：跳过换行符前，检查一下是否已经 EOF
        if (!cin.eof()) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return 0;
}