class Solution {
public:
    int knapsack(vector<vector<int>>& boxTypes, int W, int n) {
        if(n == 0 || W == 0)
            return 0;
        
        int taken = 0;
        if(boxTypes[n-1][0] > 0) {
            taken    += boxTypes[n-1][1];
            vector<vector<int>> boxTypesTemp = boxTypes;
            boxTypesTemp[n-1][0] -= 1;
            taken += knapsack(boxTypesTemp, W-boxTypes[n-1][0], n);
        }
        int notTaken = knapsack(boxTypes, W, n-1);
        
        return max(taken, notTaken);
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size();
        
        return knapsack(boxTypes, truckSize, n);
    }
};
