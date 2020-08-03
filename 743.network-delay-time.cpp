/*
 * @lc app=leetcode id=743 lang=cpp
 *
 * [743] Network Delay Time
 *
 * https://leetcode.com/problems/network-delay-time/description/
 *
 * algorithms
 * Medium (45.00%)
 * Likes:    1738
 * Dislikes: 226
 * Total Accepted:    103K
 * Total Submissions: 229.4K
 * Testcase Example:  '[[2,1,1],[2,3,1],[3,4,1]]\n4\n2'
 *
 * There are N network nodes, labelled 1 to N.
 * 
 * Given times, a list of travel times as directed edges times[i] = (u, v, w),
 * where u is the source node, v is the target node, and w is the time it takes
 * for a signal to travel from source to target.
 * 
 * Now, we send a signal from a certain node K. How long will it take for all
 * nodes to receive the signal? If it is impossible, return -1.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: times = [[2,1,1],[2,3,1],[3,4,1]], N = 4, K = 2
 * Output: 2
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * N will be in the range [1, 100].
 * K will be in the range [1, N].
 * The length of times will be in the range [1, 6000].
 * All edges times[i] = (u, v, w) will have 1 <= u, v <= N and 0 <= w <= 100.
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int N, int K)
    {
        vector<vector<pair<int, int>>> g(N + 1);

        for (int i = 0; i < times.size(); i++)
        {
            g[times[i][0]].push_back({times[i][1], times[i][2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> d(N + 1, INT_MAX);
        d[K] = 0;
        pq.push({0, K});

        while (!pq.empty())
        {
            //Current Node:
            int u = pq.top().second;
            int w = pq.top().first;

            pq.pop();

            if (d[u] < w)
                continue;

            for (int i = 0; i < g[u].size(); i++)
            {
                int v = g[u][i].first;
                int c = g[u][i].second;
                if (d[v] > d[u] + c)
                {

                    d[v] = d[u] + c;
                    pq.push({d[v], v});
                }
            }
        }
        int res = 0;
        for (int i = 1; i < d.size(); i++)
        {
            res = max(res, d[i]);
        }

        if (res == INT_MAX)
            return -1;

        return res;
    }
};
// @lc code=end
