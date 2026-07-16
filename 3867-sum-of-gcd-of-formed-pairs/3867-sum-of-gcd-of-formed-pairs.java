class Solution {
    public int gcd(int a,int b){
        if(b==0) return a;

        return gcd(b,a%b);
    }
    public long gcdSum(int[] nums) {
        int n=nums.length;
        int prefix[]=new int[n];
        int max=nums[0];
        for(int i=0;i<n;i++){
            max=Math.max(max,nums[i]);
            prefix[i] = gcd(nums[i],max);
        }
        Arrays.sort(prefix);
 
        long sum=0;
        int i=0,j=n-1;
        while(i<j){
            sum+=(long)gcd(prefix[i],prefix[j]);
            i++;
            j--;
        }
        return sum;

    }
}