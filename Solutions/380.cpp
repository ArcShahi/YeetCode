// 380. Insert Delete GetRandom O(1)

#include <unordered_set>
#include <random>

class RandomizedSet {
public:
     RandomizedSet() {
          set.reserve(100);
     }

     bool insert(int val) {
      
          if (set.contains(val)) return false;
          set.insert(val);
          return true;
     }

     bool remove(int val) {

          if (set.contains(val))
          {
               set.erase(val);
               return true;
          }
          return false;
     }

     int getRandom(const std::unordered_set<int>& set) {
         
          static std::random_device rd;
          static std::mt19937 gen(rd()); // mersenne twister engine
          std::uniform_int_distribution<std::size_t> dist(0, set.size() - 1);

          std::size_t idx = dist(gen);
          return *std::next(set.begin(), idx);
     }


private:
     std::unordered_set<int> set{};
};