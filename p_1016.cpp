#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int MAXN = 1010;
struct User{
	char name[25];
	int MM, dd, hh, mm;
	bool flag;
}user[MAXN];
int price[25], n;
bool cmp(User u1, User u2){
	if(strcmp(u1.name, u2.name)!=0){
		return strcmp(u1.name, u2.name) < 0;
	}
	if(u1.dd!=u2.dd){
		return u1.dd < u2.dd;
	}
	if(u1.hh!=u2.hh){
		return u1.hh < u2.hh;
	}
	return u1.mm < u2.mm;
}

int getMoney(User u1, User u2, int &time){
	int pay = 0;
	while(u1.dd<u2.dd||u1.hh<u2.hh||u1.mm<u2.mm){
		u1.mm++;
		time++;
		pay += price[u1.hh];
		if(u1.mm==60){
			u1.hh += 1;
			u1.mm = 0;
		}
		if(u1.hh==24){
			u1.dd += 1;
			u1.hh = 0;
		}
	}
	return pay;
}


int main(){
	for(int i=0;i<24;i++){
		scanf("%d", &price[i]);
	}
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		User tmp;
		char status[20];
		scanf("%s %d:%d:%d:%d %s", tmp.name, &tmp.MM, &tmp.dd, &tmp.hh, &tmp.mm, status);
		if(strcmp(status, "on-line")==0){
			tmp.flag = true;
		}
		else{
			tmp.flag = false;
		}
		user[i] = tmp;
	}
	
	sort(user, user+n, cmp);
	User on[MAXN];
	User off[MAXN];
	int num = 0;
	for(int i=0;i<n-1;i++){
		if(strcmp(user[i].name, user[i+1].name)==0&&user[i].flag==true&&user[i+1].flag==false){
			on[num] = user[i];
			off[num++] = user[i+1];
		}
	}
	int allMoney = 0;
	printf("%s %02d\n", on[0].name, on[0].MM);
	for(int i=0;i<num;i++){
		int time = 0, money = 0;
		if(i>0&&strcmp(on[i].name, on[i-1].name)!=0){
			printf("Total amount: $%.2f\n", allMoney / 100.0);
			allMoney = 0;
			printf("%s %02d\n", on[i].name, on[i].MM);
		}
		money = getMoney(on[i], off[i], time);
		allMoney += money;
		printf("%02d:%02d:%02d %02d:%02d:%02d ", on[i].dd, on[i].hh, on[i].mm, off[i].dd, off[i].hh, off[i].mm);
		printf("%d $%.2f\n", time, money / 100.0);
		
	}
	printf("Total amount: $%.2f\n", allMoney / 100.0);
}
