class Solution
{
    public:
        int count_set_bits(int x)
        {
            int cnt = 0;
            while (x != 0)
            {
                if (x &1 == 1) cnt++;
                x = x >> 1;	//right shift by one

            }
            return cnt;
        }
    int minBitFlips(int start, int goal) {
        if(start == goal) return 0;
        int num = start^goal;
        int res = count_set_bits(num);
        return res;
    }
};