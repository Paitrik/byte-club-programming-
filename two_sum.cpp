#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> seen;   

    for (int i = 0; i < (int)nums.size(); i++) {
        int need = target - nums[i];      

        if (seen.count(need))            
            return {seen[need], i};       

        seen[nums[i]] = i;                
    }
    return {};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, target;
    cin >> n >> target;

    vector<int> nums(n);
    for (auto& x : nums) cin >> x;

    auto ans = twoSum(nums, target);
    cout << "[" << ans[0] << "," << ans[1] << "]\n";
}
