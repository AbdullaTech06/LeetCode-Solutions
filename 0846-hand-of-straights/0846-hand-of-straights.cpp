class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0)return false;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto it:hand){
            pq.push(it);
        }
        unordered_map<int,int> m;
        for(auto it:hand){
            m[it]++;
        }
        while(!pq.empty()){
            int a=pq.top();
            if(m[a]==0){
                pq.pop();
                continue;
            }
            for(int i=0;i<groupSize;i++){
                int curr=a+i;
                if(m[curr]==0)return false;
                m[curr]--;
            }
        }
        return true;
    }
};