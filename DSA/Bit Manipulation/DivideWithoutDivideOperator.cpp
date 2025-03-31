#include <climits>
#include <cmath>

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == divisor) return 1;
        
        // Determine sign of the result
        bool sign = (dividend > 0) == (divisor > 0);
        
        // Use long long to handle edge cases
        long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);
        int quotient = 0;
        
        // Core division logic
        while (n >= d) {
            int cnt = 0;
            while (n >= (d << (cnt + 1))) {
                cnt++;
            }
            quotient += 1LL << cnt;
            n -= d << cnt;
        }
        
        // Handle overflow
        if (quotient > INT_MAX) return sign ? INT_MAX : INT_MIN;
        
        return sign ? quotient : -quotient;
    }
};
