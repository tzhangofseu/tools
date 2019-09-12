class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        unordered_map<int, int>::iterator it;
        for (int i = 0; i < nums.size(); ++i) {
            it = m.find(target - nums[i]);
            if (it != m.end()) {
                return {it->second, i};
            }
            m.insert(make_pair(nums[i], i));
        }
        return {-1, -1};
    }
};
