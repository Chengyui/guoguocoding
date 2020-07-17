
#ifndef _PROJECTNEEDED_H_
#define _PROJECTNEEDED_H_

#include <iostream>
#include <conio.h>							//��������
#include <string>
#include <assert.h>							//��Ҫʹ��assert()��������쳣
#include <cstdlib>
#include <Windows.h>
#include <fstream>

#define IN_PARAM
#define OUT_PARAM
using namespace std;

typedef struct {
	char sName[20];						//��ϵ������
	char sWorkUnit[30];					//��ϵ�˹�����ַ
	char sPhoneNumber[20];				//��ϵ�˵绰
	char sBirthday[20];					//��ϵ������
	char sE_mailAddress[20];				//��ϵ������
	char sCallLog1[20];
	char sCallLog2[20];
	char sCallLog3[20];
	int flag;
}AddressBook;

class Guidance
{
public:
	static void Welcome();
	static void Password();
	static void Menu(AddressBook* MyAddressBook, int* AddressTop);
	static void CheckAddressBookList(AddressBook* MyAddressBook, int AddressTop);
	static void AddInfo(AddressBook* MyAddressBook, int* AddressTop);
	static void ModifyInfo(AddressBook* MyAddressBook, int AddressTop);
	static void DeleteInfo(AddressBook* MyAddressBook, int AddressTop);
	static void Change_Password();
	static void log_in();
};

class BlackList                             //������
{
public:
	static void AddBlackNum();              //��Ӻ������ֻ���
	static void AddBlackEmail();            //��Ӻ�������������
	static void ResistNum();                //�������
	static void ResistEmail();              //��������
	static void DeleteBlackInfo();
	static std::string charToStr(IN_PARAM char* pArray);
	static void BlackListDisp();
};


#endif
