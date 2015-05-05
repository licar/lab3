#pragma once
#include <string>
#include <list>

using namespace std;

class CAbonnent
{
public:
	CAbonnent();

	CAbonnent(string const &name,
		string const &surname,
		string const &patronymic,
		string const &city,
		string const &house,
		unsigned apartament,
		list<string> const &phoneNumbers,
		list<string> const &mailAdresses);
	
	~CAbonnent();

	void SetName(string const &name);
	void SetSurname(string const &surname);
	void SetPatronymic(string const &patronymic);
	void SetCity(string const &city);
	void SetStreet(string const &street);
	void SetHouse(string const &house);
	void SetApartament(const unsigned apartament);
	void AddPhoneNumber(string const &number);
	void SetPhoneNumbers(list<string> const &numbers);
	void AddMailAdress(string const &number);
	void SetMailAdresses(list <string> const &numbers);

	string GetName();
	string GetSurname();
	string GetPatronymic();
	string GetCity();
	string GetStreet();
	string GetHouse();
	unsigned GetApartament();
	list <string> GetPhoneNumbers();
	list <string> GetMailAdresses();


private:
	string m_name;
	string m_surname;
	string m_patronymic;

	string m_city;
	string m_street;
	string m_house;
	unsigned m_apartament;

	list<string> m_phoneNumbers;
	list<string> m_mailAddresses;

};

