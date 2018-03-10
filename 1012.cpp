#include <cstdio>
#include <algorithm>

using namespace std;
const int MAXN = 2010;
struct Stu{
	int id;
	int g[5];
}stu[MAXN];
int n, q;
int now, Rank[1000010][5];
char s[4] = {'A', 'C', 'M', 'E'};
bool cmp(Stu s1, Stu s2){
	return s1.g[now] > s2.g[now];
}

int main(){
	scanf("%d%d", &n, &q);	
	for(int i=0;i<n;i++){
		Stu tmp;
		scanf("%d %d %d %d", &tmp.id, &tmp.g[1], &tmp.g[2], &tmp.g[3]);
		tmp.g[0] = (tmp.g[1] + tmp.g[2] + tmp.g[3]) / 3;
		stu[i] = tmp;
	}
	
	for(int i=0;i<4;i++){
		now = i;
		sort(stu, stu+n, cmp);
		int r = 1;
		for(int j=0;j<n;j++){
			if(j>0&&stu[j].g[now]!=stu[j-1].g[now]){
				r = j + 1;
			}
			Rank[stu[j].id][now] = r;
		}
	}
	
	for(int i=0;i<q;i++){
		int id, idx = 0, MIN = n + 1;
		scanf("%d", &id);
		if(Rank[id][0]==0){
			printf("N/A\n");
			continue;
		}
		for(int j=0;j<4;j++){
			if(Rank[id][j]<MIN){
				MIN = Rank[id][j];
				idx = j;
			}
		}
		printf("%d %c\n", Rank[id][idx], s[idx]);
	}
} 
