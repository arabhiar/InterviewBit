#include<bits/stdc++.h>
unordered_map<int, int> kv; // hold key value pair
list<int> lru; // list that stores latest accessed node
unordered_map<int, list<int>::iterator> um; // map from key to linked list iterator
int cap;

void updateLRU(int key) {
    if (kv.count(key))
    {
        lru.erase(um[key]);
    }
    lru.push_front(key);
    um[key] = lru.begin();
}

void expel() {
    um.erase(lru.back());
    kv.erase(lru.back());
    lru.pop_back();
}

LRUCache::LRUCache(int capacity) {
    um.erase(um.begin(), um.end());
    kv.erase(kv.begin(), kv.end());
    lru.erase(lru.begin(), lru.end());
    cap = capacity;
}

int LRUCache::get(int key) {
    if (kv.count(key) == 0)
    {
        return -1;
    }
    updateLRU(key);
    return kv[key];
}

void LRUCache::set(int key, int value) {
    if (kv.size() == cap && kv.count(key) == 0)
        expel();
    updateLRU(key);
    kv[key] = value;
}

