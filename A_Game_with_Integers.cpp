#include <iostream>
using namespace std;

string solve(int n){
    if(n%3 == 1) return "First";
    else if(n%3 == 2) return "First";
    return "Second";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
}