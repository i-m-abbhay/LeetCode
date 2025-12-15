#include <list>
class LRUCache {
    int cap;
    list<pair<int, int>> dll;
    unordered_map<int, list<pair<int, int>>::iterator> pos;
public:
    LRUCache(int capacity) : cap(capacity) {
        
    }
    
    int get(int key) {
        auto it = pos.find(key);
        if(it == pos.end()) return -1;
        dll.splice(dll.begin(), dll, it->second);
        return it-> second -> second;
    }
    
    void put(int key, int value) {
        auto it = pos.find(key);

        if(it != pos.end()){
            it->second->second = value;
            dll.splice(dll.begin(), dll, it->second);
            return;
        }

        dll.push_front({key, value});
        pos[key] = dll.begin();

        if(pos.size() > cap){
            auto lru = prev(dll.end());
            pos.erase(lru->first);
            dll.pop_back();
        }

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */