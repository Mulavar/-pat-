#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
const int MAXN = 510;
const int INF = 10000000;
int G[MAXN][MAXN], weight[MAXN], w[MAXN], d[MAXN], num[MAXN];
int n, m, st, ed, v1, v2, dis;
bool visited[MAXN];

void dijkstra(int s){
	fill(visited, visited+n, false);
	fill(d, d+n, INF);
	d[s] = 0;
	w[s] = weight[s];
	num[s] = 1;
	for(int i=0;i<n;i++){
		int u = -1, MIN = INF;
		for(int j=0;j<n;j++){
			if(visited[j]==false&&d[j]<MIN){
				MIN = d[j];
				u = j;
			}
		}
		
		if(u==-1) return ;
		visited[u] = true;
		for(int v=0;v<n;v++){
			if(visited[v]==false&&G[u][v]!=0){
				if(d[u]+G[u][v]<d[v]){
					d[v] = d[u] + G[u][v];
					w[v] = w[u] + weight[v];
					num[v] = num[u];
				}
				else if(d[u]+G[u][v]==d[v]){
					if(w[u]+weight[v]>w[v]){
						w[v] = w[u] + weight[v];
					}
					num[v] += num[u];
				}
			}
		}
	}
}
int main(){
//	freopen("data.txt", "r", stdin);
	scanf("%d%d%d%d", &n, &m, &st, &ed);
	for(int i=0;i<n;i++){
		scanf("%d", &weight[i]);
	}
	for(int i=0;i<m;i++){
		scanf("%d%d%d", &v1, &v2, &dis);
		G[v1][v2] = G[v2][v1] = dis;
	}
	dijkstra(st);
	printf("%d %d\n", num[ed], w[ed]);
	
} 
