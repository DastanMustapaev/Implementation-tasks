#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int q;
    cin >> q;
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        
        if (type == 1) {
            int v;
            cin >> v;
            pq.push(v);
        } else {
            if (!pq.empty()) {
                pq.pop();
            }
        }
        
        if (i > 0) cout << " ";
        
        if (pq.empty()) {
            cout << -1;
        } else {
            cout << pq.top();
        }
    }
    cout << "\n";
    
    return 0;
}