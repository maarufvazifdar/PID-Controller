/** 
 * @file pid.hpp
 * @author Maaruf Vazifdar
 * @author Rishabh Mukund
 * @brief A class to compute PID values for a system.
 * @version 1
 * @date 09/30/2021
 * Copyright [2021] <Pair B>
 */

#include<iostream>
#include<pid.hpp>

/** @brief  A member function to calculate the PID values based on the current
 *          velocity and required velocity
 *  @param  cur_vel Current process value
 *  @param  req_vel Setpoint value
 *  @return pTerm + iTerm + dTerm 
 */

double PID::getKp() {
  return _Kp;
}

double PID::getKi() {
  return _Ki;
}

double PID::getKd() {
  return _Kd;
}

double PID::getdt() {
  return _dt;
}

double PID::calculatePID(double process_value, double set_point) {
  // TODO(Pair_A) : Check if dt <=o - throw domain error
  // TODO(Pair_A) : Check if gain values <=0 - throw domain error
  // TODO(Pair_A) : Implement PID logic
  // TODO(Pair_A) : return output

  return 11;
}
