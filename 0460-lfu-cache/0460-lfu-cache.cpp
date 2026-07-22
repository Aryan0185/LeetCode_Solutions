class LFUCache {
    int capacity, minFreq;
    unordered_map<int, int> keyToVal;
    unordered_map<int, int> keyToFreq;
    unordered_map<int, list<int>> freqToKeys;
    unordered_map<int, list<int>::iterator> keyToIter;
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }
    void touch(int key) {
        int freq = keyToFreq[key];
        freqToKeys[freq].erase(keyToIter[key]);
        if (freqToKeys[freq].empty()) {
            freqToKeys.erase(freq);
            if (minFreq == freq) minFreq++;
        }
        keyToFreq[key] = freq + 1;
        freqToKeys[freq + 1].push_back(key);
        keyToIter[key] = prev(freqToKeys[freq + 1].end());
    }
    int get(int key) {
     if (keyToVal.find(key) == keyToVal.end()) return -1;
        touch(key);
        return keyToVal[key];   
    } 
    void put(int key, int value) {
      if (capacity <= 0) return;
        if (keyToVal.find(key) != keyToVal.end()) {
            keyToVal[key] = value;
            touch(key);
            return;
        }
        if ((int)keyToVal.size() >= capacity) {
            int evictKey = freqToKeys[minFreq].front();
            freqToKeys[minFreq].pop_front();
            if (freqToKeys[minFreq].empty()) freqToKeys.erase(minFreq);
            keyToVal.erase(evictKey);
            keyToFreq.erase(evictKey);
            keyToIter.erase(evictKey);
        }
        keyToVal[key] = value;
        keyToFreq[key] = 1;
        freqToKeys[1].push_back(key);
        keyToIter[key] = prev(freqToKeys[1].end());
        minFreq = 1; 
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */