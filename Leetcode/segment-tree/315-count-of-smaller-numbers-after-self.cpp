#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void MergeWithConstraint(vector<int>& count, vector<pair<int,int>>& v, int left, int mid, int right) {
        vector<pair<int,int>> temp(right - left + 1);
        int i = left;
        int j = mid + 1;
        int k = 0;


        while(i <= mid and j <= right) { // sorting in descending order
            if(v[i].first <= v[j].first) {
                temp[k++] = v[j++];
            } else {
                count[v[i].second] += right - j + 1;
                temp[k++] = v[i++];
            }
        }

        while(i <= mid) {
            temp[k++] = v[i++];
        }
        while(j <= right) {
            temp[k++] = v[j++];
        }
        for(int i = left;i <= right;i++) {
            v[i] = temp[i - left];
        }
    }
    void Merge(vector<int>& count, vector<pair<int,int>>& v, int left, int right){
        if(left >= right) return;
        int mid = left + (right - left) / 2;
        Merge(count, v, left, mid);
        Merge(count, v, mid+1, right);
        MergeWithConstraint(count, v, left, mid, right);
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(n, 0);
        vector<pair<int,int>> v(n);
        for(int i = 0;i < n;i++) { // val and index
            v[i] = make_pair(nums[i], i);
        }
        Merge(count, v, 0, n-1);
        return count;
    }
};

int main() {
    vector<int> nums = {5, 2, 6, 1};
    Solution solution;
    vector<int> cnt = solution.countSmaller(nums);
    for(int i:cnt ) cout << i << " ";
}