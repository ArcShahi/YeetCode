// 273. Integer to English Words
#include <string>
#include <vector>
#include <unordered_map>




 const std::vector<std::string> ones = {
    "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
    "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen",
    "Sixteen", "Seventeen", "Eighteen", "Nineteen"
};

const std::vector<std::string> tens = 
{
    "", "", "Twenty", "Thirty", "Forty", "Fifty",
    "Sixty", "Seventy", "Eighty", "Ninety"
};
 const std::vector<std::pair<int, std::string>> units = { 
      {
       {1000000000, "Billion"}, {1000000, "Million"}, {1000, "Thousand"}, {100, "Hundred"}} 
      };

class Solution {
public:
     std::string numberToWords(int num)
     {
          if (num == 0) return "Zero";

          std::string result;

          for (const auto& [value, unit] : units) 
          {
               if (num >= value)
               {
                    int count = num / value;
                    result += convert100(count) + ' ' + unit + ' ';
                    num %= value;
               }
          }

          if (num > 0) {
               result += convert100(num) + ' ';
          }

  
          if (!result.empty()) {
               result.pop_back();
          }

          return result;
     }

private:
     std::string convert100(int num) 
     {
          std::string result{};

          if (num >= 100) 
          {
               result += ones[num / 100] + " Hundred ";
               num %= 100;
          }

          if (num >= 20) {
               result += tens[num / 10] + ' ';
               num %= 10;
          }

          if (num > 0) {
               result += ones[num] + ' ';
          }

          // Remove trailing space
          if (!result.empty()) {
               result.pop_back();
          }

          return result;
     }
};
