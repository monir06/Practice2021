// Tricky, Not as usual, interesting also

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=0,h=nums.size()-1,m;
        while(l<h) // 
        {
            m=(l+h)/2;
            if(m&1) m--;
            if(nums[m]==nums[m+1]) l=m+2; //
            else h=m; //
        }
        return nums[h];
    }
};
