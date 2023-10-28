#include <bits/stdc++.h>

using namespace std;

#define fst first
#define snd second
#define pii pair<int, int>
#define fore(i, a, b) for(int i = a, to = b; i < to; i++)

const int MAXN = 2e5 + 5;

vector<int> ad[MAXN];
int ans[MAXN];

int dfs(int u){
    if(ad[u].empty()){
        return 0;
    }
    fore(i, 0, ad[u].size()){
        ans[u] += dfs(ad[u][i]) + 1;
    }
}


int main(){
    
    int n, x;
    cin>>n;
    fore(i, 2, n + 1){
        cin>>x;
        ad[x].push_back(i);
    }
    dfs(1);

    fore(i, 1, n + 1){
        cout << ans[i] << " ";
    }

    return 0;
}