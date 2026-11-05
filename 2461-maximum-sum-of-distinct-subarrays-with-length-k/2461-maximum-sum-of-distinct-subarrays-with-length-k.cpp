class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        long long sum = 0;
        long long maxii = 0;

        map<int, int> maps;
        int dups = 0;

        // First window
        for(int i = 0; i < k; i++) {

            maps[nums[i]]++;

            if(maps[nums[i]] > 1) {
                dups++;
            }

            sum += nums[i];
        }

        if(dups == 0) {
            maxii = max(maxii, sum);
        }

        // Sliding window
        for(int i = k; i < nums.size(); i++) {

            int numToAdd = nums[i];
            int numToRemove = nums[i-k];

            maps[numToAdd]++;

            if(maps[numToAdd] > 1) {
                dups++;
            }

            sum += numToAdd;

            if(maps[numToRemove] > 1) {
                dups--;
            }

            maps[numToRemove]--;
            sum -= numToRemove;

            if(dups == 0) {
                maxii = max(maxii, sum);
            }
        }

        return maxii;
    }
};
// class Solution {
// public:
//     long long maximumSubarraySum(vector<int>& nums, int k) {
//         long sum = 0;
//         long maxii = 0;
//         map<int,int> maps;
//         int dups = 0;
//         for(int i=0;i<k;i++){
//             if(!maps.containsKey(nums[i])){
//                 maps.insert(nums[i], 0);
//             }
//             maps.insert(nums[i], maps.get(nums[i])+1); //i wale index + 1 is the frquency of nums[i]
//             sum+=nums[i];

//             if(maps.get[nums[i] > 1){
//                 dups++;
//             }
//         }
//         if(dups == 0){
//             maxii = max(maxii, sum);
//         }

//         for(int i =k; i< nums.size(); i++){
//             int numTo Add = nums[i];
//             int numsToRemove = nums[i-k];

//             if(!maps.containsKey(numToAdd)+1){ //freq badhai
//                 maps.insert(numToAdd, 0);
//             }
//             maps.insert(numToAdd, numToAdd);

//             if(maps.get(numToAdd) > 1){
//                 dup++;
//             }
//             sum+= numToAdd; 
//             if(maps.get(numToRemove)>1){
//                 dups--;

//             }
//             mas.insert(numToRemove, maps.get(numToRemove)-1); //freq ghatayi
//             sum -= numToRemove;

//             if(dups==0){
//                 maxii  = max(sum, maxii);
//             }
//         }
//         return maxii;

//     }
// };

