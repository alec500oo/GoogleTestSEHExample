
#pragma once

#include "gmock/gmock.h"

#include "TestAbstractClass.h"

class TestMockClass : TestAbstractClass {
public:
	MOCK_METHOD(void, TestMethod, (), (override));
};