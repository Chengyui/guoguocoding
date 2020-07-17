#include "ProjectNeeded.h"

using namespace std;

/*void Guidance::Welcome()
{
	cout << "Welcome to the address book!" << endl;
	while (1)
	{
		cout << "Enter your PIN(6 bits) please:";
		if (Password())
		{
			cout << endl;
			cout << "Right Answer,welcome!" << endl;
			break;
		}
		cout << "Wrong input.Try again!" << endl;

	}
	Sleep(1000);
	system("cls");
}*/
int mycmp(char* a, char* b) {
	int flag = 1;
	int i;
	for (i = 0; a[i] != '\0'; i++) {
		if (a[i] != b[i]) {
			flag = 0;
			break;
		}
	}
	if (flag == 1 && b[i] == '\0') {
		return 1;
	}
	return 0;
}
void Guidance::Password()
{
	ifstream _file("data.txt");
	cout << "welcome to address book system!" << endl;

	if (!_file)
	{
		cout << "Password not created." << endl;
		Change_Password();
		cout << "succeed in creating,Please log in with password." << endl << endl;
	}
	log_in();
}

void Guidance::Change_Password()
{
	cout << "Now,start creating a new password." << endl;

	ofstream out("data.txt", ios_base::out);
	char Cpass[100];
	cin >> Cpass;
	out << Cpass;
	out.close();
}

void Guidance::log_in()
{
	ifstream _file("data.txt");
	cout << "please input the PIN" << endl;
	char sYourInput[100];
	char sPassword[100];
	int timeLimit = 3;
	_file >> sPassword;
	_file.close();
	while (1)
	{
		char ch = _getch();
		int i;
		for (i = 0; ch != '\r'; i++)
		{
			sYourInput[i] = ch;
			cout << "*";
			ch = _getch();
		}
		sYourInput[i] = '\0';
		cout << endl;

		if (mycmp(sYourInput, sPassword) == 1)
		{
			cout << "Welcome to the system!" << endl;
			break;
		}
		else if (timeLimit != 0)
		{
			cout << "There are " << timeLimit << " chances left." << endl;
			timeLimit--;
		}
		else
		{
			cout << "Chances ran out,quiting system." << endl;
			exit(1);
		}
	}
}
void Guidance::Menu(AddressBook* MyAddressBook, int* AddressTop)
{

	cout << "Following prompts, enter the corresponding number to select the operation you need." << endl;
	int iChoice = 1;
	while (iChoice != 0) {
		cout << endl;
		cout << "Welcome to the address book!©d(¨R¨Œ¨Q*)o" << endl;
		cout << "0.quit." << endl;
		cout << "1.Add contact information." << endl;
		cout << "2.Modify contact information." << endl;
		cout << "3.Check the address book list." << endl;
		cout << "4.Delete contact information." << endl;
		std::cout << "5.Phone call from others." << std::endl;
		std::cout << "6.Email from others." << std::endl;
		std::cout << "7.Add new blacklist phone number." << std::endl;
		std::cout << "8.Add new blacklist email address." << std::endl;
		std::cout << "9.Delete blacklist phone number or email address." << std::endl;
		cout << "Please enter your choice:" << endl;
		cin >> iChoice;
		switch (iChoice) {
		case 1:Guidance::AddInfo(MyAddressBook, AddressTop); break;
		case 2:Guidance::ModifyInfo(MyAddressBook, *AddressTop); break;
		case 3:Guidance::CheckAddressBookList(MyAddressBook, *AddressTop); break;
		case 4:Guidance::DeleteInfo(MyAddressBook, *AddressTop); break;
		case 5:BlackList::ResistNum(); break;
		case 6:BlackList::ResistEmail(); break;
		case 7:BlackList::AddBlackNum(); break;
		case 8:BlackList::AddBlackEmail(); break;
		case 9:BlackList::DeleteBlackInfo(); break;
		}
	}
}

void Guidance::AddInfo(AddressBook* MyAddressBook, int* AddressTop)
{
	cout << endl;
	cout << "Please input infomation as below format:" << endl;
	cout << "At first input the name" << endl;
	//cout << "JohnSmith SCU 12312341234 2020/07/14 123123123@163.com 2020/01/01/08:01:01 2020/01/01/08:01:02 2020/01/01/08:01:02" << endl;
	cout << "If what to quit this function, please input 0." << endl;
	while (true) {
		cin >> MyAddressBook[*AddressTop].sName;
		if (MyAddressBook[*AddressTop].sName[0] == '0') {
			break;
		}
		cout << "please enter the workunit:" << endl;
		cin >> MyAddressBook[*AddressTop].sWorkUnit;
		cout << "please enter the number:" << endl;
		cin >> MyAddressBook[*AddressTop].sPhoneNumber;
		cout << "please enter the birthay:" << endl;
		cin >> MyAddressBook[*AddressTop].sBirthday;
		cout << "please enter the mail:" << endl;
		cin >> MyAddressBook[*AddressTop].sE_mailAddress;
		cout << "please enter the num1 call:" << endl;
		cin >> MyAddressBook[*AddressTop].sCallLog1;
		cout << "please enter the num2 call:" << endl;
		cin >> MyAddressBook[*AddressTop].sCallLog2;
		cout << "please enter the num3 call:" << endl;
		cin >> MyAddressBook[*AddressTop].sCallLog3;
		MyAddressBook[*AddressTop].flag = 1;
		(*AddressTop)++;
		cout << "ok,i get it!" << endl;
		Sleep(1000);
		system("cls");
		break;


	}
}
void Guidance::ModifyInfo(AddressBook* MyAddressBook, int AddressTop)
{
	while (true) {
		cout << endl;
		cout << "Please input the name of the information you want to change." << endl;
		cout << "If what to quit this function, please input 0." << endl;
		char name[20];
		cin >> name;
		if (name[0] == '0') {
			break;
		}
		int flag = 0;
		for (int i = 0; i < AddressTop; i++) {
			if (strcmp(MyAddressBook[i].sName, name) == 0 && MyAddressBook[i].flag == 1) {
				cout << "We have found the name, please input new information." << endl;
				cout << "please enter the new workunit:" << endl;
				cin >> MyAddressBook[i].sWorkUnit;
				cout << "please enter the new number:" << endl;
				cin >> MyAddressBook[i].sPhoneNumber;
				cout << "please enter the new birthday:" << endl;
				cin >> MyAddressBook[i].sBirthday;
				cout << "please enter the new mail:" << endl;
				cin >> MyAddressBook[i].sE_mailAddress;
				flag = 1;
				cout << "ok,i finish!" << endl;
				Sleep(1000);
				system("cls");

			}
		}break;


		if (flag == 0) {
			cout << "Do not find the name." << endl;
			Sleep(1000);
			system("cls");
			break;
		}
	}
}
void Guidance::CheckAddressBookList(AddressBook* MyAddressBook, int AddressTop)
{
	while (true) {
		cout << endl;
		cout << "Please input the name of the information you want to check." << endl;
		cout << "If what to quit this function, please input 0." << endl;
		char name[20];
		cin >> name;
		if (name[0] == '0') {
			break;
		}
		int flag = 0;
		for (int i = 0; i < AddressTop; i++) {
			if (strcmp(MyAddressBook[i].sName, name) == 0 && MyAddressBook[i].flag == 1) {
				cout << "We have found the name, below is its information." << endl;
				cout << "Name: " << MyAddressBook[i].sName << endl;
				cout << "WorkUnit: " << MyAddressBook[i].sWorkUnit << endl;
				cout << "PhoneNumber: " << MyAddressBook[i].sPhoneNumber << endl;
				cout << "Birthday: " << MyAddressBook[i].sBirthday << endl;
				cout << "E_mailAddress: " << MyAddressBook[i].sE_mailAddress << endl;
				cout << "sCallLog1: " << MyAddressBook[i].sCallLog1 << endl;
				cout << "sCallLog2: " << MyAddressBook[i].sCallLog2 << endl;
				cout << "sCallLog3: " << MyAddressBook[i].sCallLog3 << endl;
				flag = 1;
			}

		}
		if (flag == 0) {
			cout << "Do not find the name." << endl;
			Sleep(1000);
			system("cls");
			break;
		}
		cout << "do you want to back to the menu?you can take any key to back!" << endl;
		getchar();
		getchar();
		system("cls");
		break;



	}

}



void Guidance::DeleteInfo(AddressBook* MyAddressBook, int AddressTop)
{
	while (true) {
		cout << endl;
		cout << "Please input the name of the information you want to delete." << endl;
		cout << "If what to quit this function, please input 0." << endl;
		char name[20];
		cin >> name;
		if (name[0] == '0') {
			Sleep(1000);
			system("cls");
			break;
		}
		int flag = 0;
		for (int i = 0; i < AddressTop; i++) {
			if (strcmp(MyAddressBook[i].sName, name) == 0 && MyAddressBook[i].flag == 1) {
				cout << "We have found the name, and deleted its information." << endl;
				MyAddressBook[i].flag = 0;
				flag = 1;
				Sleep(1000);
				system("cls");

			}

		}break;

		if (flag == 0) {
			cout << "Do not find the name." << endl;
			Sleep(1000);
			system("cls");
			break;
		}
	}
}

