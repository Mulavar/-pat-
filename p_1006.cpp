#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
struct Person{
	char id[20];
	int in_time, out_time;
};

bool cmp1(Person p1, Person p2){
	return p1.in_time < p2.in_time;
}

bool cmp2(Person p1, Person p2){
	return p1.out_time > p2.out_time;
}

char name[20];
int n, hh, mm, ss, tme;
vector<Person> person;
Person tmp;
int main(){
	freopen("data.txt", "r", stdin);
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%s %d:%d:%d", name, &hh, &mm, &ss);
		tme = hh * 3600 + mm * 60 + ss;
		strcpy(tmp.id, name);
		tmp.in_time = tme;
		scanf("%d:%d:%d", &hh, &mm, &ss);
		tme = hh * 3600 + mm * 60 + ss;
		tmp.out_time = tme;
		person.push_back(tmp);
	}
	
	sort(person.begin(), person.end(), cmp1);
	printf("%s", person[0].id);
	sort(person.begin(), person.end(), cmp2);
	printf(" %s\n", person[0].id);
}
