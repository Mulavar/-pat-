#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
const int MAXN = 210;
int G[MAXN][MAXN], degree[MAXN], n, m, v1, v2, k, q;
bool flag[MAXN];
vector<int> query;

bool judge1(){
    for(int i=0;i<query.size();i++){
        if(degree[query[i]]+1<query.size())
            return false;
    }

    return true;
}

bool judge2(){
    int sz = query.size();
    for(int i=0;i<sz-1;i++){
        for(int j=i+1;j<sz;j++){
            if(G[query[i]][query[j]]==0) return false;
        }
    }
    return true;
}

bool judge3(int u){
    for(int i=0;i<query.size();i++){
        if(G[query[i]][u]==0) return false;
    }
    return true;
}

int main(){
    freopen("data.txt", "r", stdin);
    scanf("%d%d", &n, &m);

    for(int i=0;i<m;i++){
        scanf("%d%d", &v1, &v2);
        G[v1][v2] = G[v2][v1] = 1;
        degree[v1]++;
        degree[v2]++;
    }

    scanf("%d", &q);
    while(q--){
        bool flg = false;
        memset(flag, 0, sizeof(flag));
        query.clear();
        int tmp;
        scanf("%d", &k);
        for(int j=0;j<k;j++){
            scanf("%d", &tmp);
            flag[tmp] = true;
            query.push_back(tmp);
        }

        if(!judge1()){
            printf("Not a Clique\n");
            continue;
        }
        if(!judge2()){
            printf("Not a Clique\n");
        }
        else{
            for(int i=1;i<=n;i++){
                if(!flag[i]){
                    if(judge3(i)){
                        flg = true;
                        printf("Not Maximal\n");
                        break;
                    }
                }
            }
            if(!flg) printf("Yes\n");
        }
    }
}