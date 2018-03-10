#include <cstdio>
#include <vector>
#include <cstring> 
#include <string>
#include <cstdlib> 
#include <algorithm>
using namespace std;
const int MAXN = 10010;
struct Fd{
	int a, b;
};
int G[MAXN][MAXN];
int n, m, k;

vector<int> fd[MAXN];
char s1[7], s2[7];

bool cmp(Fd f1, Fd f2){
	if(f1.a!=f2.a){
		return f1.a < f2.a;
	}
	return f1.b < f2.b;
}
int main(){
	FILE *fp = fopen("data.txt", "r");
	fscanf(fp, "%d%d", &n, &m);
	for(int i=0;i<m;i++){
		fscanf(fp, "%s%s", s1, s2);
		int id1 = abs(atoi(s1));
		int id2 = abs(atoi(s2));
		G[id1][id2] = G[id2][id1] = 1;
		if(strlen(s1)==strlen(s2)){
			fd[id1].push_back(id2);
			fd[id2].push_back(id1);
		}
	}
	fscanf(fp, "%d", &k);
	for(int i=0;i<k;i++){
		vector<Fd> ans;
		fscanf(fp, "%s%s", s1, s2);
		int q1 = abs(atoi(s1));
		int q2 = abs(atoi(s2));
		for(int j=0;j<fd[q1].size();j++){
			for(int l=0;l<fd[q2].size();l++){
				if(fd[q1][j]==q2||q1==fd[q2][l]) continue;
				if(G[fd[q1][j]][fd[q2][l]]==1){
					Fd node;
					node.a = fd[q1][j];
					node.b = fd[q2][l];
					ans.push_back(node);
				}
			}
		}
		sort(ans.begin(), ans.end(), cmp);
		printf("%d\n", ans.size());
		for(int j=0;j<ans.size();j++){
			printf("%04d %04d\n", ans[j].a, ans[j].b);
		}
	}
	
	
}
