#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n; 

        vector<int> second_largest_num_arr;
        int smallest_num = INT_MAX;
        for(int i=0; i<n; i++){
            int m;
            cin >> m;
            vector<int> a(m);
            for(int i=0; i<m; i++){
                cin >> a[i];
            }
            sort(a.begin(), a.end());
            second_largest_num_arr.push_back(a[1]);
            smallest_num = min(smallest_num, a[0]);
        }
        int sum_second_largest_num_arr = accumulate(second_largest_num_arr.begin(), second_largest_num_arr.end(), 0LL);
        sort(second_largest_num_arr.begin(), second_largest_num_arr.end());
        cout << sum_second_largest_num_arr + smallest_num - second_largest_num_arr[0] << endl;
    }
    // cout << 
    return 0;
}