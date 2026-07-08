class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        return {celsius+(double)273.15,celsius*(double)1.8+(double)32};
    }
};