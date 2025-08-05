#include <iostream>
#include <vector>
using namespace std;

void solve(int n, vector<int> arr){
    bool everyOneZero = true;
    for(int i =0; i < n; i++){
        if(arr[i] != 0){
            everyOneZero = false;
        } 
    }
    if(everyOneZero){
        cout << 0 << endl;
        return;
    }

    if( n % 2 == 0){
        cout << 2 << endl;
        cout << 1 << " "<< n << endl;
        cout << 1 << " "<< n << endl;
    }else{
        cout << 4 << endl;
        cout << 1 << " "<< n-1 << endl;
        cout << 1 << " "<< n-1 << endl;
        cout << n-1 << " "<< n << endl;
        cout << n-1 << " "<< n << endl;
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        solve(n, arr);
    }
    return 0;
}