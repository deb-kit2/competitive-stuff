#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxn = 2e5 + 5;
vector<int> parent(mxn), ranks(mxn);

void makeTree(int node){
    parent[node] = node;
    ranks[node] = 0;
}

int findTree(int node){
    if(node==parent[node]) return node;
    return parent[node] = findTree(parent[node]);
}

void mergeTree(int a, int b){
    a = findTree(a);
    b = findTree(b);
    if(a!=b){
        if(ranks[a]<ranks[b]) swap(a, b);
        parent[b] = a;
        if(ranks[a]==ranks[b]) ranks[a]++;
    }
}

struct edge{
    int u, v;
    ll w;
    bool operator<(edge const& other){
        return w < other.w;
    }
};

vector<edge> edges;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, start = 1; cin>>n>>m;

    vector<ll> a(n+1);
    for(int i = 1; i<=n; i++){
        cin>>a[i];
        if(a[i]<a[start]) start = i;
    }

    edge x;
    for(int i = 0; i<m; i++){
        cin>>x.u>>x.v>>x.w;
        edges.push_back(x);
    }

    for(int i = 1; i<=n; i++){
        if(i==start) continue;

        x.u = start;
        x.v = i;
        x.w = a[i] + a[start];
        edges.push_back(x);
    }

    sort(edges.begin(), edges.end());

    for(int i = 0; i<mxn; i++) makeTree(i);

    ll cost = 0;
    for(edge y : edges){
        if(findTree(y.u)!=findTree(y.v)){
            //make new graph if needed
            cost += y.w;
            mergeTree(y.u, y.v);
        }
    }

    cout<<cost<<"\n";
    return 0;
}