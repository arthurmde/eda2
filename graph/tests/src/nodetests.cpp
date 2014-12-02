#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/TestResult.h>
#include <vector>
#include "nodetests.hpp"

#include "Node.hpp"

using namespace CppUnit;
using namespace std;

void
NodeTests::setUp(void)
{
	this->mTestObj = new Node(7,"node_name");
}

void
NodeTests::tearDown(void)
{
	    delete mTestObj;
}

void
NodeTests::testInsert_neighbor(void)
{
	
//	Node *aux = new Node(37);
//
//	this->mTestObj->insert_neighbor(aux);
//	
//	CPPUNIT_ASSERT_EQUAL(!mTestObj->has_neighbor(aux));
//
//	delete aux;
}

void
NodeTests::testIncrease_neighbor(void)
{

}
void
NodeTests::testRemove_neighbor(void)
{
}

void
NodeTests::testGet_neighbors(void)
{
	Node *aux = new Node(37);
	vector<Neighbor> neighbors;

	neighbors = this->mTestObj->get_neighbors();
	CPPUNIT_ASSERT_EQUAL(0,(int)neighbors.size());

	this->mTestObj->insert_neighbor(aux);

	neighbors = this->mTestObj->get_neighbors();
	CPPUNIT_ASSERT_EQUAL(1,(int)neighbors.size());
}

void
NodeTests::testGet_value(void)
{
	CPPUNIT_ASSERT_EQUAL(7,mTestObj->get_value());
}

void
NodeTests::testGet_name(void)
{
	string compare = "node_name";
	CPPUNIT_ASSERT_EQUAL(compare,mTestObj->get_name());
}

void
NodeTests::testDegree(void)
{
	Node *aux = new Node(37);
	Node *aux2 = new Node(39);

	CPPUNIT_ASSERT_EQUAL(0,mTestObj->degree());
	this->mTestObj->insert_neighbor(aux);
	CPPUNIT_ASSERT_EQUAL(1,mTestObj->degree());
	this->mTestObj->insert_neighbor(aux);
	CPPUNIT_ASSERT_EQUAL(1,mTestObj->degree());

	this->mTestObj->insert_neighbor(aux2);
	CPPUNIT_ASSERT_EQUAL(2,mTestObj->degree());

	delete aux;
	delete aux2;
}

void
NodeTests::testHas_neighbor(void)
{
	Node *aux = new Node(37);
	CPPUNIT_ASSERT(!mTestObj->has_neighbor(aux));
	this->mTestObj->insert_neighbor(aux);
	CPPUNIT_ASSERT(mTestObj->has_neighbor(aux));
	delete aux;
}
