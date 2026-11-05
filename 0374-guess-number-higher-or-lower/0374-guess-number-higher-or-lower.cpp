class Solution {
public:
    int guessNumber(int n) {

        long long left = 1;
        long long right = n;

        while (left <= right) {

            long long mid = left + (right - left) / 2;

            int result = guess(mid);

            if (result == 0) {
                return mid;
            }
            else if (result == -1) {
                // mid is greater than pick
                right = mid - 1;
            }
            else {
                // mid is smaller than pick
                left = mid + 1;
            }
        }

        return -1;
    }
};