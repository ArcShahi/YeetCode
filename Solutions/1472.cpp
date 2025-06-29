// 1472. Design Browser History

#include <string>
#include <list>
#include <iterator>


class BrowserHistory {
public:
     BrowserHistory(std::string homepage) {
          tabs.push_back(homepage);
          curr = begin(tabs);
     }

     void visit(std::string url) {
          // Clear forward history
          tabs.erase(std::next(curr), tabs.end());

          // Add new page and move current pointer to it
          tabs.push_back(url);
          curr = std::prev(tabs.end());
     }

     std::string back(int steps) {
          while (steps-- > 0 && curr != begin(tabs))
               --curr;
         
          return *curr;
     }

     std::string forward(int steps) {
          while (steps-- > 0 && std::next(curr) != end(tabs))
               ++curr;
          
          return *curr;
     }

private:
     std::list<std::string> tabs{};
     std::list<std::string>::iterator curr;
};


// YOU CAN IMPLEMENT IT USING : std::vector , std::deque