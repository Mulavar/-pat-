#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
const int MAXN = 35;
struct Node{
	int l = -1, r = -1;
}node[MAXN];
map<int, int> mp;
int n, pre[MAXN], post[MAXN], k = 0;
bool flag = true;

int build(int preL, int preR, int postL, int postR){
	if(preL==preR) return preL;
	else if(preL>preR) return -1;
	
	int mid = mp[pre[preL+1]];
	if(mid-postL==preR-preL-1){
		flag = false;
	}
	node[preL].l = build(preL+1, preL+1+mid-postL, postL, mid);
	if(preR-preL-1>mid-postL){
		node[preL].r = build(preR-postR+mid+2, preR, mid+1, postR-1);
	}
	return preL;
} 

void levelOrder(int root){
	queue<int> q;
	q.push(root);
	int k = 0;
	
	while(!q.empty()){
		int p = q.front();
		q.pop();
		k++;
		printf("%d", p);
		if(k<n) printf(" ");
		
		if(node[p].l!=-1) q.push(node[p].l);;
		if(node[p].r!=-1) q.push(node[p].r);
	}	
	printf("\n");
}

void inOrder(int root){
	if(root==-1) return ;
	inOrder(node[root].l);
	printf("%d", pre[root]);
	k++;
	if(k<n) printf(" ");
	inOrder(node[root].r);
}

int main(){
	freopen("data.txt", "r", stdin);
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d", &pre[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d", &post[i]);
		mp[post[i]] = i;
	}
	
	int root = build(0, n-1, 0, n-1);
	if(flag) printf("Yes\n");
	else printf("No\n");
	inOrder(root);
	printf("\n");
} 
