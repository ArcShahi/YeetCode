// 3442. Maximum Difference Between Even and Odd Frequency I
#include <string>


class Solution {
public:
     int maxDifference(std::string s) {

          int arr[26]{};

          for (const auto& c : s)
               ++arr[c - 'a'];

          int odd{ -1 };
          int even{ 1000 }; // string length is [3,100] 
     
          for (int i{ 0 }; i < 26; ++i)
          {
               if (arr[i] == 0) continue;

               if (arr[i] & 1) odd = std::max(odd, arr[i]);
               else even = std::min(even, arr[i]);     
          }

          return odd - even;
     }
};
#include <print>

int main()
{
     Solution sln{};

     std::println("{}", sln.maxDifference("aaaaabbc"));

}