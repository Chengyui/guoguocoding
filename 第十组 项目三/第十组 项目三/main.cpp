#include "ProjectNeeded.h"
using namespace std;
void get_data(int* AddressTop);
void save_data(int AddressTop);
AddressBook MyAddressBook[100];//通讯录上限为100人




int main(int argc, char* argv[])
{
	int AddressTop = 0;
	get_data(&AddressTop);
	//Guidance::Welcome();
	Guidance::Password();
	Guidance::Menu(MyAddressBook, &AddressTop);
	save_data(AddressTop);
	cout << "leaving the system. Do you want to change the password?Please enter yes or no." << endl;
	std::string answer;
	cin >> answer;
	if (answer=="yes")
		Guidance::Change_Password();
	return 0;
}
void get_data(int* AddressTop) {
	std::ifstream in("source.txt");
	if (in.is_open())
	{
		while (!in.eof()) {
			in >> MyAddressBook[*AddressTop].sName;
			in >> MyAddressBook[*AddressTop].sWorkUnit;
			in >> MyAddressBook[*AddressTop].sPhoneNumber;
			in >> MyAddressBook[*AddressTop].sBirthday;
			in >> MyAddressBook[*AddressTop].sE_mailAddress;
			in >> MyAddressBook[*AddressTop].sCallLog1;
			in >> MyAddressBook[*AddressTop].sCallLog2;
			in >> MyAddressBook[*AddressTop].sCallLog3;
			if (MyAddressBook[*AddressTop].sCallLog3[0] != '\0') {

				(*AddressTop)++;

			}
			MyAddressBook[*AddressTop - 1].flag = 1;
		}
		in.close();
	}
}

void save_data(int AddressTop) {
	std::ofstream out("source.txt");
	if (out.is_open())
	{
		for (int i = 0; i < AddressTop; i++) {
			if (MyAddressBook[i].flag == 1) {
				out << MyAddressBook[i].sName << " " << MyAddressBook[i].sWorkUnit << " ";
				out << MyAddressBook[i].sPhoneNumber << " " << MyAddressBook[i].sBirthday << " ";
				out << MyAddressBook[i].sE_mailAddress << " " << MyAddressBook[i].sCallLog1 << " ";
				out << MyAddressBook[i].sCallLog2 << " " << MyAddressBook[i].sCallLog3 << endl;
			}
		}
		out.close();
	}
}