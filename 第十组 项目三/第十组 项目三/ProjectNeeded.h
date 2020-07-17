
#ifndef _PROJECTNEEDED_H_
#define _PROJECTNEEDED_H_

#include <iostream>
#include <conio.h>							//密码输入
#include <string>
#include <assert.h>							//需要使用assert()函数检测异常
#include <cstdlib>
#include <Windows.h>
#include <fstream>

#define IN_PARAM
#define OUT_PARAM
using namespace std;

typedef struct {
	char sName[20];						//联系人姓名
	char sWorkUnit[30];					//联系人工作地址
	char sPhoneNumber[20];				//联系人电话
	char sBirthday[20];					//联系人生日
	char sE_mailAddress[20];				//联系人邮箱
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

class BlackList                             //黑名单
{
public:
	static void AddBlackNum();              //添加黑名单手机号
	static void AddBlackEmail();            //添加黑名单电子邮箱
	static void ResistNum();                //来电测试
	static void ResistEmail();              //来件测试
	static void DeleteBlackInfo();
	static std::string charToStr(IN_PARAM char* pArray);
	static void BlackListDisp();
};


#endif
