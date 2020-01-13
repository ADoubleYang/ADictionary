#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<iomanip>
#include<stdlib.h> 
#include<fstream>
#include<cstring>
#include<ctype.h>

#include "glossary.h"

int words_count = 0;
vector <Glossary> glossary;

/*
�������ʱ��ļ�
*/
void load_glossary()
{
	//���ļ�
	ifstream fin(GLOSSARY_FILE);
	//����ļ������ڣ��򴴽�֮
	if (!fin)
	{
		ofstream fout(GLOSSARY_FILE);
		fout.close();
		fin.open(GLOSSARY_FILE);
	}
	string line;
	Glossary vocabulary;
	while (!fin.eof())
	{
		//��ȡ����
		std::getline(fin, line);
		//���Ϊ�գ����ļ�Ϊ�գ�������ȡ
		if (line == " ")
		{
			break;
		}
		//���ʱ��浽�ڴ��е��ֵ����ݽṹ��
		vocabulary.word = line;
		vocabulary.means.clear();  //����ϴζ�ȡ���
		vector<string> meaning;
		//һ�����ʵĽ����кܶ��У���ȡ����
		std::getline(fin, line);
		int linecount = atoi(line.c_str());
		//��������Ķ�ȡ
		for (int j = 0;j < linecount;j++)
		{
			std::getline(fin, line);
			//ÿ��һ�У��������浽���������������
			vocabulary.means.push_back(line);
		}
		//ÿһ��������һ�����壬�����Ƕ��еģ��Ž��ڴ���
		glossary.push_back(vocabulary);
	}
	fin.close();//�������ʱ�
}

/**
˼��1 ��ȡ���ʱ�֮����������кκô�
˼��2 �������ʱ���ж����ʱ����Ƿ�����
**/

void save_glossary()
{
	fstream fout(GLOSSARY_FILE, ios::trunc);
	for (int i = 0;i < glossary.size();i++)
	{
		fout << glossary[i].word << endl;
		fout << glossary[i].means.size() << endl;
		for (int j = 0;j < glossary[i].means.size();j++)
		{
			fout << glossary[i].means[j] << endl;
		}
	}
	fout.close();
}
/** �Ƴ�����*
 /*remove_glossary(word); @param word  Ҫ�Ƴ��ĵ���
 **/
void remove_glossary(string word)
{
	for (auto i = glossary.begin();i != glossary.end();i++)
	{
		Glossary vocabulary = (Glossary) * i;
		if (vocabulary.word == word)
		{
			glossary.erase(i);
			i--;
		}
	}
}
