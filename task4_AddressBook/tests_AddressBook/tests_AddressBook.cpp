// tests_AddressBook.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../task4_AddressBook/Abonnent.h"

BOOST_AUTO_TEST_CASE(CanSetAndReturnName)
{
	CAbonnent abonnent;
	BOOST_CHECK_EQUAL(abonnent.GetName(), "");
	abonnent.SetName("Max");
	BOOST_CHECK_EQUAL(abonnent.GetName(), "Max");
}

BOOST_AUTO_TEST_CASE(CanSetAndReturnSurname)
{
	CAbonnent abonnent;
	BOOST_CHECK_EQUAL(abonnent.GetSurname(), "");
	abonnent.SetName("Fall");
	BOOST_CHECK_EQUAL(abonnent.GetName(), "Fall");
}
