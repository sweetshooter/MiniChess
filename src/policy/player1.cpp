#include <cstdlib>

#include "../state/state.hpp"
#include "./player1.hpp"


/**
 * @brief Randomly get a legal action
 * 
 * @param state Now state
 * @param depth You may need this for other policy
 * @return Move 
 */
Move Player1::get_move(State *state, int depth){
  if(!state->legal_actions.size())
    state->get_legal_actions();
  
  auto actions = state->legal_actions;
  return actions[(rand()+depth)%actions.size()];
}

Move Player1::MiniMax(State *state, int depth){
  for(auto move: state.legal_actions)
  
}