 // beware with set functions to avoid tle
 class Solution {
public:
    static bool cmp(vector<int> &a,vector<int> &b)
    {
        if(a[1]==b[1]) return a[0]<b[0];
        return a[1]<b[1];
    }
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end(),cmp);
        set<int> st;
        for(int i=1;i<=100000;i++) st.insert(i);
        for(auto i:events)
        {
            auto s=i[0],e=i[1];
            auto lb=st.lower_bound(s);
            if(lb==st.end()||*lb>e) continue;
            else {
                st.erase(lb); // st.erase(*lb) caused tle
            }
        }
        return (int)1e5-(int)st.size();
    }
};
