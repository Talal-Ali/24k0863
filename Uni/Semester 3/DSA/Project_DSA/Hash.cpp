#include<iostream>
#include "Unordered_pair.h"
using namespace std;

class Hash
{
    private:
    struct Entry {
        unordered key;
        int value;
        bool used;
        bool deleted;

        Entry() {
            used = false;
            deleted = false;
            value = 0;
        }
    };

    static const int CAP = 500;
    Entry table[CAP];

    size_t hashKey(const unordered& k) {
        hash<string> h;
        return (h(k.a) ^ (h(k.b) << 1)) % CAP;
    }

public:
    bool insert(const unordered& k, int val) {
        size_t h = hashKey(k);
        for (int i = 0; i < CAP; i++) {
            int idx = (h + i) % CAP;
            if (!table[idx].used || table[idx].deleted) {
                table[idx].used = true;
                table[idx].deleted = false;
                table[idx].key = k;
                table[idx].value = val;
                return true;
            }
        }
        return false;
    }

    int find(const unordered& k) {
        size_t h = hashKey(k);
        for (int i = 0; i < CAP; i++) {
            int idx = (h + i) % CAP;
            if (!table[idx].used && !table[idx].deleted)
                return -1;

            if (table[idx].used && table[idx].key == k)
                return table[idx].value;
        }
        return -1;
    }
};
