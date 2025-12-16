#include <iostream>
using namespace std;

struct Node {
    long long val;
    Node* next;
    Node* prev;
    Node(long long v) : val(v), next(nullptr), prev(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    Node* tail;
    int size;

public:
    LinkedList() {
        head = tail = nullptr;
        size = 0;
    }

    void add(char s, long long v) {
        Node* node = new Node(v);
        if (!head) {
            head = tail = node;
        } else if (s == 'f') {
            node->next = head;
            head->prev = node;
            head = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
        size++;
    }

    long long remove(char s) {
        if (!head) return -1;
        long long result;
        if (s == 'f') {
            result = head->val;
            Node* temp = head;
            head = head->next;
            if (head) head->prev = nullptr;
            else tail = nullptr;
            delete temp;
        } else {
            result = tail->val;
            Node* temp = tail;
            tail = tail->prev;
            if (tail) tail->next = nullptr;
            else head = nullptr;
            delete temp;
        }
        size--;
        return result;
    }

    void insert(int p, long long v) {
        if (p <= 1) {
            add('f', v);
            return;
        }
        if (p > size + 1) p = size + 1;
        Node* node = new Node(v);
        Node* cur = head;
        for (int i = 1; i < p - 1; i++) cur = cur->next;
        node->next = cur->next;
        node->prev = cur;
        if (cur->next) cur->next->prev = node;
        cur->next = node;
        if (!node->next) tail = node;
        size++;
    }

    long long removeAt(int p) {
        if (p < 1 || p > size) return -1;
        if (p == 1) return remove('f');
        Node* cur = head;
        for (int i = 1; i < p; i++) cur = cur->next;
        long long val = cur->val;
        if (cur->prev) cur->prev->next = cur->next;
        if (cur->next) cur->next->prev = cur->prev;
        if (cur == tail) tail = cur->prev;
        delete cur;
        size--;
        return val;
    }

    int find(long long v) {
        Node* cur = head;
        int pos = 1;
        while (cur) {
            if (cur->val == v) return pos;
            cur = cur->next;
            pos++;
        }
        return -1;
    }

    long long get(int p) {
        if (p < 1 || p > size) return -1;
        Node* cur = head;
        for (int i = 1; i < p; i++) cur = cur->next;
        return cur->val;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    LinkedList list;

    long long output[400005];
    int idx = 0;

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            char s;
            long long v;
            cin >> s >> v;
            list.add(s, v);
        } else if (type == 2) {
            char s;
            cin >> s;
            output[idx++] = list.remove(s);
        } else if (type == 3) {
            int p;
            long long v;
            cin >> p >> v;
            list.insert(p, v);
        } else if (type == 4) {
            int p;
            cin >> p;
            output[idx++] = list.removeAt(p);
        } else if (type == 5) {
            long long v;
            cin >> v;
            output[idx++] = list.find(v);
        } else if (type == 6) {
            int p;
            cin >> p;
            output[idx++] = list.get(p);
        }
    }

    for (int i = 0; i < idx; i++) cout << output[i] << " ";
    cout << "\n";

    return 0;
}