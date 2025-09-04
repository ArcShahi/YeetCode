// 451. Sort Characters By Frequency

#include <vector>
#include <string>
#include <queue>
#include <unordered_map>

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY: O(N)

class Solution {
     
public:
     std::string frequencySort(std::string s) {
          std::unordered_map<char, int> hmap{};
          hmap.reserve(62);

          // Count character frequencies
          for (char c : s) ++hmap[c];

          std::vector<Pair> data;
          data.reserve(hmap.size());
          for (auto& [ch, freq] : hmap) 
               data.emplace_back(ch, freq);
          
          // Lambda to compare
          auto cmp = [](const Pair& a, const Pair& b) {
               return a.second < b.second;  // max-heap by frequency
               };

          // (heapify) O(N) time 
          std::priority_queue<Pair, std::vector<Pair>,decltype(cmp)> pq{cmp, std::move(data)};
      
          std::string str{};
          str.reserve(s.size()); 
          while (!pq.empty()) {
               auto [ch, freq] = pq.top();pq.pop();
               str.append(freq, ch); 
          }

          return str;
     }
private:
     using Pair = std::pair<char, int>;
};


// NOTES

/*
* // USING OVERLOAD 4 ; Check CPP refernce
 std::priority_queue<Pair, std::vector<Pair>, Greater> pq(Greater{}, std::move(data));

  We could have used Function Objects ( Functors ) for Comparison

   struct Greater {
          bool operator()(const Pair& a, const Pair& b) const {
               return a.second < b.second;
          }
     };

     std::priority_queue<Pair, std::vector<Pair>, Greater> pq(Greater{}, std::move(data));

     Well the time complexity , would be O(KlogK) where K is Unique chars. And the input size is
     fixed 62 if included 52 Upper,lower chars and 10 digits.

     LogK is the complexity for popping but K is fixed =62 so the entire complexity

     O(K) and O(N) worst 
*/