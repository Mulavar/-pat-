#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
struct Node{
	int x, y, z;
};
int m, n, l, T, G[65][1300][130], sum = 0;
int num = 0;
queue<Node> q;
int X[6] = {1, -1, 0, 0, 0, 0};
int Y[6] = {0, 0, 1, -1, 0, 0};
int Z[6] = {0, 0, 0, 0, 1, -1};
void BFS(int x, int y, int z){
	G[x][y][z] = 2;
	num += 1;
	Node node;
	node.x = x;
	node.y = y;
	node.z = z;
	q.push(node);
	while(!q.empty()){
		Node tmp = q.front();
		q.pop();
		for(int i=0;i<6;i++){
			int x1 = tmp.x + X[i];
			int y1 = tmp.y + Y[i];
			int z1 = tmp.z + Z[i];
			if(x1<l&&x1>=0&&y1<m&&y1>=0&&z1<n&&z1>=0){
				if(G[x1][y1][z1]==1){
					G[x1][y1][z1] = 2;
					node.x = x1;
					node.y = y1;
					node.z = z1;
					q.push(node);
					num += 1;
				}
			}
			
		}
	}
	
}

int main(){
	FILE *fp = fopen("data.txt", "r");
	fscanf(fp, "%d%d%d%d", &m, &n, &l, &T);
	for(int i=0;i<l;i++){
		for(int j=0;j<m;j++){
			for(int k=0;k<n;k++){
				fscanf(fp, "%d", &G[i][j][k]);
			}
		}
	}
	
	
	
	for(int i=0;i<l;i++){
		for(int j=0;j<m;j++){
			for(int k=0;k<n;k++){
				if(G[i][j][k]==1){
					num = 0;
					BFS(i, j, k);
					if(num>=T){
						sum += num;
					}
				}
			}
		}
	}
	printf("%d\n", sum);
}
