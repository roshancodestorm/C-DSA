class LRUCache {
private:
    int capacity;
    list<int> dll;
    unordered_map<int, pair<int, list<int>::iterator>> mp;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        dll.erase(mp[key].second);
        dll.push_front(key);

        mp[key].second = dll.begin();

        return mp[key].first;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            dll.erase(mp[key].second);
            dll.push_front(key);
            mp[key].second = dll.begin();
            mp[key].first = value;
        }
        else {
            if (mp.size() == capacity) {
                int lru = dll.back();
                dll.pop_back();
                mp.erase(lru);
            }

            dll.push_front(key);
            mp[key] = {value, dll.begin()};
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */