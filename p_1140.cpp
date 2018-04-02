#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;
const int MAXN = 2100;
int num[MAXN], origin[MAXN];
int main(){
    freopen("data.txt", "r", stdin);
    int d, n, len = 1, c = 1, k1, st;
    scanf("%d%d", &d, &n);
    string res;
    res = to_string(d);
    while(c<n){
        string tmp = "";
        k1 = 0;
        while(k1<res.length()){
            st = k1;
            while(k1<res.length()&&res[k1]==res[st]) k1++;
            tmp += res[st];
            tmp += to_string(k1-st);
        }
        res = tmp;
        c++;
    }

    cout<<res<<endl;
}