#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
const int MAXN = 110;
struct Node{
	int val;
	vector<int> child;
}node[MAXN];

int n, m, k, id, tmp;
vector<int> ans;

void BFS(){
	queue<Node> q;
	q.push(node[1]);
	Node p;
	int last = 1, cur = 0, leaves = 0;
	while(!q.empty()){
		p = q.front();
		q.pop();
		last--;
		
		if(p.child.size()==0){
			leaves++;
		}
		else{
			for(int i=0;i<p.child.size();i++){
				int e = p.child[i];
				q.push(node[e]);
				cur++;
			}
		}
		
		if(last==0){
			ans.push_back(leaves);
			leaves = 0;
			last = cur;
			cur = 0;
		}
	}
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i=0;i<m;i++){
		scanf("%d%d", &id, &k);
		for(int j=0;j<k;j++){
			scanf("%d", &tmp);
			node[id].child.push_back(tmp);
		}
	}
	BFS();
	
	int sz = ans.size();
	for(int i=0;i<sz;i++){
		printf("%d", ans[i]);
		if(i<sz-1){
			printf(" ");
		}
	}
}
