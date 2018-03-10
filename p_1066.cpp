#include <cstdio>
#include <algorithm>

using namespace std;

struct Node{
	int val;
	struct Node *l, *r;
};

Node* L(Node* root){
	Node *node = new Node;
	node = root->r;
	root->r = node->l;
	node->l = root;
	return node;
}

Node* R(Node* root){
	Node *node = new Node;
	node = root->l;
	root->l = node->r;
	node->r = root;
	return node;
}

int getHeight(Node* root){
	if(root==NULL){
		return 0;
	}
	return max(getHeight(root->l), getHeight(root->r)) + 1;
}

void insert(Node* &root, int v){
	if(root==NULL){
		root = new Node;
		root->val = v;
		root->l = root->r = NULL;
		return ;
	}
	
	if(v<root->val){
		insert(root->l, v);
		if(getHeight(root->l)-getHeight(root->r)==2){
			if(v<root->l->val){
				root = R(root);
			}
			else{
				root->l = L(root->l);
				root = R(root);
			}
		}
	}
	else{
		insert(root->r, v);
		if(getHeight(root->l)-getHeight(root->r)==-2){
			if(v>root->r->val){
				root = L(root);
			}
			else{
				root->r = R(root->r);
				root = L(root);
			}
		}
	}
}

int main(){
	int n;
	scanf("%d", &n);
	Node *root = NULL;
	
	for(int i=0;i<n;i++){
		int v;
		scanf("%d", &v);
		insert(root, v);
	}
	
	printf("%d\n", root->val);
}
