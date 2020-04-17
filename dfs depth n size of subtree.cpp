#include<bits/stdc++.h>
#define ll long long
#define loop(n) for(ll i = 0; i<n; i++)
#define sort(a) sort(a.rbegin(), a.rend())
using namespace std;

const int sz = 2e5 + 5; 
vector<int> tree[sz];
int sub[sz];
int dist[sz];

void dfs(ll node, ll p){
    sub[node] = 1;
    for(ll u : tree[node]){
        if(u==p) continue;
        dist[u] = dist[node] + 1;
        dfs(u, node);
        sub[node] += sub[u];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, k, x, y; cin>>n>>k;
    loop(n-1){
        cin>>x>>y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    dfs(1, -1);

    vector<ll> takbir;
    for(int i = 1; i<=n; i++) takbir.push_back(dist[i] - sub[i] + 1);
    sort(takbir);

    ll ans = 0;
    loop(k) ans += takbir[i];
    cout<<ans<<"\n";
    return 0;
}