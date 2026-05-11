class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> result;
        for(int i: nums){
            string str = to_string(i);
            for(char ch:str){
                result.push_back(ch-'0');
            }
        }
    return result;

    }
};