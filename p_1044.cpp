#include <cstdio>
#include <algorithm>

using namespace std;
const int MAXN = 100010;
const int INF = 1000000000;
int dm[MAXN];
int n, p;
int main(){
	scanf("%d%d", &n, &p);
	for(int i=0;i<n;i++){
		scanf("%d", &dm[i]);
	}
	
	int l = 0, r = 0, need = 0, minNeed = INF;
	while(l<n&&r<=n){
		
		if(need<p){
			need += dm[r];
			r++;
		}
		else if(need==p){
			minNeed = need;
			break;
		}
		else{
			if(need<minNeed){
				minNeed = need;
			}
			need -= dm[l];
			l++;
		}
	}
	
	l = r = 0;
	int ans = 0;
	while(l<n&&r<=n){
		if(ans<p){
			ans += dm[r];
			r++;
		}
		else{
			if(ans==minNeed)
				printf("%d-%d\n", l+1, r);
			ans -= dm[l];
			l++;
		} 
	}
}
