#include <cstdio>
#include <vector>
using namespace std;
const int MAXN = 510;
const int INF = 100000000;
int d[MAXN], c[MAXN], G[MAXN][MAXN], C[MAXN][MAXN];
int n, m, v1, v2, ow, length, time, pt[MAXN];
bool visited[MAXN];
int pre[MAXN], pre1[MAXN];
void dijkByDis(int st){
	fill(d, d+MAXN, INF);
	fill(c, c+MAXN, INF);
	fill(pre, pre+MAXN, -1);
	fill(visited, visited+MAXN, false);
	d[st] = 0;
	c[st] = 0;
	pre[st] = st;
	
	for(int i=0;i<n;i++){
		int u = -1, MIN = INF;
		for(int j=0;j<n;j++){
			if(visited[j]==false&&d[j]<MIN){
				MIN = d[j];
				u = j;
			}
		}
		
		if(u==-1) return;
		visited[u] = true;
		for(int v=0;v<n;v++){
			if(visited[v]==false&&G[u][v]!=0){
				if(d[u]+G[u][v]<d[v]){
					d[v] = G[u][v] + d[u];
					c[v] = c[u] + C[u][v];
					pre[v] = u;
				}
				else if(d[u]+G[u][v]==d[v]){
					if(c[u]+C[u][v]<c[v]){
						c[v] = c[u] + C[u][v];
						pre[v] = u;
					}
				}
			}
			
		}
	}
}

void dijkByTime(int st){
	fill(c, c+MAXN, INF);
	fill(pt, pt+MAXN, INF);
	fill(pre1, pre1+MAXN, -1);
	fill(visited, visited+MAXN, false);
	c[st] = 0;
	pt[st] = 0;
	pre1[st] = st;
	for(int i=0;i<n;i++){
		
		int u = -1, MIN = INF;
		for(int j=0;j<n;j++){
			if(visited[j]==false&&c[j]<MIN){
				MIN = c[j];
				u = j;
			}
		}
		
		if(u==-1) return;
		visited[u] = true;
		for(int v=0;v<n;v++){
			if(visited[v]==false&&C[u][v]!=0){
				if(c[u]+C[u][v]<c[v]){
					c[v] = c[u] + C[u][v];
					pre1[v] = u;
					pt[v] = pt[u] + 1;
				}
				else if(c[u]+C[u][v]==c[v]){
					if(pt[v]>pt[u]+1){
						pre1[v] = u;
						pt[v] = pt[u] + 1;
					}
				}
			}
			
		}
	}
}

bool isSame(int ed){
	int k = ed;
	while(pre[k]!=k){
		if(pre[k]!=pre1[k]){
			return false;
		}
		k = pre[k];
	}
	return true;
}

void printPath(int path[], int st, int ed){
	if(ed==st){
		printf("%d", st);
		return ;
	}
	printPath(path, st, path[ed]);
	printf(" -> %d", ed);
}

int main(){
	FILE *fp = fopen("data.txt", "r");
	
	fscanf(fp, "%d%d", &n, &m);
	for(int i=0;i<m;i++){
		fscanf(fp, "%d%d%d%d%d", &v1, &v2, &ow, &length, &time);
		G[v1][v2] = length;
		C[v1][v2] = time;
		if(ow==0){
			G[v2][v1] = length;
			C[v2][v1] = time;
		}
		
	}
	
	int st, ed;
	fscanf(fp, "%d%d", &st, &ed);
	dijkByDis(st);
	dijkByTime(st);
	if(isSame(ed)){
		printf("Distance = %d; Time = %d: ", d[ed], c[ed]);
		printPath(pre, st, ed);
	}
	else{
		printf("Distance = %d: ", d[ed]);
		printPath(pre, st, ed);
		printf("\nTime = %d: ", c[ed]);
		printPath(pre1, st, ed);
	}
}
