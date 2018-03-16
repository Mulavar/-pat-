#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXN = 110;
struct Node{
	int w;
	vector<int> child;
}node[MAXN];
int n, m, weight, id, k;
vector< vector<int> > ans;
vector<int> tmpPath;

bool cmp(int v1, int v2){
	return node[v1].w > node[v2].w;
}

void DFS(int u, int sum){
	sum += node[u].w;
	tmpPath.push_back(u);
	if(sum==weight){
		if(node[u].child.size()==0)
			ans.push_back(tmpPath);
	}
	else if(sum<weight){
		for(int i=0;i<node[u].child.size();i++){
			DFS(node[u].child[i], sum);
		}
	}
	
	tmpPath.pop_back();
	return ;
	
}

int main(){
	freopen("data.txt", "r", stdin);
	scanf("%d%d%d", &n, &m, &weight);
	for(int i=0;i<n;i++){
		scanf("%d", &node[i].w);
	}
	
	for(int i=0;i<m;i++){
		scanf("%d%d", &id, &k);
		for(int j=0;j<k;j++){
			int tmp;
			scanf("%d", &tmp);
			node[id].child.push_back(tmp);
		}
		sort(node[id].child.begin(), node[id].child.end(), cmp);
	} 
	
	DFS(0, 0);
	for(int i=0;i<ans.size();i++){
		vector<int> tmp = ans[i];
		int sz = tmp.size();
		for(int j=0;j<tmp.size();j++){
			int id = tmp[j];
			printf("%d", node[id].w);
			if(j<sz-1){
				printf(" ");
			}
		}
		printf("\n");
	}
}
