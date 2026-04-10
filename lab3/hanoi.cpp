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
        getline(cin, input);
        if (input == "Q") {
            break;
        }

        // TODO
        if(!isInputValid (input))
        {
            continue;
        }
        Board board(input[0] - '0');
        board.draw();
        while(true)
        {
            cout << "Move a disk. Format: x y" << endl;
            int x,y;
            cin >> x >> y;
            if(x == 0 and y == 0)
            {
                board.autoplay();
                cout << "Congratulations! You win!" << endl;
                break;
            }
            board.move(x,y);
            board.draw();
            if(board.win())
            {
                cout << "Congratulations! You win!" << endl;
                break;
            }
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        // unfinished
    }
    return 0;
}
