// 65. Valid Number
#include <string>
#include <algorithm>

enum class State 
{
     Alpha,     // Start
     Beta,      // Sign
     Gamma,     // Integer digits
     Delta,     // Dot seen (may or may not have digits before)
     Epsilon,   // Digits after dot
     Zeta,      // 'e' or 'E'
     Eta,       // Sign after 'e'
     Theta,     // Exponent digits
     Reject     // Invalid input
};

namespace Handler {

     State shift_state(State state, char c) {
          switch (state) {
          case State::Alpha:  // Starting state
               if (c == '+' || c == '-') return State::Beta;
               if (isdigit(c)) return State::Gamma;
               if (c == '.') return State::Delta;
               return State::Reject;

          case State::Beta:  // Sign seen
               if (isdigit(c)) return State::Gamma;
               if (c == '.') return State::Delta;
               return State::Reject;

          case State::Gamma:  // Digits before dot
               if (isdigit(c)) return State::Gamma;
               if (c == '.') return State::Epsilon;
               if (c == 'e' || c == 'E') return State::Zeta;
               return State::Reject;

          case State::Delta:  // Dot without digits before
               if (isdigit(c)) return State::Epsilon;
               return State::Reject;

          case State::Epsilon:  // Fraction digits
               if (isdigit(c)) return State::Epsilon;
               if (c == 'e' || c == 'E') return State::Zeta;
               return State::Reject;

          case State::Zeta:  // 'e' seen
               if (c == '+' || c == '-') return State::Eta;
               if (isdigit(c)) return State::Theta;
               return State::Reject;

          case State::Eta:  // Sign after 'e'
               if (isdigit(c)) return State::Theta;
               return State::Reject;

          case State::Theta:  // Exponent digits
               if (isdigit(c)) return State::Theta;
               return State::Reject;

          default:
               return State::Reject;
          }
     }

     bool in_final(State s) {
          return s == State::Gamma || s == State::Epsilon || s == State::Theta;
     }
}

class Solution {
public:
     bool isNumber(std::string s) {
         
          State state = State::Alpha;
          for (char c : s) {
               state = Handler::shift_state(state, c);
               if (state == State::Reject)
                    return false;
          }

          return Handler::in_final(state);
     }
};