class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {     
        int maxthresh = k * threshold;   // avg = sum/k so sum = k*avg but agar inequality ki baat hai toh threshhold se bada hona chahiye sum/k or avg

    int sum = 0;
    //first window
    //runs upto k
    for(int i = 0; i < k; i++){
        sum+=arr[i];
    }

    int count = 0;

    if(sum >= maxthresh){
        count++;
    }
    //next window
    //runs from k to end
    //therefore, the T: O(n)
    for(int i = k; i<arr.size(); i++){
        sum += arr[i];
        sum -= arr[i-k];

        if(sum >= maxthresh){
            count++;
        }
    }
    return count;
    }
};