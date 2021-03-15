// https://www.geeksforgeeks.org/split-the-given-array-into-k-sub-arrays-such-that-maximum-sum-of-all-sub-arrays-is-minimum/


class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int ans=0,mid,low=1,high=1e9,n=weights.size();
        for(int i=0;i<n;i++) low=max(low,weights[i]);
        while(low<=high)
        {
            mid=(low+high)/2;
            int c=0,sum=0;
            for(int i=0;i<n;i++)
            {
                sum+=weights[i];
                if(sum>mid) {
                    sum=weights[i];
                    c++;
                }
            }
            c++;
            if(c<=D)
            {
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};
