#include "Matrix.h"
#include "..\src\Matrix.cpp"
#include "..\src\Vector.cpp"

#include <gtest.h>

TEST(TDynamicMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicMatrix<int> m(5));
}

TEST(TDynamicMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TDynamicMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(-5));
}

TEST(TDynamicMatrix, can_create_copied_matrix)
{
  TDynamicMatrix<int> m(5);

  ASSERT_NO_THROW(TDynamicMatrix<int> m1(m));
}

TEST(TDynamicMatrix, copied_matrix_is_equal_to_source_one)
{
  TDynamicMatrix<int> m(5);
  m[2][4] = 3;
  m[3][3] = -1;
  TDynamicMatrix<int> a(m);
  EXPECT_EQ(a, m);
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
  TDynamicMatrix<int> m(5);
  m[2][4] = 3;
  m[3][3] = -1;
  TDynamicMatrix<int> a(m);
  EXPECT_NE(&m[0][0], &a[0][0]);
}

TEST(TDynamicMatrix, can_get_size)
{
  TDynamicMatrix<int> m(5);
  EXPECT_EQ(5, m.GetSize());
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
  TDynamicMatrix<int> m(5);
  m[2][4] = 3;
  EXPECT_EQ(m[2][4], 3);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
  TDynamicMatrix<int> m(5);
  ASSERT_ANY_THROW(m[-1][2] = 2);
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
  TDynamicMatrix<int> m(5);
  ASSERT_ANY_THROW(m[1][5] = 2);
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
  TDynamicMatrix<int> m(5);
  m[2][2] = 2;
  m[3][1] = 31;
  m = m;
  TDynamicMatrix<int> a(m);
  EXPECT_EQ(m, a);
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
  TDynamicMatrix<int> m(5);
  TDynamicMatrix<int> a(5);
  m[2][3] = 17;
  a = m;

  EXPECT_EQ(a, m);
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
  TDynamicMatrix<int> m(5);
  TDynamicMatrix<int> a(3);
  a = m;
  EXPECT_EQ(a.GetSize(), m.GetSize());
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
  TDynamicMatrix<int> m(5);
  TDynamicMatrix<int> a(3);
  a = m;
  EXPECT_EQ(a.GetSize(), 5);
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
  TDynamicMatrix<int> m(5);
  m[1][2] = 12;
  m[0][4] = 4;
  TDynamicMatrix<int> a(m);
  bool f = a == m;
  EXPECT_EQ(f, true);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
  TDynamicMatrix<int> m(5);
  m[1][2] = 12;
  m[0][4] = 4;
  bool f = m == m;
  EXPECT_EQ(f, true);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
  TDynamicMatrix<int> m(5);
  TDynamicMatrix<int> a(3);
  bool f = m == a;
  EXPECT_EQ(f, false);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
  TDynamicMatrix<int> m(3);
  TDynamicMatrix<int> a(3);
  TDynamicMatrix<int> res(3);
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
    {
      m[i][j] = 2;
      a[i][j] = 2;
    }
  res = m + a;

  EXPECT_EQ(res, a + m);
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
  TDynamicMatrix<int> m(5);
  TDynamicMatrix<int> a(3);
  TDynamicMatrix<int> b(1);
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
    {
      m[i][j] = 2;
      a[i][j] = 2;
    }

  ASSERT_ANY_THROW(b = a + m);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
  TDynamicMatrix<int> m(3);
  TDynamicMatrix<int> a(3);
  TDynamicMatrix<int> res(3);
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
    {
      m[i][j] = 2;
      a[i][j] = 1;
    }
  res = m - a;
  EXPECT_EQ(res, m - a);
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
  TDynamicMatrix<int> m(5);
  TDynamicMatrix<int> a(3);
  TDynamicMatrix<int> res(3);
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
    {
      m[i][j] = 2;
      a[i][j] = 1;
    }

  ASSERT_ANY_THROW(res = m - a);
}

