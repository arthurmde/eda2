#include <cppunit/ui/text/TestRunner.h>
#include "graphtests.hpp"
#include "nodetests.hpp"

int main(void)
{

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION( GraphTests);
CPPUNIT_TEST_SUITE_REGISTRATION( NodeTests);
 
// Get the instance of registry Create
CppUnit::TestFactoryRegistry &registry =  CppUnit::TestFactoryRegistry::getRegistry();
 
// Adds the test to the list of test to run
CppUnit::TextUi::TestRunner runner;
runner.addTest( registry.makeTest() );
 
// Run the test.
bool wasSucessful = runner.run();

}
