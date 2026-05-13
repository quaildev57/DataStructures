class Solution {
public:
int sumOfSq(int n){
    int sum = 0;
    while(n>0){
        int digit = n%10;
        sum += digit*digit;
        n/=10;
    }
    return sum;
}
    bool isHappy(int n) {
        unordered_set<int> found;
        while(n != 1 && found.find(n) == found.end()){
            found.insert(n);
            n = sumOfSq(n);
        }
        return n == 1;
        
    }
};