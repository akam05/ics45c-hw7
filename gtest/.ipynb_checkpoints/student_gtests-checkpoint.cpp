// ------------------------- Your tests - student_gtests.cpp ----------------------------- //
// Your own GoogleTest suite for the Array of int in int_array.hpp. It is graded: the
// autograder runs it against a correct Array and against several with one bug each. A test is
// worth something only when it passes on the correct Array and fails on a broken one, so a
// test that always fails (or that tests nothing) earns nothing.
//
// Two examples are given. Add tests of your own for the constructors, the copy and move
// operations, operator[] in and out of range, fill, and length.
// --------------------------------------------------------------------------------------- //

#include <gtest/gtest.h>

#include "int_array.hpp"

TEST(IntArrayTests, DefaultArrayIsEmpty) {
    const Array a;
    EXPECT_EQ(a.length(), 0);
}

TEST(IntArrayTests, SizedArrayReportsItsLength) {
    const Array a{5};
    EXPECT_EQ(a.length(), 5);
}

// ADD YOUR TESTS HERE:
TEST(IntArrayTests, OutOfBoundsThrows)
{
    Array a(3);
    a.fill(4);
    EXPECT_EQ(a[2], 4);
    EXPECT_ANY_THROW(a[3] = 4);
    EXPECT_ANY_THROW(a[-1] = 4);
}

TEST(IntArrayTests, Copy)
{
    Array a(3);
    a.fill(1);
    Array b(a);
    EXPECT_EQ(b.length(), 3);
    EXPECT_EQ(a[2], 1);
    b[2] = 9;
    EXPECT_EQ(a[2], 1);
    EXPECT_EQ(b[2], 9);
}

TEST(IntArrayTests, Move)
{
    Array a(3);
    a.fill(1);

    Array b(2);
    b.fill(9);

    b = std::move(a);
    EXPECT_EQ(b[0], 1);
}