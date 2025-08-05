#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

signed main(){
    int t;
    cin >> t;
    while (t--) {
        int n, p;
        cin >> n >> p;
        vector<int> a(n);
        vector<int> b(n);
        vector<pair<int, int>> v(n);

        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<n; i++) cin >> b[i];

        for(int i=0; i<n; i++) v[i] = {b[i], a[i]}; //insert pair

        sort(v.begin(), v.end());
        // for(auto it:v) cout<< it.first << " " << it.second << endl;
        int min_cost = p;
        int shared = 1;

        for(auto& it : v){
            int sharing_cost = it.first;
            int can_share = it.second;

            if(sharing_cost >= p){
                break;
            }

            if(shared + can_share > n){
                min_cost += (n- shared)*sharing_cost;
                shared = n;
                break;
            }else{
                min_cost += can_share * sharing_cost;
                shared += can_share;
            }
        }

        min_cost += (n - shared) * p; 
        cout << min_cost << endl;

    }
    return 0;
}
