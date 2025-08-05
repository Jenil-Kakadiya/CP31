#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n >> s;
        vector<int> prefix(n);
        vector<int> suffix(n);
        unordered_map<int,int> frq;

        for(int i=0; i<n; i++){
            if(!frq[s[i] - 'a']){
                frq[s[i] - 'a']++;
            }
            prefix[i] = frq.size();
        }
        frq.clear();
        // cout << frq.size() << endl;
        for(int i=n-1; i>-1; i--){
            if(!frq[s[i] - 'a']){
                frq[s[i] - 'a']++;
            }
            suffix[i] = frq.size();
        }
        int maxDifferent = 0;
        for(int i=0; i<n-1; i++){
            maxDifferent = max(maxDifferent, prefix[i] + suffix[i+1]);
        }

        cout << maxDifferent << endl;
    }
    return 0;
}