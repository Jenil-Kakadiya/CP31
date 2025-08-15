#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    int t;
    cin>> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> pre(n);


        for(int i=0; i<n; i++) cin >> a[i];
        pre[0]= a[0];
        for(int i=1; i<n; i++) pre[i] = pre[i-1] + a[i];

        int maxDiff = 0;
        for(int k=1; k<=n; k++){

            if(n%k) continue;

            int start = k-1;
            int maxi = pre[start];
            int mini = pre[start];

            for(int i=start+k; i<n; i+=k){
                int diff = pre[i] - pre[i-k];
                maxi = max(maxi, diff);
                mini = min(mini, diff);
            }
            maxDiff = max(maxDiff, maxi - mini);
        }
        
        cout << maxDiff << endl;
    }
    return 0;
}