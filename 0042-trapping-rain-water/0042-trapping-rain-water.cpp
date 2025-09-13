class Solution {
public:
    int trap(vector<int>& height) {
        int maxEl=INT_MIN, maxInd=0;
        for(int i =0;i<height.size();i++){
            if(height[i]>=maxEl){   
                maxInd = i;
                maxEl = height[i];
            }
        }
        int preMax = 0;
        int preWater = 0; 
        for(int i=0;i<=maxInd;i++){
            preMax = max(preMax, height[i]);
            preWater += preMax - height[i];
        }
        int sufWater = 0;
        int sufMax = 0;
        for(int i=height.size()-1;i>maxInd;i--){
            sufMax = max(sufMax, height[i]);
            sufWater += sufMax - height[i];
        }
        return sufWater+preWater;
    }
};