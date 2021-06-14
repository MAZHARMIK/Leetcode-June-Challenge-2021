class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        auto lambda = [&](vector<int>& v1, vector<int>& v2) {
            return v1[1] > v2[1];
        };
        
        sort(begin(boxTypes), end(boxTypes), lambda);
        int n = boxTypes.size();
        int units = 0;
        
        for(int i = 0; i<n; i++) {
            int boxCount     = boxTypes[i][0];
            int unitsPerBox  = boxTypes[i][1];
            
            int freq   = min(truckSize, boxCount);
            truckSize -= freq;
            units     += (unitsPerBox*freq);

            if(truckSize == 0)
                break;
        }
        
        return units;
    }
};
