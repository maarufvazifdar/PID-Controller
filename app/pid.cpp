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

  if (_Kp <= 0)
    throw std::domain_error("Kp should be greater than 0.");
  else if (_Ki <= 0)
    throw std::domain_error("Ki should be positive.");
  else if (_Kd <= 0)
    throw std::domain_error("Kd should be positive.");
  else if (_dt <= 0)
    throw std::domain_error("Sample time should be positive.");

  // Calculate Error
  double _error = set_point - process_value;

  // Proportional term
  double pTerm = PID::getKp() * _error;

  // Integral term
  _integral += _error * _dt;
  double iTerm = PID::getKi() * _integral;

  // Deravitive term
  _derivative = (_error - _prev_error) / PID::getdt();
  double dTerm = PID::getKd() * _derivative;

  // Output value
  double output = pTerm + iTerm + dTerm;

  // Constraint the output value between min and max
  if (output > _max)
    output = _max;
  else if (output < _min)
    output = _min;

  _prev_error = _error;
  return output;

  // return 11;
}
