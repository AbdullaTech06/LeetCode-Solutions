class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
     int n = nums.size();
     int st=0,end=n-1;
     int mid;
     vector<int> result;
     int leftmost=-1;
     int rightmost=-1;

     while(st<=end){
        mid = st + (end-st)/2;
      //to find leftmost index 
        if(nums[mid]==target){
          leftmost=mid;
          end=mid-1;
        }else if(nums[mid]>target){
        end=mid-1;
        }else{
            st = mid+1;
        }
     }
     st=0;
     end=n-1;

          while(st<=end){
        mid = st + (end-st)/2;
      //to find rightmost index 
        if(nums[mid]==target){
          rightmost=mid;
          st=mid+1;
        }else if(nums[mid]>target){
        end=mid-1;
        }else{
            st = mid+1;
        }
     }
     result.push_back(leftmost);
     result.push_back(rightmost);

     return result;

    }
};