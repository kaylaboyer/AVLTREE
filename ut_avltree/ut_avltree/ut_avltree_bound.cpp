/**	@file: ut_avltree_bound.cpp
	@author Garth Santor
	@author gsantor@fanshaweonline.ca
	@author http://www.gats.ca/
	@date 2013-01-16
	@version 0.0.0
	@note Developed for C++ 11
	@brief avltree<T>::bound() unit tests.
	*/

#include <boost/test/auto_unit_test.hpp>
#include <iostream>
#include "avltree.hpp"
#include "KaylaTestObject.hpp"
#include <map>



/**	iterator lower_bound( Key const& ) */
BOOST_AUTO_TEST_CASE( ut_lower_bound_key ) {
	//std::cout << "NOT IMPLEMENTED: avltree<T>::lower_bound(Key)\n";

	KaylaTestObject TestObject;	
	std::map<char, int> mapcharint;
	std::map<char,int>::iterator itmapcharint_hi,itmapcharint_low;
	avltree<char, int> avlcharint;
	avltree<char, int>::iterator itavlcharint_hi,itavlcharint_low;
	std::map<int, int> mapintint;
	std::map<int,int>::iterator itmapintint_hi,itmapintint_low;
	avltree<int, int> avlintint;
	avltree<int, int>::iterator itavlintint_hi,itavlintint_low;
	std::map<int, KaylaTestObject> mapinttestobject;
	std::map<int, KaylaTestObject>::iterator itmapinttestobject_hi,itmapinttestobject_low;
	avltree<int, KaylaTestObject>avlinttestobject;
	avltree<int, KaylaTestObject>::iterator itavlinttestobject_hi,itavlinttestobject_low;
	std::map<double, std::string> mapdoublestring;
	std::map<double, std::string>::iterator itmapdoublestring_hi, itmapdoublestring_low;
	avltree<double, std::string> avldoublestring;
	avltree<double, std::string>::iterator  itavldoublestring_hi, itavldoublestring_low;
	std::map<int,std::map<int,int>>mapintmapintint;
	std::map<int,std::map<int,int>>::iterator itmapintmapintint_hi, itmapintmapintint_low;
	avltree<int,avltree<int,int>>avlintavlintint;
	avltree<int,avltree<int,int>>::iterator itavlintavlinint_hi, itavlintavlintint_low;

	mapcharint.insert (std::pair<char,int>('a',100));
	avlcharint.insert (std::pair<char,int>('a',100));
	itmapcharint_low = mapcharint.lower_bound('a');
	itavlcharint_low = avlcharint.lower_bound('a');
	mapinttestobject.insert (std::pair<int,KaylaTestObject>(1,TestObject));
	avlinttestobject.insert (std::pair<int,KaylaTestObject>(1,TestObject));
	itmapinttestobject_low = mapinttestobject.lower_bound(1);
	itavlinttestobject_low = avlinttestobject.lower_bound(1);
	mapdoublestring.insert (std::pair<double,std::string>(1.0,"Clay"));
	avldoublestring.insert (std::pair<double,std::string>(1.0,"Clay"));
	itmapdoublestring_low = mapdoublestring.lower_bound(1.0);
	itavldoublestring_low = avldoublestring.lower_bound(1.0);
	mapintmapintint.insert (std::pair<int,std::map<int,int>>(1,mapintint));
	avlintavlintint.insert (std::pair<int,avltree<int,int>>(1,avlintint));
	itmapintmapintint_low = mapintmapintint.lower_bound(1);
	itavlintavlintint_low = avlintavlintint.lower_bound(1);
		
	
	char charToTest = 'a';
	BOOST_CHECK_EQUAL(itmapcharint_low->first == charToTest, true);
	BOOST_CHECK_EQUAL(itavlcharint_low->first == charToTest, true );
	BOOST_CHECK_EQUAL(itmapcharint_low->second == 100, true);
	BOOST_CHECK_EQUAL(itavlcharint_low->second == 100, true);

	
	BOOST_CHECK_EQUAL(itmapinttestobject_low->first, 1);
	BOOST_CHECK_EQUAL(itavlinttestobject_low->first == 1, true);

	BOOST_CHECK_EQUAL(itmapdoublestring_low->first, 1.0);
	BOOST_CHECK_EQUAL(itavldoublestring_low->first == 1.0, true);
	
	BOOST_CHECK_EQUAL(itmapintmapintint_low->first, 1);
	BOOST_CHECK_EQUAL(itavlintavlintint_low->first ==  1, true);

	
	mapcharint.insert (std::pair<char,int>('b',101));
	avlcharint.insert (std::pair<char,int>('b',101));
	itmapcharint_low = mapcharint.lower_bound('b');
	itavlcharint_low = avlcharint.lower_bound('b');
	mapinttestobject.insert (std::pair<int,KaylaTestObject>(2,TestObject));
	avlinttestobject.insert (std::pair<int,KaylaTestObject>(2,TestObject));
	itmapinttestobject_low = mapinttestobject.lower_bound(2);
	itavlinttestobject_low = avlinttestobject.lower_bound(2);
	mapdoublestring.insert (std::pair<double,std::string>(2.0,"Kayla"));
	avldoublestring.insert (std::pair<double,std::string>(2.0,"Kayla"));
	itmapdoublestring_low = mapdoublestring.lower_bound(2.0);
	itavldoublestring_low = avldoublestring.lower_bound(2.0);
	mapintmapintint.insert (std::pair<int,std::map<int,int>>(2,mapintint));
	avlintavlintint.insert (std::pair<int,avltree<int,int>>(2,avlintint));
	itmapintmapintint_low = mapintmapintint.lower_bound(2);
	itavlintavlintint_low = avlintavlintint.lower_bound(2);

	BOOST_CHECK_EQUAL(itmapcharint_low->first == 'b', true);
	BOOST_CHECK_EQUAL(itavlcharint_low->first == 'b', true);
	
	BOOST_CHECK_EQUAL(itmapinttestobject_low->first == 2, true);
	BOOST_CHECK_EQUAL(itavlinttestobject_low->first == 2, true);

	BOOST_CHECK_EQUAL(itmapdoublestring_low->first == 2.0, true);
	BOOST_CHECK_EQUAL(itavldoublestring_low->first ==  2.0, true);
	
	BOOST_CHECK_EQUAL(itmapintmapintint_low->first == 2, true);
	BOOST_CHECK_EQUAL(itavlintavlintint_low->first == 2, true);

	
	for(unsigned int i = 0; i <= 99; ++i)
	{
		mapcharint.insert(std::pair<char,int>('a'+i, i));
		avlcharint.insert(std::pair<char,int>('a'+i, i));
	}
	itmapcharint_low = mapcharint.lower_bound('e');
	itavlcharint_low = avlcharint.lower_bound('e');
	
	BOOST_CHECK_EQUAL(itmapcharint_low->first == 'e', true);
	BOOST_CHECK_EQUAL(itavlcharint_low->first ==  'e', true);

	for(unsigned int i = 0; i <= 99; ++i)
	{
		mapinttestobject.insert(std::pair<int,KaylaTestObject>(1+i, TestObject));
		avlinttestobject.insert(std::pair<int,KaylaTestObject>(1+i, TestObject));
	}
	itmapinttestobject_low = mapinttestobject.lower_bound(5);
	itavlinttestobject_low = avlinttestobject.lower_bound(5);

	BOOST_CHECK_EQUAL(itmapinttestobject_low->first == 5, true);
	BOOST_CHECK_EQUAL(itavlinttestobject_low->first == 5, true);
	
}



/**	const_iterator lower_bound( Key const& ) const */
BOOST_AUTO_TEST_CASE( ut_lower_bound_key_const ) {
	//std::cout << "NOT IMPLEMENTED: avltree<T>::lower_bound(Key) const\n";

	KaylaTestObject TestObject;
	
	std::map<char, int> mapcharint;
	std::map<char,int>::iterator itmapcharint_hi,itmapcharint_low;
	avltree<char, int> avlcharint;
	avltree<char, int>::iterator itavlcharint_hi,itavlcharint_low;
	std::map<int, int> mapintint;
	std::map<int,int>::iterator itmapintint_hi,itmapintint_low;
	avltree<int, int> avlintint;
	avltree<int, int>::iterator itavlintint_hi,itavlintint_low;
	std::map<int, KaylaTestObject> mapinttestobject;
	std::map<int, KaylaTestObject>::iterator itmapinttestobject_hi,itmapinttestobject_low;
	avltree<int, KaylaTestObject>avlinttestobject;
	avltree< int, KaylaTestObject>::iterator itavlinttestobject_hi,itavlinttestobject_low;
	std::map< double, std::string> mapdoublestring;
	std::map< double, std::string>::iterator itmapdoublestring_hi, itmapdoublestring_low;
	avltree< double, std::string> avldoublestring;
	avltree< double, std::string>::iterator  itavldoublestring_hi, itavldoublestring_low;
	std::map< int,std::map<int,int>>mapintmapintint;
	std::map<int,std::map<int,int>>::iterator itmapintmapintint_hi, itmapintmapintint_low;
	avltree<int,avltree<int,int>>avlintavlintint;
	avltree<int,avltree<int,int>>::iterator itavlintavlinint_hi, itavlintavlintint_low;

	mapcharint.insert (std::pair<char,int>('a',100));
	avlcharint.insert (std::pair<char,int>('a',100));
	const char& firstchar = 'a';
	const char& secondchar = 'b';
	itmapcharint_low = mapcharint.lower_bound(firstchar);
	itavlcharint_low = avlcharint.lower_bound(firstchar);
	
	mapinttestobject.insert (std::pair<int,KaylaTestObject>(1,TestObject));
	avlinttestobject.insert (std::pair<int,KaylaTestObject>(1,TestObject));
	const int& firstint = 1;
	const int& secondint = 2;
	itmapinttestobject_low = mapinttestobject.lower_bound(firstint);
	itavlinttestobject_low = avlinttestobject.lower_bound(firstint);

	mapdoublestring.insert (std::pair<double,std::string>(1.0,"Clay"));
	avldoublestring.insert (std::pair<double,std::string>(1.0,"Clay"));
	const double& firstdouble = 1.0;
	const double& seconddouble = 2.0;
	itmapdoublestring_low = mapdoublestring.lower_bound(firstdouble);
	itavldoublestring_low = avldoublestring.lower_bound(firstdouble);

	mapintint.insert(std::pair<int, int>(1,1));
	avlintint.insert(std::pair<int, int>(1,1));
	itmapintint_low = mapintint.lower_bound(firstint);	
	itavlintint_low = avlintint.lower_bound(firstint);
	
		
	BOOST_CHECK_EQUAL(itmapcharint_low->first == 'a', true);
	BOOST_CHECK_EQUAL(itavlcharint_low->first == 'a', true);

	BOOST_CHECK_EQUAL(itmapinttestobject_low->first == 1, true);
	BOOST_CHECK_EQUAL(itavlinttestobject_low->first == 1, true);

	BOOST_CHECK_EQUAL(itmapdoublestring_low->first == 1.0, true);
	BOOST_CHECK_EQUAL(itavldoublestring_low->first == 1.0, true);
	
	mapcharint.insert (std::pair<const char,int>('b',101));
	avlcharint.insert (std::pair<const char,int>('b',101));

	itmapcharint_low = mapcharint.lower_bound(secondchar);
	itavlcharint_low = avlcharint.lower_bound(secondchar);

	mapinttestobject.insert (std::pair<const int,KaylaTestObject>(2,TestObject));
	avlinttestobject.insert (std::pair<const int,KaylaTestObject>(2,TestObject));

	itmapinttestobject_low = mapinttestobject.lower_bound(secondint);
	itavlinttestobject_low = avlinttestobject.lower_bound(secondint);

	mapdoublestring.insert (std::pair<const double,std::string>(2.0,"Clayton"));
	avldoublestring.insert (std::pair<const double,std::string>(2.0,"Clayton"));

	itmapdoublestring_low = mapdoublestring.lower_bound(seconddouble);
	itavldoublestring_low = avldoublestring.lower_bound(seconddouble);
	
	BOOST_CHECK_EQUAL(itmapcharint_low->first == 'b', true);
	BOOST_CHECK_EQUAL(itavlcharint_low->first == 'b', true);
	
	BOOST_CHECK_EQUAL(itmapinttestobject_low->first == 2, true);
	BOOST_CHECK_EQUAL(itavlinttestobject_low->first == 2, true);

	BOOST_CHECK_EQUAL(itmapdoublestring_low->first ==  2.0, true);
	BOOST_CHECK_EQUAL(itavldoublestring_low->first == 2.0, true);

}



/**	iterator upper_bound( Key const& ) */
BOOST_AUTO_TEST_CASE( ut_upper_bound_key ) {
	//std::cout << "NOT IMPLEMENTED: avltree<T>::upper_bound(Key) const\n";

	KaylaTestObject TestObject;
	
	std::map<char, int> mapcharint;
	std::map<char,int>::iterator itmapcharint_hi,itmapcharint_low;
	avltree<char, int> avlcharint;
	avltree<char, int>::iterator itavlcharint_hi,itavlcharint_low;
	std::map<int, int> mapintint;
	std::map<int,int>::iterator itmapintint_hi,itmapintint_low;
	avltree<int, int> avlintint;
	avltree<int, int>::iterator itavlintint_hi,itavlintint_low;
	std::map<int, KaylaTestObject> mapinttestobject;
	std::map<int, KaylaTestObject>::iterator itmapinttestobject_hi,itmapinttestobject_low;
	avltree<int, KaylaTestObject>avlinttestobject;
	avltree<int, KaylaTestObject>::iterator itavlinttestobject_hi,itavlinttestobject_low;
	std::map<double, std::string> mapdoublestring;
	std::map<double, std::string>::iterator itmapdoublestring_hi, itmapdoublestring_low;
	avltree<double, std::string> avldoublestring;
	avltree<double, std::string>::iterator  itavldoublestring_hi, itavldoublestring_low;
	std::map<int,std::map<int,int>>mapintmapintint;
	std::map<int,std::map<int,int>>::iterator itmapintmapintint_hi, itmapintmapintint_low;
	avltree<int,avltree<int,int>>avlintavlintint;
	avltree<int,avltree<int,int>>::iterator itavlintavlintint_hi, itavlintavlintint_low;

	mapcharint.insert (std::pair<char,int>('a',100));
	avlcharint.insert (std::pair<char,int>('a',100));
	mapcharint.insert (std::pair<char,int>('b',100));
	avlcharint.insert (std::pair<char,int>('b',100));
	itmapcharint_hi = mapcharint.upper_bound('a');
	itavlcharint_hi = avlcharint.upper_bound('a');
	
	mapinttestobject.insert (std::pair<int,KaylaTestObject>(1,TestObject));
	avlinttestobject.insert (std::pair<int,KaylaTestObject>(1,TestObject));
	mapinttestobject.insert (std::pair<int,KaylaTestObject>(2,TestObject));
	avlinttestobject.insert (std::pair<int,KaylaTestObject>(2,TestObject));
	itmapinttestobject_hi = mapinttestobject.upper_bound(1);
	itavlinttestobject_hi = avlinttestobject.upper_bound(1);
	
	mapdoublestring.insert (std::pair<double,std::string>(1.0,"Clay"));
	avldoublestring.insert (std::pair<double,std::string>(1.0,"Clay"));
	mapdoublestring.insert (std::pair<double,std::string>(2.0,"Clay"));
	avldoublestring.insert (std::pair<double,std::string>(2.0,"Clay"));
	itmapdoublestring_hi = mapdoublestring.upper_bound(1.0);
	itavldoublestring_hi = avldoublestring.upper_bound(1.0);

	mapintmapintint.insert (std::pair<int,std::map<int,int>>(1,mapintint));
	avlintavlintint.insert (std::pair<int,avltree<int,int>>(1,avlintint));
	mapintmapintint.insert (std::pair<int,std::map<int,int>>(2,mapintint));
	avlintavlintint.insert (std::pair<int,avltree<int,int>>(2,avlintint));
	itmapintmapintint_hi = mapintmapintint.upper_bound(1);
	itavlintavlintint_hi = avlintavlintint.upper_bound(1);

	BOOST_CHECK_EQUAL(itmapcharint_hi->first == 'b', true);
	BOOST_CHECK_EQUAL(itavlcharint_hi->first =='b', true);
	BOOST_CHECK_EQUAL(itmapcharint_hi->first == itavlcharint_hi->first, true);

	BOOST_CHECK_EQUAL(itmapinttestobject_hi->first == 2, true);
	BOOST_CHECK_EQUAL(itavlinttestobject_hi->first == 2, true);
	BOOST_CHECK_EQUAL(itmapinttestobject_hi->first == itavlinttestobject_hi->first, true);

	BOOST_CHECK_EQUAL(itmapdoublestring_hi->first == 2.0, true);
	BOOST_CHECK_EQUAL(itavldoublestring_hi->first == 2.0, true);
	BOOST_CHECK_EQUAL(itmapdoublestring_hi->first == itavldoublestring_hi->first, true);

	BOOST_CHECK_EQUAL(itmapintmapintint_hi->first == 2, true);
	BOOST_CHECK_EQUAL(itavlintavlintint_hi->first == 2, true);
	BOOST_CHECK_EQUAL(itmapintmapintint_hi->first == itavlintavlintint_hi->first, true);


}



/**	const_iterator upper_bound( Key const& ) const */
BOOST_AUTO_TEST_CASE( ut_upper_bound_key_const ) {
	//std::cout << "NOT IMPLEMENTED: avltree<T>::upper_bound(Key) const\n";

	KaylaTestObject TestObject;

	std::map<char, int> mapcharint;
	std::map< char,int>::iterator itmapcharint_hi,itmapcharint_low;
	avltree< char, int> avlcharint;
	avltree< char, int>::iterator itavlcharint_hi,itavlcharint_low;
	std::map< int, int> mapintint;
	std::map< int,int>::iterator itmapintint_hi,itmapintint_low;
	avltree< int, int> avlintint;
	avltree< int, int>::iterator itavlintint_hi,itavlintint_low;
	std::map< int, KaylaTestObject> mapinttestobject;
	std::map< int, KaylaTestObject>::iterator itmapinttestobject_hi,itmapinttestobject_low;
	avltree< int, KaylaTestObject>avlinttestobject;
	avltree< int, KaylaTestObject>::iterator itavlinttestobject_hi,itavlinttestobject_low;
	std::map< double, std::string> mapdoublestring;
	std::map< double, std::string>::iterator itmapdoublestring_hi, itmapdoublestring_low;
	avltree< double, std::string> avldoublestring;
	avltree< double, std::string>::iterator  itavldoublestring_hi, itavldoublestring_low;
	std::map< int,std::map<int,int>>mapintmapintint;
	std::map< int,std::map<int,int>>::iterator itmapintmapintint_hi, itmapintmapintint_low;
	avltree< int,avltree<int,int>>avlintavlintint;
	avltree< int,avltree<int,int>>::iterator itavlintavlintint_hi, itavlintavlintint_low;

	const char& firstchar = 'a';
	const int& firstint = 1;
	const double& firstdouble = 1.0;


	mapcharint.insert (std::pair< char,int>('a',100));
	avlcharint.insert (std::pair< char,int>('a',100));
	mapinttestobject.insert (std::pair< int,KaylaTestObject>(1,TestObject));
	avlinttestobject.insert (std::pair< int,KaylaTestObject>(1,TestObject));
	mapdoublestring.insert (std::pair< double,std::string>(1.0,"Clay"));
	avldoublestring.insert (std::pair< double,std::string>(1.0,"Clay"));
	mapintint.insert(std::pair< int, int>(1,1));
	avlintint.insert(std::pair<int, int>(1,1));
	
	mapcharint.insert (std::pair< char,int>('b',101));
	avlcharint.insert (std::pair< char,int>('b',101));
	mapinttestobject.insert (std::pair< int,KaylaTestObject>(2,TestObject));
	avlinttestobject.insert (std::pair< int,KaylaTestObject>(2,TestObject));
	mapdoublestring.insert (std::pair< double,std::string>(2.0,"Clayton"));
	avldoublestring.insert (std::pair< double,std::string>(2.0,"Clayton"));
	mapintint.insert(std::pair< int, int>(2,1));
	avlintint.insert(std::pair< int, int>(2,1));

	itmapcharint_hi = mapcharint.upper_bound(firstchar);
	itavlcharint_hi = avlcharint.upper_bound(firstchar);
	
	
	itmapinttestobject_hi = mapinttestobject.upper_bound(firstint);
	itavlinttestobject_hi = avlinttestobject.upper_bound(firstint);

	
	itmapdoublestring_hi = mapdoublestring.upper_bound(firstdouble);
	itavldoublestring_hi = avldoublestring.upper_bound(firstdouble);

	
	itmapintint_hi = mapintint.upper_bound(firstint);	
	itavlintint_hi = avlintint.upper_bound(firstint);
	
		
	BOOST_CHECK_EQUAL(itmapcharint_hi->first == 'b', true);
	BOOST_CHECK_EQUAL(itavlcharint_hi->first ==  'b', true);
	BOOST_CHECK_EQUAL(itmapcharint_hi->second == 101, true);
	BOOST_CHECK_EQUAL(itavlcharint_hi->second == 101, true);
	BOOST_CHECK_EQUAL(itmapdoublestring_hi->first == 2.0, true);
	BOOST_CHECK_EQUAL(itavldoublestring_hi->first == 2.0, true);
	BOOST_CHECK_EQUAL(itmapinttestobject_hi->first == 2, true);
	BOOST_CHECK_EQUAL(itavlinttestobject_hi->first == 2, true);
	
	
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