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
GraphTests::testEmpty(void)
{
	CPPUNIT_ASSERT(mTestObj->empty());
}

void
GraphTests::testNotEmpty(void)
{
	mTestObj->insert_node(3);
	CPPUNIT_ASSERT(!mTestObj->empty());
	mTestObj->insert_node(7);
	CPPUNIT_ASSERT(!mTestObj->empty());
}

void
GraphTests::testSize(void)
{
	CPPUNIT_ASSERT_EQUAL(0,mTestObj->size());

	mTestObj->insert_node(1);
	CPPUNIT_ASSERT_EQUAL(1,mTestObj->size());

	mTestObj->insert_node(1);
	CPPUNIT_ASSERT_EQUAL(1,mTestObj->size());

	mTestObj->insert_node(3);
	mTestObj->insert_node(7);
	CPPUNIT_ASSERT_EQUAL(3,mTestObj->size());
}

void
GraphTests::testIsConnected(void)
{
	mTestObj->insert_edge(1,2);
	CPPUNIT_ASSERT(mTestObj->is_connected());
	mTestObj->insert_edge(2,3);
	CPPUNIT_ASSERT(mTestObj->is_connected());
	mTestObj->insert_edge(3,1);
	CPPUNIT_ASSERT(mTestObj->is_connected());
}

void
GraphTests::testIsNotConnected(void)
{
	mTestObj->insert_edge(1,2);
	mTestObj->insert_edge(2,3);
	mTestObj->insert_edge(3,1);
	mTestObj->insert_node(7);
	CPPUNIT_ASSERT(!mTestObj->is_connected());
}

void
GraphTests::testIsCyclical(void)
{
//	CPPUNIT_FAIL("TODO");
}

void
GraphTests::testIsNotCyclical(void)
{
//	CPPUNIT_FAIL("TODO");
}

void
GraphTests::testIsTree(void)
{
//	CPPUNIT_FAIL("TODO");
}

void
GraphTests::testDistance(void)
{
//	CPPUNIT_FAIL("TODO");
}

void
GraphTests::testToDot(void)
{
//	CPPUNIT_FAIL("TODO");
}

void
GraphTests::testInsert_node(void)
{
	mTestObj->insert_node(3);
	CPPUNIT_ASSERT_EQUAL(1,mTestObj->size());
	mTestObj->insert_node(3);
	CPPUNIT_ASSERT_EQUAL(1,mTestObj->size());
	mTestObj->insert_node(7);
	CPPUNIT_ASSERT_EQUAL(2,mTestObj->size());
}

void
GraphTests::testInsert_edgeWithoutWeight(void)
{
	//Edge without weight
	mTestObj->insert_edge(3,3);
	CPPUNIT_ASSERT_EQUAL(1,mTestObj->size());

	mTestObj->insert_edge(3,7);
	CPPUNIT_ASSERT_EQUAL(2,mTestObj->size());

}

void
GraphTests::testInsert_edgeWithWeight(void)
{
	//Edge without weight
//	mTestObj->insert_edge(3,3,100);
//	CPPUNIT_ASSERT_EQUAL(1,mTestObj->size());
//
//	mTestObj->insert_edge(3,7);
//	CPPUNIT_ASSERT_EQUAL(2,mTestObj->size());

}

void
GraphTests::testIncrease_edge(void)
{
}

void
GraphTests::testRemove_edge(void)
{
}

void
GraphTests::testRemove_node(void)
{
}

void
GraphTests::testGet_node(void)
{
}

void
GraphTests::testGet_nodes(void)
{
}
