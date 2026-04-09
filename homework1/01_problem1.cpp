#include <iostream>
using namespace std;
template <class T>
class link
{
    private:
    struct node
    {
        node *pre;
        int num;
        node *next;
        node(const T&x,node *n = nullptr,node *p = nullptr)
    {
        num = x;
        next = n;
        pre = p;
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
    if(curr) curr->pre = head;
}
int max_num(int m,int n)
{
    return m > n ? m : n;
}
int main(){
    int m,n;
    cin >> m >> n;
    link<int> l1 ,l2;
    for(int i = 0;i < m ;i++)
    {
        int x;
        cin >> x;
        l1.addfirst(x);
    }
    for(int i = 0;i < n ;i++)
    {
        int x;
        cin >> x;
        l2.addfirst(x);
    }
    link<int> result;
    int carry = 0;
    auto p1 = l1.gethead();
    auto p2 = l2.gethead();
    for(int i = 0;i < max_num(m,n);i++)
    {
        int a = 0,b = 0;
        if(p1)
        {
            a = p1->num;
            p1 = p1->next;
        }
        if(p2)
        {
            b = p2->num;
            p2 = p2->next;
        }
        int sum = a + b + carry;
        result.addfirst(sum % 10);
        carry = sum / 10;
    }
    if(carry)
    {
        result.addfirst(carry);
    }
    auto p = result.gethead();
    while(p)
    {
        cout << p->num << " ";
        p = p->next;
    }
    return 0;
}