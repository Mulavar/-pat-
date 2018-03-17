#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;
struct Node{
	int val;
	Node *l, *r;
};
int n, v, h, d[1010];
Node *root = NULL;

void insert(Node *&root, int x){
	if(root==NULL){
		root = new Node;
		root->val = x;
		root->l = root->r = NULL;
		return ;
	}
	
	if(x<=root->val) insert(root->l, x);
	if(x>root->val) insert(root->r, x);
}

int getHeight(Node *root){
	if(root==NULL) return 0;
	return max(getHeight(root->l), getHeight(root->r)) + 1;
}

void DFS(Node *root, int depth){
	if(root==NULL) return ;
	if(depth==h||depth==h-1) d[depth]++;
	
	DFS(root->l, depth+1);
	DFS(root->r, depth+1);
}

int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d", &v);
		insert(root, v);
	}
	h = getHeight(root);
	DFS(root, 1);
	
	printf("%d + %d = %d", d[h], d[h-1], d[h-1] + d[h]);
}
