/** 
 * @file pid.hpp
 * @author Maaruf Vazifdar
 * @author Rishabh Mukund
 * @brief A class to compute PID values for a system.
 * @version 1.1
 * @date 09/30/2021
 * Copyright [2021] <Pair B>
 */

#include <gtest/gtest.h>
#include"../include/pid.hpp"

/**
* @brief Test for invalid sampling time
*/
TEST(invaliddt, checkParameters) {
  PID pid1(1, 1, 1, 0, 0, 0);
  EXPECT_THROW(pid1.calculatePID(1, 5), std::domain_error);
  PID pid2(1, 1, 1, -1, 0, 0);
  EXPECT_THROW(pid1.calculatePID(1, 5), std::domain_error);
}

/**
* @brief Test for invalid gain parameters
*/
TEST(invalidGains, checkParameters) {
  // invalid Kp
  PID pid1(0, 1, 1, 1, 10, 10);
  EXPECT_THROW(pid1.calculatePID(1, 5), std::domain_error);
  PID pid2(-1, 1, 1, 1, 10, 10);
  EXPECT_THROW(pid1.calculatePID(1, 5), std::domain_error);

  // invalid Ki
  PID pid3(1, 0, 1, 1, 10, 10);
  EXPECT_THROW(pid1.calculatePID(1, 5), std::domain_error);
  PID pid4(1, -1, 1, 1, 10, 10);
  EXPECT_THROW(pid1.calculatePID(1, 5), std::domain_error);

  // invalid Kd
  PID pid5(1, 1, 0, 1, 10, 10);
  EXPECT_THROW(pid1.calculatePID(1, 5), std::domain_error);
  PID pid6(1, 1, -1, 1, 10, 10);
  EXPECT_THROW(pid1.calculatePID(1, 5), std::domain_error);
}

/**
* @brief Test for valid gain parameters
*/
TEST(validGains, checkParameters) {
  // valid Kp
  EXPECT_NO_THROW(PID pid(1, 1, 1, 1, 0, 0));
  EXPECT_NO_THROW(PID pid(5, 1, 1, 2, 0, 0));

  // valid Ki
  EXPECT_NO_THROW(PID pid(1, 1, 1, 1, 0, 0));
  EXPECT_NO_THROW(PID pid(1, 5, 1, 2, 0, 0));

  // valid Kd
  EXPECT_NO_THROW(PID pid(1, 1, 1, 1, 0, 0));
  EXPECT_NO_THROW(PID pid(1, 1, 5, 2, 0, 0));
}

/**
* @brief Tests for checking PID Implementation
*/
TEST(PIDLogicTest1, test_computeOutput) {
  PID pid(0.8, 0.5, 0.3, 1.0, -20.0, 20.0);

  double output = pid.calculatePID(0, 5);
  ASSERT_NEAR(8, output, 0.5);
}
TEST(PIDLogicTest2, test_computeOutput) {
  PID pid(0.8, 0.5, 0.3, 1.0, -20.0, 20.0);

  double output = pid.calculatePID(5, 15);
  ASSERT_NEAR(16, output, 0.5);
}
TEST(PIDLogicTest3, test_computeOutput) {
  PID pid(0.8, 0.5, 0.3, 1.0, -20.0, 20.0);
  double output = pid.calculatePID(10, -2);
  ASSERT_NEAR(-19.2, output, 0.5);
}

/**
* @brief Test for Output Constraints.
*/
TEST(outputConstrain, test_constraints) {
  PID pid(10, 5, 30, 1.0, -10.0, 10.0);
  ASSERT_LE(pid.calculatePID(5, 25), 10);
  ASSERT_GE(pid.calculatePID(20, -2), -10);
}
