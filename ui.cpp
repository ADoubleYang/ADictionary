#include<iostream>
#include "ui.h"
void init_console()
{
	system("mode con cols=64 lines=30");
	system("chcp 936");
	system("color 7d");
	system("cls");
}

const string main_ui_prompt =
"\n\n"
"\t|***********************************|\n"
"\t|*   ��ӭʹ��  �ҵĴʵ� <*-*>      *|\n"
"\t|***********************************|\n"
"\t|*   1 �ִʲ�ѯ                    *|\n"
"\t|*   2 �ִʿ���                    *|\n"
"\t|*   3 ���ʸ�ϰ                    *|\n"
"\t|*   0 �˳�ϵͳ                    *|\n"
"\t|***********************************|\n"
"\t   ������(1��2��3��0):"
;

void main_ui()
{
	CLEAR();
	cout << main_ui_prompt;
	string op;
	std::getline(cin, op);
	if (op == "1")
	{
		dict_ui();
	}
	else if (op == "2")
	{
		exam_ui();
	}
	else if (op == "3")
	{

	}
	else if (op == "0")
	{
		return;
	}

	main_ui();
}
string get_input_string(const string& prompt)
{
	cout << prompt;
	string word;
	std::getline(cin, word);
	return word;
}