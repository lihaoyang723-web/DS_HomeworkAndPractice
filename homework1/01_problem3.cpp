#include <iostream>
using namespace std;

struct slink{
    int x;
    slink *next;
};

int main(){
    int m,n;
    cin >> m >> n;

    slink *headA = nullptr,*headB = nullptr,*headC = nullptr;
    slink *tmp1 = headA,*tmp2 = headB,*tmp3 = headC;

    for(int i = 0;i < m;i++)
    {
        int x;
        cin >> x;
        if(headA == nullptr) 
        {
            headA = new slink{x,nullptr};
            tmp1 = headA;
        }
        else if(tmp1->x != x)
        {
            tmp1->next = new slink{x,nullptr};
            tmp1 = tmp1->next;
        }
    }


    for(int i = 0;i < n;i++) 
    {
        int x;
        cin >> x;
        if(headB == nullptr) 
        {
            headB = new slink{x,nullptr};
            tmp2 = headB;
        }
        else if(tmp2->x != x) 
        {
            tmp2->next = new slink{x,nullptr};
            tmp2 = tmp2->next;
        }
    }

    tmp1 = headA; 
    tmp2 = headB; 

    while(tmp1 && tmp2) 
    {
        if(tmp1->x == tmp2->x)
        {
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }
        else if(tmp1->x < tmp2->x)
        {
            if(headC == nullptr) 
            {
                headC = new slink{tmp1->x,nullptr};
                tmp3 = headC;
            }
            else
            {
                tmp3->next = new slink{tmp1->x,nullptr};
                tmp3 = tmp3->next;
            }
            tmp1 = tmp1->next;
        }
        else
        {
            if(headC == nullptr)
            {
                headC = new slink{tmp2->x,nullptr};
                tmp3 = headC;
            }
            else
            {
                tmp3->next = new slink{tmp2->x,nullptr};
                tmp3 = tmp3->next;
            }
            tmp2 = tmp2->next;
        }
    }

    while(tmp1) 
    {
        if(headC == nullptr)
        {
            headC = new slink{tmp1->x,nullptr};
            tmp3 = headC;
        }
        else
        {
            tmp3->next = new slink{tmp1->x,nullptr};
            tmp3 = tmp3->next;
        }
        tmp1 = tmp1->next;
    }

    while(tmp2) 
    {
        if(headC == nullptr)
        {
            headC = new slink{tmp2->x,nullptr};
            tmp3 = headC;
        }
        else
        {
            tmp3->next = new slink{tmp2->x,nullptr};
            tmp3 = tmp3->next;
        }
        tmp2 = tmp2->next;
    }

    if(headC == nullptr)
    {
        cout<<"Empty";
        return 0;
    }

    while(headC)
    {
        cout<<headC->x;
        if(headC->next) cout<<" ";
        headC = headC->next;
    }

    return 0;
}