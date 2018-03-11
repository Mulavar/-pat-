#include <cstdio>
#include <vector>

using namespace std;
const int MAXN = 10010;
const int INF = 1000000000;
int G[MAXN][MAXN];
vector<int> vec[MAXN], tmpPath, path;
bool visited[MAXN];
int m, n, k, minTrans = INF, minD = INF;

int getTrans(vector<int> tmp){
	int line = 0, trans = 0;
	for(int i=1;i<tmp.size();i++){
		int v1 = tmp[i-1], v2 = tmp[i];
		if(G[v1][v2]!=line){
			if(line!=0){
				trans++;
			}
			line = G[v1][v2];
		}
	}
	return trans;
}
void DFS(int p1, int p2, int d){
	tmpPath.push_back(p1);
	visited[p1] = true;
	if(p1==p2){
		if(d<minD){
			minD = d;
			minTrans = getTrans(tmpPath);
			path = tmpPath;
		}
		else if(d==minD){
			int trans = getTrans(tmpPath);
			if(trans<minTrans){
				minTrans = trans;
				path = tmpPath;
			}
		}
		tmpPath.pop_back();
		visited[p1] = false;
		return ;
	}
	
	for(int i=0;i<vec[p1].size();i++){
		if(visited[vec[p1][i]]==false){
			DFS(vec[p1][i], p2, d+1);
		}
	}
	tmpPath.pop_back();
	visited[p1] = false;
}

void printLine(vector<int> Path){
	int line = 0;
	int st = Path[0];
	printf("%d\n", minD);
	for(int i=1;i<Path.size();i++){
		int v1 = Path[i-1];
		int v2 = Path[i];
		if(G[v1][v2]!=line){
			if(line!=0){
				printf("Take Line#%d from %04d to %04d.\n", line, st, Path[i-1]);
				line = G[i-1][i];
				st = Path[i-1];
			}
			line = G[v1][v2]; 
		}
	}
	printf("Take Line#%d from %04d to %04d.\n", line, st, Path[path.size()-1]);
	
}

int main(){
	FILE *fp = fopen("data.txt", "r");
	fscanf(fp, "%d", &n);
	for(int i=0;i<n;i++){
		int pre, cur;
		fscanf(fp, "%d%d", &m, &pre);
		for(int j=1;j<m;j++){
			fscanf(fp, "%d", &cur);
			vec[pre].push_back(cur);
			vec[cur].push_back(pre);
			G[pre][cur] = G[cur][pre] = i + 1;
			pre = cur;
		}
	}
	
	
	fscanf(fp, "%d", &k);
	for(int i=0;i<k;i++){
		int q1, q2;
		fscanf(fp, "%d%d", &q1, &q2);
		minTrans = INF, minD = INF;
		tmpPath.clear();
		path.clear();
		fill(visited, visited+MAXN, false);
		DFS(q1, q2, 0);
		
		printLine(path);
	}
} 
