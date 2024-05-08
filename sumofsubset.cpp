#include <iostream>
#include <vector>

using namespace std;

void subsetSum(vector<int>& nums, int targetSum, vector<int>& subset, int index) {
    if (targetSum == 0) {
        for (int num : subset)
            cout << num << " ";
        cout << endl;
        return;
    }

    if (index >= nums.size() || targetSum < 0)
        return;

    subset.push_back(nums[index]);
    subsetSum(nums, targetSum - nums[index], subset, index + 1);

    subset.pop_back();
    subsetSum(nums, targetSum, subset, index + 1);
}

int main() {
    vector<int> nums = {2, 4, 6, 8, 10};
    int targetSum = 10;
    vector<int> subset;

    subsetSum(nums, targetSum, subset, 0);

    return 0;
}
