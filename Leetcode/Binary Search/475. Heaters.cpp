// optimizable


// O(n*log(m))
class Solution {
public:
    int closestdist(int &val,vector<int>& heaters)
    {
        auto lb=lower_bound(heaters.begin(),heaters.end(),val);
        if(lb==heaters.end()) lb--;
        auto lb2=lb;
        if(lb2!=heaters.begin()) lb2--;
        return min(abs(*lb2-val),abs(*lb-val));
    }
        
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(),heaters.end());
        int mn=0;
        for(auto &i:houses)
        {
            mn=max(mn,closestdist(i,heaters));
        }
        return mn;
    }
};


// O(n*log(INT_MAX)*log(m))
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(),heaters.end());
        long long int l=0,h=INT_MAX,m,ans=0;
        while(l<=h)
        {
            m=l+(h-l)/2;
            int f=0;
            for(auto i:houses)
            {
                auto lb=lower_bound(heaters.begin(),heaters.end(),i);
                if(lb==heaters.end()) lb--;
                auto lb2=lb;
                if(lb2!=heaters.begin()) lb2--;
                if(abs(*lb-i)>m && abs(*lb2-i)>m)
                {
                    f=1;
                    break;
                }
                else f=2;
            }
            if(f<=1) l=m+1;
            else {ans=m;h=m-1;}
    }
        return ans;
    }
};
