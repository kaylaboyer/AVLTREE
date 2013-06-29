/**	@file: ut_avltree_operator_relational.cpp
	@author Garth Santor
	@author gsantor@fanshaweonline.ca
	@author http://www.gats.ca/
	@date 2013-01-16
	@version 0.0.0
	@note Developed for C++ 11
	@brief avltree<T> relational operator unit tests.
	*/

#include <boost/test/auto_unit_test.hpp>
#include <iostream>
#include "avltree.hpp"
#include "KaylaTestObject.hpp"
#include <map>



/**	operator != */
BOOST_AUTO_TEST_CASE( ut_inequality ) {
//	//std::cout << "NOT IMPLEMENTED: operator !=\n";
	std::map<char, int> mapcharint;
	avltree<char, int> avlcharint;
	std::map<double, std::string> mapdoublestring;
	avltree<double, std::string> avldoublestring;
	std::map<int,int> mapintint;
	avltree<int,int>avlintint;
	
	avltree<char, int> avlcharintEmpty;
	avltree<double, std::string> avldoublestringEmpty;
	avltree<int,int>avlintintEmpty;

	std::map<double, std::string> mapdoublestringEmpty;
	std::map<int,int> mapintintEmpty;
	std::map<char, int> mapcharintEmpty;
	
	BOOST_CHECK(avlintint == avlintint);
	BOOST_CHECK(avlcharint == avlcharint);
	BOOST_CHECK(avldoublestring == avldoublestring);
	
	BOOST_CHECK(mapcharint == mapcharint);
	BOOST_CHECK(mapdoublestring == mapdoublestring);
	BOOST_CHECK(mapintint == mapintint);

	mapdoublestring.insert (std::pair<double,std::string>(1.0,"Kayla"));
	avldoublestring.insert (std::pair<double,std::string>(1.0,"Kayla"));
	mapcharint.insert (std::pair<char,int>('a',100));
	avlcharint.insert (std::pair<char,int>('a',100));
	avlintint.insert (std::pair<int,int>(1,1));
	mapintint.insert (std::pair<int,int>(1,1));
	
	BOOST_CHECK(avlintint == avlintint);
	BOOST_CHECK(avlcharint == avlcharint);
	BOOST_CHECK(avldoublestring == avldoublestring);
	
	BOOST_CHECK(mapcharint == mapcharint);
	BOOST_CHECK(mapdoublestring == mapdoublestring);
	BOOST_CHECK(mapintint == mapintint);

	mapdoublestring.insert (std::pair<double,std::string>(2.0,"Kayla"));
	avldoublestring.insert (std::pair<double,std::string>(2.0,"Kayla"));
	mapcharint.insert (std::pair<char,int>('b',100));
	avlcharint.insert (std::pair<char,int>('b',100));
	avlintint.insert (std::pair<int,int>(2,1));
	mapintint.insert (std::pair<int,int>(2,1));

	BOOST_CHECK(avlintint == avlintint);
	BOOST_CHECK(avlcharint == avlcharint);
	BOOST_CHECK(avldoublestring == avldoublestring);
		
	BOOST_CHECK(mapcharint == mapcharint);
	BOOST_CHECK(mapdoublestring == mapdoublestring);
	BOOST_CHECK(mapintint == mapintint);

	for(unsigned int i = 0; i <= 99; ++i)
	{
		mapcharint.insert(std::pair<char,int>('a'+i, i));
		avlcharint.insert(std::pair<char,int>('a'+i, i));
	}
	for(double i = 0.00; i <= 99.00; ++i)
	{
		mapdoublestring.insert(std::pair<double,std::string>(1.00+i, "kayla"));
		avldoublestring.insert(std::pair<double,std::string>(1.00+i, "kayla"));
	}
	for(unsigned int i = 0; i <= 99; ++i)
	{
		mapintint.insert(std::pair<int,int>(i,i));
		avlintint.insert(std::pair<int,int>(i,i));
	}
	BOOST_CHECK(avlintint == avlintint);
	BOOST_CHECK(avlcharint == avlcharint);
	BOOST_CHECK(avldoublestring == avldoublestring);

	BOOST_CHECK(mapcharint == mapcharint);
	BOOST_CHECK(mapdoublestring == mapdoublestring);
	BOOST_CHECK(mapintint == mapintint);

	BOOST_CHECK(avlintint != avlintintEmpty);
	BOOST_CHECK(avlcharint != avlcharintEmpty);
	BOOST_CHECK(avldoublestring != avldoublestringEmpty);

	BOOST_CHECK(mapcharint != mapcharintEmpty);
	BOOST_CHECK(mapdoublestring != mapdoublestringEmpty);
	BOOST_CHECK(mapintint != mapintintEmpty);
}


BOOST_AUTO_TEST_CASE( ut_equality ) {
//std::cout << "NOT IMPLEMENTED: operator ==\n";
	
	
	
	std::map<char, int> mapcharint;
	avltree<char, int> avlcharint;
	std::map<double, std::string> mapdoublestring;
	avltree<double, std::string> avldoublestring;
	std::map<int,int> mapintint;
	avltree<int,int>avlintint;
	
	
	avltree<char, int> avlcharintEmpty;
	avltree<double, std::string> avldoublestringEmpty;
	avltree<int,int>avlintintEmpty;

	std::map<double, std::string> mapdoublestringEmpty;
	std::map<int,int> mapintintEmpty;
	std::map<char, int> mapcharintEmpty;
	
	BOOST_CHECK(avlintint == avlintint);
	BOOST_CHECK(avlcharint == avlcharint);
	BOOST_CHECK(avldoublestring == avldoublestring);

	BOOST_CHECK(mapcharint == mapcharint);
	BOOST_CHECK(mapdoublestring == mapdoublestring);
	BOOST_CHECK(mapintint == mapintint);

	mapdoublestring.insert (std::pair<double,std::string>(1.0,"Kayla"));
	avldoublestring.insert (std::pair<double,std::string>(1.0,"Kayla"));
	mapcharint.insert (std::pair<char,int>('a',100));
	avlcharint.insert (std::pair<char,int>('a',100));
	avlintint.insert (std::pair<int,int>(1,1));
	mapintint.insert (std::pair<int,int>(1,1));
	
	BOOST_CHECK(avlcharintEmpty != avlcharint);
	BOOST_CHECK(avldoublestring != avldoublestringEmpty);
	BOOST_CHECK(avlintint != avlintintEmpty);

	BOOST_CHECK(mapcharint != mapcharintEmpty);
	BOOST_CHECK(mapdoublestring != mapdoublestringEmpty);
	BOOST_CHECK(mapintint != mapintintEmpty);

	mapdoublestring.insert (std::pair<double,std::string>(2.0,"Kayla"));
	avldoublestring.insert (std::pair<double,std::string>(2.0,"Kayla"));
	mapcharint.insert (std::pair<char,int>('b',100));
	avlcharint.insert (std::pair<char,int>('b',100));
	avlintint.insert (std::pair<int,int>(2,1));
	mapintint.insert (std::pair<int,int>(2,1));

	BOOST_CHECK(avlcharintEmpty != avlcharint);
	BOOST_CHECK(avldoublestring != avldoublestringEmpty);
	BOOST_CHECK(avlintint != avlintintEmpty);

	BOOST_CHECK(mapcharint != mapcharintEmpty);
	BOOST_CHECK(mapdoublestring != mapdoublestringEmpty);
	BOOST_CHECK(mapintint != mapintintEmpty);

	for(unsigned int i = 0; i <= 99; ++i)
	{
		mapcharint.insert(std::pair<char,int>('a'+i, i));
		avlcharint.insert(std::pair<char,int>('a'+i, i));
	}
	for(double i = 0.00; i <= 99.00; ++i)
	{
		mapdoublestring.insert(std::pair<double,std::string>(1.00+i, "kayla"));
		avldoublestring.insert(std::pair<double,std::string>(1.00+i, "kayla"));
	}
	for(unsigned int i = 0; i <= 99; ++i)
	{
		mapintint.insert(std::pair<int,int>(i,i));
		avlintint.insert(std::pair<int,int>(i,i));
	}

	BOOST_CHECK(avlcharintEmpty != avlcharint);
	BOOST_CHECK(avldoublestring != avldoublestringEmpty);
	BOOST_CHECK(avlintint != avlintintEmpty);

	BOOST_CHECK(mapcharint != mapcharintEmpty);
	BOOST_CHECK(mapdoublestring != mapdoublestringEmpty);
	BOOST_CHECK(mapintint != mapintintEmpty);

}

BOOST_AUTO_TEST_CASE( ut_less ) {


	
	
	std::map<char, int> mapcharint;
	avltree<char, int> avlcharint;
	std::map<double, std::string> mapdoublestring;
	avltree<double, std::string> avldoublestring;
	std::map<int,int> mapintint;
	avltree<int,int>avlintint;
	
	avltree<char, int> avlcharintEmpty;
	avltree<double, std::string> avldoublestringEmpty;
	avltree<int,int>avlintintEmpty;

	std::map<double, std::string> mapdoublestringEmpty;
	std::map<int,int> mapintintEmpty;
	std::map<char, int> mapcharintEmpty;
	
	
	BOOST_CHECK_EQUAL(avlcharint < avlcharint, false);
	BOOST_CHECK_EQUAL(avldoublestring < avldoublestring, false);
	BOOST_CHECK_EQUAL(avlintint < avlintint, false);

	BOOST_CHECK_EQUAL(mapcharint < mapcharint, false);
	BOOST_CHECK_EQUAL(mapdoublestring < mapdoublestring, false);
	BOOST_CHECK_EQUAL(mapintint < mapintint, false);


	mapdoublestring.insert (std::pair<double,std::string>(1.0,"A"));
	avldoublestring.insert (std::pair<double,std::string>(1.0,"A"));
	mapcharint.insert (std::pair<char,int>('a',100));
	avlcharint.insert (std::pair<char,int>('a',100));
	avlintint.insert (std::pair<int,int>(1,1));
	mapintint.insert (std::pair<int,int>(1,1));

	BOOST_CHECK_EQUAL(avlcharint < avlcharint, false);
	BOOST_CHECK_EQUAL(avldoublestring < avldoublestring, false);
	BOOST_CHECK_EQUAL(avlintint < avlintint, false);

	BOOST_CHECK_EQUAL(mapcharint < mapcharint, false);
	BOOST_CHECK_EQUAL(mapdoublestring < mapdoublestring, false);
	BOOST_CHECK_EQUAL(mapintint < mapintint, false);

	BOOST_CHECK_EQUAL( avlcharintEmpty  < avlcharint, true);
	BOOST_CHECK_EQUAL(avldoublestringEmpty < avldoublestring, true);
	BOOST_CHECK_EQUAL(avlintintEmpty < avlintint, true);

	BOOST_CHECK_EQUAL(avlcharint < avlcharintEmpty, true);
	BOOST_CHECK_EQUAL(avldoublestring < avldoublestringEmpty, true);
	BOOST_CHECK_EQUAL(avlintint < avlintintEmpty, true);


	BOOST_CHECK_EQUAL(mapcharintEmpty < mapcharint,true);
	BOOST_CHECK_EQUAL(mapdoublestringEmpty < mapdoublestring, true);
	BOOST_CHECK_EQUAL(mapintintEmpty < mapintint, true);

	mapdoublestring.insert (std::pair<double,std::string>(2.0,"B"));
	avldoublestring.insert (std::pair<double,std::string>(2.0,"B"));
	mapcharint.insert (std::pair<char,int>('b',200));
	avlcharint.insert (std::pair<char,int>('b',200));
	avlintint.insert (std::pair<int,int>(2,2));
	mapintint.insert (std::pair<int,int>(2,2));

	
	avldoublestringEmpty.insert (std::pair<double,std::string>(1.0,"A"));
	avlcharintEmpty.insert (std::pair<char,int>('a',100));
	avlintintEmpty.insert (std::pair<int,int>(1,1));
	mapcharintEmpty.insert (std::pair<char,int>('a',100));
	mapdoublestringEmpty.insert (std::pair<double,std::string>(1.0,"A"));
	mapintintEmpty.insert (std::pair<int,int>(1,1));


	BOOST_CHECK_EQUAL( avlcharintEmpty  < avlcharint, true);
	BOOST_CHECK_EQUAL(avldoublestringEmpty < avldoublestring, true);
	BOOST_CHECK_EQUAL(avlintintEmpty < avlintint, true);
	
	BOOST_CHECK_EQUAL(mapcharintEmpty < mapcharint,true);
	BOOST_CHECK_EQUAL(mapdoublestringEmpty < mapdoublestring, true);
	BOOST_CHECK_EQUAL(mapintintEmpty < mapintint, true);

	
	avldoublestringEmpty.insert (std::pair<double,std::string>(2.0,"B"));
	avlcharintEmpty.insert (std::pair<char,int>('b',200));
	avlintintEmpty.insert (std::pair<int,int>(2,2));
	mapcharintEmpty.insert (std::pair<char,int>('b',200));
	mapdoublestringEmpty.insert (std::pair<double,std::string>(2.0,"B"));
	mapintintEmpty.insert (std::pair<int,int>(2,2));
	
	BOOST_CHECK_EQUAL( avlcharintEmpty  < avlcharint, false);
	BOOST_CHECK_EQUAL(avldoublestringEmpty < avldoublestring, false);
	BOOST_CHECK_EQUAL(avlintintEmpty < avlintint, false);
	BOOST_CHECK_EQUAL(mapcharintEmpty < mapcharint,false);
	BOOST_CHECK_EQUAL(mapdoublestringEmpty < mapdoublestring,false);
	BOOST_CHECK_EQUAL(mapintintEmpty < mapintint,false);

	for(unsigned int i = 0; i <= 4; ++i)
	{
		mapcharint.insert(std::pair<char,int>('!'+i, i));
		avlcharint.insert(std::pair<char,int>('!'+i, i));
	}
	for(double i = 0.00; i <= 4.0; ++i)
	{
		mapdoublestring.insert(std::pair<double,std::string>(1.00+i, "kayla"));
		avldoublestring.insert(std::pair<double,std::string>(1.00+i, "kayla"));
	}
	for(unsigned int i = 0; i <= 4; ++i)
	{
		mapintint.insert(std::pair<int,int>(i,i));
		avlintint.insert(std::pair<int,int>(i,i));
	}
	
	BOOST_CHECK_EQUAL( avlcharintEmpty  < avlcharint, false);
	BOOST_CHECK_EQUAL(avldoublestringEmpty < avldoublestring, true);
	BOOST_CHECK_EQUAL(avlintintEmpty < avlintint, false);
	BOOST_CHECK_EQUAL(mapcharintEmpty < mapcharint,false);
	BOOST_CHECK_EQUAL(mapdoublestringEmpty < mapdoublestring,true);
	BOOST_CHECK_EQUAL(mapintintEmpty < mapintint,false);

}

BOOST_AUTO_TEST_CASE( ut_less_equal ) {
		
	std::map<char, int> mapcharint;
	avltree<char, int> avlcharint;
	std::map<double, std::string> mapdoublestring;
	avltree<double, std::string> avldoublestring;
	std::map<int,int> mapintint;
	avltree<int,int>avlintint;
	
	avltree<char, int> avlcharintEmpty;
	avltree<double, std::string> avldoublestringEmpty;
	avltree<int,int>avlintintEmpty;

	std::map<double, std::string> mapdoublestringEmpty;
	std::map<int,int> mapintintEmpty;
	std::map<char, int> mapcharintEmpty;
	
	
	BOOST_CHECK_EQUAL(avlcharint <= avlcharint, true);
	BOOST_CHECK_EQUAL(avldoublestring <= avldoublestring, true);
	BOOST_CHECK_EQUAL(avlintint <= avlintint, true);

	BOOST_CHECK_EQUAL(mapcharint <= mapcharint, true);
	BOOST_CHECK_EQUAL(mapdoublestring <= mapdoublestring, true);
	BOOST_CHECK_EQUAL(mapintint <= mapintint, true);


	mapdoublestring.insert (std::pair<double,std::string>(1.0,"A"));
	avldoublestring.insert (std::pair<double,std::string>(1.0,"A"));
	mapcharint.insert (std::pair<char,int>('a',100));
	avlcharint.insert (std::pair<char,int>('a',100));
	avlintint.insert (std::pair<int,int>(1,1));
	mapintint.insert (std::pair<int,int>(1,1));

	BOOST_CHECK_EQUAL(avlcharint <= avlcharint, true);
	BOOST_CHECK_EQUAL(avldoublestring <= avldoublestring, true);
	BOOST_CHECK_EQUAL(avlintint <= avlintint, true);

	BOOST_CHECK_EQUAL(mapcharint <= mapcharint, true);
	BOOST_CHECK_EQUAL(mapdoublestring <= mapdoublestring, true);
	BOOST_CHECK_EQUAL(mapintint <= mapintint, true);

	BOOST_CHECK_EQUAL( avlcharintEmpty  <= avlcharint, true);
	BOOST_CHECK_EQUAL(avldoublestringEmpty <= avldoublestring, true);
	BOOST_CHECK_EQUAL(avlintintEmpty <= avlintint, true);

	BOOST_CHECK_EQUAL(mapcharintEmpty <= mapcharint,true);
	BOOST_CHECK_EQUAL(mapdoublestringEmpty <= mapdoublestring, true);
	BOOST_CHECK_EQUAL(mapintintEmpty <= mapintint, true);

	mapdoublestring.insert (std::pair<double,std::string>(2.0,"B"));
	avldoublestring.insert (std::pair<double,std::string>(2.0,"B"));
	mapcharint.insert (std::pair<char,int>('b',200));
	avlcharint.insert (std::pair<char,int>('b',200));
	avlintint.insert (std::pair<int,int>(2,2));
	mapintint.insert (std::pair<int,int>(2,2));

	
	avldoublestringEmpty.insert (std::pair<double,std::string>(1.0,"A"));
	avlcharintEmpty.insert (std::pair<char,int>('a',100));
	avlintintEmpty.insert (std::pair<int,int>(1,1));
	mapcharintEmpty.insert (std::pair<char,int>('a',100));
	mapdoublestringEmpty.insert (std::pair<double,std::string>(1.0,"A"));
	mapintintEmpty.insert (std::pair<int,int>(1,1));


	BOOST_CHECK_EQUAL( avlcharintEmpty  <= avlcharint, true);
	BOOST_CHECK_EQUAL(avldoublestringEmpty <= avldoublestring, true);
	BOOST_CHECK_EQUAL(avlintintEmpty <= avlintint, true);
	
	BOOST_CHECK_EQUAL(mapcharintEmpty <= mapcharint,true);
	BOOST_CHECK_EQUAL(mapdoublestringEmpty <= mapdoublestring, true);
	BOOST_CHECK_EQUAL(mapintintEmpty <= mapintint, true);

	
	avldoublestringEmpty.insert (std::pair<double,std::string>(2.0,"B"));
	avlcharintEmpty.insert (std::pair<char,int>('b',200));
	avlintintEmpty.insert (std::pair<int,int>(2,2));
	mapcharintEmpty.insert (std::pair<char,int>('b',200));
	mapdoublestringEmpty.insert (std::pair<double,std::string>(2.0,"B"));
	mapintintEmpty.insert (std::pair<int,int>(2,2));
	
	BOOST_CHECK_EQUAL( avlcharintEmpty  <= avlcharint, true);
	BOOST_CHECK_EQUAL(avldoublestringEmpty <= avldoublestring, true);
	BOOST_CHECK_EQUAL(avlintintEmpty <= avlintint, true);
	BOOST_CHECK_EQUAL(mapcharintEmpty <= mapcharint,true);
	BOOST_CHECK_EQUAL(mapdoublestringEmpty <= mapdoublestring,true);
	BOOST_CHECK_EQUAL(mapintintEmpty <= mapintint,true);

	for(unsigned int i = 0; i <= 4; ++i)
	{
		mapcharint.insert(std::pair<char,int>('!'+i, i));
		avlcharint.insert(std::pair<char,int>('!'+i, i));
	}
	for(double i = 0.00; i <= 4.0; ++i)
	{
		mapdoublestring.insert(std::pair<double,std::string>(1.00+i, "kayla"));
		avldoublestring.insert(std::pair<double,std::string>(1.00+i, "kayla"));
	}
	for(unsigned int i = 0; i <= 4; ++i)
	{
		mapintint.insert(std::pair<int,int>(i,i));
		avlintint.insert(std::pair<int,int>(i,i));
	}
	
	BOOST_CHECK_EQUAL( avlcharintEmpty  <= avlcharint, false);
	BOOST_CHECK_EQUAL(avldoublestringEmpty <= avldoublestring, true);
	BOOST_CHECK_EQUAL(avlintintEmpty <= avlintint, false);
	BOOST_CHECK_EQUAL(mapcharintEmpty <= mapcharint,false);
	BOOST_CHECK_EQUAL(mapdoublestringEmpty <= mapdoublestring,true);
	BOOST_CHECK_EQUAL(mapintintEmpty <= mapintint,false);

}

BOOST_AUTO_TEST_CASE( ut_greater ){

std::map<char, int> mapcharint;
	avltree<char, int> avlcharint;
	std::map<double, std::string> mapdoublestring;
	avltree<double, std::string> avldoublestring;
	std::map<int,int> mapintint;
	avltree<int,int>avlintint;
	
	avltree<char, int> avlcharintEmpty;
	avltree<double, std::string> avldoublestringEmpty;
	avltree<int,int>avlintintEmpty;

	std::map<double, std::string> mapdoublestringEmpty;
	std::map<int,int> mapintintEmpty;
	std::map<char, int> mapcharintEmpty;
	
	
	BOOST_CHECK_EQUAL(avlcharint > avlcharint, false);
	BOOST_CHECK_EQUAL(avldoublestring > avldoublestring, false);
	BOOST_CHECK_EQUAL(avlintint > avlintint, false);

	BOOST_CHECK_EQUAL(mapcharint > mapcharint, false);
	BOOST_CHECK_EQUAL(mapdoublestring > mapdoublestring, false);
	BOOST_CHECK_EQUAL(mapintint > mapintint, false);


	mapdoublestring.insert (std::pair<double,std::string>(1.0,"A"));
	avldoublestring.insert (std::pair<double,std::string>(1.0,"A"));
	mapcharint.insert (std::pair<char,int>('a',100));
	avlcharint.insert (std::pair<char,int>('a',100));
	avlintint.insert (std::pair<int,int>(1,1));
	mapintint.insert (std::pair<int,int>(1,1));

	BOOST_CHECK_EQUAL(avlcharint > avlcharint, false);
	BOOST_CHECK_EQUAL(avldoublestring > avldoublestring, false);
	BOOST_CHECK_EQUAL(avlintint > avlintint, false);

	BOOST_CHECK_EQUAL(mapcharint > mapcharint, false);
	BOOST_CHECK_EQUAL(mapdoublestring > mapdoublestring, false);
	BOOST_CHECK_EQUAL(mapintint > mapintint, false);

	BOOST_CHECK_EQUAL( avlcharintEmpty  > avlcharint, false);
	BOOST_CHECK_EQUAL(avldoublestringEmpty > avldoublestring, false);
	BOOST_CHECK_EQUAL(avlintintEmpty > avlintint, false);

	BOOST_CHECK_EQUAL(mapcharintEmpty > mapcharint,false);
	BOOST_CHECK_EQUAL(mapdoublestringEmpty > mapdoublestring, false);
	BOOST_CHECK_EQUAL(mapintintEmpty > mapintint, false);

	mapdoublestring.insert (std::pair<double,std::string>(2.0,"B"));
	avldoublestring.insert (std::pair<double,std::string>(2.0,"B"));
	mapcharint.insert (std::pair<char,int>('b',200));
	avlcharint.insert (std::pair<char,int>('b',200));
	avlintint.insert (std::pair<int,int>(2,2));
	mapintint.insert (std::pair<int,int>(2,2));

	
	avldoublestringEmpty.insert (std::pair<double,std::string>(1.0,"A"));
	avlcharintEmpty.insert (std::pair<char,int>('a',100));
	avlintintEmpty.insert (std::pair<int,int>(1,1));
	mapcharintEmpty.insert (std::pair<char,int>('a',100));
	mapdoublestringEmpty.insert (std::pair<double,std::string>(1.0,"A"));
	mapintintEmpty.insert (std::pair<int,int>(1,1));


	BOOST_CHECK_EQUAL( avlcharintEmpty  > avlcharint, false);
	BOOST_CHECK_EQUAL(avldoublestringEmpty > avldoublestring, false);
	BOOST_CHECK_EQUAL(avlintintEmpty > avlintint, false);
	
	BOOST_CHECK_EQUAL(mapcharintEmpty > mapcharint,false);
	BOOST_CHECK_EQUAL(mapdoublestringEmpty > mapdoublestring, false);
	BOOST_CHECK_EQUAL(mapintintEmpty > mapintint, false);

	
	avldoublestringEmpty.insert (std::pair<double,std::string>(2.0,"B"));
	avlcharintEmpty.insert (std::pair<char,int>('b',200));
	avlintintEmpty.insert (std::pair<int,int>(2,2));
	mapcharintEmpty.insert (std::pair<char,int>('b',200));
	mapdoublestringEmpty.insert (std::pair<double,std::string>(2.0,"B"));
	mapintintEmpty.insert (std::pair<int,int>(2,2));
	
	BOOST_CHECK_EQUAL( avlcharintEmpty  > avlcharint, false);
	BOOST_CHECK_EQUAL(avldoublestringEmpty > avldoublestring, false);
	BOOST_CHECK_EQUAL(avlintintEmpty > avlintint, false);
	BOOST_CHECK_EQUAL(mapcharintEmpty > mapcharint,false);
	BOOST_CHECK_EQUAL(mapdoublestringEmpty > mapdoublestring,false);
	BOOST_CHECK_EQUAL(mapintintEmpty > mapintint,false);

	for(unsigned int i = 0; i <= 4; ++i)
	{
		mapcharint.insert(std::pair<char,int>('!'+i, i));
		avlcharint.insert(std::pair<char,int>('!'+i, i));
	}
	for(double i = 0.00; i <= 4.0; ++i)
	{
		mapdoublestring.insert(std::pair<double,std::string>(1.00+i, "kayla"));
		avldoublestring.insert(std::pair<double,std::string>(1.00+i, "kayla"));
	}
	for(unsigned int i = 0; i <= 4; ++i)
	{
		mapintint.insert(std::pair<int,int>(i,i));
		avlintint.insert(std::pair<int,int>(i,i));
	}
	BOOST_CHECK_EQUAL(mapcharintEmpty > mapcharint,true);
	BOOST_CHECK_EQUAL(mapdoublestringEmpty > mapdoublestring,false);
	BOOST_CHECK_EQUAL(mapintintEmpty > mapintint,true);
		
	BOOST_CHECK_EQUAL( avlcharintEmpty  > avlcharint, true);
	BOOST_CHECK_EQUAL(avldoublestringEmpty > avldoublestring, false);
	BOOST_CHECK_EQUAL(avlintintEmpty > avlintint, true);
	
	

}

///**	operator >= */
BOOST_AUTO_TEST_CASE( ut_greater_equal )  {
		
	std::map<char, int> mapcharint;
	avltree<char, int> avlcharint;
	std::map<double, std::string> mapdoublestring;
	avltree<double, std::string> avldoublestring;
	std::map<int,int> mapintint;
	avltree<int,int>avlintint;
	
	avltree<char, int> avlcharintEmpty;
	avltree<double, std::string> avldoublestringEmpty;
	avltree<int,int>avlintintEmpty;

	std::map<double, std::string> mapdoublestringEmpty;
	std::map<int,int> mapintintEmpty;
	std::map<char, int> mapcharintEmpty;
	
	
	BOOST_CHECK_EQUAL(avlcharint >= avlcharint, true);
	BOOST_CHECK_EQUAL(avldoublestring >= avldoublestring, true);
	BOOST_CHECK_EQUAL(avlintint >= avlintint, true);

	BOOST_CHECK_EQUAL(mapcharint >= mapcharint, true);
	BOOST_CHECK_EQUAL(mapdoublestring >= mapdoublestring, true);
	BOOST_CHECK_EQUAL(mapintint >= mapintint, true);


	mapdoublestring.insert (std::pair<double,std::string>(1.0,"A"));
	avldoublestring.insert (std::pair<double,std::string>(1.0,"A"));
	mapcharint.insert (std::pair<char,int>('a',100));
	avlcharint.insert (std::pair<char,int>('a',100));
	avlintint.insert (std::pair<int,int>(1,1));
	mapintint.insert (std::pair<int,int>(1,1));

	BOOST_CHECK_EQUAL(avlcharint >= avlcharint, true);
	BOOST_CHECK_EQUAL(avldoublestring >= avldoublestring, true);
	BOOST_CHECK_EQUAL(avlintint >= avlintint, true);

	BOOST_CHECK_EQUAL(mapcharint >= mapcharint, true);
	BOOST_CHECK_EQUAL(mapdoublestring >= mapdoublestring, true);
	BOOST_CHECK_EQUAL(mapintint >= mapintint, true);

	BOOST_CHECK_EQUAL( avlcharintEmpty  >= avlcharint, false);
	BOOST_CHECK_EQUAL(avldoublestringEmpty >= avldoublestring, false);
	BOOST_CHECK_EQUAL(avlintintEmpty >= avlintint, false);

	BOOST_CHECK_EQUAL(mapcharintEmpty >= mapcharint,false);
	BOOST_CHECK_EQUAL(mapdoublestringEmpty >= mapdoublestring, false);
	BOOST_CHECK_EQUAL(mapintintEmpty >= mapintint, false);

	mapdoublestring.insert (std::pair<double,std::string>(2.0,"B"));
	avldoublestring.insert (std::pair<double,std::string>(2.0,"B"));
	mapcharint.insert (std::pair<char,int>('b',200));
	avlcharint.insert (std::pair<char,int>('b',200));
	avlintint.insert (std::pair<int,int>(2,2));
	mapintint.insert (std::pair<int,int>(2,2));

	
	avldoublestringEmpty.insert (std::pair<double,std::string>(1.0,"A"));
	avlcharintEmpty.insert (std::pair<char,int>('a',100));
	avlintintEmpty.insert (std::pair<int,int>(1,1));
	mapcharintEmpty.insert (std::pair<char,int>('a',100));
	mapdoublestringEmpty.insert (std::pair<double,std::string>(1.0,"A"));
	mapintintEmpty.insert (std::pair<int,int>(1,1));


	BOOST_CHECK_EQUAL( avlcharintEmpty  >= avlcharint, false);
	BOOST_CHECK_EQUAL(avldoublestringEmpty >= avldoublestring, false);
	BOOST_CHECK_EQUAL(avlintintEmpty >= avlintint, false);
	
	BOOST_CHECK_EQUAL(mapcharintEmpty >= mapcharint,false);
	BOOST_CHECK_EQUAL(mapdoublestringEmpty >= mapdoublestring, false);
	BOOST_CHECK_EQUAL(mapintintEmpty >= mapintint, false);

	
	avldoublestringEmpty.insert (std::pair<double,std::string>(2.0,"B"));
	avlcharintEmpty.insert (std::pair<char,int>('b',200));
	avlintintEmpty.insert (std::pair<int,int>(2,2));
	mapcharintEmpty.insert (std::pair<char,int>('b',200));
	mapdoublestringEmpty.insert (std::pair<double,std::string>(2.0,"B"));
	mapintintEmpty.insert (std::pair<int,int>(2,2));
	
	BOOST_CHECK_EQUAL( avlcharintEmpty  >= avlcharint, true);
	BOOST_CHECK_EQUAL(avldoublestringEmpty >= avldoublestring, true);
	BOOST_CHECK_EQUAL(avlintintEmpty >= avlintint, true);
	BOOST_CHECK_EQUAL(mapcharintEmpty >= mapcharint,true);
	BOOST_CHECK_EQUAL(mapdoublestringEmpty >= mapdoublestring,true);
	BOOST_CHECK_EQUAL(mapintintEmpty >= mapintint,true);

	for(unsigned int i = 0; i <= 4; ++i)
	{
		mapcharint.insert(std::pair<char,int>('!'+i, i));
		avlcharint.insert(std::pair<char,int>('!'+i, i));
	}
	for(double i = 0.00; i <= 4.0; ++i)
	{
		mapdoublestring.insert(std::pair<double,std::string>(1.00+i, "kayla"));
		avldoublestring.insert(std::pair<double,std::string>(1.00+i, "kayla"));
	}
	for(unsigned int i = 0; i <= 4; ++i)
	{
		mapintint.insert(std::pair<int,int>(i,i));
		avlintint.insert(std::pair<int,int>(i,i));
	}
	
	BOOST_CHECK_EQUAL( avlcharintEmpty  >= avlcharint, true);
	BOOST_CHECK_EQUAL(avldoublestringEmpty >= avldoublestring, false);
	BOOST_CHECK_EQUAL(avlintintEmpty >= avlintint, true);
	BOOST_CHECK_EQUAL(mapcharintEmpty >= mapcharint,true);
	BOOST_CHECK_EQUAL(mapdoublestringEmpty >= mapdoublestring,false);
	BOOST_CHECK_EQUAL(mapintintEmpty >= mapintint,true);

}


/*=============================================================

Revision History

Version 0.0.0: 2013-01-16
Alpha release.

=============================================================

Copyright Garth Santor

The copyright to the computer program(s) herein
is the property of Garth Santor of Canada.
The program(s) may be used and/or copied only with
the written permission of Garth Santor
or in accordance with the terms and conditions
stipulated in the agreement/contract under which
the program(s) have been supplied.
=============================================================*/