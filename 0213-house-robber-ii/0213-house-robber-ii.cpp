class Solution {
public:
    int rob(vector<int>& nums) {
       
        //the answer can not contain first and last houses together
        if(nums.size()==1) return nums[0];
        vector<int> temp_nums_with_1, temp_nums_without_1;
        for(int i=0;i<nums.size();i++){
            // we can answer this by this approach.. what if we leave last house to get one answer which   considered first house
            if(i!=nums.size()-1) temp_nums_with_1.push_back(nums[i]);

            // and we can do the same to get our answer leaving the first house but considering the last one.
            if(i!=0) temp_nums_without_1.push_back(nums[i]);
           
        }
      
        //then we can compare both and get the max;

        return max(robHelper(temp_nums_without_1), robHelper(temp_nums_with_1));

    }
    int robHelper(vector<int> &money){
        int prev = money[0];
        int prev2 = 0;
        for(int i=1;i<money.size();i++){
            int take = money[i]+prev2;
            int not_take = 0 + prev;
            int curi = max(take, not_take);
            prev2 = prev;
            prev = curi;
        }
        return prev;
    }
};