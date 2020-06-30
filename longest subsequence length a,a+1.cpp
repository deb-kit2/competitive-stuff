#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin>>n;
    vector<int> a(n);
    for(int i = 0, x; i<n; i++){
        cin>>x;
        x--;
        a[x] = i;
    }

    int mx = 1, len = 1;
    for(int i = 1; i<n; i++){
        if(a[i]>a[i-1]) len++;
        else{
            if(mx<len) mx = len;
            len = 1;
        }
    }
    if(mx<len) mx = len;
    cout<<n-mx<<"\n";
    return 0;
}