#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> sTree;
    void update(int st, int en, int ind, int node) {
        if(ind < st or ind > en) return;
        if(st == en) {
            sTree[node] = 1;
            return;
        }
        int mid = st + (en - st) / 2;
        if(ind <= mid) update(st, mid, ind, node*2+1);
        else update(mid+1, en, ind, 2*node+2);
        sTree[node] = sTree[node*2+1] + sTree[node*2+2];
    }

    long long query(int st, int en, int l, int r, int node) {
        if(r < st or l > en) {
            return 0;
        }
        if(st >= l and en <= r) {
            return sTree[node];
        }
        int mid = st + (en - st) / 2;
        long long lq = query(st, mid, l, r, 2*node + 1);
        long long rq = query(mid+1, en, l, r, 2*node + 2);
        return lq + rq;
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        sTree.resize(4*n, 0);
        vector<pair<long long, long long> > vp(n);

        // pairwise storing of elements {element, index}
        for(int i = 0;i < n;i++) vp[i] = {nums[i], i};
        // sorting elements 
        sort(vp.begin(), vp.end());

        long long j = 0;
        long long ans = 0;
        for(int i = 0;i < n;i++) {
            while(j < n and vp[i].first > 2*vp[j].first) update(0, n-1, vp[j++].second,0);
            ans += query(0, n-1, vp[i].second+1, n-1, 0);
        }
        return ans;
    }
};