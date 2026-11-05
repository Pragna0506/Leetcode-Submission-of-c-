#include <bits/stdc++.h>
using namespace std;

class Solution {
    int n, timer;
    vector<vector<int>> adj;
    vector<int> parent, depth, subtree, heavy;
    vector<int> head, pos, bit;
    string s;

    void dfsSize(int u, int p) {
        parent[u] = p;
        subtree[u] = 1;
        heavy[u] = -1;

        int largest = 0;

        for (int v : adj[u]) {
            if (v == p) continue;

            depth[v] = depth[u] + 1;
            dfsSize(v, u);
            subtree[u] += subtree[v];

            if (subtree[v] > largest) {
                largest = subtree[v];
                heavy[u] = v;
            }
        }
    }

    void decompose(int u, int h) {
        head[u] = h;
        pos[u] = ++timer;

        if (heavy[u] != -1)
            decompose(heavy[u], h);

        for (int v : adj[u]) {
            if (v == parent[u] || v == heavy[u]) continue;
            decompose(v, v);
        }
    }

    void add(int i, int val) {
        for (; i <= n; i += i & -i)
            bit[i] ^= val;
    }

    int queryPrefix(int i) {
        int result = 0;
        for (; i > 0; i -= i & -i)
            result ^= bit[i];
        return result;
    }

    int rangeQuery(int l, int r) {
        return queryPrefix(r) ^ queryPrefix(l - 1);
    }

    int pathMask(int u, int v) {
        int mask = 0;

        while (head[u] != head[v]) {
            if (depth[head[u]] < depth[head[v]])
                swap(u, v);

            mask ^= rangeQuery(pos[head[u]], pos[u]);
            u = parent[head[u]];
        }

        if (depth[u] > depth[v])
            swap(u, v);

        mask ^= rangeQuery(pos[u], pos[v]);
        return mask;
    }

public:
    vector<bool> palindromePath(
        int n,
        vector<vector<int>>& edges,
        string s,
        vector<string>& queries
    ) {
        this->n = n;
        this->s = s;
        timer = 0;

        adj.assign(n, {});
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        parent.assign(n, -1);
        depth.assign(n, 0);
        subtree.assign(n, 0);
        heavy.assign(n, -1);
        head.assign(n, 0);
        pos.assign(n, 0);
        bit.assign(n + 1, 0);

        dfsSize(0, -1);
        decompose(0, 0);

        for (int u = 0; u < n; u++)
            add(pos[u], 1 << (s[u] - 'a'));

        vector<bool> answer;

        for (const string& q : queries) {
            stringstream ss(q);
            string type;
            int u;
            ss >> type >> u;

            if (type == "update") {
                char c;
                ss >> c;

                add(pos[u], 1 << (s[u] - 'a'));
                s[u] = c;
                add(pos[u], 1 << (s[u] - 'a'));
            } else {
                int v;
                ss >> v;

                int mask = pathMask(u, v);
                answer.push_back((mask & (mask - 1)) == 0);
            }
        }

        return answer;
    }
};