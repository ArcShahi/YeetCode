// 728. Self Dividing Numbers
#include <vector>

bool self_div(const int x)
{
     int n{ x };
     while (n)
     {
          if (n % 10 == 0 || x%(n%10)!=0) return false;
          n /= 10;
     }
     return true;
}

class Solution {
public:
     std::vector<int> selfDividingNumbers(int left, int right) {

          std::vector<int> num{};

          for (int i{ left }; i <= right; ++i)
               if (self_div(i)) num.push_back(i);

          return num;
     }
};