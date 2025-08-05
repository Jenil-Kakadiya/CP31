#include<iostream>
#include<unordered_map>
using namespace std;

string solve(string s, int k){
    unordered_map<int, int> freq; 
    for(int i = 0; i < s.length(); i++) freq[s[i]]++;
    int oddFreq = 0;
    for(auto& x: freq)
        if(x.second % 2 != 0) oddFreq++;
    
    if(oddFreq > k+1) return "NO";
    return "YES";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        cout<< solve(s, k) << endl;
    }
    return 0;
}