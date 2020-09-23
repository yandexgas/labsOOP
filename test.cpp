
#include "pch.h"
#include "iostream"
#include"../Lab1bSem3/Versiera.cpp"
using namespace Lab2;
TEST(VersieraConstructor, defaultConstructor) {
    Lab2::Versiera v1;

    ASSERT_EQ(0, v1.getp().x);
    ASSERT_EQ(0, v1.getp().y);
    ASSERT_EQ(1, v1.getD());
}
  TEST(VersieraConstructor, InitConstructor) {
    Lab2::Versiera v2(3);
    Lab2::ProectionPoint p(2, 7);
    ASSERT_EQ(0, v2.getp().x);
    ASSERT_EQ(0, v2.getp().y);
    ASSERT_EQ(3, v2.getD());
    Lab2::Versiera v3(p, 3);
    ASSERT_EQ(2, v3.getp().x);
    ASSERT_EQ(7, v3.getp().y);
    ASSERT_EQ(3, v3.getD());
    Lab2::Versiera v4(-1, 2, 3);
    ASSERT_EQ(-1, v4.getp().x);
    ASSERT_EQ(2, v4.getp().y);
    ASSERT_EQ(3, v4.getD());
}
TEST(VersieraConstructor, Test_Exception) {
    Lab2::ProectionPoint p;
    ASSERT_ANY_THROW(Lab2::Versiera(-1, -1, 0));
    ASSERT_ANY_THROW(Lab2::Versiera(p, 0));
}
TEST(VersieraMethods, setters) {
    Lab2::Versiera v;
    Lab2::ProectionPoint p1(-1, -11);
    v.setP(p1);
    ASSERT_EQ(-1, v.getp().x);
    ASSERT_EQ(-11, v.getp().y);
    v.setD(11);
    ASSERT_EQ(11, v.getD());
    ASSERT_ANY_THROW(v.setD(0));
}
TEST(VersieraMethods, otherMethods) {
    Lab2::Versiera v;
    const double err = 0.001;
    ASSERT_NEAR(0.5, v.y(1), 0);
    ASSERT_NEAR(0.0588, v.y(4), err);
    ASSERT_NEAR(0.5773, ((v.Inflections())->x), err);
    ASSERT_NEAR(0.75, ((v.Inflections())->y), err);
    ASSERT_NEAR(3.14159, v.Space(), err);
    ASSERT_NEAR((3.14159 * 3.14159 / 2), v.Volume(), err);
    ASSERT_STREQ("y = (1.00) / (1.00 + (x)^2) ", v.Equation());
}
int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}