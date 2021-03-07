/*
 * @lc app=leetcode.cn id=943 lang=cpp
 *
 * [943] 最短超级串
 */

// @lc code=start
class Solution {
public:
    string shortestSuperstring(vector<string>& words) {
        // a->b 非前缀的距离，也就是a -> b 节点的距离
        auto un_prefix_length = [](const string& a, const string& b) -> int {
            int d = b.length();
            for (int i = 1; i <= min(a.length(), b.length()); ++i) {
                if (a.substr(a.size() - i) == b.substr(0, i))
                    d = b.size() - i;
            }
            return d;
        };

        // 把words构建成一张图
        int n = words.size();
        vector<vector<int>> g(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                g[i][j] = un_prefix_length(words[i], words[j]);
                g[j][i] = un_prefix_length(words[j], words[i]);
            }
        }

        // dp[i] 表示路径，由words中的节点构成的路径图，
        // dp[i][j] 表示路径是i，然后路径中的最后一个节点是j 
        // parent 表示在这个路径下，记录的所有parent路径，用于恢复路径
        vector<vector<int>> dp(1 << n, vector<int>(n, INT_MAX / 2));
        vector<vector<int>> parent(1 << n, vector<int>(n, -1));
        for (int i = 0; i < n; ++i) {
            dp[1 << i][i] = words[i].size();
        }

        for (int k = 1; k < (1 << n); ++k) {
            for (int i = 0; i < n; ++i) {
                if (k & (1<<i)) {
                    int pre = k - (1<<i);  //  上一个路径
                    for (int j = 0; j < n; ++j) {
                        if (dp[pre][j] + g[j][i] < dp[k][i]) {
                            dp[k][i] = dp[pre][j] + g[j][i];
                            parent[k][i] = j;
                        }
                    }
                }
            }
        }

        auto it = min_element(begin(dp.back()), end(dp.back()));
        int current = it - begin(dp.back());
        string ans;
        int k = (1 << n) - 1;
        while (k) {
            int pre = parent[k][current];
            if (pre < 0) ans = words[current] + ans;
            else ans = words[current].substr(words[current].size() - g[pre][current]) + ans;
            k &= ~(1 << current);
            current = pre;
        }
        return ans;
    }
};
// @lc code=end

