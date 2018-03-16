#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAXN = 10010;
struct Customer{
	int a_time, s_time;
}ct[MAXN];

priority_queue<int, vector<int>, greater<int> > q;
int n, m, hh, mm, ss, service, num = 0, total = 0;
int st = 8 * 3600;
int ed = 17 * 3600;

bool cmp(Customer c1, Customer c2){
	return c1.a_time < c2.a_time;	
}

int main(){
	freopen("data.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	for(int i=0;i<n;i++){
		scanf("%d:%d:%d %d", &hh, &mm, &ss, &service);
		int tmp = hh * 3600 + mm * 60 + ss;
		if(tmp<=ed){
			ct[num].a_time = tmp;
			ct[num++].s_time = min(service, 60) * 60;
		}
	}
	
	sort(ct, ct+num, cmp);
	for(int i=0;i<num;i++){
		if(ct[i].a_time<st){
			total += st - ct[i].a_time;
			ct[i].a_time = st;
		}
		else break;
	}
	
	for(int i=0;i<num;i++){
		if(q.size()<m){
			q.push(ct[i].a_time+ct[i].s_time);
		}
		else{
			int end_time = q.top();
			total += max(end_time - ct[i].a_time, 0);
			q.pop();
			q.push(max(ct[i].a_time, end_time) + ct[i].s_time);
		}
	}
	
	printf("%.1f\n", total * 1.0 / 60 / num);
}
