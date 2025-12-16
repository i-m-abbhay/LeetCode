class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //making sure the nums1 is always the smaller array
        if(nums1.size()>nums2.size()){
            vector<int> temp = nums1;
            nums1 = nums2;
            nums2 = temp;
        }

        int m = nums1.size();
        int n = nums2.size();

        int total = m + n;
        int leftSize = (total + 1)/2; //the left partition should be this size
        
        int low = 0; 
        int high = m;

        while(low <= high){
            int i = low + (high-low)/2; //these many elements from first arr
            int j = leftSize - i; // these many from second
            
            double leftA, rightA, leftB, rightB;
            if(i==0)
                leftA = -1e18;
            else 
                leftA = nums1[i-1];
            
            if(i==m)    
                rightA = 1e18;
            else
                rightA = nums1[i];
            
            if(j==0)
                leftB = -1e18;
            else
                leftB = nums2[j-1];
            
            if(j==n)
                rightB = 1e18;
            else
                rightB = nums2[j];
            
            //to check if the partition we did is valid
            if(leftA <= rightB && leftB <= rightA){
                if(total%2 == 1){
                    return max(leftA, leftB);
                } else {
                    double leftMax = max(leftA, leftB);
                    double rightMin = min(rightA, rightB);
                    return (leftMax + rightMin) / 2.0;
                }
            }
            if(leftA > rightB){
                high = i - 1;
            } else {
                low = i + 1;
            }
        }
        return 0.0;
    }
};