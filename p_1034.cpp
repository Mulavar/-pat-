#include <cstdio>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;
const int MAXN = 2010;
struct Node{
	int head;
	int member;
};
map<string, int> mp1;
map<int, string> mp2;

int n, k, w[MAXN], num = 0, tmp, G[MAXN][MAXN];
string s1, s2;
bool visited[MAXN];
vector<Node> ans;

bool cmp(Node n1, Node n2){
	return mp2[n1.head] < mp2[n2.head];
}

int str2int(string ss){
	if(mp1.find(ss)==mp1.end()){
		mp1[ss] = num;
		mp2[num] = ss;
		num++;
	}
	
	return mp1[ss];
}

void DFS(int u, int &m, int &head, int &total){
	if(w[u]>w[head]){
		head = u;
	}
	if(visited[u]==false){
		visited[u] = true;
		m += 1;
	}
	for(int i=0;i<num;i++){
		if(G[u][i]!=0){
			total += G[u][i];
			G[u][i] = G[i][u] = 0;
			DFS(i, m, head, total);
		}
	}
}

int main(){
	scanf("%d%d", &n, &k);
	for(int i=0;i<n;i++){
		cin>>s1>>s2>>tmp;
		int v1 = str2int(s1);
		int v2 = str2int(s2);
		w[v1] += tmp;
		w[v2] += tmp;
		G[v1][v2] = G[v2][v1] += tmp;
	}
	
	for(int i=0;i<num;i++){
		if(visited[i]==false){
			int m = 0, total = 0, head = i;
			DFS(i, m, head, total);
			if(m>2&&total>k){
				Node node;
				node.head = head;
				node.member = m;
				ans.push_back(node);
			}
		}
	}
	
	sort(ans.begin(), ans.end(), cmp);
	
	printf("%d\n", ans.size());
	for(int i=0;i<ans.size();i++){
		printf("%s %d\n", mp2[ans[i].head].c_str(), ans[i].member);
	}
}
