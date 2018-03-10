#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
#include <string>
using namespace std;
const int MAXN = 10010;
struct Car{
	char id[10];
	int time;
	bool flag;
}car[MAXN], valid[MAXN];
int n, m;
map<string, int> mp;

bool cmp1(Car c1, Car c2){
	if(strcmp(c1.id, c2.id)!=0){
		return strcmp(c1.id, c2.id) < 0;
	}	
	return c1.time < c2.time;
}

bool cmp2(Car c1, Car c2){
	return c1.time < c2.time;
}

int main(){
	
	scanf("%d%d", &n, &m);
	for(int i=0;i<n;i++){
		Car tmp;
		int hh, mm, ss;
		char status[5];
		scanf("%s %d:%d:%d %s", tmp.id, &hh, &mm, &ss, status);
		tmp.time = hh * 3600 + mm * 60 + ss;
		if(strcmp(status, "in")==0){
			tmp.flag = true;
		}
		else{
			tmp.flag = false;
		}
		car[i] = tmp;
	}
	
	sort(car, car+n, cmp1);
	int len = 0;
	for(int i=1;i<n;i++){
		if(strcmp(car[i].id, car[i-1].id)==0&&car[i-1].flag==true&&car[i].flag==false){
			valid[len++] = car[i-1];
			valid[len++] = car[i];
			if(mp.count(car[i].id)==0){
				mp[car[i].id] = 0;
			}
			mp[car[i].id] += car[i].time - car[i-1].time;
		}
	}
	
	sort(valid, valid+len, cmp2);
	int now = 0, cnt = 0;
	for(int i=0;i<m;i++){
		int hh, mm, ss;
		scanf("%d:%d:%d", &hh, &mm, &ss);
		int s_time = hh * 3600 + mm * 60 + ss;
		while(now<len&&valid[now].time<=s_time){
			if(valid[now].flag){
				cnt++;
			}
			else{
				cnt--;
			}
			now++;
		}
		printf("%d\n", cnt);
	}
	
	map<string, int>::iterator it;
	int p_time = 0;
	for(it=mp.begin();it!=mp.end();it++){
		if(it->second>p_time){
			p_time = it->second;
		}
	}
	for(it=mp.begin();it!=mp.end();it++){
		if(it->second==p_time){
			printf("%s ", it->first.c_str());
		}
	}
	printf("%02d:%02d:%02d", p_time/3600, p_time%3600/60, p_time%60);
	
	
	
	
}
