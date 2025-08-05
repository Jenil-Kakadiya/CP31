#include<iostream>
#include<vector>
using namespace std;
// #include <utility> // Required for pair
#include <algorithm> // Required for sort and set_intersection
#include <iterator> // Required for back_inserter

int solve() {
    int a, b, xk, yk, xq, yq;
    cin >> a >> b >> xk >> yk >> xq >> yq;

    vector<pair<int, int>> kingAttackes;
    vector<pair<int, int>> queenAttackes;

    if (a != b) {
        // Add 8 pairs for a != b (King)
        kingAttackes.push_back({xk + a, yk + b});
        kingAttackes.push_back({xk - a, yk - b});
        kingAttackes.push_back({xk - a, yk + b});
        kingAttackes.push_back({xk + a, yk - b});
        kingAttackes.push_back({xk + b, yk + a});
        kingAttackes.push_back({xk - b, yk - a});
        kingAttackes.push_back({xk - b, yk + a});
        kingAttackes.push_back({xk + b, yk - a});

        // Add 8 pairs for a != b (Queen)
        queenAttackes.push_back({xq + a, yq + b});
        queenAttackes.push_back({xq - a, yq - b});
        queenAttackes.push_back({xq - a, yq + b});
        queenAttackes.push_back({xq + a, yq - b});
        queenAttackes.push_back({xq + b, yq + a});
        queenAttackes.push_back({xq - b, yq - a});
        queenAttackes.push_back({xq - b, yq + a});
        queenAttackes.push_back({xq + b, yq - a});
    } else { // a == b
        // Add 4 pairs for a = b (King)
        kingAttackes.push_back({xk + a, yk + b});
        kingAttackes.push_back({xk - a, yk - b});
        kingAttackes.push_back({xk - a, yk + b});
        kingAttackes.push_back({xk + a, yk - b});

        // Add 4 pairs for a = b (Queen)
        queenAttackes.push_back({xq + a, yq + b});
        queenAttackes.push_back({xq - a, yq - b});
        queenAttackes.push_back({xq - a, yq + b});
        queenAttackes.push_back({xq + a, yq - b});
    }

    // Sort both vectors for set_intersection
    sort(kingAttackes.begin(), kingAttackes.end());
    sort(queenAttackes.begin(), queenAttackes.end());

    // Create a vector to store common pairs
    vector<pair<int, int>> commonAttackes;

    // Find the intersection
    set_intersection(kingAttackes.begin(), kingAttackes.end(),
                          queenAttackes.begin(), queenAttackes.end(),
                          back_inserter(commonAttackes));

    // The size of commonAttackes vector is the count of common pairs
    return commonAttackes.size();
}
int main(){
    int t;
    cin >> t;
    while(t--){
        cout << solve() << endl;
    }
    return 0;
}