#include <gtest/gtest.h>
#include <algorithm>
#include <iostream>
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

TEST(matrixMultiply , multiplyBasic)
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
  mat::Matrix<int, 2, 2> m3 = m1 * m2;
  EXPECT_EQ(7, m3(0, 0));
  EXPECT_EQ(10, m3(0, 1));
  EXPECT_EQ(15, m3(1, 0));
  EXPECT_EQ(22, m3(1, 1));
}

TEST(matrixMultiply , differentSize)
{
  mat::Matrix<int, 2, 3> m1;
  m1(0, 0) = 1;
  m1(0, 1) = 2;
  m1(0, 2) = 3;
  m1(1, 0) = 4;
  m1(1, 1) = 5;
  m1(1, 2) = 6;

  mat::Matrix<int, 3, 2> m2;
  m2(0, 0) = 1;
  m2(0, 1) = 2;
  m2(1, 0) = 3;
  m2(1, 1) = 4;
  m2(2, 0) = 5;
  m2(2, 1) = 6;

  mat::Matrix<int, 2, 2> m3 = m1 * m2;
  EXPECT_EQ(22, m3(0, 0));
  EXPECT_EQ(28, m3(0, 1));
  EXPECT_EQ(49, m3(1, 0));
  EXPECT_EQ(64, m3(1, 1));

}



//-----------------------------------------------------------
//-----------------------------------------------------------
//-----------------One or no element
TEST(matrixCreate, matrixEmpty){
  mat::Matrix<int,0,0> m;
  EXPECT_TRUE(m.Size == 0);
  EXPECT_TRUE(m.Rows == 0);
  EXPECT_TRUE(m.Cols == 0);
  EXPECT_TRUE(m.Order == mat::MatrixOrdering::RowMajor);
}

TEST(matrixCreate, matrixOneElementInt){
  mat::Matrix<int,1,1> m;
  EXPECT_TRUE(m.Size == 1);
  EXPECT_TRUE(m.Rows == 1);
  EXPECT_TRUE(m.Cols == 1);
  EXPECT_TRUE(m.Order == mat::MatrixOrdering::RowMajor);
  EXPECT_TRUE(m(0,0)==0);
}

TEST(matrixCreate, matrixOneElementLong){
  mat::Matrix<long,1,1> m;
  EXPECT_TRUE(m.Size == 1);
  EXPECT_TRUE(m.Rows == 1);
  EXPECT_TRUE(m.Cols == 1);
  EXPECT_TRUE(m.Order == mat::MatrixOrdering::RowMajor);
  EXPECT_TRUE(m(0,0)==0);
}

TEST(matrixCreate, matrixOneElementFloat){
  mat::Matrix<float,1,1> m;
  EXPECT_TRUE(m.Size == 1);
  EXPECT_TRUE(m.Rows == 1);
  EXPECT_TRUE(m.Cols == 1);
  EXPECT_TRUE(m.Order == mat::MatrixOrdering::RowMajor);
  EXPECT_TRUE(m(0,0)==0);
}

TEST(matrixCreate, matrixOneElementDouble){
  mat::Matrix<double,1,1> m;
  EXPECT_TRUE(m.Size == 1);
  EXPECT_TRUE(m.Rows == 1);
  EXPECT_TRUE(m.Cols == 1);
  EXPECT_TRUE(m.Order == mat::MatrixOrdering::RowMajor);
  EXPECT_TRUE(m(0,0)==0);
}

//-----------------------------------------------------------
//-----------------------------------------------------------
//-----------------2 elements Row major

TEST(matrixCreate, matrixIntTwoElemRowMaj){
  mat::Matrix<int,1,2> m;
  EXPECT_TRUE(m.Size == 2);
  EXPECT_TRUE(m.Rows == 1);
  EXPECT_TRUE(m.Cols == 2);
  EXPECT_TRUE(m.Order == mat::MatrixOrdering::RowMajor);
  EXPECT_TRUE(m(0,0)==0);
  EXPECT_TRUE(m(0,1)==0);
}

TEST(matrixCreate, matrixIntTwoElemRowMajSpecified){
  mat::Matrix<int,1,2,mat::MatrixOrdering::RowMajor> m;
  EXPECT_TRUE(m.Size == 2);
  EXPECT_TRUE(m.Rows == 1);
  EXPECT_TRUE(m.Cols == 2);
  EXPECT_TRUE(m.Order == mat::MatrixOrdering::RowMajor);
  EXPECT_TRUE(m(0,0)==0);
  EXPECT_TRUE(m(0,1)==0);
}

TEST(matrixCreate, matrixDoubleTwoElemRowMaj){
  mat::Matrix<double,1,2> m;
  EXPECT_TRUE(m.Size == 2);
  EXPECT_TRUE(m.Rows == 1);
  EXPECT_TRUE(m.Cols == 2);
  EXPECT_TRUE(m.Order == mat::MatrixOrdering::RowMajor);
  EXPECT_TRUE(m(0,0)==0);
  EXPECT_TRUE(m(0,1)==0);
}

TEST(matrixCreate, matrixDoubleTwoElemRowMajFromTab){
  mat::Matrix<double,1,2> m({
    1.75, 2.25
  });
  EXPECT_TRUE(m.Size == 2);
  EXPECT_TRUE(m.Rows == 1);
  EXPECT_TRUE(m.Cols == 2);
  EXPECT_TRUE(m.Order == mat::MatrixOrdering::RowMajor);
  EXPECT_DOUBLE_EQ(1.75, m(0,0));
  EXPECT_DOUBLE_EQ(2.25, m(0,1));
}

//-----------------------------------------------------------
//-----------------------------------------------------------
//-----------------2 elements Col major

TEST(matrixCreate, matrixIntColElemColMaj){
  mat::Matrix<int,1,2,mat::MatrixOrdering::ColMajor> m;
  EXPECT_TRUE(m.Size == 2);
  EXPECT_TRUE(m.Rows == 1);
  EXPECT_TRUE(m.Cols == 2);
  EXPECT_TRUE(m.Order == mat::MatrixOrdering::ColMajor);
  EXPECT_TRUE(m(0,0)==0);
  EXPECT_TRUE(m(0,1)==0);
}


TEST(matrixCreate, matrixDoubleTwoElemColMaj){
  mat::Matrix<double,1,2,mat::MatrixOrdering::ColMajor> m;
  EXPECT_TRUE(m.Size == 2);
  EXPECT_TRUE(m.Rows == 1);
  EXPECT_TRUE(m.Cols == 2);
  EXPECT_TRUE(m.Order == mat::MatrixOrdering::ColMajor);
  EXPECT_TRUE(m(0,0)==0);
  EXPECT_TRUE(m(0,1)==0);
}

TEST(matrixCreate, matrixDoubleTwoElemColMajFromTab){
  mat::Matrix<double,1,2, mat::MatrixOrdering::ColMajor> m({
    1.75, 2.25
  });
  EXPECT_TRUE(m.Size == 2);
  EXPECT_TRUE(m.Rows == 1);
  EXPECT_TRUE(m.Cols == 2);
  EXPECT_TRUE(m.Order == mat::MatrixOrdering::ColMajor);
  EXPECT_DOUBLE_EQ(1.75, m(0,0));
  EXPECT_DOUBLE_EQ(2.25, m(0,1));
}


//-----------------------------------------------------------
//-----------------------------------------------------------
//-----------------2x2 elements Row major

TEST(matrixCreate, matrixInt2x2ElemRowMaj){
  mat::Matrix<int,2,2> m;
  EXPECT_TRUE(m.Size == 4);
  EXPECT_TRUE(m.Rows == 2);
  EXPECT_TRUE(m.Cols == 2);
  EXPECT_TRUE(m.Order == mat::MatrixOrdering::RowMajor);
  EXPECT_TRUE(m(0,0)==0);
  EXPECT_TRUE(m(0,1)==0);
  EXPECT_TRUE(m(1,0)==0);
  EXPECT_TRUE(m(1,1)==0);
}

TEST(matrixCreate, matrixInt2x2ElemRowMajSpecified){
  mat::Matrix<int,2,2,mat::MatrixOrdering::RowMajor> m;
  EXPECT_TRUE(m.Size == 4);
  EXPECT_TRUE(m.Rows == 2);
  EXPECT_TRUE(m.Cols == 2);
  EXPECT_TRUE(m.Order == mat::MatrixOrdering::RowMajor);
  EXPECT_TRUE(m(0,0)==0);
  EXPECT_TRUE(m(0,1)==0);
  EXPECT_TRUE(m(1,1)==0);
  EXPECT_TRUE(m(1,0)==0);
}

TEST(matrixCreate, matrixDouble2x2ElemRowMajFromTab){
  mat::Matrix<double,2,2> m({
    1.75, 2.25,
    0.0   , 1.0 
  });
  EXPECT_TRUE(m.Size == 4);
  EXPECT_TRUE(m.Rows == 2);
  EXPECT_TRUE(m.Cols == 2);
  EXPECT_TRUE(m.Order == mat::MatrixOrdering::RowMajor);
  EXPECT_DOUBLE_EQ(1.75, m(0,0));
  EXPECT_DOUBLE_EQ(2.25, m(0,1));
  EXPECT_DOUBLE_EQ(0, m(1,0));
  EXPECT_DOUBLE_EQ(1, m(1,1));
}

//-----------------------------------------------------------
//-----------------------------------------------------------
//-----------------2x2 elements Row major

TEST(matrixCreate, matrixInt2x2ElemColMaj){
  mat::Matrix<int,2,2,mat::MatrixOrdering::ColMajor> m;
  EXPECT_TRUE(m.Size == 4);
  EXPECT_TRUE(m.Rows == 2);
  EXPECT_TRUE(m.Cols == 2);
  EXPECT_TRUE(m.Order == mat::MatrixOrdering::ColMajor);
  EXPECT_TRUE(m(0,0)==0);
  EXPECT_TRUE(m(0,1)==0);
  EXPECT_TRUE(m(1,0)==0);
  EXPECT_TRUE(m(1,1)==0);
}

TEST(matrixCreate, matrixDouble2x2ElemColMajFromTab){
  mat::Matrix<int,2,2,mat::MatrixOrdering::ColMajor> m({
    1, 2,
    3, 4 
  });
  EXPECT_TRUE(m.Size == 4);
  EXPECT_TRUE(m.Rows == 2);
  EXPECT_TRUE(m.Cols == 2);
  EXPECT_TRUE(m.Order == mat::MatrixOrdering::ColMajor);
  EXPECT_EQ(1, m(0,0));
  EXPECT_EQ(2, m(0,1));
  EXPECT_EQ(3, m(1,0));
  EXPECT_EQ(4, m(1,1));
}

//-------------------------------------------------------------
//------------------------------------------------------------
//-----------------Conversion constructor

TEST(matrixCreate, matrixInt2x2FromMat){
  mat::Matrix<int,2,2> m1({
    1, 2,
    3, 4 
  });
  mat::Matrix<int,2,2>m2(m1);
  EXPECT_TRUE(m2.Size == 4);
  EXPECT_TRUE(m2.Rows == 2);
  EXPECT_TRUE(m2.Cols == 2);
  EXPECT_TRUE(m2.Order == mat::MatrixOrdering::ColMajor);
  EXPECT_EQ(1, m2(0,0));
  EXPECT_EQ(3, m2(0,1));
  EXPECT_EQ(2, m2(1,0));
  EXPECT_EQ(4, m2(1,1));
}

//-------------------------------------------------------------
//------------------------------------------------------------
//-----------------Test Create Identity

TEST(matrixCreate, Identity1Matrix1){
  mat::Matrix<int,1,1> m = mat::identity<int,1>
  EXPECT_EQ(1, m2(0,0));
}

TEST(matrixCreate, Identity1Matrix2){
  mat::Matrix<int,2,2> m = mat::identity<int,1>();
  EXPECT_EQ(1, m2(0,0));
  EXPECT_EQ(1, m2(1,1));
  EXPECT_EQ(1, m2(0,1));
  EXPECT_EQ(1, m2(1,0));
TEST(matrixCreate , matrix3x2ElemColMajFromTab){
  mat::Matrix<int,3,2,mat::MatrixOrdering::ColMajor> m({
    1, 2,
    3, 4,
    5, 6
  });
  int i = 0;
  for(auto elem : m)
  {
    i += elem;
   std::cout << elem << std::endl;
  }
  // get an iterator to the first element
  auto it = m.begin();
  EXPECT_TRUE(*it == 1);
  EXPECT_TRUE(*(++it) == 3);
  EXPECT_TRUE(*(++it) == 5);
  EXPECT_TRUE(*(++it) == 2);
  EXPECT_TRUE(*(++it) == 4);
  EXPECT_TRUE(*(++it) == 6);
  EXPECT_TRUE(++it == m.end());

  std::cout << "i opti : " << i << std::endl;


  EXPECT_TRUE(m.Size == 6);
  EXPECT_TRUE(m.Rows == 3);
  EXPECT_TRUE(m.Cols == 2);
  EXPECT_TRUE(m.Order == mat::MatrixOrdering::ColMajor);
  EXPECT_EQ(1, m(0,0));
  EXPECT_EQ(2, m(0,1));
  EXPECT_EQ(5, m(2,0));
  EXPECT_EQ(6, m(2,1));
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
