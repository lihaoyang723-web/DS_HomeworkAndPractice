#include <iostream>
using namespace std;
class priorityQueue
{   
    private:
        int currentsize;
        int *array;
        int maxsize;
        void percolateDown(int hole);
    public:
        priorityQueue():currentsize(0),maxsize(0),array(nullptr){}
        priorityQueue(int n):currentsize(0),maxsize(n)
        {
            array = new int [n + 1];
        }
        ~priorityQueue(){ delete []array;}
        void enQueue(int x);
        void deQueue();
        bool isempty(){return currentsize == 0;}
};
void priorityQueue::enQueue(int x)
{
    if (isempty())
    {
        array[1] = x;
        currentsize = 1;
        return ;
    }
    int hole = ++currentsize;
    for(;hole > 1 and x < array[hole / 2];hole /= 2)
    {
        array[hole] = array[hole / 2];
    }
    array[hole] = x;
}
void priorityQueue::percolateDown(int hole)
{
    int child;
    int tmp = array[hole];
    for(;hole * 2 <= currentsize;hole = child)
    {
        child = hole * 2;
        if(child != currentsize and array[child + 1] < array[child]) child ++;
        if(array[child] < tmp) array[hole] = array[child];
        else break;
    }
    array[hole] = tmp;
}
void priorityQueue::deQueue()
{
    if (isempty()) return ;
    int minItem;
    minItem = array[1];
    array[1] = array[currentsize --];
    percolateDown(1);
    cout << minItem << endl;
    return ;
} 
int main()
{   
    int n;
    cin >> n;
    priorityQueue s(n);
    while(n--)
    {
        int flag,num;
        cin >> flag;
        if(flag == 2) s.deQueue();
        else 
        {
            cin >> num;
            s.enQueue(num);
        }
    }
    return 0;
}