#include<bits/stdc++.h>
#define ll long long
#define loop(n) for(ll i = 0; i<n; i++)
#define sort(a) sort(a.begin(), a.end())
using namespace std;

const int mxn = 10005;
bool vis[mxn];
vector<int> adj[mxn];
int in[mxn], low[mxn], timer;
set<int> ap;

void dfs(int node, int parent){
    vis[node] = 1;
    low[node] = in[node] = timer++;
    int children = 0;
    for(int x : adj[node]){
        if(x==parent) continue;
        if(vis[x]) low[node] = min(low[node], in[x]);
        else{
            dfs(x, node);
            children++;
            low[node] = min(low[node], low[x]);
            if(low[x]>=in[node] && parent!=-1) ap.insert(node);
        }
    }

    if(parent==-1 and children>1) ap.insert(node);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, x, y;
    while(1){
        cin>>n>>m;
        if(n==0 && m==0) return 0;

        for(int i = 1; i<=n; i++){
            vis[i] = 0;
            adj[i].clear();
        }
        timer = 1;
        ap.clear();

        while(m--){
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        for(int i = 1; i<=n; i++){
            if(!vis[i]) dfs(i, -1);
        }

        cout<<ap.size()<<"\n";
    }
    return 0;
}