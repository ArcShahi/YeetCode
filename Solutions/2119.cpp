// 2119. A Number After a Double Reversal

int f(int n)
{
     int r{ 0 };

     while (n > 0)
     {
          r = r * 10 + (n % 10);
          n /= 10;
     }
     return r;
}


class Solution {
public:
     bool isSameAfterReversals(int num)
     {

          return num == f(f(num));
     }
};

// Much simpler solultion (BOTH HAS ALMOST SIMLiAR RUN TIME )

// if the last digit is zero it's not going to be same after being reversed
/*
bool isSameAfterReversals(int num) {

        if(!num) return true;
        return num%10 ? 1 : 0;
    }

*/