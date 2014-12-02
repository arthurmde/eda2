#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/TestResult.h>

#include "Node.hpp"

using namespace CppUnit;
using namespace std;

class NodeTests : public CppUnit::TestFixture { 
public: 

    CPPUNIT_TEST_SUITE(NodeTests);

	CPPUNIT_TEST(testInsert_neighbor);
	CPPUNIT_TEST(testIncrease_neighbor);
	CPPUNIT_TEST(testRemove_neighbor);
	CPPUNIT_TEST(testGet_neighbors);
	CPPUNIT_TEST(testGet_value);
	CPPUNIT_TEST(testDegree);
	CPPUNIT_TEST(testHas_neighbor);

    CPPUNIT_TEST_SUITE_END();

public:
    void setUp(void);
    void tearDown(void);

protected:

	void testInsert_neighbor(void);
	void testIncrease_neighbor(void);
	void testRemove_neighbor(void);
	void testGet_neighbors(void);
	void testGet_value(void);
	void testDegree(void);
	void testHas_neighbor(void);
private:
    Node *mTestObj;

};
