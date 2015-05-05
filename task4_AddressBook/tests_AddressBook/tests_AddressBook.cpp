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

BOOST_AUTO_TEST_CASE(CanSetAndReturnPatronymic)
{
	CAbonnent abonnent;
	BOOST_CHECK_EQUAL(abonnent.GetPatronymic(), "");
	abonnent.SetPatronymic("Fox");
	BOOST_CHECK_EQUAL(abonnent.GetPatronymic(), "Fox");
}

BOOST_AUTO_TEST_CASE(CanSetAndReturnCity)
{
	CAbonnent abonnent;
	BOOST_CHECK_EQUAL(abonnent.GetCity(), "");
	abonnent.SetCity("San Francisco");
	BOOST_CHECK_EQUAL(abonnent.GetCity(), "San Francisco");
}

BOOST_AUTO_TEST_CASE(CanSetAndReturnStreet)
{
	CAbonnent abonnent;
	BOOST_CHECK_EQUAL(abonnent.GetStreet(), "");
	abonnent.SetStreet("Julie");
	BOOST_CHECK_EQUAL(abonnent.GetStreet(), "Julie");
}

BOOST_AUTO_TEST_CASE(CanSetAndReturnHouse)
{
	CAbonnent abonnent;
	BOOST_CHECK_EQUAL(abonnent.GetHouse(), "");
	abonnent.SetHouse("11A");
	BOOST_CHECK_EQUAL(abonnent.GetHouse(), "11A");
}

BOOST_AUTO_TEST_CASE(CanSetAndReturnApartament)
{
	CAbonnent abonnent;
	BOOST_CHECK_EQUAL(abonnent.GetApartament(), 0);
	abonnent.SetApartament(11);
	BOOST_CHECK_EQUAL(abonnent.GetApartament(), 11);
	abonnent.SetApartament(-11);
	BOOST_CHECK_EQUAL(abonnent.GetApartament(), 11);
}

BOOST_AUTO_TEST_CASE(CanSetAndReturnNumber)
{
	CAbonnent abonnent;
	vector<string> numbers;
	vector<string> phoneNumbers;
	
	{
		phoneNumbers = abonnent.GetPhoneNumbers();

		for (size_t i = 0; i != numbers.size(); ++i)
		{
			BOOST_CHECK_EQUAL(phoneNumbers[i], numbers[i]);
		}
	}
	
	{
		numbers.push_back("121212");
		BOOST_CHECK(abonnent.AddPhoneNumber("121212"));
		phoneNumbers = abonnent.GetPhoneNumbers();

		for (size_t i = 0; i != numbers.size(); ++i)
		{
			BOOST_CHECK_EQUAL(phoneNumbers[i], numbers[i]);
		}
	}

	{
		BOOST_CHECK(!abonnent.AddPhoneNumber("-121212"));
		phoneNumbers = abonnent.GetPhoneNumbers();

		for (size_t i = 0; i != numbers.size(); ++i)
		{
			BOOST_CHECK_EQUAL(phoneNumbers[i], numbers[i]);
		}
	}
}




