#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;


void solve(int n, vector<int> a){

    unordered_map<int, int> frq;
    for(int i=0; i<n; i++) frq[a[i]]++;
    for(int i=0; i<n; i++){
        if(frq[a[i]] == 1){
            cout << -1 << endl;
            return;
        }
    }
    vector<int> students(n);
    
    for(int i=0; i<n; i++) students[i] = i+1;
    int l = 0, r = 0;
    while(r < n){
        if(a[r] == a[l]) r++;
        else{
            rotate(students.begin()+l, students.begin()+l+1, students.begin()+r);
            l=r;
        }
    }
    rotate(students.begin()+l, students.begin()+l+1, students.begin()+r);

    for(int i=0; i<n; i++) cout << students[i] << " " ;
    cout << endl;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i=0; i<n; i++) cin >> a[i];
        solve(n, a);
    }
    return 0;
}