#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> cnt(n, 1), len(n, 1);
        int max_len = 0, res = 0;
        // code 
        for(int i = 0; i < n; i++) {
            for(int j = 0;j < i; j++) {
                if(nums[i] > nums[j]) {
                    if(len[i] < len[j] + 1) {
                        len[i] = len[j] + 1;
                        cnt[i] = cnt[j];
                    } else if(len[i] == len[j] + 1) {
                        cnt[i] += cnt[j];
                    }
                }
            }
            // treating nums[i] as ending point 
            if(len[i] > max_len) {
                max_len = len[i];
                res = cnt[i];
            } else if(len[i] == max_len) {
                res += cnt[i];
            }
        }
        return res;
    }
};


