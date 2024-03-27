#include <math.h>

#include <gtest/gtest.h>


class Calculator {
public:
    virtual ~Calculator() {}
    virtual double getUpToPower(int numb, int power) const = 0;
};

class Calculator1 : public Calculator {
public:
    virtual double getUpToPower(int numb, int power) const override {
        if (power != 0) {
            int result = (double)numb;

            int i = 1;
            while (i < power) {
                result *= numb;
                i++;
            }
            return result;
        } else { return 1; }
    }
};

class Calculator2 : public Calculator {
public:
    virtual double getUpToPower(int numb, int power) const override {
        return pow((double)numb, (double)power);
    }
};


/*================== TESTS =========================*/

template <class T>
class CalculatorTest : public testing::Test {
public:
    T calculator_;
};

typedef testing::Types<Calculator1, Calculator2> CalcImplementations;
TYPED_TEST_SUITE(CalculatorTest, CalcImplementations);

TYPED_TEST(CalculatorTest, RaiseToPowerTest) {
    EXPECT_EQ(this->calculator_.getUpToPower(2, 2), 4);
}

TYPED_TEST(CalculatorTest, RaiseToPowerOfZeroTest) {
    EXPECT_EQ(this->calculator_.getUpToPower(222, 0), 1);
}