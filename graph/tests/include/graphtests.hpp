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
    CPPUNIT_TEST(testIsConnected);
    CPPUNIT_TEST(testIsCyclical);
    CPPUNIT_TEST(testIsTree);
    CPPUNIT_TEST(testDistance);
    CPPUNIT_TEST(testToDot);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp(void);
    void tearDown(void);

protected:
    void testSize(void);
    void testEmpty(void);
    void testIsConnected(void);
    void testIsCyclical(void);
    void testIsTree(void);
    void testDistance(void);
    void testToDot(void);

private:
    Graph *mTestObj;

};
