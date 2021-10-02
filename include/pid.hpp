/** 
 * @file pid.hpp
 * @author Maaruf Vazifdar
 * @author Rishabh Mukund
 * @brief A class to compute PID values for a system.
 * @version 0.1
 * @date 09/30/2021
 * Copyright [2021] <Pair B>
 */

#pragma once
class PID {
  public:
    /**
     * @brief Constructor for class PID
     * @param Kp double - Proportional gain constant
     * @param Ki double - Integral gain constant
     * @param Kd double - Deravitive gain constant
     * @param dt double - Sampling time
     * @param min double - Minimum limit of output value
     * @param max double - Maximum limit of output value 
     */
    PID(double Kp, double Ki, double Kd, double dt, double min, double max){
      _Kp = Kp;
      _Ki = Ki;
      _Kd = Kd;
      _dt = dt;
      _min = min;
      _max = max;
      _error = 0;
      _prev_error = 0;
      _integral = 0;
      _derivative = 0;
    };

    /**
     * @brief Update the gain parameters
     * @param Kp, Ki, Kd, dt, min, max
     */ 
    double updateGains(double Kp, double Ki, double Kd, double dt, double min,
                      double max);

    /**
     * @brief Calculate the output based on the current process
     *        value and the set_point
     * @param process_value double - current value of system
     * @param set_point double - desired value of system
     * @return void
     */
    double calculatePID(double process_value, double set_point);

    /**
     * @brief Get the Kp value
     * @return double 
     */
    double getKp();

    /**
     * @brief Get the Ki value
     * @return double 
     */
    double getKi();

    /**
     * @brief Get the Kd value
     * @return double 
     */
    double getKd();
  
    /**
     * @brief Get the dt
     * @return double 
     */
    double getdt();

  private:
    /**
     * Class local variables.
     */
    double _Kp, _Ki, _Kd, _dt, _max, _min;
    double _error, _prev_error, _integral, _derivative;
};
