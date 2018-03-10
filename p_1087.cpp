#include <cstdio>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;
const int MAXN = 210;
const int INF = 1000000000;
int n, m, dis, r1, r2;
int w[MAXN], G[MAXN][MAXN], d[MAXN], h[MAXN], num[MAXN], pre[MAXN], pt[MAXN];
bool visited[MAXN];
map<string, int> city2idx;
map<int, string> idx2city;

void dijkstra(int st){
	fill(d, d+MAXN, INF);
	fill(pre, pre+MAXN, -1);
	d[st] = 0;
	h[st] = w[st];
	num[st] = 1;
	pre[st] = st;
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
					h[v] = h[u] + w[v];
					num[v] = num[u];
					pt[v] = pt[u] + 1;
					pre[v] = u;
				}
				else if(d[u]+G[u][v]==d[v]){
					num[v] += num[u];
					if(h[u]+w[v]>h[v]){
						h[v] = h[u] + w[v];
						pre[v] = u;
						pt[v] = pt[u] + 1;
					}
					else if(h[u]+w[v]==h[v]){
						double avgu = h[v] * 1.0 / (pt[u] + 1);
						double avgv = h[v] * 1.0 / pt[v];
						if(avgu>avgv){
							pre[v] = u;
							pt[v] = pt[u] + 1;
						}
						
					}
					
				}
			}
		}
	}
}

void printPath(int v){
	if(v==0){
		cout<<idx2city[v];
		return ;
	}
	printPath(pre[v]);
	cout<<"->"<<idx2city[v];
}

int main(){
	
	string start, city1, city2, city;
	cin>>n>>m>>start;
	city2idx[start] = 0;
	idx2city[0] = start;
	for(int i=1;i<n;i++){
		cin>>city>>w[i];
		city2idx[city] = i;
		idx2city[i] = city;
	}
	for(int i=0;i<m;i++){
		cin>>city1>>city2>>dis;
		int c1 = city2idx[city1];
		int c2 = city2idx[city2];
		G[c1][c2] = G[c2][c1] = dis;
	}
	
	dijkstra(0);
	int id = city2idx["ROM"];
	printf("%d %d %d %d\n", num[id], d[id], h[id], h[id]/pt[id]);
	printPath(id);
}
