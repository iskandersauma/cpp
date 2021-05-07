/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/ErrorPrinter.h>

int main( int argc, char *argv[] ) {
 int status;
    CxxTest::ErrorPrinter tmp;
    CxxTest::RealWorldDescription::_worldName = "cxxtest";
    status = CxxTest::Main< CxxTest::ErrorPrinter >( tmp, argc, argv );
    return status;
}
bool suite_MyTestSuite_init = false;
#include "test.cpp"

static MyTestSuite suite_MyTestSuite;

static CxxTest::List Tests_MyTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_MyTestSuite( "test.cpp", 4, "MyTestSuite", suite_MyTestSuite, Tests_MyTestSuite );

static class TestDescription_suite_MyTestSuite_test_insert : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_insert() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 6, "test_insert" ) {}
 void runTest() { suite_MyTestSuite.test_insert(); }
} testDescription_suite_MyTestSuite_test_insert;

static class TestDescription_suite_MyTestSuite_test_append : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_append() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 14, "test_append" ) {}
 void runTest() { suite_MyTestSuite.test_append(); }
} testDescription_suite_MyTestSuite_test_append;

static class TestDescription_suite_MyTestSuite_test_remove : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_remove() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 20, "test_remove" ) {}
 void runTest() { suite_MyTestSuite.test_remove(); }
} testDescription_suite_MyTestSuite_test_remove;

static class TestDescription_suite_MyTestSuite_test_get : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_get() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 26, "test_get" ) {}
 void runTest() { suite_MyTestSuite.test_get(); }
} testDescription_suite_MyTestSuite_test_get;

static class TestDescription_suite_MyTestSuite_test_add : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_add() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 33, "test_add" ) {}
 void runTest() { suite_MyTestSuite.test_add(); }
} testDescription_suite_MyTestSuite_test_add;

static class TestDescription_suite_MyTestSuite_test_subtract : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_subtract() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 43, "test_subtract" ) {}
 void runTest() { suite_MyTestSuite.test_subtract(); }
} testDescription_suite_MyTestSuite_test_subtract;

static class TestDescription_suite_MyTestSuite_test_multi : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_multi() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 54, "test_multi" ) {}
 void runTest() { suite_MyTestSuite.test_multi(); }
} testDescription_suite_MyTestSuite_test_multi;

static class TestDescription_suite_MyTestSuite_test_cout_cin : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_cout_cin() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 67, "test_cout_cin" ) {}
 void runTest() { suite_MyTestSuite.test_cout_cin(); }
} testDescription_suite_MyTestSuite_test_cout_cin;

static class TestDescription_suite_MyTestSuite_test_constructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_constructor() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 75, "test_constructor" ) {}
 void runTest() { suite_MyTestSuite.test_constructor(); }
} testDescription_suite_MyTestSuite_test_constructor;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
