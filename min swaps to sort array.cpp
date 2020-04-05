#include <bits/stdc++.h>

using namespace std;
int main(){
    long long int n; cin>>n;
    pair<long long int, long long int> arr[n];
    
    for(int i = 0; i<n; i++){
    	cin>>arr[i].first;
    	arr[i].second = i;
    }
    
    sort(arr, arr + n);
    vector<bool> vis (n, false);
    
    int swaps = 0;
    for(long long int i = 0; i<n; i++){
    	if(vis[i] || arr[i].second == i) continue;
    	long long int cycle_size = 0;
    	long long int j = i;
    	while(!vis[j]){
    		vis[j]=1;
    		j = arr[j].second;
    		cycle_size++;
    	}
    	
    	if(cycle_size>0) swaps += cycle_size-1;
    }
    cout<<swaps;
    return 0;
}
