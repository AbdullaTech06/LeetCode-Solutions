class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {

        int totalSum = 0;

        for (int n : nums) {
            vector<int> temp;

            for (int j = 2; j * j <= n; j++) {
                if (n % j == 0) {
                    temp.push_back(j);
                    if (j != n / j)
                        temp.push_back(n / j);
                }
            }

            if (temp.size() == 2) {
                totalSum += 1 + n + temp[0] + temp[1];
            }
        }
        return totalSum;
    }
};
