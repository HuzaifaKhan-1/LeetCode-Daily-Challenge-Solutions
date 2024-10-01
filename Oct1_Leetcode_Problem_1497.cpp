class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> remainderCount(k,0);

        //Counting frequencies of remainders
        for(int num : arr) {
            int rem = (num % k + k) % k; //Ensuring remainder is non-negative
            remainderCount[rem]++;
        }

        //check for pairs with remainder 0
        if (remainderCount[0] % 2 != 0) //Must be even to pair
            return false;
    

    // Checking pair for all other remainders
    for (int i = 1; i <= k/2; i++) {
        if (remainderCount[i] != remainderCount[k - i]) // Remainder i must pair with k-i
            return false;
    
    }
    return true;
    }
};
