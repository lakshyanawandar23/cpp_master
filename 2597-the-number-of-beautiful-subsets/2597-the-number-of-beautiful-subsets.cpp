class Solution {
public:
      int solve(int index, vector<int>& nums, int k, unordered_map<int, int>& mp) {
        if (index == nums.size()) {
            return 1;
        }

        int op1 = 0, op2 = 0;
        int element = nums[index];
        bool canInclude = true;

        if (mp[element - k] > 0 ) {
            canInclude = false;
        }

        if (canInclude) {
            mp[element]++;
            op1 = solve(index + 1, nums, k, mp);
            mp[element]--;
        }

        op2 = solve(index + 1, nums, k, mp);

        return op1 + op2;
    }

public:
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        sort(nums.begin(),nums.end());
        return solve(0, nums, k, mp) - 1;
    }
};