//#define ENABLE_GYMMANAGER_TEST  // Uncomment this line to enable the Gymmanager tests

#include "gtest/gtest.h"
#include "../../gymmanager/header/gymmanager.h"  // Adjust this include path based on your project structure

class GymmanagerTest : public ::testing::Test {
protected:
    const char* inputTest = "inputTest.txt";
    const char* outputTest = "outputTest.txt";
    void SetUp() override {
        // Setup test data
    }

    void TearDown() override {
        remove(inputTest);
        remove(outputTest);
    }
    void simulateUserInput(const char* userInput) {
        FILE* fileinput = fopen(inputTest, "wb");
        fputs(userInput, fileinput);
        fclose(fileinput);
        freopen(inputTest, "rb", stdin);
        freopen(outputTest, "wb", stdout);
    }

    void readOutput(const char* outputFilePath, char* buffer, size_t bufferSize) {
        FILE* fileoutput = fopen(outputFilePath, "rb");
        size_t charsRead = fread(buffer, sizeof(char), bufferSize - 1, fileoutput);
        fclose(fileoutput);
        buffer[charsRead] = '\0';
        removeClearScreenCharsFromOutputFile(buffer);
    }

    void resetStdinStdout() {
        fclose(stdin);
        fflush(stdout);
#ifdef _WIN32
        freopen("CON", "a", stdout);
        freopen("CON", "r", stdin);
#else
        freopen("/dev/tty", "a", stdout);
        freopen("/dev/tty", "r", stdin);
#endif // _WIN32
    }

    void removeClearScreenCharsFromOutputFile(char* str) {
        char* src = str;
        char* dst = str;
        while (*src) {
            if (*src != '\f') {
                *dst++ = *src;
            }
            src++;
        }
        *dst = '\0';
    }
};

TEST_F(GymmanagerTest, UserAuthenticationTest) {
    simulateUserInput("1\nAhmet Bera Celik\nqwerty\n100\n\n");

    bool result = userAuthentication2();

    resetStdinStdout();

    EXPECT_TRUE(result);
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