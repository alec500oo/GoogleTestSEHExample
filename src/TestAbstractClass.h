/** TestAbstractClass.h
 * This file holds a test abstract class that can be used
 * create a mock class.
 * 
 * @author Alec Matthews <alec\@hoodtech.com>
 */

#pragma once

class TestAbstractClass {
public:
	virtual void TestMethod() = 0;

	virtual ~TestAbstractClass() = default;
};