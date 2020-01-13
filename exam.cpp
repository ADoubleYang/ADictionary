#include<iostream>
#include<stdio.h>
#include<string>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include<ctype.h>
#include"ui.h"
#include"exam.h"
#include"dict.h"
#include "ui.cpp"

using namespace std;


static const string exam_ui_prompt =
"\n\n"
"\t|***********************************|\n"
"\t|*     ��ѡ�������              *|\n"
"\t|***********************************|\n"
"\t|*     1 ������дӢ��              *|\n"
"\t|*     2 ��Ӣ��д����              *|\n"
"\t|*     3 ������д����              *|\n"
"\t|*     0 �˳�ϵͳ                  *|\n"
"\t|***********************************|\n"
"\t  �����루1��2��3��0����"
;

void exam_ui()
{
	CLEAR();
	cout << exam_ui_prompt;
	string op;
	std::getline(cin, op);
	if (op == "1")
	{
		exam_ui_english_for_chinese();
	}
	else if (op == "2")
	{
		exam_ui_chinese_for_english();
	}
	else if (op == "3")
	{
		exam_ui_chengyu();
	}
	else if (op == "0")
	{
		return;
	}
	exam_ui();

}

void exam_ui_english_for_chinese()              //��Ӣ��д���Ŀ��Ժ��� 
{
	dict_load(
		&dictionaries[0],    //װ��Ӣ���ֵ�ʿ� 
		DICT_PATH DICT_ENGLISH_CHINESE);

	Examination exam;
	exam_create(&exam, &dictionaries[0]);  //���ɿ�����Ŀ 
	for (int i = 0;i<exam.words.size();i++)
	{
		CLEAR();
		cout << "\n\n";
		cout << "\t|***********************************|\n";
		meaning_display1(exam.meanings[i]);
		cout << "\n";
		cout << "\t|***********************************|\n";
		string word =get_input_string("\t ������Ӣ�Ĵ𰸣�0 �˳�����");


		if (word == exam.words[i])
		{
			cout << "\t  ��ȷ������" << endl;
			string op =get_input_string("\t  �����루0 �˳�������  ��һ�⣩��");
			if (op == "0")
			{
				break;
			}
		}
		else if (word == "0")
		{
			break;
		}
		else
		{
			cout << "\t   ���󣬼�������Ŷ" << endl;
			string op = get_input_string("\t  �����루0 �˳���1 ��һ�� ��2 �������ԣ���");
			if (op == "0")
			{
				break;
			}
			else if (op == "1")
			{
				exam_ui_english_for_chinese();
			}
			else if (op == "2")
			{
			}
			i--;
		}

	}
}


void exam_ui_chinese_for_english()                //��Ӣ��д���ĺ��� 
{
	dict_load(                                     //װ�شʿ� 
		&dictionaries[1],
		DICT_PATH DICT_CHINESE_ENGLISH);

	Examination exam;
	exam_create(&exam, &dictionaries[1]);
	for (int i = 0;i < exam.words.size();i++)
	{
		CLEAR();
		cout << "\n\n";
		cout << "\t|***********************************|\n";
		meaning_display(exam.meanings[i]);
		cout << "\n";
		cout << "\t|***********************************|\n";
		string word = get_input_string("\t ���������Ĵ𰸣�0 �˳�����");
		if (word == exam.words[i])
		{
			cout << "\t  ��ȷ������" << endl;
			string op = get_input_string("\t  �����루0 �˳�������  ��һ�⣩��");
			if (op == "0")
			{
				break;
			}
		}
		else if (word == "0")
		{
			break;
		}
		else
		{
			cout << "\t   ���󣬼�������Ŷ" << endl;
			string op = get_input_string("\t  �����루0 �˳���1 ��һ�� ��2 �������ԣ���");
			if (op == "0")
			{
				break;
			}
			else if (op == "1")
			{
				exam_ui_chinese_for_english();
			}
			else if (op == "2")
			{
			}
			i--;
			getchar();
			getchar();
		}

	}
}

void exam_ui_chengyu()              //������д���ﺯ�� 
{
	dict_load(
		&dictionaries[2],    //װ�س���ʵ�ʿ� 
		DICT_PATH DICT_CHENGYUDACIDIAN);

	Examination exam;
	exam_create(&exam, &dictionaries[2]);  //���ɿ�����Ŀ 
	for (int i = 0;i < exam.words.size();i++)
	{
		CLEAR();
		cout << "\n\n";
		cout << "\t|***********************************|\n";
		meaning_display1(exam.meanings[i]);
		cout << "\n";
		cout << "\t|***********************************|\n";
		string word = get_input_string("\t ��������0 �˳�����");


		if (word == exam.words[i])
		{
			cout << "\t  ��ȷ������" << endl;
			string op = get_input_string("\t  �����루0 �˳�������  ��һ�⣩��");
			if (op == "0")
			{
				break;
			}
		}
		else if (word == "0")
		{
			break;
		}
		else
		{
			cout << "\t   ���󣬼�������Ŷ" << endl;
			string op = get_input_string("\t  �����루0 �˳���1 ��һ�� ��2 �������ԣ���");
			if (op == "0")
			{
				break;
			}
			else if (op == "1")
			{
				exam_ui_chengyu();
			}
			else if (op == "2")
			{
			}
			i--;
			getchar();
			getchar();
		}

	}
}


static int random_index(int min, int max)                       //����һ��[min,max)֮���������� 
{
	return (int)(min + (double)rand() / (double)RAND_MAX * (max - min));
}

void exam_create(Examination* exam, Dictionary* dict)             //���ֵ����������һ���Ծ� 
{
	srand(time(nullptr));
	int wordcount = dict->words.size();

	int itemcount = wordcount < 10 ? wordcount : 10;
	for (int i = 0;i < itemcount;i++)
	{
		int idx = random_index(0, wordcount);
		exam->words.push_back(dict->words[idx]);
		exam->meanings.push_back(dict->meanings[idx]);
	}
}
