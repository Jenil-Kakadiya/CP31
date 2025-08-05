#include <iostream>
#include <vector>

#define int long long
using namespace std;

int solve(int a, int b, int n){
    vector<int> tools(n);
    for(int i = 0; i < n; i++){
        cin >> tools[i];
    }
    int sum = 0;
    for(auto& tool : tools){
        if(tool < a) sum += tool;
        else{
            sum += a;
            sum = sum - 1;
        }
    }
    // cout << sum << endl;
    return sum+b;
}
signed main(){
    int t;
    cin >> t;
    while(t--){
        int a, b, n;
        cin >> a >> b >> n;
        cout << solve(a, b, n) << endl;
    }
    return 0;
}