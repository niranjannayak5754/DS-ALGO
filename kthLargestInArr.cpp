#include <iostream>
#include <vector>
#include <queue>

using namespace std; // Adding this line to use the std namespace

// Abstract base class (interface)
class PriorityQueueInterface {
public:
    virtual void push(int value) = 0;
    virtual void pop() = 0;
    virtual int top() const = 0;
    virtual ~PriorityQueueInterface() {} // Virtual destructor for proper cleanup
};

// Concrete class implementing the interface for max-heap
class MaxHeapPriorityQueue : public PriorityQueueInterface {
private:
    priority_queue<int> pq;

public:
    void push(int value) override {
        pq.push(value);
    }

    void pop() override {
        pq.pop();
    }

    int top() const override {
        return pq.top();
    }
};

// Concrete class implementing the interface for min-heap
class MinHeapPriorityQueue : public PriorityQueueInterface {
private:
    priority_queue<int, vector<int>, greater<int>> pq;

public:
    void push(int value) override {
        pq.push(value);
    }

    void pop() override {
        pq.pop();
    }

    int top() const override {
        return pq.top();
    }
};

class Solution {
private:
    int heap_algo(PriorityQueueInterface& pq, int k, vector<int>& nums) {
        for (int val : nums) {
            pq.push(val);
        }

        for (int i = 1; i < k; i++)
            pq.pop();

        return pq.top();
    }

public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        if (n - k + 1 < k) {
            MinHeapPriorityQueue pq;
            cout << "using min heap" << endl;
            return heap_algo(pq, n - k + 1, nums);
        }
        cout << "using max heap" << endl;
        MaxHeapPriorityQueue pq;
        return heap_algo(pq, k, nums);
    }
};

class SolutionQuickSelect {
public:
    int quickSelect(vector<int>& nums, int l, int r, int k){
        int pivot = nums[r];
        int p = l;

        for(int i = l; i< r; i++){
            if(nums[i] <= pivot){
                swap(nums[i], nums[p]);
                p++;
            }
        }

        swap(nums[p], nums[r]);

        if(p < k)
            return quickSelect(nums, p+1, r, k);
        else if(p > k)
            return quickSelect(nums, l, p-1, k);

        return nums[p];
    }

    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        return quickSelect(nums, 0, n-1, n-k);
    }
};

int main() {
    Solution solution;
    vector<int> nums = {3, 1, 4, 1, 5, 9, 2, 6, 5};
    int k;
    cout << "Enter K: ";
    cin >> k;

    int result = solution.findKthLargest(nums, k);
    cout << "The " << k << "th largest element is: " << result << endl;

    return 0;
}
