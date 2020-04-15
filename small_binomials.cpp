#include<bits/stdc++.h>
#define ll long long
#define loop(n) for(ll i = 0; i<n; i++)
#define sort(a) sort(a.rbegin(), a.rend())
using namespace std;

int nCr(int n, int k){
    int res = 1;
    if (k>n-k) k = n-k;  
    for (int i = 0; i < k; ++i){
        res *= (n - i);  
        res /= (i + 1);  
    }  
    return res;  
}  

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout<<nCr(4,0);
    return 0;
}