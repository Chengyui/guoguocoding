#include "ProjectNeeded.h"

using namespace std;




void BlackList::ResistNum()
{
	std::ofstream add;
	add.open("BlackList.txt", std::ios::app);
	add.close();
	std::ifstream in("BlackList.txt");
	if (!in)
	{
		std::cout << "open file failed." << std::endl;
	}
	else
	{
		std::string CallNum;
		std::cout << "The phone call is from:" << std::endl;
		std::cin >> CallNum;
		std::string read;
		bool i = true;
		while (getline(in, read))
		{
			if (CallNum == read)
			{
				std::cout << "The call is form blacklist number,refused." << std::endl;
				i = false;
				break;
			}
		}
		if (i == true)
		{
			std::cout << "your phone is ringing!" << std::endl;
		}
		i = true;
	}
	Sleep(2000);
	system("cls");
}

void BlackList::ResistEmail()
{
	std::ofstream add;
	add.open("BlackList.txt", std::ios::app);
	add.close();
	std::ifstream in("BlackList.txt");
	if (!in)
	{
		std::cout << "open file failed." << std::endl;
	}
	else
	{
		std::string Email;
		std::cout << "The email is from:" << std::endl;
		std::cin >> Email;
		std::string content;
		std::cout << "The content of the email is:" << std::endl;
		std::cin >> content;
		std::string read;
		bool i = true;
		while (getline(in, read))
		{
			if (Email == read)
			{
				std::cout << "The email is from blacklist address,refused." << std::endl;
				std::string check;
				std::cout << "Check the resisted Email?Please enter yes or no." << std::endl;
				std::cin >> check;
				if (check == "yes")
				{
					std::cout << "The content is:" << content << std::endl;
				}
				i = false;
				break;
			}
		}
		if (i == true)
		{
			std::cout << "New email available." << std::endl;
		}
		i = true;
	}
	Sleep(2000);
	system("cls");
}



void BlackList::AddBlackNum()
{
	bool repeat = false;
	std::string BlackListNum;
	std::cout << "enter new blacklist phone number." << std::endl;
	std::cin >> BlackListNum;
	std::ofstream add;
	add.open("BlackList.txt", std::ios::app);
	std::string get;
	std::ifstream in("BlackList.txt");
	if (!in)
	{
		std::cout << "open file failed." << std::endl;
	}
	else
	{
		while (getline(in, get))
		{
			if (BlackListNum == get)
			{
				repeat = true;
				break;
			}
		}
	}
	if (repeat == false)
	{
		add << BlackListNum << "\n";
		std::cout << "Black phone number added successfully." << std::endl;
		std::cout << "The blacklist before adding has:" << std::endl;
		BlackListDisp();
		add.close();
		cout << "Take any key to back!" << endl;
		getchar();
		getchar();
		Sleep(2000);
		system("cls");
	}
	else
	{
		std::cout << "Blacklist number repeat." << std::endl;
		std::cout << "The blacklist before adding has:" << std::endl;
		BlackListDisp();
		add.close();
		cout << "Take any key to back!" << endl;
		getchar();
		getchar();
		Sleep(2000);
		system("cls");
	}
}

void BlackList::AddBlackEmail()
{
	bool repeat = false;
	std::string BlackListEmail;
	std::cout << "enter new blacklist email adress." << std::endl;
	std::cin >> BlackListEmail;
	std::ofstream add;
	add.open("BlackList.txt", std::ios::app);
	std::string get;
	std::ifstream in("BlackList.txt");
	if (!in)
	{
		std::cout << "open file failed." << std::endl;
	}
	else
	{
		while (getline(in, get))
		{
			if (BlackListEmail == get)
			{
				repeat = true;
				break;
			}
		}
	}
	if (repeat == false)
	{
		add << BlackListEmail << "\n";
		std::cout << "Black email address added successfully." << std::endl;
		std::cout << "The blacklist before adding has:" << std::endl;
		BlackListDisp();
		add.close();
		cout << "Take any key to back!" << endl;
		getchar();
		getchar();
		Sleep(1000);
		system("cls");
	}
	else
	{
		std::cout << "Blacklist email repeat." << std::endl;
		std::cout << "The blacklist before adding has:" << std::endl;
		BlackListDisp();
		add.close();
		cout << "Take any key to back!" << endl;
		getchar();
		getchar();
		Sleep(2000);
		system("cls");
	}
}

std::string BlackList::charToStr(IN_PARAM char* pArray)
{
	std::string sTempStr;
	for (int i = 0; pArray[i] != '\0'; i++)
	{
		sTempStr += pArray[i];
	}
	sTempStr += "\n";
	return sTempStr;
}

void BlackList::DeleteBlackInfo()
{
	char cLine[200] = { '\0' };
	std::string sTempAns;
	std::string sContent;
	int iNumOfContact;
	int LineNum = 0;
	std::cout << "You have chosen to delete the BlackList information." << std::endl;
	BlackListDisp();
	std::cout << "Please follow the guidelines to enter the changed BlackList information." << std::endl;
	std::cout << "The number of line you want to delete (from top to bottom):";
	std::cin >> iNumOfContact;
	std::ifstream in("BlackList.txt", std::ios::in);
	std::string lines;
	while (getline(in, lines))
	{
		LineNum++;
	}
	if (iNumOfContact <= LineNum)
	{
		if (in.is_open())
		{
			int iTemp = 0;
			while (in.getline(cLine, sizeof(cLine)))
			{
				iTemp++;
				if (iTemp != iNumOfContact)
				{
					sTempAns += charToStr(cLine);
				}
			}
			in.close();
			std::ofstream out("BlackList.txt", std::ios::out);
			if (out.is_open())
			{
				out.flush();
				out << sTempAns;
				out.close();
			}
			else
			{
				std::cout << "Error opening file!" << std::endl;
				exit(1);
			}
			std::cout << "Wonderful!BlackList information has been deleted successfully!" << std::endl;
			Sleep(2000);
			system("cls");
		}
		else
		{
			std::cout << "Error opening file!" << std::endl;
			exit(1);
		}
	}
	else
	{
		std::cout << "Wrong number of line!" << std::endl;
		cout << "Take any key to back!" << endl;
		getchar();
		getchar();
		Sleep(2000);
		system("cls");
	}
}

void BlackList::BlackListDisp()
{
	std::string read;
	int i = 1;
	std::ifstream in("BlackList.txt");
	if (!in)
	{
		std::cout << "open file failed." << std::endl;
	}
	else
	{
		getline(in, read);
		if (read == "\0")
		{
			cout << "there is nothing in this List" << endl;
		}

		else
		{
			std::cout << i << ":" << read << std::endl;
			i++;
			while (getline(in, read))
			{
				std::cout << i << ":" << read << std::endl;
				i++;
			}
		}
	}
}