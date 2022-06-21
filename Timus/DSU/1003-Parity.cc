/*
 If you don't understand my implementation please read
 this: https://acm.timus.ru/forum/thread.aspx?id=42643&upd=637911606016461599
 Spend some time on that to understand. If you don't get that either please 
 leave. It took me 3 days to get AC on this problem as I was such bad at problem
 solving.
*/

#include <iostream>
#include <map>
#include <cstring>
#include <string>
using namespace std;

map<int, int> tracks;
int limit = 0;
void map_number(int num, int q, int& map1, int& map2) {
    if(tracks.find(num) != tracks.end()) {
        map1 = tracks[num], map2 = map1 + q;
        return;
    }
    map1 = limit;
    map2 = limit + q;
    tracks[num] = limit;
    limit++;
}

int *parents, *sizes;
void init(int n) {
    // cout << "init" << n << endl;
    parents = new int[n + 10], 
    sizes = new int[n + 10], 
    limit = 1;

    for (int i = 0; i < n + 10; i++) parents[i] = i, sizes[i] = 1;

}

int find(int x) {
    if(x == parents[x] ) 
        return x;
    return parents[x] = find(parents[x]);
}

void unite(int a, int b) {
    a = find(a), b = find(b);
    if(a == b) return;
    if(a < b) swap(a,b);
    sizes[a] += b;
    parents[b] = a;
}



int main() {
    int n;
    while(cin >> n) {

        if(n == -1) break;
        int q;
        cin >> q;
        init(2 * q);
        int ans = 0;
        bool invalid = false;
        tracks.clear();
        for( int i = 0; i < q; i++) {
            
            int l, r; string odd_even;
            cin >> l >> r >> odd_even;
            if(invalid) continue;
            ans++;
            l--;
            int l_mapped, not_l_mapped, r_mapped, not_r_mapped;
            map_number(l, q, l_mapped, not_l_mapped);
            // cout << l_mapped << " " << not_l_mapped << endl;
            map_number(r, q, r_mapped, not_r_mapped);
            // cout << r_mapped << " " << not_r_mapped << endl;

            if(odd_even[0] == 'e') {
                unite(l_mapped, r_mapped);
                // cout << l_mapped << "->" << r_mapped << endl;
                unite(not_l_mapped, not_r_mapped);
                // cout << not_l_mapped << "->" << not_r_mapped << endl;
            } 
            else {
                unite(l_mapped, not_r_mapped);
                // cout << l_mapped << "->" << not_r_mapped << endl; 
                unite(not_l_mapped, r_mapped);
                // cout << not_l_mapped << "->" << r_mapped << endl; 


            }
            for(int i = 1; i < limit; i++) {
                // cout<< i << " " << find(i) << " " << i + q << " " << find(i + q) << endl;
                if(find(i) == find(i + q)) {
                    // cout << "invalid" << i << endl;
                    invalid = true;
                    break;
                }
            }
        }
        cout << (invalid ? ans - 1 : ans) << endl;
        delete[] parents, sizes;
    }
    
    return 0;
}
