

class Solution {
private:
template <typename T, typename U>
    auto maxm(T a, U b){
        return a>b ? a : b;
    }
public:
    
    int maxDistinctElements(vector<int>& nums, int k) {
        using int64 = long long;
        vector<pair<int,int>> ranges;
        ranges.reserve(nums.size());
        for(int x: nums){
            ranges.push_back(make_pair((int64)x-k, (int64)x+k));
        }
        sort(ranges.begin(), ranges.end(),[](const auto&a, const auto &b){          if(a.second!=b.second) return a.second<b.second;
            return a.first < b.first;
        });
        int64 last = LLONG_MIN/4;
        int ans=0;
        for(const auto& [L,R]: ranges){
            int64 candidate = maxm(L, last+1);
            if (candidate <= R){
            last = candidate;
            ans++;
            }
        }
        return ans;
    }
};