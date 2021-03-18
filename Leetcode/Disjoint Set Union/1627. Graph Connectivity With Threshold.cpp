class Solution {
public:
    int par[10002];
    int find(int &x)
    {
        if(par[x]==x) return x;
        return par[x]=find(par[x]); // return find(par[x]) results in tle
    }
    void make_union(int &i,int &j)
    {
        int a=find(i);
        int b=find(j);
        if(a!=b) par[a]=b;
    }
    vector<bool> areConnected(int n, int t, vector<vector<int>>& q) {
        // int par[n+1];
        for(int i=1;i<=n;i++) par[i]=i;
        for(int i=t+1,j,a,b;i<=n;i++)
        {
            j=i;
            while(j<=n)
            {
                make_union(i,j);
                j+=i;
            }
        }
        vector<bool> res; 
        for(auto v:q) {
            res.push_back(find(v[0]) == find(v[1]));
        }
        return res;
    }
};
