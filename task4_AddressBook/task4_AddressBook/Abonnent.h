#pragma once
#include <string>
#include <vector>

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
		vector<string> const &phoneNumbers,
		vector<string> const &mailAdresses);
	
	~CAbonnent();

	void SetName(string const &name);
	void SetSurname(string const &surname);
	void SetPatronymic(string const &patronymic);
	void SetCity(string const &city);
	void SetStreet(string const &street);
	void SetHouse(string const &house);
	void SetApartament(const int apartament);
	bool AddPhoneNumber(string const &newPhoneNumber);
	bool AddMailAddress(string const &newMailAddress);

	string GetName();
	string GetSurname();
	string GetPatronymic();
	string GetCity();
	string GetStreet();
	string GetHouse();
	int GetApartament();
	vector<string> GetPhoneNumbers();
	vector<string> GetMailAddresses();


private:
	string m_name;
	string m_surname;
	string m_patronymic;

	string m_city;
	string m_street;
	string m_house;
	int m_apartament;

	vector<string> m_phoneNumbers;
	vector<string> m_mailAddresses;
};

