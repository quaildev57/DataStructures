class Solution {
public:
//T: O(n) and S: O(1)
    int totalFruit(vector<int>& fruits) {
        map<int, int> map;
        int i = 0;
        int j = 0;
        int maxi = 0;
        while(j<fruits.size()){
            map[fruits[j]]++;
            while(map.size()>2){
            map[fruits[i]]--; // i ka count kam kiya and agar  count 0 hogya toh remove the element
            if(map[fruits[i]] == 0) {
                map.erase(fruits[i]);
            }
            i++;
            }
            maxi = max(maxi, j-i+1);
            j++;
        }
        return maxi;
    }
};