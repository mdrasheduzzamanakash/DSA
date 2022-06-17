#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

struct edge{
    int a, b;
};

int *parents, *sizes;
void init(int n) {
    parents = new int[n + 5];
    sizes = new int[n + 5];
    for (int i = 0; i <= n; i++) parents[i] = i, sizes[i] = 1;
}

int find(int x) {
    while(x != parents[x]) x = parents[x];
    return x;
}

void unite(int a, int b) {
    a = find(a), b = find(b);
    if(sizes[a] < sizes[b]) std::swap(a, b);
    sizes[a] += sizes[b];
    parents[b] = a;
}

bool is_connected(int a, int b) {
    return find(a) == find(b);
}

int main() {
    int n, tmp1, tmp2;
    scanf("%d", &n);
    init(n);
    std::vector< struct edge > redundant_roads;
    for (int i = 0; i < n - 1; i++) {
        scanf("%d %d", &tmp1, &tmp2);
        if(is_connected(tmp1, tmp2)) redundant_roads.push_back({tmp1, tmp2});
        else unite(tmp1, tmp2);
    }
    bool track_parents[n + 5];
    memset(track_parents, false, sizeof(track_parents));
    std::queue< int > component_parents;
    for (int i = 1; i <= n; i++) {
        int parent = find(i);
        if(track_parents[parent]) continue;
        track_parents[parent] = true;
        component_parents.push(parent);
    }
    printf("%d\n", redundant_roads.size());

    int a_component = component_parents.front();
    component_parents.pop();

    for(auto x: redundant_roads) {
        printf("%d %d %d %d\n",  x.a, x.b, a_component, component_parents.front());
        component_parents.pop();
    }

    return 0;
}
