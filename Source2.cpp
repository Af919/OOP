#include <iostream>
#include <string>
using namespace std;

enum Gender
{
	male,
	female,
	unknown
};
class Person
{
private:
	string name;
	Gender sex;
	int age;
	string EGN;
public:
	void SetName(string tname)
	{
		name = tname;
	}

	string GetName()
	{
		return name;
	}
	void SetSex(Gender tsex)
	{
		sex = tsex;

	}

	Gender GetSex()
	{
		return sex;
	}

	void SetAge(int tage)
	{
		age = tage;

	}

	int GetAge()
	{
		return age;
	}
	void SetEGN(string tEGN)
	{
		EGN = tEGN;
	}
	string GetEGN()
	{
		return EGN;
	}
	Person()
	{
		name = "N/A";
		sex = Gender::unknown;
		age = 19;
		EGN ="N/A";

	}
	Person(string tname, Gender tsex, int tage, string tEGN)
	{
		name = tname;
		sex = tsex;
		age = tage;
		EGN = tEGN;
	}
	bool isValid(const string strEGN);
};


bool Person::isValid(const string strEGN)
{
	bool bRes = true;
	//proverka na duljina
	if (strEGN.length() == 10)
	{
		bRes = true;
		bool b2000 = false;
		bool b1800 = false;
		//proverka na data na rajdane
		//proverka na meseca
		int iMonth = atoi(strEGN.substr(2, 2).data());
		if (iMonth > 12)
		{
			iMonth -= 40;
			if (iMonth < 20)
			{
				iMonth += 20;
				b1800 = true;
			}
			else
				b2000=true;
		}
		if (iMonth < 1 || iMonth>12)
			bRes = false;
		//proverka na denq
		int iDay = atoi(strEGN.substr(4, 2).data());
		if (iDay < 1 || iDay>31)
			bRes;
		//proverka na godina
		int iYear = atoi(strEGN.substr(0, 2).data());
		if (b2000)
			iYear += 2000;
		else
			if (b1800)
				iYear += 1800;
			else
				iYear += 1800;
		//proverka na pola
		string strBirtOrder = strEGN.substr(6, 3);
		int iSequenceNum = atoi(strBirtOrder.data());
		int iSexCode;
		if (iSequenceNum % 2)iSexCode = female;
		else iSexCode = male;
		if (iSexCode != sex)
			bRes = false;
		//moje da se dobavi proverka na datata za validnost
		//proverka na kontrolna tsifra
		int iSum = atoi(strEGN.substr(0, 1).data()) * 2 +
			atoi(strEGN.substr(1, 1).data()) * 4 +
			atoi(strEGN.substr(2, 1).data()) * 8 +
			atoi(strEGN.substr(3, 1).data()) * 5 +
			atoi(strEGN.substr(4, 1).data()) * 10 +
			atoi(strEGN.substr(5, 1).data()) * 9 +
			atoi(strEGN.substr(6, 1).data()) * 7 +
			atoi(strEGN.substr(7, 1).data()) * 3 +
			atoi(strEGN.substr(8, 1).data()) * 6;
		int iCheck = atoi(strEGN.substr(9, 1).data());
		int iTest = iSum % 11;
		if (iTest == 10)iTest = 0;
		if (iTest = iCheck) bRes = true;
		else bRes = false;
	}
	return bRes;
}

int main()
{

	Person p1, p2, p3;
	/*p1.name = "Ivan";
	p1.sex = "Male";
	p1.age = 69;
	p2.name = "Pesho";
	p2.sex = "Male";
	p2.age = 49;*/
	//p3.SetName("Toshko");
	//p3.sex = "Male";
	//p3.age = (59);

	Person p4("Bobi ", Gender::male, 16," 0357231025"); // експлицитен конструктор (explit)
	Person grupa1[30];  /*{ Person("Ivan", "man","20"),
		Person("Pesho", "man","59"),
	Person("Toshko", "man","19"),
		p1
	}*/
	//cout << p1.name << " " << p1.sex << " " << p1.age << endl;
	//cout << p2.name << " " << p2.sex << " " << p2.age << endl;
	//cout << p3.name << " " << p3.sex << " " << p3.age << endl;

	cout << p1.GetName() << " " << p1.GetSex() << " " << p1.GetAge() << p1.GetEGN() << endl;
	cout << p2.GetName() << " " << p2.GetSex() << " " << p2.GetAge() << p2.GetEGN() << endl;
	cout << p3.GetName() << " " << p3.GetSex() << " " << p3.GetAge() << p3.GetEGN() << endl;
	cout << p4.GetName() << " " << p4.GetSex() << " " << p4.GetAge() << p4.GetEGN() << endl;
	system("pause");

}

