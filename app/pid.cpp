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
  return _Kp;
  return 0;
}

double PID::getKi() {
  return _Ki;
  return 0;
}

double PID::getKd() {
  return _Kd;
  return 0;
}

double PID::getdt() {
  return _dt;
  return 0;
}

double PID::calculatePID(double process_value, double set_point) {
  // Calculate Error
  double _error = set_point - process_value;

  // Proportional term
  double pTerm = _Kp * _error;

  // Integral term
  _integral += _error * _dt;
  double iTerm = _Ki * _integral;

  // Deravitive term
  _derivative = _error - _prev_error;
  double dTerm = _Kd * _derivative;

  // Output value
  double output = pTerm + iTerm + dTerm;

  // Constraint the output value between min and max
  if (output > _max)
    output = _max;
  else if (output < _min)
    output = _min;

  _prev_error = _error;
  return output;
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
