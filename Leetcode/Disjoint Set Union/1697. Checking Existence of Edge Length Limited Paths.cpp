// whats the catch?
// we can process queries offline
// for a query we only need to work with every edge with distance less than of it (e[dis]<q[dist]) 
// we can do the above task using two pointer
// now for only checking path we can use dsu

// find a detail explanation on https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths/discuss/978450/C%2B%2B-DSU-%2B-Two-Pointers


class Solution {
public:
    int par[100002],rank[100002];
    int find(int x)
    {
        if(par[x]==x) return x;
        return par[x]=find(par[x]);
    }
    void union_set(int &a,int &b)
    {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (rank[a] < rank[b])
                swap(a, b);
            par[b] = a;
            if (rank[a] == rank[b])
                rank[a]++;
        }
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& e, vector<vector<int>>& que) {
        for(int i=0;i<n;i++) par[i]=i;
        memset(rank,0,sizeof rank);
        for(int i=0;i<que.size();i++) que[i].push_back(i);
        sort(e.begin(),e.end(),[](auto &l,auto &r) {return l[2]<r[2];});
        sort(que.begin(),que.end(),[](auto &l,auto &r) {return l[2]<r[2];});
        
        int i=0;
        vector<bool> result(que.size());
        for (auto &q:que) 
        {
            while (i<e.size() && e[i][2]<q[2]) {
                union_set(e[i][0],e[i][1]);
                i++;
            }
			
            result[q.back()]=find(q[0]) == find(q[1]);
        }
        return result;
    }
};
