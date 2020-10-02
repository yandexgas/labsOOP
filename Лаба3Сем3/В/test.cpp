#include "pch.h"
#include"C:\Users\79044\source\repos\BigInt-dinamic\BigInt-dinamic\BigInt-dinamic.cpp"
using namespace BigInt;
TEST(Constructors, defaultconstructor) {
    BigIntClass* A = new BigIntClass;

  ASSERT_EQ(0, (int)*A);
  delete A;
}
TEST(Constructors, string_constructor) {
    char c[] = "0000";
    BigIntClass* A = new BigIntClass(c);
    ASSERT_EQ(0, (int)*A);
    delete A;
    char a[] = "-0002";
    A = new BigIntClass(a);
    ASSERT_EQ(-2, (int)*A);
    delete A;
    char b[] = "-0002y";
    A = new BigIntClass(b);
    ASSERT_EQ(0, (int)*A);
    delete A;
    A = new BigIntClass(nullptr);
    ASSERT_EQ(0, (int)*A);
    delete A;
}
TEST(Constructors, int_constructor) {
    BigIntClass* A = new BigIntClass(-0);
    ASSERT_EQ(0, (int)*A);
    delete A;
     A = new BigIntClass(111);
    ASSERT_EQ(111, (int)*A);
    delete A;
     A = new BigIntClass(-111);
    ASSERT_EQ(-111, (int)*A);
    delete A;
     A = new BigIntClass(-1);
    ASSERT_EQ(-1, (int)*A);
}
TEST(operators, operator_inverce) {
    BigIntClass* A = new BigIntClass(0);
    *A = ~*A;
    ASSERT_EQ(0, (int)*A);
    delete A;
    A = new BigIntClass(11);
    ASSERT_EQ(11, (int)(~*A));
    delete A;
    A = new BigIntClass(-1);
    ASSERT_EQ(-9, (int)~*A);
    delete A;
}
TEST(operators, operator_unminus) {
    BigIntClass* A = new BigIntClass(0);
    *A = -*A;
    ASSERT_EQ(0, (int)*A);
    delete A;
    A = new BigIntClass(11);
    ASSERT_EQ(-11, (int)(-*A));
    delete A;
     A = new BigIntClass(-1);
    ASSERT_EQ(1, (int)-*A);
    delete A;
}
TEST(operators, operator_sum) {
    BigIntClass* A = new BigIntClass(0);
    ASSERT_EQ(-1, (int)(*A - 1));
    ASSERT_EQ(-1, (int)(*A +(- 1)));
    *A += -2;
    ASSERT_EQ(-2, (int)(*A));
    ASSERT_EQ(198, (int)(*A + 200));
    ASSERT_EQ(0, (int)(*A + 2));
    ASSERT_EQ(-4, (int)(*A - 2));
    ASSERT_EQ(-2, (int)(*A+0));
}
TEST(operators, operator_devmult) {
    BigIntClass* A = new BigIntClass(122);
    ASSERT_EQ(12, (int)(*A/10));
    *A /= 10;
    ASSERT_EQ(120, (int)(*A*10));
    *A += -4;
    ASSERT_EQ(0, (int)(*A/10));
    *A = 0;
    ASSERT_EQ(0, (int)(*A*10));
    *A = -1;
    ASSERT_EQ(0, (int)(*A/10));
    ASSERT_EQ(-10, (int)(*A*10));
}
int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
