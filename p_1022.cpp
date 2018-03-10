#include <cstdio>
#include <algorithm>
#include <map>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int n, k;
map<string, vector<int> > mp[8];
int main(){
	int id;
	string name, author, keywords, publisher, year;
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d", &id);
		getchar();
		getline(cin, name);
		getline(cin, author);
		mp[1][name].push_back(id);
		mp[2][author].push_back(id);
		while(cin>>keywords){
			char ch;
			mp[3][keywords].push_back(id);
			ch = getchar();
			if(ch=='\n'){
				break;
			}
		}
		getline(cin, publisher);
		getline(cin, year);
		mp[4][publisher].push_back(id);
		mp[5][year].push_back(id);
	}
	
	scanf("%d", &k);
	for(int i=0;i<k;i++){
		int idx;
		string search;
		scanf("%d: ", &idx);
		getline(cin, search);
		cout<<idx<<": "<<search<<endl;
		if(mp[idx].count(search)==0){
			cout<<"Not Found"<<endl;
		}
		else{
			vector<int> tmp = mp[idx][search];
            sort(tmp.begin(), tmp.end());
            for(int j=0;j<tmp.size();j++){
                printf("%07d\n", tmp[j]);
            }
		}
	}
}
