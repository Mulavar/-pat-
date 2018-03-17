#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
const int MAXN = 110;
int n;
char str1[MAXN], str2[MAXN], res1[MAXN], res2[MAXN];

int trans(char str[], char res[]){
	int len = strlen(str);
	int idx = 0, k = 0, e = 0, nonzero = -1;
	bool flag = false;
	res[0] = '0';
	res[1] = '.';
	for(int i=0;i<len;i++){
		if(str[i]=='.'){
			idx = i;
		}
		else if(str[i]!='0'&&flag==false){
			nonzero = i;
			flag = true;
		}
	}
	
	for(int i=nonzero;i<len&&k<n;i++){
		if(str[i]=='.') continue;
		res[k+2] = str[i];
		k++;
	}	
	while(k<n){
		res[k+2] = '0';
		k++;
	}
	res[k+2] = '\0';
	
	if(nonzero==-1){
		for(int i=0;i<n;i++){
			res[i+2] = '0';
		}
		return 0;
	}
	if(idx==0){
		e = len - nonzero;
	}
	else{
		if(idx-nonzero<0) e = idx - nonzero + 1;
		else e = idx - nonzero;
		
	}
	return e;
}

bool isSame(char s1[], char s2[]){
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	if(len1!=len2) return false;
	for(int i=0;i<len1;i++){
		if(s1[i]!=s2[i]) return false;
	}
	return true;
}

int main(){
	
	scanf("%d", &n);
	scanf("%s", str1);
	scanf("%s", str2);
	int e1 = trans(str1, res1);
	int e2 = trans(str2, res2);
	bool flag = isSame(res1, res2);
	if(flag&&e1==e2){
		printf("YES ");
		for(int i=0;i<strlen(res1);i++){
			printf("%c", res1[i]);
		}
		printf("*10^%d", e1);
	}
	else{
		printf("NO ");
		for(int i=0;i<strlen(res1);i++){
			printf("%c", res1[i]);
		}
		printf("*10^%d ", e1);
		for(int i=0;i<strlen(res2);i++){
			printf("%c", res2[i]);
		}
		printf("*10^%d", e2);
	}
}
