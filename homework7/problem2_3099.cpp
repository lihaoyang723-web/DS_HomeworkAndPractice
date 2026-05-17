// need to rewrite
#include <iostream>
using namespace std;
class priorityQueue{ 
    public:
        priorityQueue(int capacity = 1000);
        ~priorityQueue();
        void dequeue();
        void enqueue(int x);
        void getHead();
    private:
        int maxsize;
        int *array;
        int currentsize;
        void percolateDown(int hole);
        void doublespace();
};
priorityQueue::priorityQueue(int capacity):maxsize(capacity),currentsize(0)
{
    array = new int [capacity];
}
priorityQueue::~priorityQueue()
{
    delete []array;
}
void priorityQueue::getHead()
{
    if(currentsize == 0) 
    {
        cout << -1 << endl;
        return ;
    }
    cout << array[1] << endl;
}

void priorityQueue::doublespace()
{
    int *tmp = array;
    maxsize *= 2;
    array = new int [maxsize];
    for(int i = 1;i <= currentsize;i++)
    {
        array[i] = tmp [i];
    }
    delete []tmp;
}

void priorityQueue::enqueue(int x)
{   
    if(currentsize == maxsize) doublespace();
    int hole = ++ currentsize;
    for(;hole > 1 and x < array[hole /2];hole /= 2)
    {
        array[hole] = array [hole / 2];
    }
    array[hole] = x;
}

void priorityQueue::percolateDown(int hole)
{
    int tmp = array[currentsize --];
    int child;
    for(;hole * 2 <= currentsize;hole = child)
    {
        child = hole * 2;
        if(child != currentsize and array[child + 1] < array[child])
        {
            child ++;
        }
        if(array[child] < tmp) array[hole] = array[child];
        else break;
    }
    array[hole] = tmp;
}

void priorityQueue::dequeue()
{
    if(currentsize == 0)
    {
        cout << -1 << endl;
        return ;
    }
    int min = array[1];
    percolateDown(1);
    cout << min << endl;
}
int main(){
    int m;
    cin >> m;
    priorityQueue q;
    for(int i = 1;i <= m;i ++)
    {
        int flag,x;
        cin >> flag;
        if(flag == 1) 
        {
            cin >> x;
            q.enqueue(x);
            continue;
        }
        else if(flag == 2)
        {
            q.dequeue();
        }
        else q.getHead();
    }
    return 0;
}