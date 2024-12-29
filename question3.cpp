#include<bits/stdc++.h>
using namespace std;
bool isSubsetSum(const vector<int>& nums, int n, int sum) {
    if (sum == 0) return true;
    if (n == 0) return false;
    if (nums[n - 1] > sum) {
        return isSubsetSum(nums, n - 1, sum);
    }
    return isSubsetSum(nums, n - 1, sum) || 
           isSubsetSum(nums, n - 1, sum - nums[n - 1]);
}
int main() {
    vector<int> nums = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    int n = nums.size();
    if (isSubsetSum(nums, n, sum)) {
        cout << "Found a subset with the given sum." << endl;
    } else {
        cout << "No subset with the given sum." << endl;
    }
    return 0;
}
