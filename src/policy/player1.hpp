#pragma once
#include "../state/state.hpp"


/**
 * @brief Policy class for random policy, 
 * your policy class should have get_move method
 */
class Player1{
public:
  static Move get_move(State *state, int depth);
  static Move MiniMax(State *state, int depth);
};