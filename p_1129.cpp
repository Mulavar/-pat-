#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
const int MAXN = 50010;
struct Node{
	int v, w;
	
	bool operator < (const Node &n) const{
		if(w!=n.w) return w > n.w;
		return v < n.v;
	}
};

set<Node> st;
int n, m, id, ct[MAXN], k;
int main(){
	freopen("data.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	for(int i=0;i<n;i++){
		scanf("%d", &id);
		k = 0;
		if(i>0){
			printf("%d:", id);
			for(set<Node>::iterator it=st.begin();it!=st.end()&&k<m;it++,k++){
				printf(" %d", it->v);
			}
			printf("\n");
		}
		Node node;
		node.v = id;
		node.w = ct[id];
		if(st.find(node)!=st.end()){
			st.erase(st.find(node));
		}
		node.w += 1;
		st.insert(node);
		ct[id]++;
	}
	
	
}
