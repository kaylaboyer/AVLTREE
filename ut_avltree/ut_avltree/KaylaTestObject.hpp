#ifndef GUARD_KAYLA_TEST__OBJECT
#define GUARD_KAYLA_TEST_OBJECT
#include <string>
#include <vector>


//A test object used to test the functionality of objects within an avltree. 
class KaylaTestObject
{
private:
	int _test_int;	
public:
	double doubleTest;

	KaylaTestObject( int n = 0 ) : _test_int(n) {} //custom and default done in one shot 

	
	bool operator < ( KaylaTestObject& rhs)
	{
		return this->doubleTest < rhs.doubleTest;
	}

		
	bool operator < (const KaylaTestObject& rhs) const
	{
		return this->doubleTest < rhs.doubleTest;
	}
	
	bool operator != (KaylaTestObject& rhs)
	{
		return this->doubleTest != rhs.doubleTest;
	}

	bool operator == (KaylaTestObject& rhs)
	{
		return this->doubleTest == rhs.doubleTest;
	}

	bool operator != (const KaylaTestObject& rhs) const
	{
		return this->doubleTest != rhs.doubleTest;
	}

	double operator * ()
	{
		return this->doubleTest;
	}

	~KaylaTestObject(){}

	std::string testString()
	{
		return "This is a test string.";
	}
};



#endif