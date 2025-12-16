#include <iostream>
using namespace std;

class DynamicArray {
private:
    long long* arr;
    int sz;
    int cap;

    void resize() {
        cap *= 2;
        long long* newArr = new long long[cap];
        for (int i = 0; i < sz; i++) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }

public:
    DynamicArray() {
        cap = 1;
        sz = 0;
        arr = new long long[cap];
    }

    ~DynamicArray() {
        delete[] arr;
    }

    void push_back(long long v) {
        if (sz == cap) resize();
        arr[sz++] = v;
    }

    long long pop_back() {
        if (sz == 0) return -1;
        return arr[--sz];
    }

    void insert_at(int p, long long v) {
        if (sz == cap) resize();
        for (int i = sz; i >= p; i--) {
            arr[i] = arr[i - 1];
        }
        arr[p - 1] = v;
        sz++;
    }

    long long erase_at(int p) {
        long long val = arr[p - 1];
        for (int i = p - 1; i < sz - 1; i++) {
            arr[i] = arr[i + 1];
        }
        sz--;
        return val;
    }

    int find_first(long long v) {
        for (int i = 0; i < sz; i++) {
            if (arr[i] == v) return i + 1;
        }
        return -1;
    }

    long long get(int p) {
        return arr[p - 1];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    DynamicArray da;

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            long long v;
            cin >> v;
            da.push_back(v);
        }
        else if (type == 2) {
            cout << da.pop_back() << " ";
        }
        else if (type == 3) {
            int p;
            long long v;
            cin >> p >> v;
            da.insert_at(p, v);
        }
        else if (type == 4) {
            int p;
            cin >> p;
            cout << da.erase_at(p) << " ";
        }
        else if (type == 5) {
            long long v;
            cin >> v;
            cout << da.find_first(v) << " ";
        }
        else if (type == 6) {
            int p;
            cin >> p;
            cout << da.get(p) << " ";
        }
    }

    return 0;
}
