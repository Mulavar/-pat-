#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>
#include <map>
using namespace std;
const int MAXN = 35;
struct Node{
	int l;
	int r;
}node[MAXN];

int n, pre[MAXN], in[MAXN], k1 = 0, k2 = 0, c = 0;
stack<int> s;
map<int, int> mp;
int create(int preL, int preR, int inL, int inR){
	if(preL>preR){
		return -1;
	}
	if(preL==preR){
		return pre[preL];
	}
	
	int idx = mp[pre[preL]];
	
	node[pre[preL]].l = create(preL+1, idx-inL+preL, inL, idx-1);
	node[pre[preL]].r = create(preR-inR+idx+1, preR, idx+1, inR);
	
	return pre[preL];
}

void postOrder(int root){
	if(root==-1){
		return ;
	}
	
	postOrder(node[root].l);
	postOrder(node[root].r);
	printf("%d", root);
	c++;
	if(c<n){
		printf(" ");
	}
}

void init(){
	for(int i=0;i<MAXN;i++){
		node[i].l = node[i].r = -1;
	}
}
int main(){
	init();
	
	scanf("%d", &n);
	for(int i=0;i<2*n;i++){
		char op[6];
		int num;
		scanf("%s", op);
		if(strcmp(op, "Push")==0){
			scanf("%d", &num);
			s.push(num);
			pre[k1++] = num;
		}
		else{
			num = s.top();
			s.pop();
			in[k2] = num;
			mp[num] = k2++;
 		}
	}
	int root = create(0, n-1, 0, n-1);
	
	postOrder(root);
}
