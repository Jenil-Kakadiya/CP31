#include <iostream>
#include <climits>
#include <limits>
using namespace std;


string solve(unsigned int n, unsigned int k, unsigned long long x){
    unsigned long long nSum = (static_cast<unsigned long long>(n) * (n + 1)) / 2; 
    if (n == k && x != nSum) return "NO";
    unsigned long long kMinus_sum = (static_cast<unsigned long long>(n - k) * (n - k + 1)) / 2;
    unsigned long long nMinus_nMinusK_sum = nSum - kMinus_sum;
    unsigned long long K_sum = (static_cast<unsigned long long>(k)*(k+1))/2;

    // cout << K_sum<< endl;


    // cout<< nSum << " " << kMinus_sum << " " << nMinus_nMinusK_sum << " " << K_sum << endl;
    if(x <= nMinus_nMinusK_sum && x >= K_sum) return "YES";
    return "NO";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        unsigned int n, k;
        unsigned long long x;
        cin >> n >> k >> x;
        cout << solve(n, k, x) << endl;
    }
    return 0;
}
