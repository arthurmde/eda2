#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/TestResult.h>

#include "Graph.hpp"

using namespace CppUnit;
using namespace std;

class GraphTests : public CppUnit::TestFixture { 
public: 

    CPPUNIT_TEST_SUITE(GraphTests);
    CPPUNIT_TEST(testSize);
    CPPUNIT_TEST(testEmpty);
    CPPUNIT_TEST(testNotEmpty);
    CPPUNIT_TEST(testIsConnected);
    CPPUNIT_TEST(testIsNotConnected);
    CPPUNIT_TEST(testIsCyclical);
    CPPUNIT_TEST(testIsNotCyclical);
    CPPUNIT_TEST(testIsTree);
    CPPUNIT_TEST(testDistance);
    CPPUNIT_TEST(testToDot);

	CPPUNIT_TEST(testInsert_node);
	CPPUNIT_TEST(testInsert_edgeWithoutWeight);
	CPPUNIT_TEST(testInsert_edgeWithWeight);
	CPPUNIT_TEST(testIncrease_edge);
	CPPUNIT_TEST(testRemove_edge);
	CPPUNIT_TEST(testRemove_node);
	CPPUNIT_TEST(testGet_node);
	CPPUNIT_TEST(testGet_nodes);

    CPPUNIT_TEST_SUITE_END();

public:
    void setUp(void);
    void tearDown(void);

protected:
    void testSize(void);
    void testEmpty(void);
    void testNotEmpty(void);
    void testIsConnected(void);
    void testIsNotConnected(void);
    void testIsCyclical(void);
    void testIsNotCyclical(void);
    void testIsTree(void);
    void testDistance(void);
    void testToDot(void);

	void testInsert_node(void);
	void testInsert_edgeWithoutWeight(void);
	void testInsert_edgeWithWeight(void);
	void testIncrease_edge(void);
	void testRemove_edge(void);
	void testRemove_node(void);
	void testGet_node(void);
	void testGet_nodes(void);

private:
    Graph *mTestObj;

};
