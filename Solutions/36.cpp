// 36. Valid Sudoku

#include <vector>
#include <unordered_set>
#include <bitset>

// TIME COMPLEXITY : O(N^2)
// SPACE COMPLEXITY :O(N)

class Solution {
public:
     bool isValidSudoku(std::vector<std::vector<char>>& board) {

         
          for (int i=0; i < N; ++i)
          {
               if (!validate_row(board, i) || !validate_clm(board, i)) return false;

               if (i == 0 || i == 3 || i == 6)
                    for (int j{ 0 }; j < N; j += G)
                         if (!validate_grid(board, i, j)) return false;
          }
          return true;
     }
private:
     static constexpr int N{ 9 };
     static constexpr int G{ 3 };
     using Board = std::vector<std::vector<char>>;

     bool validate_row(const Board& board,int row)
     {
          std::bitset<9> seen{};

          for (int i=0; i < N; ++i)
          {
               auto ch{ board[row][i] };
               if (ch == '.') continue;
               auto idx{ ch - '1' };
               if (seen[idx])return false;
               seen.set(idx);
          }

          return true;
     }

     bool validate_clm(const Board& board,int clm)
     {
          std::bitset<9> seen{};

          for (int i= 0; i < N; ++i)
          {
               auto ch{ board[i][clm]};
               if (ch == '.') continue;
               auto idx{ ch - '1' };
               if (seen[idx]) return false;
               seen.set(idx);
          }
          return true;
     }
     
     bool validate_grid(const Board& board,int row, int clm)
     {
          std::bitset<9> seen{};

          for (int i=row; i < row+G; ++i)
               for (int j=clm; j <clm+G; ++j)
               {
                    auto ch{ board[i][j] };
                    if (ch == '.') continue;
                    auto idx{ ch - '1' };
                    if (seen[idx]) return false;
                    seen.set(idx);
               }

          return true;
     }
};


// COMPACTED VERSION

// SAME COMPLEXITY

class Solution {
public:
     bool isValidSudoku(const std::vector<std::vector<char>>& board) {

          std::vector<std::bitset<9>> rows(9), cols(9), boxes(9);

          for (int i = 0; i < 9; ++i) {
               for (int j = 0; j < 9; ++j) {

                    char ch{ board[i][j] };
                    if (ch == '.') continue;

                    int idx{ ch - '1' };
                    int box{ (i / 3) * 3 + (j / 3) };

                    if (rows[i][idx] || cols[j][idx] || boxes[box][idx])
                         return false;

                    rows[i][idx] = cols[j][idx] = boxes[box][idx] = true;           
               }
          }
          return true;
     }
};
