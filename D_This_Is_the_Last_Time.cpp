#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Casino {
    int l, r, real;
};

long long solve(int n, long long k, vector<Casino>& casinos) {
    // Sort by left boundary
    sort(casinos.begin(), casinos.end(), [](const Casino& a, const Casino& b) {
        return a.l < b.l;
    });
    
    priority_queue<pair<int, int>> pq; // {real, index}
    vector<bool> used(n, false);
    int idx = 0;
    
    while (true) {
        // Add all newly accessible casinos
        while (idx < n && casinos[idx].l <= k) {
            if (k <= casinos[idx].r) {
                pq.push({casinos[idx].real, idx});
            }
            idx++;
        }
        
        // Find the best valid casino
        int best_idx = -1;
        int best_real = k;
        
        while (!pq.empty()) {
            auto top = pq.top();
            int real_val = top.first;
            int casino_idx = top.second;
            
            // Check if this casino is still valid
            if (!used[casino_idx] && casinos[casino_idx].l <= k && k <= casinos[casino_idx].r && real_val > k) {
                best_idx = casino_idx;
                best_real = real_val;
                pq.pop();
                break;
            }
            pq.pop();
        }
        
        if (best_idx == -1) {
            break;
        }
        
        used[best_idx] = true;
        k = best_real;
    }
    
    return k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long k;
        cin >> n >> k;
        vector<Casino> casinos(n);
        for (int i = 0; i < n; ++i) {
            cin >> casinos[i].l >> casinos[i].r >> casinos[i].real;
        }
        cout << solve(n, k, casinos) << '\n';
    }
    return 0;
}