/** 
 * @file pid.hpp
 * @author Maaruf Vazifdar
 * @author Rishabh Mukund
 * @brief A class to compute PID values for a system.
 * @version 1
 * @date 09/30/2021
 * Copyright [2021] <Pair B>
 */

#include<pid.hpp>
#include<iostream>

int main() {
  PID pid(0, 0, 0, 1.0, -20.0, 20.0);
  pid.updateGains(0.8, 0.5, 0.3, 1.0, -20.0, 20.0);
  std::cout << pid.calculatePID(5, 50) << std::endl;
  return 0;
}
