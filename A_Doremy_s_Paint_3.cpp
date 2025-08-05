#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

string solve(vector<int> &a, int n){
    unordered_map<int, int> freq;
    for (int x : a)
        freq[x]++;
    if (freq.size() >= 3)
        return "No";
    if(freq.size() == 1) return "Yes";
    auto it = freq.begin();
    int f1 = it->second;
    it++;
    int f2 = it->second;
    // cout << f1 << " " << f2 << endl;
    if( n % 2 == 0 && f1 == f2) return "Yes";
    if( n% 2 == 1 && abs(f1-f2) == 1) return "Yes";
    return "No";
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cout << solve(a, n) << endl;
    }
    return 0;
}