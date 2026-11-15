class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int count=0;
        int n =arr.size();

        for(int i =0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum +=arr[j];
                if(sum%2!=0){
                count++;
                }
            }
        }
        return count;
    }
};