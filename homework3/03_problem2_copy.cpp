#include<iostream>
#include<queue>
using namespace std;
namespace IO_ReadWrite{
	template <typename T>
	inline void read(T &x){
		x=0; T f=1; char c=getchar();
		while(c<'0'||c>'9'){if(c=='-') f=-1; c=getchar();}
		while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48); c=getchar();}
		x*=f; return;
	}
	
	template<typename T>
	inline void write(T x){
		if(x<0) putchar('-'), x=-x;
		if(x>9) write(x/10);
		putchar('0'+x%10);
	}
	template <typename T>
	inline void writeln(T x){write(x); putchar('\n');}
}
using namespace IO_ReadWrite;
const int maxn=1e5+10;
struct Node{
	int id;
	int val;
	Node *left;
	Node *right;
	Node *next;
	Node (int id) : id(id),val(0), left(nullptr), right(nullptr),next(nullptr){}
	Node(int id,int x) : id(id),val(x), left(nullptr), right(nullptr),next(nullptr){}
	Node(int id,int x, Node *l,Node *r): id(id),val(x), left(l), right(r),next(nullptr){}
};
Node *tr[maxn];
int n,ind[maxn];
int main(){
	read(n);
	for(int i=1;i<=n;i++) tr[i]=new Node(i);
	for(int i=1,v,l,r;i<=n;i++){
		read(v),read(l),read(r);
		tr[i]->val=v;
		if(l) tr[i]->left=tr[l],ind[l]++;
		if(r) tr[i]->right=tr[r],ind[r]++;
	}
	queue<Node *>q;
	for(int i=1;i<=n;i++) if(!ind[i]){
		q.push(tr[i]);
		break;
	}
	while(!q.empty()){
		int siz=q.size();
		Node *prev=nullptr;
		for(int i=1;i<=siz;i++){
			Node *cur=q.front(); q.pop();
            
			if(prev) prev->next=cur;
			prev=cur;
			if(cur->left) q.push(cur->left);
			if(cur->right) q.push(cur->right);
		}
	}
	for(int i=1;i<=n;i++){
		if(tr[i]->next) writeln(tr[i]->next->id);
		else writeln(0);
	}
	return 0;
}