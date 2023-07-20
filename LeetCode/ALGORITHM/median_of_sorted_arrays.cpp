class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int total_size = nums1.size() + nums2.size();
        int a = 0, b = 0, num1, num2;
        double ans;

        for (int i = 0; i < (total_size + 1) / 2; i++)
        {
            num1 = (a == nums1.size() ? INT_MAX : nums1[a]);
            num2 = (b == nums2.size() ? INT_MAX : nums2[b]);

            if (num1 < num2)
            {
                a++;
                ans = num1;
            }
            else
            {
                b++;
                ans = num2;
            }
        }

        if (total_size % 2 == 0)
        {
            num1 = (a == nums1.size() ? INT_MAX : nums1[a]);
            num2 = (b == nums2.size() ? INT_MAX : nums2[b]);
            ans += min(num1, num2);
            ans /= 2;
        }

        return ans;
    }
};