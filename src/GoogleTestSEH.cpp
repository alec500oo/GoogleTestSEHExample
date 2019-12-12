
#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "TestMockClass.h"

TEST(Test, t) {
	TestMockClass t;
	EXPECT_CALL(t, TestMethod()).Times(1);

	t.TestMethod();
}
