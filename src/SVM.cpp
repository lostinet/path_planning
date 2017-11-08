
// Space Vector Machine

#include "SVM.h"


StateMachine::State
StateMachine::evaluate_next_state(StateMachine::State cur_state, int target_lane, int cur_lane, bool all_collision,double vel)
{

  // keep lane as a initial state
  State state = KL;


  switch (cur_state) {
    // Keep Lane have 3 possible transitions: Keep lane, Prep Lane Change Left, Prep Lane Change Right
    case KL:
      if (target_lane == cur_lane) state = KL;
      else if (target_lane < cur_lane) state = PLCL;
      else if (target_lane > cur_lane) state = PLCR;
      break;

    // Prep Lane Change Left have 2 possible transitions: staty PLCL, LCL.
    case PLCL:
      if ((target_lane < cur_lane)) {
        if (all_collision || vel > 35.5) state = PLCL;
        else state = LCL;
      }
      break;

    // Lane Change Left -> Keep lane
    case LCL:
      state = KL;
      break;

    // Prep Lane Change Left have 2 possible transitions: staty PLCR, LCR.
    case PLCR:
      if ((target_lane > cur_lane)) {
        if (all_collision || vel > 35.5) state = PLCR;
        else state = LCR;
      }
      break;

    // Lane Change Right -> Keep Lane.
    case LCR:
      state = KL;
      break;


    default:
      state = cur_state;
      break;


  }
  return state;
}
