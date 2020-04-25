#include<bits/stdc++.h>
#define ll long long
#define loop(n) for(ll i = 0; i<n; i++)
#define sort(a) sort(a.begin(), a.end())
using namespace std;

vector<int> adj[11];
int level[11], parent[11];
bool vis[11];
void dfs(int node, int par){
    vis[node] = 1;
    level[node] = level[par] + 1;
    parent[node] = par;
    for(int child : adj[node]){
        if(child==par) continue;
        if(!vis[child]){
            dfs(child, node);
        }
    }
}

int lca(int a, int b){
    if(level[a]<level[b]) swap(a, b);

    int d = level[a] - level[b];
    while(d){
        a = parent[a];
        d--;
    }
    if(a==b) return a;
    
    while(parent[a]!=parent[b]){
        a = parent[a];
        b = parent[b];
    }

    return parent[a];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x, y; cin>>n;
    loop(n-1){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    parent[1] = 0;
    level[0] = -1;
    dfs(1,0);
    
    cin>>x>>y;
    cout<<lca(x, y)<<"\n";
    return 0;       
}