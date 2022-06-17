//https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        map<int,int> cnt;
        for(int i = 0;i < deck.size();i++) {
            cnt[deck[i]]++;
        }
        int gcd = 0;
        for(auto I : cnt) {
            gcd = __gcd(gcd, I.second);
        }
        return gcd >= 2;
    }
};