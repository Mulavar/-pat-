#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
using namespace std;
struct Customer{
	int start, end;
	int line;
	
	bool operator < (const Customer tmp) const {
		if(end!=tmp.end){
			return end > tmp.end;
		}
		return line > tmp.line;
	}
};
vector<Customer> windows[25];
int n, m, k, q;
priority_queue<Customer> custom;
map<int, Customer> mp;
void init(){
	for(int i=0;i<25;i++){
		Customer c;
		c.line = i + 1;
		c.end = 0;
		windows[i].push_back(c);
	}
}
int main(){
	int n, m, k, q;
	init();
	scanf("%d%d%d%d", &n, &m, &k, &q);
	for(int i=0;i<k&&i<n*m;i++){
		Customer tmp;
		int l = (i + 1) % n;
		int p_time;
		scanf("%d", &p_time);
		tmp.line = l;
		tmp.start = (*(windows[l].end() - 1)).end;
		tmp.end = tmp.start + p_time;
		windows[l].push_back(tmp);
		mp[i+1] = tmp;
		custom.push(tmp);
	}
	for(int i=n*m;i<k;i++){
		Customer tmp;
		int p_time;
		int l = custom.top().line;
		custom.pop();
		scanf("%d", &p_time);
		tmp.line = l;
		tmp.start = (*(windows[l].end() - 1)).end;
		tmp.end = tmp.start + p_time;
		windows[l].push_back(tmp);
		mp[i+1] = tmp;
		custom.push(tmp);
	}
	
	int latest = (17 - 8) * 60;
	for(int i=0;i<q;i++){
		int id;
		scanf("%d", &id);
		Customer ans = mp[id];
		if(ans.start>=latest){
			printf("Sorry\n");
		}
		else{
			int hh = 8 + ans.end / 60;
			int mm = ans.end % 60;
			printf("%02d:%02d\n", hh, mm);
		}
	}
}
