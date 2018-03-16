#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
const int MAXN = 1010;
vector<int> node[MAXN];
int n, m, k, id;
bool visited[MAXN];

int BFS(int u, int d){
	queue<int> q;
	q.push(u);
	visited[u] = true;
	int last = 1, cur = 0, layer = 0, ans = 0;
	while(!q.empty()&&layer<d){
		int p = q.front();
		q.pop();
		last--;
		
		for(int i=0;i<node[p].size();i++){
			if(visited[node[p][i]]==false){
				ans++;
				visited[node[p][i]] = true;
				q.push(node[p][i]);
				cur++;
			} 
			
		} 
		
		if(last==0){
			last = cur;
			cur = 0;
			layer += 1;
		}
	}
	return ans;
}

int main(){
	
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++){
		scanf("%d", &k);
		for(int j=0;j<k;j++){
			scanf("%d", &id);
			node[id].push_back(i);
		}
	}
	
	scanf("%d", &k);
	for(int i=0;i<k;i++){
		scanf("%d", &id);
		fill(visited, visited+n+1, false);
		int ans = BFS(id, m);
		printf("%d\n", ans);
	}
}
