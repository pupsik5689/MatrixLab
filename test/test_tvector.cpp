#include "Vector.h"

#include <gtest.h>
#include "test_tvector.h"

TEST(TDynamicVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TDynamicVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TDynamicVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicVector<int> v(-5));
}

TEST(TDynamicVector, can_create_copied_vector)
{
  TDynamicVector<int> v(10);

  ASSERT_NO_THROW(TDynamicVector<int> v1(v));
}

TEST(TDynamicVector, copied_vector_is_equal_to_source_one)
{
  TDynamicVector<int> a(4);
  for (int i = 0; i < 4; i++)
    a[i] = i;

  TDynamicVector<int> b(a);

  EXPECT_EQ(a, b);
}

TEST(TDynamicVector, copied_vector_has_its_own_memory)
{
  TDynamicVector<int> a(4);

  TDynamicVector<int> b(a);

  EXPECT_NE(&a[0], &b[0]);
}

TEST(TDynamicVector, can_get_size)
{
  TDynamicVector<int> v(4);

  EXPECT_EQ(4, v.GetSize());
}

TEST(TDynamicVector, throws_when_set_element_with_negative_index)
{
  TDynamicVector<int> v(3);
  ASSERT_ANY_THROW(v[-2] = 1);
}

TEST(TDynamicVector, throws_when_set_element_with_too_large_index)
{
  TDynamicVector<int> v(3);
  ASSERT_ANY_THROW(v[5] = 1);
}

TEST(TDynamicVector, can_assign_vector_to_itself)
{
  TDynamicVector<int> a(5);
  TDynamicVector<int> b(a);
  a = a;

  EXPECT_EQ(a, b);
}

TEST(TDynamicVector, can_assign_vectors_of_equal_size)
{
  TDynamicVector<int> a(5);
  TDynamicVector<int> b(5);
  a[2] = 17;
  a = b;
  EXPECT_EQ(a, b);
}

TEST(TDynamicVector, assign_operator_change_vector_size)
{
  TDynamicVector<int> a(5);
  TDynamicVector<int> b(3);
  b = a;
  EXPECT_EQ(b.GetSize(), 5);
}

TEST(TDynamicVector, can_assign_vectors_of_different_size)
{
  TDynamicVector<int> a(5);
  TDynamicVector<int> b(3);

  b = a;
  EXPECT_EQ(a, b);
}

TEST(TDynamicVector, compare_equal_vectors_return_true)
{
  TDynamicVector<int> a(5);
  TDynamicVector<int> b(5);
  for (int i = 0; i < 5; i++)
  {
    a[i] = i;
    b[i] = i;
  }
  bool f = a == b;
  EXPECT_EQ(f, true);
}

TEST(TDynamicVector, compare_vector_with_itself_return_true)
{
  TDynamicVector<int> a(5);

  bool f = a == a;
  EXPECT_EQ(f, true);
}

TEST(TDynamicVector, vectors_with_different_size_are_not_equal)
{
  TDynamicVector<int> a(5);
  TDynamicVector<int> b(3);

  bool f = a == b;
  EXPECT_EQ(f, false);
}

TEST(TDynamicVector, can_add_scalar_to_vector)
{
  TDynamicVector<int> a(5);
  TDynamicVector<int> b(a);
  b = a + 5;
  for (int i = 0; i < 5; i++)
    EXPECT_EQ(b[i], 5);

}

TEST(TDynamicVector, can_subtract_scalar_from_vector)
{
  TDynamicVector<int> a(5);
  TDynamicVector<int> b(a);
  b = a - 5;
  for (int i = 0; i < 5; i++)
    EXPECT_EQ(b[i], -5);
}

TEST(TDynamicVector, can_multiply_scalar_by_vector)
{
  TDynamicVector<int> a(5);
  TDynamicVector<int> b(5);
  for (int i = 0; i < 5; i++)
    a[i] = 1;
  b = a * 5;

  for (int i = 0; i < 5; i++)
    EXPECT_EQ(b[i], 5);
}

TEST(TDynamicVector, can_add_vectors_with_equal_size)
{
  TDynamicVector<int> a(5);
  TDynamicVector<int> b(5);
  TDynamicVector<int> res(5);

  for (int i = 0; i < 5; i++)
  {
    a[i] = 1;
    b[i] = 3;
  }

  res = a + b;
  for (int i = 0; i < 5; i++)
    EXPECT_EQ(res[i], 4);
}

TEST(TDynamicVector, cant_add_vectors_with_not_equal_size)
{
  TDynamicVector<int> a(5);
  TDynamicVector<int> b(3);
  for (int i = 0; i < 3; i++)
  {
    a[i] = 3;
    b[i] = 1;
  }
  TDynamicVector<int> res;
  ASSERT_ANY_THROW(res = a + b);
}

TEST(TDynamicVector, can_subtract_vectors_with_equal_size)
{
  TDynamicVector<int> a(5);
  TDynamicVector<int> b(5);
  TDynamicVector<int> res(5);

  for (int i = 0; i < 5; i++)
  {
    a[i] = 3;
    b[i] = 1;
  }

  res = a - b;
  for (int i = 0; i < 5; i++)
    EXPECT_EQ(res[i], 2);
}

TEST(TDynamicVector, cant_subtract_vectors_with_not_equal_size)
{
  TDynamicVector<int> a(5);
  TDynamicVector<int> b(3);
  for (int i = 0; i < 3; i++)
  {
    a[i] = 3;
    b[i] = 1;
  }
  TDynamicVector<int> res;
  ASSERT_ANY_THROW(res = a - b);
}

TEST(TDynamicVector, can_multiply_vectors_with_equal_size)
{
  TDynamicVector<int> a(3);
  TDynamicVector<int> b(3);
  for (int i = 0; i < 3; i++)
  {
    a[i] = 1;
    b[i] = 2;
  }
  TDynamicVector<int> res = a * b;
  EXPECT_EQ(res, 6);
}

TEST(TDynamicVector, cant_multiply_vectors_with_not_equal_size)
{
  TDynamicVector<int> a(5);
  TDynamicVector<int> b(3);
  for (int i = 0; i < 3; i++)
  {
    a[i] = 3;
    b[i] = 2;
  }
  TDynamicVector<int> res;
  ASSERT_ANY_THROW(res = a * b);
}

