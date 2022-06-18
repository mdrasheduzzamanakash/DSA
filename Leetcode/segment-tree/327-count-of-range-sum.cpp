#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int countWithMergeSort(vector<long> &sums, int left, int right, int lower, int upper) {
        int count = 0;
        if(right - left <= 1) {
            if(right - left == 1) {
                return (lower <= sums[left] and sums[left] <= upper);
            } else {
                return 0;
            }
        }
        int mid = (left + right) / 2;
        int leftSideSum = countWithMergeSort(sums, left, mid, lower, upper);
        int rightSideSum = countWithMergeSort(sums, mid, right, lower, upper);

        int i = left;
        int j = mid;
        int n = 0;
        int m = 0;

        vector<long> cache(right - left, 0);
        int k = 0;

        while(i < mid) {
            while(n+mid < right and (sums[n+mid] - sums[i]) < lower) n++;
            while(m+mid < right and sums[m+mid]-sums[i] <= upper) m++;
            while(j < right and sums[i] > sums[j]) cache[k++] = sums[j++];
            cache[k++] = sums[i++];
            count += m - n; 
        }

        while(j < right) cache[k++] = sums[j++];
        for(int i = 0;i < cache.size();i++) sums[left + i] = cache[i];
        return leftSideSum + rightSideSum + count;
    }
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long> prefixSum(nums.size(), 0);
        int n = nums.size();
        prefixSum[0] = nums[0];
        for(int i = 1;i < n;i++) prefixSum[i] = nums[i] + prefixSum[i-1];
        return countWithMergeSort(prefixSum, 0, n, lower, upper);
    }
};