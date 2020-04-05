#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset = tree<T,null_type, less<T>,rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long
#define loop(n) for(ll i = 0; i<n; i++)

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n; cin>>n;
    ll a[n], b[n];
    loop(n) cin>>a[i];
    loop(n) cin>>b[i];

    ll ans = 0;
    oset<pair<ll,ll>> s;
    
    loop(n){
        ans += s.order_of_key({a[i]-b[i], -1});
        s.insert({b[i]-a[i], i});
    }
    cout<<ans<<"\n";
    return 0;
}