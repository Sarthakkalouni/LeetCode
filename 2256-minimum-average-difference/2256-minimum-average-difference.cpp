class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n =nums.size();

        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];

        }
        long long ls =0;
        long long rs =0;
        int result =INT_MAX;
        int idx=-1;

        for(int i=0;i<n;i++){
            ls+=nums[i];
            rs = sum-ls;

            int n1 =i+1;
            int n2 = n-n1;


       long long left_avg = ls/n1;
       long long right_avg =(i==n-1) ? 0 : rs/n2;
       int diff =abs(left_avg-right_avg);

       if(result>diff){
        result=diff;
        idx=i;
       }
        }
        return idx;
        
    }
};