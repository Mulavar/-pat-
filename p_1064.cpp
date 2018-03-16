#include <cstdio>
#include <algorithm>
#include <queue>
 
using namespace std;
const int MAXN = 1010;

int n, in[MAXN], num[MAXN], k = 0;

void inOrder(int root){
	if(root>=n) return ;
	inOrder(2*root+1);
	in[root] = num[k++];
	inOrder(2*root+2);
}

int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d", &num[i]);
	}
	sort(num, num+n);
	inOrder(0);
	for(int i =0;i<n;i++){
		printf("%d", in[i]);
		if(i<n-1){
			printf(" ");
		}
	}
}
