class Solution { //OPTIMAL
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //Always BS on smaller array
        if (nums1.size() > nums2.size()) 
            return findMedianSortedArrays(nums2, nums1);
        
        int m = nums1.size();
        int n = nums2.size();

        int low = 0;
        int high = m;

        while (low <= high) {
            int cut1 = low + ((high - low) / 2);
            int cut2 = (m + n + 1) / 2 - cut1;

            int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int r1 = (cut1 == m) ? INT_MAX : nums1[cut1];

            int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            int r2 = (cut2 == n) ? INT_MAX : nums2[cut2];

            //Correct partition found
            if (l1 <= r2 && l2 <= r1){
                //odd total length
                if ((m + n) % 2 == 1)
                    return max(l1, l2);
                else //even total length
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
            }

            //too many elements taken from nums1
            else if (l1 > r2) {
                high = cut1 - 1;
            }

            //too many elements taken from nums2
            else {
                low = cut1 + 1;
            }
        }
        return 0.0; //never reached for the valid input
    }
};
