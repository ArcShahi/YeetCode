// 12. Integer to Roman

#include <string>
#include <vector>

// TIME  COMPLEXITY : O(1)
// SPACE COMPLEXITY: O(1)

class Solution {
public:
     std::string intToRoman(int num) 
     {      
          using namespace std::string_literals;

          static const std::vector<std::pair<int, std::string>> symbols{
                {1000,"M"s},{900,"CM"s},{500,"D"s},{400,"CD"s},{100,"C"s},
               {90,"XC"s},{50,"L"s},{40,"XL"s},{10,"X"s},{9,"IX"s},
               {5,"V"s},{4,"IV"s},{1,"I"s}
          };
 
          std::string roman{};

          for (const auto& [f, s] : symbols)
          {
               while (f<=num)
               {
                    roman += s;
                    num -= f;
               }
          }

          return roman;

     }
};
