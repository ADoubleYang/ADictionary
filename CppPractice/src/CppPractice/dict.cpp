#include "dict.h"
#include <string>
#include <iostream>
#include "ui.h"
#include <fstream>
#include <vector>

using namespace std;

Dictionary dictionaries[4];
Dictionary unfamiliarDictionaries[4];

void dict_ui()
{
	CLEAR();

}

//ʵ�ֳ���ʵ书��
void idioms_dict()
{
	CLEAR();
	const string dict4_struct =
		"\n\n"
		"\t|>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>|\n"
		"\t|*               �����ֵ�                  |\n"
		"\t|------------------------------------------|\n"
		"\t�����������ѯ�ĳ��";
	cout << dict4_struct;
	string word = "";
	std::getline(cin, word);
	if (word == "")
	{
		dict_ui_mean_of_idiom();
		return;
	}
}

void dict_load(Dictionary* dict, const string& filename)
{
	if (dict->loaded)
	{
		return;
	}
	fstream in(filename, ios::in);
	if (!in)
	{
		cerr << "�򲻿��ʵ��ļ�:" << filename << endl;
		PAUSE();
		exit(1);
	}
	dict->filename = filename;

	int wordscount;
	string line;
	std::getline(in, line);//�õ�����/������� 
	wordscount = atoi(line.c_str());//��ȡ���������ַ�����Ҫ����ת���������У�atoi ����
	//����ظ����������ַ���ת������
	for (int i = 0; i < wordscount; i++)
	{
		std::getline(in, line);//��ȡ���� 
		dict->words.push_back(line);//���ʱ��浽�ڴ��е��ֵ����ݽṹ�� 
		vector<string> meaning;
		std::getline(in, line);// һ�����ʵĽ����кܶ��У���ȡ���� 
		int linecount = atoi(line.c_str());
		for (int j = 0; j < linecount; j++)// ��������Ķ�ȡ
		{
			std::getline(in, line);
			meaning.push_back(line);// ÿ��һ�У��������浽��������������� 

		}
		dict->meanings.push_back(meaning);// ÿһ��������һ�����壬�����Ƕ��еģ��Ž��ڴ�����ȥ 
	}
	in.close();
	dict->loaded = true;
}

vector<string> dict_lookup(Dictionary* dict, const string& word, bool& find)
{
	vector<string> result;
	result.push_back("�������ã�û���ҵ���");
	//�����ѯ���ǰ�˳������һ�����Ƚϣ� 
	//���ƥ��ɹ����ͱ�ʾ�鵽��������ʣ�������Ӧ�Ľ��� 
	for (unsigned int i = 0; i < dict->words.size(); i++)
	{
		if (word == dict->words[i])
		{
			result = dict->meanings[i];
			find = true;
			return result;
		}
	}
	// ���û�鵽������͵���������
	find = false;
	return result;
}

void dict_ui_mean_of_idiom()
{
	dict_load(&dictionaries[CHENGYUCIDIAN], file_location IDIOMS_DICT_FILE);
	CLEAR();
	dict_ui_mean_of_idiom();
}