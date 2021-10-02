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

/** @brief  Constructor for the class PID to initialize all the 
 *          PID parameters.
 *  @param  double Kp, double Ki, double Kd, double dt, double max, double min
 *  @return void
 */

// PID::PID(double Kp, double Ki, double Kd, double dt, double min, double max) {
  
// }

/** @brief  A member function to calculate the PID values based on the current
 *          velocity and required velocity
 *  @param  cur_vel Current process value
 *  @param  req_vel Setpoint value
 *  @return pTerm + iTerm + dTerm 
 */

double PID::getKp() {
  // TODO(Pair_A) : return Kp
  return 0;
}

double PID::getKi() {
  // TODO(Pair_A) : return Ki
  return 0;
}

double PID::getKd() {
  // TODO(Pair_A) : return Kd
  return 0;
}

double PID::getdt() {
  // TODO(Pair_A) : return dt
  return 0;
}

double PID::calculatePID(double process_value, double set_point) {
  // TODO(Pair_A) : Check if dt <=o - throw domain error
  // TODO(Pair_A) : Check if gain values <=0 - throw domain error
  // TODO(Pair_A) : Implement PID logic
  // TODO(Pair_A) : return output
  return 11;
}

/** @brief  A member function to update the PID parameters.
 *  @param  double Kp, double Ki, double Kd, double dt, double max, double min
 *  @return void
 */

double PID::updateGains(double Kp, double Ki, double Kd, double dt, double min,
                        double max) {
  _Kp = Kp;
  _Ki = Ki;
  _Kd = Kd;
  _dt = dt;
  _min = min;
  _max = max;
}
