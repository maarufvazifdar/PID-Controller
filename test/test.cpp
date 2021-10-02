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

// /**
// * @brief Test for invalid sampling time
// */
// TEST(invaliddt, checkParameters) {
//   EXPECT_THROW(PID pid(1, 1, 1, 0, 0, 0),std::domain_error);
//   EXPECT_THROW(PID pid(1, 1, 1, -2, 0, 0),std::domain_error);
// }

// /**
// * @brief Test for invalid gain parameters
// */
// TEST(invalidGains, checkParameters) {
//   // invalid Kp
//   EXPECT_THROW(PID pid(0, 1, 1, 1, 0, 0),std::domain_error);
//   EXPECT_THROW(PID pid(-1, 1, 1, 2, 0, 0),std::domain_error);

//   // invalid Ki
//   EXPECT_THROW(PID pid(1, 0, 1, 1, 0, 0),std::domain_error);
//   EXPECT_THROW(PID pid(1, -1, 1, 2, 0, 0),std::domain_error);

//   // invalid Kd
//   EXPECT_THROW(PID pid(1, 1, 0, 1, 0, 0),std::domain_error);
//   EXPECT_THROW(PID pid(1, 1, -1, 2, 0, 0),std::domain_error);
// }

// /**
// * @brief Test for valid gain parameters
// */
// TEST(validGains, checkParameters) {
//   // valid Kp
//   EXPECT_NO_THROW(PID pid(0, 1, 1, 1, 0, 0));
//   EXPECT_NO_THROW(PID pid(-1, 1, 1, 2, 0, 0));

//   // valid Ki
//   EXPECT_NO_THROW(PID pid(1, 0, 1, 1, 0, 0));
//   EXPECT_NO_THROW(PID pid(1, -1, 1, 2, 0, 0));

//   // valid Kd
//   EXPECT_NO_THROW(PID pid(1, 1, 0, 1, 0, 0));
//   EXPECT_NO_THROW(PID pid(1, 1, -1, 2, 0, 0));
// }

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

/**
* @brief Test for updateGains function
*/
TEST(updateGainsVerification, test_updateGains) {
  PID pid (10, 5, 30, 0.1, -10.0, 10.0);
  ASSERT_EQ(pid.getdt(), 0.1);
  ASSERT_EQ(pid.getKp(), 10);
  ASSERT_EQ(pid.getKi(), 5);
  ASSERT_EQ(pid.getKd(), 30);
}
