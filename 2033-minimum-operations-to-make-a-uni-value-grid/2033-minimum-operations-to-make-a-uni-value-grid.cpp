class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        int rem = grid[0][0] % x;

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] % x != rem)
                    return -1;
                nums.push_back(grid[i][j]);
            }
        }

        sort(nums.begin(), nums.end());

        int mid = nums[nums.size() / 2];
        int ans = 0;

        for(int i = 0; i < nums.size(); i++) {
            ans += abs(nums[i] - mid) / x;
        }

        return ans;
    }
};