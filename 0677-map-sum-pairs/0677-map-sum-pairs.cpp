class MapSum {
private:
    unordered_map<string, int> mp;
public:
    MapSum() {
    }
    
    void insert(string key, int val) {
        mp[key]=val;
    }
    
    int sum(string prefix) {
        int val = 0;
        for(auto item: mp){
            if(item.first.find(prefix)==0){
                val+=item.second;
            }
        }
        return val;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */