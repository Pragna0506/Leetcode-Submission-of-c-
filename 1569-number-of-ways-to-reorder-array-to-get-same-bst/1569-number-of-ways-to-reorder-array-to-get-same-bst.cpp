
class Solution {
    using ll = long long;
    static const int MOD = 1'000'000'007;

    vector<vector<ll>> choose;

    ll countWays(vector<int>& nums) {
        int n = nums.size();

        if (n <= 2)
            return 1;

        vector<int> left, right;

        int root = nums[0];

        for (int i = 1; i < n; i++) {
            if (nums[i] < root)
                left.push_back(nums[i]);
            else
                right.push_back(nums[i]);
        }

        ll leftWays = countWays(left);
        ll rightWays = countWays(right);

        ll combinations = choose[n - 1][left.size()];

        return combinations * leftWays % MOD * rightWays % MOD;
    }

public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();

        choose.assign(n, vector<ll>(n, 0));

        for (int i = 0; i < n; i++) {
            choose[i][0] = choose[i][i] = 1;

            for (int j = 1; j < i; j++) {
                choose[i][j] =
                    (choose[i - 1][j - 1] + choose[i - 1][j]) % MOD;
            }
        }

        return (countWays(nums) - 1 + MOD) % MOD;
    }
};
