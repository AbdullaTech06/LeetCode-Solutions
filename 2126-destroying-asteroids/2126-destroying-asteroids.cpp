class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        long long cmass=mass;
        for(int i=0;i<asteroids.size();i++){
            if(asteroids[i]>cmass)return false;
            cmass+=asteroids[i];
        }
        return true;
    }
};