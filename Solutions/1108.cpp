//1108. Defanging an IP Address

#include <string>

class Solution {
public:
     std::string defangIPaddr(std::string address) 
     {
          std::string def_ip{};

          for (const auto c : address)
          {
               if (c != '.')
                    def_ip += c;
               else
                    def_ip += "[.]";      
      
          }
          return def_ip;
     }
};