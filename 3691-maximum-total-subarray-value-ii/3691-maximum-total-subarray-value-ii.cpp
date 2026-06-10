class SegmentTree{
public:
    vector<int> segmentTree;
    bool isMinTree;

    SegmentTree(vector<int>& nums,bool flag){
        int n=nums.size();
        this->isMinTree=flag;

        segmentTree.resize(4*n);
        buildSegmentTree(0,0,n-1,nums);
    }

    void buildSegmentTree(int i,int l,int r,vector<int>& nums){
        if(l==r){
            segmentTree[i]=nums[l];
            return;
        }
        int mid=l+(r-l)/2;
        buildSegmentTree(2*i+1,l,mid,nums);
        buildSegmentTree(2*i+2,mid+1,r,nums);

        if(isMinTree){
            segmentTree[i]=min(segmentTree[2*i+1],segmentTree[2*i+2]);
        }else{
            segmentTree[i]=max(segmentTree[2*i+1],segmentTree[2*i+2]);
        }
    }

    int querySegmentTree(int st,int end,int i,int l,int r){
        if(l>end || r<st){
            return isMinTree?INT_MAX:INT_MIN;
        }
        if(l>=st && r<=end){
            return segmentTree[i];
        }
        int mid=l+(r-l)/2;

        int a=querySegmentTree(st,end,2*i+1,l,mid);
        int b=querySegmentTree(st,end,2*i+2,mid+1,r);

        if(isMinTree){
            return min(a,b);
        }
        return max(a,b);
    }

    int query(int l,int r,int n){
        return querySegmentTree(l,r,0,0,n-1);
    }
};
class Solution {
public: 
    typedef long long ll;

    ll getVal(int l,int r,SegmentTree& minST,SegmentTree& maxST,int n){
        int minel=minST.query(l,r,n);
        int maxel=maxST.query(l,r,n);
        return (ll)maxel-(ll)minel;
    }

    long long maxTotalValue(vector<int>& nums, int k) {
        int n=nums.size();

        SegmentTree minST(nums,true); //min
        SegmentTree maxST(nums,false); //max

        priority_queue<tuple<ll,int,int>> pq;

        //best values se initialize kardo
        for(int l=0;l<n;l++){
            ll val=getVal(l,n-1,minST,maxST,n);
            pq.push({val,l,n-1});
        }

        ll ans=0;
        while(k--){
            auto[val,l,r]=pq.top();
            pq.pop();
            ans+=val;
            if(r>l){
                ll nextbest=getVal(l,r-1,minST,maxST,n);
                pq.push({nextbest,l,r-1});
            }
        }
        return ans;
    }
};