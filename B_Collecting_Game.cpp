#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int,int>> a(n);
        vector<int> ans(n);
        for(int i=0; i<n; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }

        sort(a.begin(), a.end());
        vector<int> leftSum(n);
        leftSum[0] = a[0].first;
        for(int i=1; i<n; i++) {
            leftSum[i] = leftSum[i-1] + a[i].first;
        }

        for(int i=0; i<n; i++) {
            int j=i;
            int found = i;
            while(j < n){
                pair<int, int> temp = {leftSum[j]+1, INT_MIN};
                auto idx = lower_bound(a.begin(), a.end(), temp) - a.begin();
                idx--;
                if(idx == j) break;
                found += idx-j;
                j = idx;
            }
            ans[a[i].second] = found;
        }
        for(int x: ans) cout << x << " ";
        cout << endl;
    }
}