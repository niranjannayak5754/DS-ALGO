#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> res;
        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < k; i++)
        {
            pq.push({nums[i], i});
        }

        res.push_back(pq.top().first);
        int index = 0; // index is i - k

        for (int i = k; i < nums.size(); i++)
        {
            pq.push({nums[i], i});
            while (pq.top().second <= index)
                pq.pop();
            res.push_back(pq.top().first);

            index++;
        }

        return res;
    }
};

class Solution2
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> res;
        deque<int> dq; // doubly linnked list. allows to get and pop first as well as last element

        for (int i = 0; i < nums.size(); i++)
        {
            if (!dq.empty() && dq.front() == i - k)
                dq.pop_front();

            while (!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();

            dq.push_back(i);
            if(i >= k - 1)
                res.push_back(nums[dq.front()]);
        }

        return res;
    }
};