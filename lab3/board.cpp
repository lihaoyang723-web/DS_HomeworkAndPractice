#include <iostream>

#include "board.h"
#include "queue.h"

Board::Board(const int num_disk) : /* TODO */ num_disk(num_disk),rods{Rod(num_disk,0),Rod(num_disk,1),Rod(num_disk,2)},disks(nullptr){
    // TODO
    disks = new Disk[num_disk];
    for(int i = 0;i < num_disk;i++)
    {
        disks[i].id = i;
        disks[i].val = 2 * (num_disk - i) + 1;
    }
    history.push(std::pair<int, int>(0,0));
    for(int i = 0;i < num_disk;i++)
    {
        rods[0].push(disks[i]);
    }
}

Board::~Board() {
    // TODO
    delete[] disks;
}

void Board::draw() {
    Canvas canvas {};
    canvas.reset();
    for (int row = 0; row < Canvas::HEIGHT - 1; row++) {
        canvas.buffer[row][5] = '|';
        canvas.buffer[row][20] = '|';
        canvas.buffer[row][35] = '|';
    }
    for (int col = 0; col < Canvas::WIDTH; col++) {
        canvas.buffer[Canvas::HEIGHT - 1][col] = '-';
    }
    canvas.buffer[Canvas::HEIGHT - 1][5] = '|';
    canvas.buffer[Canvas::HEIGHT - 1][20] = '|';
    canvas.buffer[Canvas::HEIGHT - 1][35] = '|';

    rods[0].draw(canvas);
    rods[1].draw(canvas);
    rods[2].draw(canvas);
    canvas.draw();
}

void Board::move(int from, int to, const bool log) {
    // TODO
    if (from < 1 || from > static_cast<int>(ROD_SIZE) || to < 1 || to > static_cast<int>(ROD_SIZE)) return;
    if(from == to) return ;
    if(rods[from - 1].empty()) return ;
    if(log == true)
    {
        if(rods[to - 1].push(rods[from - 1].top()))
        {
            rods[from - 1].pop();
            history.push(std::pair<int,int>(from,to));
            return ;
        }
        else
            {
                return ;
            }
    }
    else
    {
        if(rods[to - 1].push(rods[from - 1].top()))
        {
            history.pop();
            rods[from - 1].pop();
        }
    }
}

bool Board::win() const {
    // TODO
    return rods[1].full();
}

void solve(
    const int n,
    const int src,
    const int buf,
    const int dest,
    Queue<std::pair<int, int>> &solution
) {
    if (n <= 0) {
        return;
    }

    solve(n - 1, src, dest, buf, solution);
    solution.push(std::pair<int, int>(src, dest));
    solve(n - 1, buf, src, dest, solution);
}

void Board::autoplay() {
    // TODO
    while(history.top() != std::pair<int,int>(0,0))
    {
        int verse_from = history.top().second,verse_to = history.top().first;
        move(verse_from,verse_to,false);
        std::cout << "Auto moving:" << verse_from << "->" << verse_to << std::endl;
        draw();
    }
    Queue<std::pair<int,int>> solution;
    solve(num_disk,1,3,2,solution);
    while(!solution.empty())
    {
        std::pair<int,int> tmp = solution.front();
        int from = tmp.first;
        int to = tmp.second;
        std::cout << "Auto moving:" << from << "->" << to << std::endl;
        move(from,to);
        draw();
        solution.pop();
    }
    // unfinished
}
