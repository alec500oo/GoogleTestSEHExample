#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "TestMockClass.h"

/* This test will fail with an SEH exception with compiled with
 * C++17. */ 
TEST(Test, t) {
	TestMockClass t;
	EXPECT_CALL(t, TestMethod()).Times(1);

	t.TestMethod();
}
