#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <stdlib.h> 
#include "glossary.h"
#include "dict.h"

int word_count=0;
vector<Glossary> glossary;

//�������ʱ��ļ� 
void load_glossary()
{
	//���ļ�
	ifstream fin(DICT_PATH DICT_NEW_ENGLISH_CHINESE);
	//����ļ�������,�ʹ���һ���ļ�
	if(!fin)
	{
		ofstream fout(DICT_NEW_ENGLISH_CHINESE);
		fout.close();
		fin.open(DICT_NEW_ENGLISH_CHINESE);
	} 
	string line;
	Glossary vocabulary;
	while(!fin.eof())
	{
		//��ȡ����
		std::getline(fin,line);
		
		//���Ϊ�գ����ļ�Ϊ�գ�������ȡ
		if(line==" ") break;
		 
		//���ʱ��浽�ڴ���ֵ����ݽṹ��
		vocabulary.word=line;
		vocabulary.meaning.clear();      //�����ϴεĶ�ȡ���
		
		//һ�����ʵĽ����ж��У���ȡ����
		std::getline(fin,line);
		int linecount=atoi(line.c_str());
		
		//��������Ķ�ȡ
		for(int j=0;j<linecount;j++)
		{
			std::getline(fin,line);
			//ÿ��һ�У��������浽���������������
			vocabulary.meaning.push_back(line); 
	    }
	    glossary.push_back(vocabulary);
	}
	fin.close();
}

void save_glossary()
{
	ofstream fout(DICT_NEW_ENGLISH_CHINESE,ios::in);
	for(int i=0;i<glossary.size();i++)
	{
		fout<<glossary[i].word<<endl<<glossary[i].meaning.size()<<endl;
		for(int j=0;j<glossary[i].meaning.size();j++)
		{
			fout<<glossary[i].meaning[i]<<endl; 
		}
	} 
	fout.close();
}

void remove_glossary(string word)
{
	for(vector<Glossary>::iterator i=glossary.begin(); i!=glossary.end();i++)
	{
		Glossary vocabulary=(Glossary)*i;
		if(vocabulary.word==word)
		{
			glossary.erase(i);
			i--;
		}
	}
}
