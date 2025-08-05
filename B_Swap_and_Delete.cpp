#include <iostream>
using namespace std;

int solve(string s)
{
    int n = s.length();
    if (n == 1)
        return 1;

    int zeros = 0;
    int delets = 0;
    int ones = 0;
    for (int i = 0; i < n; i++){
        if (s[i] == '1') ones++;
        else zeros++;
    }
    // cout << zeros << " " << ones << endl;
    for (int i = 0; i < n; i++){
        if (s[i] == '1'){
            if(!zeros){
                delets += n-i;
                break;
            }
            else zeros--;
        }else if (s[i] == '0'){
            if(!ones) {
                delets += n-i;
                break;
            }
            else ones--;
        }else delets++;
    }
    return delets;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << solve(s) << endl;
    }
    return 0;
}