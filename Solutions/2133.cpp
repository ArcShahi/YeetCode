//2133. Check if Every Row and Column Contains All Numbers

#include <vector>
#include <unordered_set>
#include <bitset>


// TIME COMPLEXITY : O(N^2)
// SPACE COMPLEXITY : O(N)

class Solution {
public:
     bool checkValid(std::vector<std::vector<int>>& matrix) {

          const int N{ matrix.size() };

          for (int i = 0; i < N; ++i)
               if (!validate_row(matrix, i) || !validate_column(matrix, i)) return false;

          return true;      
     }

private:
     using Matrix = std::vector<std::vector<int>>;

     bool validate_row(const Matrix& matrix, int row) {

          std::unordered_set<int> set{};

          for (int i = 0; i < matrix.size(); ++i)
          {
               auto num{ matrix[row][i] };
               if (set.find(num) != end(set)) return false;
               set.insert(num);
          }
          return true;
     }

     bool validate_column(const Matrix& matrix, int clm)
     {
          std::unordered_set<int> set{};

          for (int i= 0; i < matrix.size(); ++i)
          {
               auto num{ matrix[i][clm] };
               if (set.find(num) != end(set))return false;
               set.insert(num);
          }
          return true;
     }

};


// COMPACTED SOLUTION

// TIME COMPLEXITY : O(N^2)
// SPACE COMPLEXITY : O(N)

class Solution2 {
public:
     bool checkValid(std::vector<std::vector<int>>& matrix) {

          const int n = matrix.size();

          for (int i = 0; i < n; i++) {
              
               std::bitset<100> row{}, clm{};

               for (int j = 0; j < n; j++) {
                    int x{ matrix[i][j] };
                    int y {matrix[j][i]};

                    if (row[x] || clm[y]) return false;

                    row[x] = clm[y] = true;
               }
          }
             
          return true;
     }
};