//TC - O(M+N)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int m = nums1.size();
        int n = nums2.size();
        int total  = m+n;

        int mid1 = (total -1)/2;
        int mid2 = total/2;

        int i=0, j=0;
        int count = 0;
        int first =0, second=0;

        while(i<m || j<n){
            int val; //stores ci=urrent smallest element

            if(i<m && (j>= n || nums1[i]<=nums2[j])){
                val = nums1[i];
                i++;
            }
            else{
                val = nums2[j];
                j++;
            }
            if(count == mid1){
                first = val;
            }
            if(count == mid2){
                second = val;
            }
            count++;
        }
        if(total%2==0)
           return (first+second)/2.0;
        
        return second;
        
    }
};
