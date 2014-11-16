#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/TestResult.h>
#include "graphtests.hpp"

#include "Graph.hpp"

using namespace CppUnit;
using namespace std;

void
GraphTests::setUp(void)
{
	    this->mTestObj = new Graph(false);
}

void
GraphTests::tearDown(void)
{
	    delete mTestObj;
}

void
GraphTests::testSize(void)
{
	    CPPUNIT_ASSERT_EQUAL(0,mTestObj->size());
		mTestObj->insert_node(1);
	    CPPUNIT_ASSERT_EQUAL(1,mTestObj->size());
}

void
GraphTests::testEmpty(void)
{
	CPPUNIT_ASSERT(mTestObj->empty());
	mTestObj->insert_node(1);
	CPPUNIT_ASSERT(!mTestObj->empty());
}

void
GraphTests::testIsConnected(void)
{
	CPPUNIT_FAIL("TODO");
}

void
GraphTests::testIsCyclical(void)
{
	CPPUNIT_FAIL("TODO");
}

void
GraphTests::testIsTree(void)
{
	CPPUNIT_FAIL("TODO");
}

void
GraphTests::testDistance(void)
{
	CPPUNIT_FAIL("TODO");
}

void
GraphTests::testToDot(void)
{
	CPPUNIT_FAIL("TODO");
}

