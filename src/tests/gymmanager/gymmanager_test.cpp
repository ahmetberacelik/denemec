//#define ENABLE_GYMMANAGER_TEST  // Uncomment this line to enable the Gymmanager tests

#include "gtest/gtest.h"
#include "../../gymmanager/header/gymmanager.h"  // Adjust this include path based on your project structure

using namespace Coruh::Gymmanager;

class GymmanagerTest : public ::testing::Test {
protected:
	void SetUp() override {
		// Setup test data
	}

	void TearDown() override {
		// Clean up test data
	}
};

TEST_F(GymmanagerTest, TestAdd) {
	double result = Gymmanager::add(5.0, 3.0);
	EXPECT_DOUBLE_EQ(result, 8.0);
}

TEST_F(GymmanagerTest, TestSubtract) {
	double result = Gymmanager::subtract(5.0, 3.0);
	EXPECT_DOUBLE_EQ(result, 2.0);
}

TEST_F(GymmanagerTest, TestMultiply) {
	double result = Gymmanager::multiply(5.0, 3.0);
	EXPECT_DOUBLE_EQ(result, 15.0);
}

TEST_F(GymmanagerTest, TestDivide) {
	double result = Gymmanager::divide(6.0, 3.0);
	EXPECT_DOUBLE_EQ(result, 2.0);
}

TEST_F(GymmanagerTest, TestDivideByZero) {
	EXPECT_THROW(Gymmanager::divide(5.0, 0.0), std::invalid_argument);
}

/**
 * @brief The main function of the test program.
 *
 * @param argc The number of command-line arguments.
 * @param argv An array of command-line argument strings.
 * @return int The exit status of the program.
 */
int main(int argc, char** argv) {
#ifdef ENABLE_GYMMANAGER_TEST
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
#else
	return 0;
#endif
}