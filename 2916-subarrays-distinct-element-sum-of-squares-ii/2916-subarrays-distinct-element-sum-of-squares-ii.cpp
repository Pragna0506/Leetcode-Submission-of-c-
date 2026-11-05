
class Solution {
    using ll = long long;
    static const int MOD = 1'000'000'007;

    struct Node {
        ll sum = 0;
        ll sumSq = 0;
        ll lazy = 0;
    };

    vector<Node> tree;
    int n;

    void apply(int node, int left, int right, ll add) {
        ll len = right - left + 1;
        ll oldSum = tree[node].sum;

        tree[node].sumSq =
            (tree[node].sumSq
             + 2LL * add % MOD * oldSum % MOD
             + add * add % MOD * len % MOD) % MOD;

        tree[node].sum =
            (oldSum + add * len % MOD) % MOD;

        tree[node].lazy = (tree[node].lazy + add) % MOD;
    }

    void push(int node, int left, int right) {
        if (tree[node].lazy == 0 || left == right)
            return;

        int mid = left + (right - left) / 2;
        ll add = tree[node].lazy;

        apply(node * 2, left, mid, add);
        apply(node * 2 + 1, mid + 1, right, add);

        tree[node].lazy = 0;
    }

    void update(int node, int left, int right,
                int ql, int qr, ll add) {
        if (ql > right || qr < left)
            return;

        if (ql <= left && right <= qr) {
            apply(node, left, right, add);
            return;
        }

        push(node, left, right);

        int mid = left + (right - left) / 2;

        update(node * 2, left, mid, ql, qr, add);
        update(node * 2 + 1, mid + 1, right, ql, qr, add);

        tree[node].sum =
            (tree[node * 2].sum + tree[node * 2 + 1].sum) % MOD;

        tree[node].sumSq =
            (tree[node * 2].sumSq + tree[node * 2 + 1].sumSq) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        n = nums.size();
        tree.assign(4 * n, Node());

        unordered_map<int, int> lastSeen;
        ll answer = 0;

        for (int i = 0; i < n; i++) {
            int previous = -1;

            if (lastSeen.count(nums[i]))
                previous = lastSeen[nums[i]];

            // Increase distinct counts for all subarrays
            // ending at i that did not contain nums[i] before.
            update(1, 0, n - 1, previous + 1, i, 1);

            lastSeen[nums[i]] = i;

            // Sum of squared distinct counts for subarrays
            // ending at this index.
            answer = (answer + tree[1].sumSq) % MOD;
        }

        return (int)answer;
    }
};
