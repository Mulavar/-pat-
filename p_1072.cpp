#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAXN = 1050;
const int INF = 100000000;
int G[MAXN][MAXN], d[MAXN];
int minD = 0, tmpSum = 0, tmpMin = INF, sum = INF; 
bool visited[MAXN], flag;
int n, m, k, r;

int str2int(char str[], int len){
	if(str[0]!='G'){
		return atoi(str);
	}
	int res = 0;
	for(int i=1;i<len;i++){
		res = res * 10 + (str[i] - '0');
	}
	res += n;
	return res;
}

void dijkstra(int st){
	fill(d, d+n+m+1, INF);
	fill(visited, visited+n+m+1, false);
	tmpMin = INF;
	tmpSum = 0;
	flag = true;
	d[st] = 0;
	for(int i=1;i<=n+m;i++){
		int u = -1, MIN = INF;
		for(int j=1;j<=n+m;j++){
			if(visited[j]==false&&d[j]<MIN){
				MIN = d[j];
				u = j;
			}
		}
		if(u==-1){
			return ;
		}
		
		if(u>=1&&u<=n){
			if(d[u]>r){
				flag = false;
				return ;
			}
			tmpSum += d[u];
			if(d[u]<tmpMin){
				tmpMin = d[u];
			}
		}
		visited[u] = true;
		for(int v=1;v<=n+m;v++){
			if(visited[v]==false&&G[u][v]!=0){
				if(d[u]+G[u][v]<d[v]){
					d[v] = d[u] + G[u][v];
				}
			}
		}
	}
}
int main(){
	FILE *fp = fopen("data.txt", "r");
	
	scanf("%d%d%d%d", &n, &m, &k, &r);
	for(int i=0;i<k;i++){
		char v1[10], v2[10];
		int dis;
		scanf("%s%s%d", v1, v2, &dis);
		int len1 = strlen(v1);
		int len2 = strlen(v2);
		int c1 = str2int(v1, len1);
		int c2 = str2int(v2, len2);
		G[c1][c2] = G[c2][c1] = dis;
	}
	
	bool exist = false;
	int id;
	for(int i=1;i<=m;i++){
		dijkstra(n+i);
		if(flag==true){
			exist = true;
			if(tmpMin>minD){
				sum = tmpSum;
				minD = tmpMin;
				id = i;
			}
			else if(tmpMin==minD){
				if(tmpSum<sum){
					sum = tmpSum;
					minD = tmpMin;
					id = i;
				}
			}
		}
	}
	
	if(exist==false){
		printf("No Solution\n");
	}
	else{
		printf("G%d\n", id);
		printf("%.1f %.1f\n", minD*1.0, (sum*1.0/n));
	}
	
}
