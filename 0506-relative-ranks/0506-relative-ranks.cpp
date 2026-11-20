class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<int> pq;
        for(auto it:score){
            pq.push(it);
        }
        unordered_map<int,string> m;
        if(!pq.empty()){
            m[pq.top()]="Gold Medal";
            pq.pop();
        }
        if(!pq.empty()){
            m[pq.top()]="Silver Medal";
            pq.pop();
        }
        if(!pq.empty()){
            m[pq.top()]="Bronze Medal";
            pq.pop();
        }
        int x=4;
        while(!pq.empty()){
            m[pq.top()]=to_string(x);
            pq.pop();
            x++;
        }
        vector<string> ans;
        for(int i=0;i<score.size();i++){
            ans.push_back(m[score[i]]);
        }
        return ans;
    }
};