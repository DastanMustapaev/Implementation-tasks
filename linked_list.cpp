#include <iostream>
using namespace std;

struct Node {
    long long val;
    Node* next;
    Node(long long v) : val(v), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    Node* tail;
    int size;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void add(char s, long long v) {
        Node* node = new Node(v);
        if (!head) {
            head = tail = node;
        } else if (s == 'f') {
            node->next = head;
            head = node;
        } else if (s == 'b') {
            tail->next = node;
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
            delete temp;
            if (!head) tail = nullptr;
        } else { 
            if (head == tail) {
                result = head->val;
                delete head;
                head = tail = nullptr;
            } else {
                Node* cur = head;
                while (cur->next != tail) cur = cur->next;
                result = tail->val;
                delete tail;
                tail = cur;
                tail->next = nullptr;
            }
        }
        size--;
        return result;
    }

    void insert(int p, long long v) {
        if (p == 1) {
            add('f', v);
            return;
        }
        Node* node = new Node(v);
        Node* cur = head;
        for (int i = 1; i < p - 1; i++) cur = cur->next;
        node->next = cur->next;
        cur->next = node;
        if (!node->next) tail = node;
        size++;
    }

    long long removeAt(int p) {
        if (p == 1) return remove('f');
        Node* cur = head;
        for (int i = 1; i < p - 1; i++) cur = cur->next;
        Node* temp = cur->next;
        long long val = temp->val;
        cur->next = temp->next;
        if (temp == tail) tail = cur;
        delete temp;
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

    long long output[2*105];
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