class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> m;
        for(auto it : magazine){
            m[it]++;
        }
        for(int i=0;i<ransomNote.size();i++){
            if(m[ransomNote[i]]>0){
                m[ransomNote[i]]-=1;
            }else{
                return false;
            }
        }
        return true;
    }
};