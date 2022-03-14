#include <gtest/gtest.h>
#include <algorithm>
#include "Matrix.h"


TEST(matrixIterator , basicIterator)
{
  mat::Matrix<int, 2 , 2> m;
  m(0,0) = 1;
  m(0,1) = 2;
  m(1, 0) = 3;
  m(1, 1) = 4;
  mat::Matrix<int, 2 , 2>::iterator it = m.begin();
  EXPECT_EQ(1, *it);
  ++it;
  EXPECT_EQ(2, *it);
  ++it;
  EXPECT_EQ(3, *it);
  ++it;
  EXPECT_EQ(4, *it);
  ++it;
  EXPECT_EQ(m.end(), it);
}

TEST(matrixIterator, maxElement)
{
  mat::Matrix<int, 2, 2> m;
  m(0, 0) = 1;
  m(0, 1) = 5;
  m(1, 0) = 7;
  m(1, 1) = 5;
  auto max = std::max_element(m.begin(), m.end());
  EXPECT_EQ(7, *max);
}

TEST(matrixAdd, addBasic)
{
  mat::Matrix<int, 2, 2> m1;
  m1(0, 0) = 1;
  m1(0, 1) = 2;
  m1(1, 0) = 3;
  m1(1, 1) = 4;
  mat::Matrix<int, 2, 2> m2;
  m2(0, 0) = 1;
  m2(0, 1) = 2;
  m2(1, 0) = 3;
  m2(1, 1) = 4;
  mat::Matrix<int, 2, 2> m3 = m1 + m2;
  EXPECT_EQ(2, m3(0, 0));
  EXPECT_EQ(4, m3(0, 1));
  EXPECT_EQ(6, m3(1, 0));
  EXPECT_EQ(8, m3(1, 1));
}

TEST(matrixAdd, inPlace)
{
  mat::Matrix<int, 2, 2> m1;
  m1(0, 0) = 1;
  m1(0, 1) = 2;
  m1(1, 0) = 3;
  m1(1, 1) = 4;
  mat::Matrix<int, 2, 2> m2;
  m2(0, 0) = 1;
  m2(0, 1) = 2;
  m2(1, 0) = 3;
  m2(1, 1) = 4;
  m1 += m2;
  EXPECT_EQ(2, m1(0, 0));
  EXPECT_EQ(4, m1(0, 1));
  EXPECT_EQ(6, m1(1, 0));
  EXPECT_EQ(8, m1(1, 1));
}


TEST(matrixSub, subBasic)
{
  mat::Matrix<int, 2, 2> m1;
  m1(0, 0) = 1;
  m1(0, 1) = 2;
  m1(1, 0) = 3;
  m1(1, 1) = 4;
  mat::Matrix<int, 2, 2> m2;
  m2(0, 0) = 1;
  m2(0, 1) = 2;
  m2(1, 0) = 3;
  m2(1, 1) = 4;
  mat::Matrix<int, 2, 2> m3 = m1 - m2;
  EXPECT_EQ(0, m3(0, 0));
  EXPECT_EQ(0, m3(0, 1));
  EXPECT_EQ(0, m3(1, 0));
  EXPECT_EQ(0, m3(1, 1));
}

TEST(matrixSub , inPlace)
{
  mat::Matrix<int, 2, 2> m1;
  m1(0, 0) = 1;
  m1(0, 1) = 2;
  m1(1, 0) = 3;
  m1(1, 1) = 4;
  mat::Matrix<int, 2, 2> m2;
  m2(0, 0) = 1;
  m2(0, 1) = 2;
  m2(1, 0) = 3;
  m2(1, 1) = 4;
  m1 -= m2;
  EXPECT_EQ(0, m1(0, 0));
  EXPECT_EQ(0, m1(0, 1));
  EXPECT_EQ(0, m1(1, 0));
  EXPECT_EQ(0, m1(1, 1));
}


TEST(matrixCompare, compareBasic)
{
  mat::Matrix<int, 2, 2> m1;
  m1(0, 0) = 1;
  m1(0, 1) = 2;
  m1(1, 0) = 3;
  m1(1, 1) = 4;
  mat::Matrix<int, 2, 2> m2;
  m2(0, 0) = 1;
  m2(0, 1) = 2;
  m2(1, 0) = 3;
  m2(1, 1) = 4;
  EXPECT_TRUE(m1 == m2);
}

TEST(matrixCompare , compareDifferent)
{
  mat::Matrix<int, 2, 2> m1;
  m1(0, 0) = 1;
  m1(0, 1) = 2;
  m1(1, 0) = 3;
  m1(1, 1) = 4;
  mat::Matrix<int, 2, 2> m2;
  m2(0, 0) = 1;
  m2(0, 1) = 2;
  m2(1, 0) = 3;
  m2(1, 1) = 5;
  EXPECT_FALSE(m1 == m2);
  EXPECT_TRUE(m1 != m2);
}

TEST(matrixTranspose , transposeBasic)
{
  mat::Matrix<int, 2, 3> m1;
  m1(0, 0) = 1;
  m1(0, 1) = 3;
  m1(0, 2) = 5;
  m1(1, 0) = 2;
  m1(1, 1) = 4;
  m1(1, 2) = 6;

  mat::Matrix<int, 3, 2> m2 = m1.transpose();
  EXPECT_EQ(1, m2(0, 0));
  EXPECT_EQ(2, m2(0, 1));
  EXPECT_EQ(3, m2(1, 0));
  EXPECT_EQ(4, m2(1, 1));
  EXPECT_EQ(5, m2(2, 0));
  EXPECT_EQ(6, m2(2, 1));


}




int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
