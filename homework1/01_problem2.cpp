#include <iostream>
using namespace std;
template <class T>
class link
{
    private:
    struct node
    {
        int num;
        node *next;
        node(const T&x,node *n = nullptr)
    {
        num = x;
        next = n;
    }
    };
    node *head;
    public:
    link();
    ~link(){clear();delete head;}
    void clear();
    void addfirst(int x);
    node* gethead(){return head;}
};
template <class T>
link<T>::link()
{
    head = nullptr;
}
template<class T>
void link<T>::clear()
{
    node *curr = head;
    while(curr)
    {
        node *tmp = curr;
        curr = curr -> next;
        delete tmp;
    }
    head = nullptr;
}
template <class T>
void link<T>::addfirst(int x)
{
    node *curr = head;
    head = new node(x);
    head->next = curr;
}
int max_num(int m,int n)
{
    return m > n ? m : n;
}
int main(){
    int n;
    cin >> n;
    link <int>l;
    for(int i = 0;i < n;i++)
    {
        int x;
        cin >> x;
        l.addfirst(x);
    }
    auto p = l.gethead();
    for(int i = 0;i < n;i++)
    {
        while(p)
        {
            cout << p->num << " ";
            p = p ->next;
        }
    }
    return 0;
}