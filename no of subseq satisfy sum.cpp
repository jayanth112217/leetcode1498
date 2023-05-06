class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int count=0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int mod=1000000007;
        int pow[n];
        pow[0]=1;
        for(int i=1;i<n;i++){
            pow[i]=(pow[i-1]*2)%mod;
        }
        int left=0;
        int right=n-1;
        while(left<=right){
            if(nums[left]+nums[right]<=target){
                count+=pow[right-left];
                count%=mod;
                left++;
            }
            else right--;
        }
        return count;
    }
};