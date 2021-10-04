/** 
 * @file pid.hpp
 * @author Maaruf Vazifdar
 * @author Rishabh Mukund
 * @brief A class to compute PID values for a system.
 * @version 1
 * @date 09/30/2021
 * Copyright [2021] <Pair B>
 */

#include <iostream>
#include <stdexcept>
#include <pid.hpp>

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
  if (getdt() <= 0.0)
    throw std::domain_error("The delta t must be greater than zero");
  else if (getKp() <= 0 || getKi() <= 0 || getKd() <= 0)
    throw std::domain_error("Kp, Kd and Ki must be greater than zero");

  double error = set_point - process_value;
  double derivative = (error - _prev_error) / getdt();
  _integral += error*getdt();
  double output = getKp()*error + getKi()*_integral + getKd()*derivative;

  _prev_error = error;

  if (output <= _min) output = _min;
  else if (output >= _max) output = _max;

  std::cout << "output = " << output << std::endl;
  return output;
}
