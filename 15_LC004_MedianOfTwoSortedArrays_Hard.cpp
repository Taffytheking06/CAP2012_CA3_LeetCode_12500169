
double max(double a, double b)
{
    return a > b ? a : b;
}

double min(double a, double b)
{
    return a < b ? a : b;
}

double findMedianSortedArrays(int* nums1, int nums1Size,
                              int* nums2, int nums2Size)
{
    // Always binary search the smaller array
    if (nums1Size > nums2Size)
        return findMedianSortedArrays(nums2, nums2Size,
                                      nums1, nums1Size);

    int total = nums1Size + nums2Size;
    int half = total / 2;

    int left = 0;
    int right = nums1Size;

    while (left <= right)
    {
        int i = (left + right) / 2;
        int j = half - i;

        int Aleft  = (i == 0) ? INT_MIN : nums1[i - 1];
        int Aright = (i == nums1Size) ? INT_MAX : nums1[i];

        int Bleft  = (j == 0) ? INT_MIN : nums2[j - 1];
        int Bright = (j == nums2Size) ? INT_MAX : nums2[j];

        if (Aleft <= Bright && Bleft <= Aright)
        {
            // Even length
            if (total % 2 == 0)
            {
                return (max(Aleft, Bleft) +
                        min(Aright, Bright)) / 2.0;
            }

            // Odd length
            return min(Aright, Bright);
        }

        if (Aleft > Bright)
            right = i - 1;
        else
            left = i + 1;
    }

    return 0.0;
}
