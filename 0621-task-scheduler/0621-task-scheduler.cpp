class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>m;
        for(auto it:tasks){
            m[it]++;
        }
        int time=0;
        priority_queue<int> pq;
        for(auto it:m){
            pq.push(it.second);
        }
        while(!pq.empty()){
            vector<int> cool;
            int cycle=n+1;
            int tasks=0;
            for(int i=0;i<cycle;i++){
                if(!pq.empty()){
                    int cfreq=pq.top();
                    pq.pop();
                    tasks++;
                
                if(cfreq>1){
                    cool.push_back(cfreq-1);
                }
                }
            }
            for(int rem:cool){
                pq.push(rem);
            }
            time+=pq.empty()?tasks:cycle;
        }
        return time;
    }
};