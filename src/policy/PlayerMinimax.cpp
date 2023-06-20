#include <cstdlib>
#include <climits>
#include <iostream>
#include "../state/state.hpp"
#include "./PlayerMinimax.hpp"


/**
 * @brief Randomly get a legal action
 * 
 * @param state Now state
 * @param depth You may need this for other policy
 * @return Move 
 */
Move PlayerMinimax::get_move(State *state, int depth){
  state->get_legal_actions();
  int bestScore;

  if(state->player) 
    bestScore = INT_MAX;
  else 
    bestScore = INT_MIN;

  auto actions = state->legal_actions;
  Move move = actions[0];
    for(auto it : actions){
      auto nextState = state->next_state(it);
      if(state->player) {
        int moveScore = PlayerMinimax::minimax(nextState, depth-1, 1-state->player); //nextstate need to get lower point
        if(moveScore < bestScore){ //bestScore have updated
          bestScore = moveScore;
          move = it;
        }
      }
      else{
        int moveScore = PlayerMinimax::minimax(nextState, depth-1, 1-state->player);
        if(moveScore > bestScore){ //bestScore have updated
          bestScore = moveScore;
          move = it;
        }
      } 
    }
  return move;
}


int PlayerMinimax::minimax(State* state, int depth, int isMaximizingPlayer){
  // isMaximizingPlayer is used to judge what the player is
  // if isMaximizingPlayer = 0, it means your turn , get the max value
  
  int nowplayer = state->player;
  int score;

  if(depth == 0||state->legal_actions.empty()){  //evaluate only calculate white - black
    score = state->evaluate();
    return score; 
  }
  // assume i'm white
  
  if(isMaximizingPlayer == 0 ){ // my turn
    int bestScore = INT_MIN;
    state->get_legal_actions();
    if(!state->legal_actions.empty()){
      for(auto move: state->legal_actions) {
        auto nextState = state->next_state(move);
        int moveScore = minimax(nextState, depth-1, 1);
        bestScore = std::max(bestScore, moveScore); 
      }
      return bestScore;
    } 
  }
  else{ // oppn's turn
    int bestScore = INT_MAX;
    state->get_legal_actions();
    if(!state->legal_actions.empty()){
      for(auto move: state->legal_actions){
        auto nextState = state->next_state(move);
        int moveScore = minimax(nextState, depth-1, 0);
        bestScore = std::min(bestScore, moveScore); 
      }
      return bestScore;
    }
  }
}