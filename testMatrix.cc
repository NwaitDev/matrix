#include <gtest/gtest.h>

#include "Matrix.h"

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
    0   , 1 
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
  mat::Matrix<int,2,2> m({
    1, 2,
    3, 4 
  });
  EXPECT_TRUE(m.Size == 4);
  EXPECT_TRUE(m.Rows == 2);
  EXPECT_TRUE(m.Cols == 2);
  EXPECT_TRUE(m.Order == mat::MatrixOrdering::ColMajor);
  EXPECT_EQ(1, m(0,0));
  EXPECT_EQ(3, m(0,1));
  EXPECT_EQ(2, m(1,0));
  EXPECT_EQ(4, m(1,1));
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
