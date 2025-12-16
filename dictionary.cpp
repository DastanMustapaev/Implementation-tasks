#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    unordered_map<long long, long long> dict;
    long long output[800005]; 
    int idx = 0;

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            long long k, v;
            cin >> k >> v;
            if (dict.count(k)) {
                output[idx++] = dict[k];
            } else {
                output[idx++] = -1;
            }
            dict[k] = v; 
        } 
        else if (type == 2) {
            long long k;
            cin >> k;
            if (dict.count(k)) {
                output[idx++] = dict[k]; 
                dict.erase(k);
            } else {
                output[idx++] = -1;
            }
        } 
        else if (type == 3) {
            long long k;
            cin >> k;
            if (dict.count(k)) {
                output[idx++] = dict[k];
            } else {
                output[idx++] = -1;
            }
        }
    }

    for (int i = 0; i < idx; i++) cout << output[i] << " ";
    cout << "\n";

    return 0;
}