#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n , k;
        cin >> n >> k;
        vector<int> a(n);
        vector<int> b(n);
        vector<int> ans;
        for(int i = 0 ; i < n ; i++) cin >> a[i];
        for(int i = 0 ; i < n ; i++) cin >> b[i];
        int curMax = 0;
        int availMax = 0;
        int maxPossible = 0;
        for(int i =0; i<n; i++){
            if (!k) continue;
            k--;
            curMax += a[i];
            availMax = max(availMax , b[i]);
            ans.push_back(curMax + availMax*(k));
        }

        sort(ans.begin(), ans.end(), greater<int>());
        // for(int x: ans) cout << x << " ";
        cout << ans[0] << endl;
    }
    return 0;
}