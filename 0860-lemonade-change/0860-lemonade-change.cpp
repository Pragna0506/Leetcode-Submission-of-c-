class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {

        int five = 0;
        int ten = 0;

        for (int bill : bills) {

            if (bill == 5) {
                // Customer gives $5
                five++;
            }

            else if (bill == 10) {
                // Need $5 change
                if (five == 0)
                    return false;

                five--;
                ten++;
            }

            else { // bill == 20

                // Need $15 change
                if (ten > 0 && five > 0) {
                    // Prefer $10 + $5
                    ten--;
                    five--;
                }
                else if (five >= 3) {
                    // Otherwise use three $5 bills
                    five -= 3;
                }
                else {
                    return false;
                }
            }
        }

        return true;
    }
};