#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string solve(vector<int> &a, int n) {
    //it doen't matter if 0th ele is 1 any ele from 1st index to nth i can swap finite time to achive sorted array
    if(a[0] == 1) return "YES";
    return "NO";
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        cout << solve(a, n) << endl;
    }
    return 0;
}