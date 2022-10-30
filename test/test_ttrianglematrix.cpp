#include "TriangleMatrix.h"
#include "..\src\TriangleMatrix.cpp"
#include "..\src\Vector.cpp"

#include <gtest.h>

TEST(TTriangleMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TTriangleMatrix<int> m(5));
}

TEST(TTriangleMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TTriangleMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TTriangleMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TTriangleMatrix<int> m(-5));
}

TEST(TTriangleMatrix, can_create_copied_matrix)
{
  TTriangleMatrix<int> m(5);

  ASSERT_NO_THROW(TTriangleMatrix<int> m1(m));
}

TEST(TTriangleMatrix, copied_matrix_is_equal_to_source_one)
{
  TTriangleMatrix<int> m(5);
  TTriangleMatrix<int> a(m);

  EXPECT_EQ(a, m);
}

TEST(TTriangleMatrix, copied_matrix_has_its_own_memory)
{
  TTriangleMatrix<int> m(5);
  TTriangleMatrix<int> a(m);

  EXPECT_NE(&m[0][0], &a[0][0]);
}

TEST(TTriangleMatrix, can_get_size)
{
  TTriangleMatrix<int> m(5);
  EXPECT_EQ(5, m.GetSize());
}

TEST(TTriangleMatrix, can_set_and_get_element)
{
  TTriangleMatrix<int> m(5);
  m[2][2] = 3;
  EXPECT_EQ(m[2][2], 3);
}

TEST(TTriangleMatrix, throws_when_set_element_with_negative_index)
{
  TTriangleMatrix<int> m(5);
  ASSERT_ANY_THROW(m[-1][2] = 2);
}

TEST(TTriangleMatrix, throws_when_set_element_with_too_large_index)
{
  TTriangleMatrix<int> m(5);
  ASSERT_ANY_THROW(m[1][5] = 2);
}

TEST(TTriangleMatrix, can_assign_matrix_to_itself)
{
  TTriangleMatrix<int> m(5);
  m[2][2] = 2;
  m[3][1] = 31;
  m = m;
  TTriangleMatrix<int> a(m);
  EXPECT_EQ(m, a);
}

TEST(TTriangleMatrix, can_assign_matrices_of_equal_size)
{
  TTriangleMatrix<int> m(5);
  TTriangleMatrix<int> a(5);
  m[1][1] = 17;
  a = m;

  EXPECT_EQ(a, m);
}

TEST(TTriangleMatrix, assign_operator_change_matrix_size)
{
  TTriangleMatrix<int> m(5);
  TTriangleMatrix<int> a(3);
  a = m;
  EXPECT_EQ(a.GetSize(), m.GetSize());
}

TEST(TTriangleMatrix, can_assign_matrices_of_different_size)
{
  TTriangleMatrix<int> m(5);
  TTriangleMatrix<int> a(3);
  a = m;
  EXPECT_EQ(a.GetSize(), 5);
}

TEST(TTriangleMatrix, compare_equal_matrices_return_true)
{
  TTriangleMatrix<int> m(5);
  m[1][1] = 12;
  m[4][4] = 4;
  TTriangleMatrix<int> a(m);
  bool f = a == m;
  EXPECT_EQ(f, true);
}

TEST(TTriangleMatrix, compare_matrix_with_itself_return_true)
{
  TTriangleMatrix<int> m(5);
  m[1][1] = 12;
  m[4][4] = 4;
  bool f = m == m;
  EXPECT_EQ(f, true);
}

TEST(TTriangleMatrix, matrices_with_different_size_are_not_equal)
{
  TTriangleMatrix<int> m(5);
  TTriangleMatrix<int> a(3);
  bool f = m == a;
  EXPECT_EQ(f, false);
}

TEST(TTriangleMatrix, can_add_matrices_with_equal_size)
{
  TTriangleMatrix<int> m(2);
  TTriangleMatrix<int> a(2);
  TTriangleMatrix<int> res(2);

  m[0][0] = 1;
  m[1][0] = 2;
  m[1][1] = 3;
  a[0][0] = 1;
  a[1][0] = 2;
  a[1][1] = 3;
  res = m + a;

  EXPECT_EQ(res, a + m);
}

TEST(TTriangleMatrix, cant_add_matrices_with_not_equal_size)
{
  TTriangleMatrix<int> m(5);
  TTriangleMatrix<int> a(3);
  TTriangleMatrix<int> b(1);

  ASSERT_ANY_THROW(b = a + m);
}

TEST(TTriangleMatrix, can_subtract_matrices_with_equal_size)
{
  TTriangleMatrix<int> m(2);
  TTriangleMatrix<int> a(2);
  TTriangleMatrix<int> res(2);

  m[0][0] = 1;
  m[1][0] = 2;
  m[1][1] = 3;
  a[0][0] = 1;
  a[1][0] = 2;
  a[1][1] = 3;
  res = m - a;

  EXPECT_EQ(res, a - m);
}

TEST(TTriangleMatrix, cant_subtract_matrixes_with_not_equal_size)
{
  TTriangleMatrix<int> m(5);
  TTriangleMatrix<int> a(3);
  TTriangleMatrix<int> res(3);


  ASSERT_ANY_THROW(res = m - a);
}

