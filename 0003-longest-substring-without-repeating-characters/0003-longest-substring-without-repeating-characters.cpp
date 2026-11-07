class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i =0;
        int j =0;
        int maxi = 0;
        set<char> set;
        while(j<s.size()){
            char c = s[j];
            while(set.contains(c)){
                auto it = set.find(s[i]);
                set.erase(it); //agar set m already vo iten hai toh remove it fro set and increment i;
                i++;
            }
            set.insert(c); //agar set m nhi hai toh just add it
            maxi = max(maxi, j-i+1);
            j++;
        }
        return maxi;
        
    }
};