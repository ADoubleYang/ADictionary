#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<ctype.h>
#include<stdlib.h>
#include<stdio.h>
#include"ui.h"
#include"dict.h"
#include "glossary.h"

using namespace std;

Dictionary dictionaries[4];
Dictionary unfamiliarDictionaries[4];
const string dict_ui_prompt =
"\n\n"
"\t|***********************************|\n"
"\t|*   ��ѡ���֣��ʵ�              *|\n"
"\t|***********************************|\n"
"\t|*   1 Ӣ���ʵ�                    *|\n"
"\t|*   2 ��Ӣ�ʵ�                    *|\n"
"\t|*   3 ����ʵ�                    *|\n"
"\t|*   4 �»��ֵ�                    *|\n"
"\t|*   0 �����ϼ�                    *|\n"
"\t|***********************************|\n"
"\t   ������(1��2��3��4��0):"
;

extern void dict_ui()
{
	CLEAR();
	cout << dict_ui_prompt;
	string op;
	std::getline(cin, op);
	if (op == "1")
	{
		dict_ui_english_to_chinese();
	}
	else if (op == "2")
	{
		dict_ui_chinese_to_english();
	}
	else if (op == "3")
	{
		dict_ui_chengyudacidian();
	}
	else if (op == "4")
	{
		dict_ui_xinhuazidian();
	}
	else if (op == "0")
	{
		return;
	}

	dict_ui();

}
void meaning_display(const vector<string>& meaning)
{
	cout << "\n";
	for (unsigned int i = 0;i < meaning.size();i++)
	{
		cout << "\t" << meaning[i] << endl;
	}
}
void dict_load(Dictionary* dict, const char* filename)
{
	//���װ�ع��˾Ͳ�Ҫ�ٶ��ļ���
	if (dict->loaded)
	{
		return;
	}
	fstream infile;
	infile.open(filename, ios_base::in);
	if (!infile)
	{
		cerr << "�򿪴ʵ��ļ���" << filename << "ʧ��" << endl;
		PAUSE();
		exit(1);
	}
	dict->filename = filename;
	//�õ�����/�������
	int wordscount;
	string line;
	std::getline(infile, line);
	//��ȡ���������ַ�����Ҫ����ת���������У�atoi����
	wordscount = atoi(line.c_str());
	//����ô�൥�ʣ���ȻҪ��ô���
	for (int i = 0;i < wordscount;i++)
	{
		//��ȡ����
		std::getline(infile, line);
		//���ʱ��浽�ڴ��е��ֵ����ݽṹ��
		dict->words.push_back(line);
		vector<string> meaning;
		//һ�����ʵĽ����кܶ��У���ȡ����
		std::getline(infile, line);
		int linecount = atoi(line.c_str());
		//��������Ķ�ȡ
		for (int j = 0;j < linecount;j++)
		{
			std::getline(infile, line);
			//ÿ��һ�У��������浽���������������
			meaning.push_back(line);
		}
		//ÿһ��������һ�����壬�����Ƕ��еģ��Ž��ڴ���
		dict->meanings.push_back(meaning);
	}

	infile.close();
	//װ�سɹ��ˣ�����һ��װ�سɹ��ı�־
	dict->loaded = true;
}

void dict_ui_english_to_chinese()
{
	dict_load(&dictionaries[0], DICT_PATH DICT_ENGLISH_CHINESE);
	CLEAR();
	const string prompt =
		"\n\n"
		"\t|***********************************|\n"
		"\t|*   ��ӭʹ��  Ӣ���ʵ�            *|\n"
		"\t|***********************************|\n"
		"\t|*   ������Ӣ�ģ� ��(��������)~    *|\n"
		;
	cout << prompt;
	cout << "\t|*   ";
	string word = " ";
	std::getline(cin, word);
	if (word == " ")
	{
		dict_ui_english_to_chinese();
		return;
	}
	bool find = false;
	vector<string> meaning = dict_lookup(&dictionaries[0], word, find);
	if (find)
	{
		cout << "\t  ��ѯ����ǣ�" << endl;
		meaning_display(meaning);
		cout << "\t|***********************************|\n";
		cout << "\t|***********************************|\n";
		cout << "\t|  ��ѡ��1 �������ʱ�            *|\n";
		cout << "\t|          2 �������              *|\n";
		cout << "\t|          0 �����ϼ������� ����   *|\n";
		cout << "\t|***********************************|\n";
	}
	else
	{
		meaning_display(meaning);
		cout << "\t|***********************************|\n";
		cout << "\t|  ��ѡ��0 �����ϼ� ���� ����    *|\n";
	}

	string op;
	std::getline(cin, op);
	if (op == "1")
	{
		//ֻ�в�ѯ�õ��ĵ���/����Ż���Ҫ�������ʱ�
		if (find)
		{
			load_glossary();
			save_glossary();
			
			cout << "����ɹ�������Ϊ����ת����ʽ���" << endl;
			dict_ui_english_to_chinese();
			//�������ʱ� 
		}
	}
	else if (op == "2")
	{
		dict_ui_english_to_chinese();
	}
	else if (op == "0")
	{
		return;
	}
	dict_ui_english_to_chinese();
}

void dict_ui_chinese_to_english()
{
	dict_load(&dictionaries[1], DICT_PATH DICT_CHINESE_ENGLISH);
	CLEAR();
	const string prompt =
		"\n\n"
		"\t|***********************************|\n"
		"\t|*   ��ӭʹ��  ��Ӣ�ʵ� (����ء�`)*|\n"
		"\t|***********************************|\n"
		"\t|*   ���������ģ���(��������)~     *|\n"
		;
	cout << prompt;
	cout << "\t|*   ";
	string word = " ";
	std::getline(cin, word);
	if (word == " ")
	{
		dict_ui_chinese_to_english();
		return;
	}
	bool find = false;
	vector<string> meaning = dict_lookup(&dictionaries[1], word, find);
	if (find)
	{
		cout << "\t  ��ѯ����ǣ�" << endl;
		meaning_display(meaning);
		cout << "\t|***********************************|\n";
		cout << "\t|***********************************|\n";
		cout << "\t|  ��ѡ��1 �������ʱ�            *|\n";
		cout << "\t|          2 �������              *|\n";
		cout << "\t|          0 �����ϼ������� ����   *|\n";
		cout << "\t|***********************************|\n";
	}
	else
	{
		meaning_display(meaning);
		cout << "\t|***********************************|\n";
		cout << "\t|  ��ѡ��0 �����ϼ� ���� ����    *|\n";
	}

	string op;
	std::getline(cin, op);
	if (op == "1")
	{
		//ֻ�в�ѯ�õ��ĵ���/����Ż���Ҫ�������ʱ�
		if (find)
		{
			//�������ʱ� 
		}
	}
	else if (op == "2")
	{
		dict_ui_chinese_to_english();
	}
	else if (op == "0")
	{
		return;
	}
	dict_ui_chinese_to_english();
}

void dict_ui_chengyudacidian()
{
	dict_load(&dictionaries[2], DICT_PATH DICT_CHENGYUDACIDIAN);
	CLEAR();
	const string prompt =
		"\n\n"
		"\t|***********************************|\n"
		"\t|*   ��ӭʹ��  ����ʵ�  (�R�بQ)  *|\n"
		"\t|***********************************|\n"
		"\t|*   ��������  ��(��������)~   *|\n"
		;
	cout << prompt;
	cout << "\t|*   ";
	string word = " ";
	std::getline(cin, word);
	if (word == " ")
	{
		dict_ui_chengyudacidian();
		return;
	}
	bool find = false;
	vector<string> meaning = dict_lookup(&dictionaries[2], word, find);
	if (find)
	{
		cout << "\t  ��ѯ����ǣ�" << endl;
		meaning_display(meaning);
		cout << "\t|***********************************|\n";
		cout << "\t|***********************************|\n";
		cout << "\t|  ��ѡ��1 �������ʱ�            *|\n";
		cout << "\t|          2 ���������            *|\n";
		cout << "\t|          0 �����ϼ������� ����   *|\n";
		cout << "\t|***********************************|\n";
	}
	else
	{
		meaning_display(meaning);
		cout << "\t|***********************************|\n";
		cout << "\t|  ��ѡ��0 �����ϼ� ���� ����    *|\n";
	}

	string op;
	std::getline(cin, op);
	if (op == "1")
	{
		//ֻ�в�ѯ�õ��ĵ���/����Ż���Ҫ�������ʱ�
		if (find)
		{
			//�������ʱ� 
		}
	}
	else if (op == "2")
	{
		dict_ui_chengyudacidian();
	}
	else if (op == "0")
	{
		return;
	}
	dict_ui_chengyudacidian();
}

void dict_ui_xinhuazidian()
{
	dict_load(&dictionaries[3], DICT_PATH DICT_XINHUAZIDIAN);
	CLEAR();
	const string prompt =
		"\n\n"
		"\t|***********************************|\n"
		"\t|*   ��ӭʹ��  �»��ֵ�   (=^��^=) *|\n"
		"\t|***********************************|\n"
		"\t|*   �����뺺�֣�   ��(��������)~  *|\n"
		;
	cout << prompt;
	cout << "\t|*   ";
	string word = " ";
	std::getline(cin, word);
	if (word == " ")
	{
		dict_ui_xinhuazidian();
		return;
	}
	bool find = false;
	vector<string> meaning = dict_lookup(&dictionaries[3], word, find);
	if (find)
	{
		cout << "\t  ��ѯ����ǣ�" << endl;
		meaning_display(meaning);
		cout << "\t|***********************************|\n";
		cout << "\t|***********************************|\n";
		cout << "\t|  ��ѡ��1 �������ʱ�            *|\n";
		cout << "\t|          2 ��������              *|\n";
		cout << "\t|          0 �����ϼ������� ����   *|\n";
		cout << "\t|***********************************|\n";
	}
	else
	{
		meaning_display(meaning);
		cout << "\t|***********************************|\n";
		cout << "\t|  ��ѡ��0 �����ϼ� ���� ����    *|\n";
	}

	string op;
	std::getline(cin, op);
	if (op == "1")
	{
		//ֻ�в�ѯ�õ��ĵ���/����Ż���Ҫ�������ʱ�
		if (find)
		{
			//�������ʱ� 
		}
	}
	else if (op == "2")
	{
		dict_ui_xinhuazidian();
	}
	else if (op == "0")
	{
		return;
	}
	dict_ui_xinhuazidian();
}

/*void meaning_display(const vector<string>& meaning)     //�����Ҫ���ҵĵ��ʵ���˼ 
{
	cout << "\n";
	for (unsigned int i = 0;i < meaning.size();i++)
	{
		cout << "\t" << meaning[i] << endl;
	}
}
*/

void meaning_display1(const vector<string>& meaning)    //���ڳ��￼��ʱ��������³��� 
{
	cout << "\n";
	for (unsigned int i = 2;i < meaning.size();i++)           //���ʱ����ǰ���� 
	{
		cout << "\t" << meaning[i] << endl;
	}
}

vector<string> dict_lookup(Dictionary* dict, const string& word, bool& find)
{
	vector<string> result;
	result.push_back("�������ã�û���ҵ���#����#��");
	//�����ѯ���ǰ�˳������һ�����Ƚϣ�
	//���ƥ��ɹ����ͱ�ʾ�鵽��������ʣ�������Ӧ�Ľ���
	for (unsigned int i = 0;i < dict->words.size();i++)
	{
		if (word == dict->words[i])
		{
			result = dict->meanings[i];
			find = true;
			return result;
		}
	}
	// ���û�鵽������͵�������
	find = false;
	return result;
}

vector<string> dict_lookup(Dictionary* dict, const string& word)
{
	bool find = false;
	return dict_lookup(dict, word, find);
}