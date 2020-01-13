#include <stdlib.h> 
#include <string>
#include <iostream>
#include <fstream>
#include "ui.h"
#include "dict.h"
#include "glossary.h"
using namespace std;

extern int words_count;
extern vector<Glossary> glossary;
Dictionary dictionaries[4];
Dictionary unfamiliarDictionaries[4]; 
Glossary vocabulary;

const string dict_ui_prompt=
"\n\n"
"\t|********************************************|\n"
"\t|*            ��ѡ��ʵ�                    *|\n"
"\t|********************************************|\n"
"\t|*            1 Ӣ���ʵ�                    *|\n"
"\t|*            2 ��Ӣ�ʵ�                    *|\n"
"\t|*            3 ����ʵ�                    *|\n" 
"\t|*            4 �»��ʵ�                    *|\n"
"\t|*            0 �����ϼ�                    *|\n"
"\t|********************************************|\n"   
"\t  �����루1��2��3��4��0����"
;

extern void dict_ui()
{
	CLEAR();
	cout<<dict_ui_prompt;
	string op;
	std::getline(cin,op);
	if(op=="1"){
		dict_ui_english_to_chinese();
	}
	else if(op=="2"){
		dict_ui_chinese_to_english();
	}
	else if(op=="3"){
		dict_ui_chengyudacidian();
	}
	else if(op=="4"){
	}
	else if(op=="0"){
		return;
	}
	dict_ui();
} 

void meaning_display(const vector<string>&meaning)
{
	cout<<"\n";
	for(unsigned int i=0;i<meaning.size();i++)
	{
		cout<<"\t"<<meaning[i]<<endl;
	}
}

void meaning_display_special(const vector<string>&meaning)
{
	cout<<"\n";
	for(unsigned int i=2;i<meaning.size();i++)
	{
		cout<<"\t"<<meaning[i]<<endl;
	}
}

//Ӣ�뺺�ʵ��ѯ���� 
void dict_ui_english_to_chinese()
{ 
	dict_load(&dictionaries[ENGLISH_CHINESE],DICT_PATH DICT_ENGLISH_CHINESE);
	CLEAR();
	const string prompt=
	"\n\n"
    "\t|********************************************|\n"
    "\t|*   Ӣ���ʵ�                               *|\n"
    "\t|********************************************|\n"
    "\t     ������Ӣ�ģ�" 
	;
	cout<<prompt;
	string word=" ";
	std::getline(cin,word);
	if(word==" ")
	{
		dict_ui_english_to_chinese();
		return;
	} 
	bool find=false;
	vector<string>meaning=dict_lookup(&dictionaries[ENGLISH_CHINESE],word,find);
	if(find)
	{
		cout<<"\t ��ѯ����ǣ�"<<endl;
		meaning_display(meaning);
		cout<<"\t|********************************************|\n";
	    cout<<"\t   ��ѡ��1 �������ʱ���0�����ϼ������� ��������";
	}
	else
	{
		meaning_display(meaning);
		cout<<"\t|********************************************|\n";
	    cout<<"\t   ��ѡ��0�����ϼ������� ��������";
	}
	string op;
	std::getline(cin,op);
	if(op=="1")
	{
		//ֻ�в�ѯ�õ��ĵ���/����Ż���Ҫ�������ʱ�
		if(find)
		{
            vocabulary.word=word;
		    vocabulary.meaning.clear();
		    for(int i=0;i<meaning.size();i++)
		    {
			    vocabulary.meaning.push_back(meaning[i]);
		    }
	    	glossary.push_back(vocabulary);
		    //�������ʱ� 
		    ofstream fout(DICT_PATH DICT_NEW_ENGLISH_CHINESE,ios::in);
		    fout<<glossary.size()<<endl;
	        for(int i=0;i<glossary.size();i++)
    	    {
    		    fout<<glossary[i].word<<endl<<glossary[i].meaning.size()<<endl;
	    	    for(int j=0;j<glossary[i].meaning.size();j++)
		        {
			        fout<<glossary[i].meaning[j]<<endl; 
		        } 
	        }   
	        fout.close(); 
		} 
	} 
	else if(op=="0")
	{
		return;
	}
	dict_ui_english_to_chinese();
}

//����Ӣ�ʵ��ѯ���� 
void dict_ui_chinese_to_english()
{ 
	dict_load(&dictionaries[CHINESE_ENGLISH],DICT_PATH DICT_CHINESE_ENGLISH);
	CLEAR();
	const string prompt=
	"\n\n"
    "\t|********************************************|\n"
    "\t|*         ��Ӣ�ʵ�                         *|\n"
    "\t|********************************************|\n"
    "\t           ���������ģ�" 
	;
	cout<<prompt;
	string word=" ";
	std::getline(cin,word);
	if(word==" ")
	{
		dict_ui_chinese_to_english();
		return;
	} 
	bool find=false;
	vector<string>meaning=dict_lookup(&dictionaries[CHINESE_ENGLISH],word,find);
	if(find)
	{
		cout<<"\t ��ѯ����ǣ�"<<endl;
		meaning_display(meaning);
		cout<<"\t|********************************************|\n";
	    cout<<"\t   ��ѡ��1 �������ʱ���0�����ϼ������� ��������";
	}
	else
	{
		meaning_display(meaning);
		cout<<"\t|********************************************|\n";
	    cout<<"\t   ��ѡ��0�����ϼ������� ��������";
	}
	string op;
	std::getline(cin,op);
	if(op=="1")
	{
		//ֻ�в�ѯ�õ��ĵ���/����Ż���Ҫ�������ʱ�
		if(find)
		{
            vocabulary.word=word;
		    vocabulary.meaning.clear();
		    for(int i=0;i<meaning.size();i++)
		    {
			    vocabulary.meaning.push_back(meaning[i]);
		    }
	    	glossary.push_back(vocabulary);
		    //�������ʱ� 
		    ofstream fout(DICT_PATH DICT_NEW_CHINESE_ENGLISH,ios::in);
		    fout<<glossary.size()<<endl;
	        for(int i=0;i<glossary.size();i++)
    	    {
    		    fout<<glossary[i].word<<endl<<glossary[i].meaning.size()<<endl;
	    	    for(int j=0;j<glossary[i].meaning.size();j++)
		        {
			        fout<<glossary[i].meaning[j]<<endl; 
		        } 
	        }   
	        fout.close(); 
		} 
	} 
	else if(op=="0")
	{
		return;
	}
	dict_ui_chinese_to_english();
}

//����ʵ��ѯ���� 
void dict_ui_chengyudacidian()
{
	
	dict_load(& dictionaries[CHENGYUDACIDIAN],DICT_PATH DICT_CHENGYUDACIDIAN );
	CLEAR();
	const string prompt=
   "\n\n"
   "\t|*********************************************|\n"
   "\t|*              ����ʵ�                     *|\n"
   "\t|*********************************************|\n"
   "\t   ��������Ҫ��ѯ�ĳ��� :"
   ;
   cout<<prompt;
   string word=" ";
   std::getline(cin,word);
   if(word==" ")
   {
       dict_ui_chengyudacidian();
       return;
   }
   bool find=false;
   vector<string>meaning=dict_lookup(&dictionaries[CHENGYUDACIDIAN],word,find);
   if(find)
   {
	   cout<<"\t  ��ѯ����ǣ�"<<endl;
	   meaning_display(meaning);
	   cout<<"\t***********************************|\n";
	   cout<<"\t ��ѡ��1 �������ʱ���0 �����ϼ������� ������"; 
   }
   else
   {
       meaning_display(meaning);
       cout<<"\t***********************************|\n";
       cout<<"\t ��ѡ��0 �����ϼ������� ������"; 
    }
    string op;
    std::getline(cin,op);
    if(op=="1")
    {
	    //ֻ�в�ѯ�õ��ĵ���/����Ż���Ҫ�������ʱ�
		if(find)
		{
            vocabulary.word=word;
		    vocabulary.meaning.clear();
		    for(int i=0;i<meaning.size();i++)
		    {
			    vocabulary.meaning.push_back(meaning[i]);
		    }
	    	glossary.push_back(vocabulary);
		    //�������ʱ� 
		    ofstream fout(DICT_PATH DICT_NEW_CHENGYUDACIDIAN,ios::in);
		    fout<<glossary.size()<<endl;
	        for(int i=0;i<glossary.size();i++)
    	    {
    		    fout<<glossary[i].word<<endl<<glossary[i].meaning.size()<<endl;
	    	    for(int j=0;j<glossary[i].meaning.size();j++)
		        {
			        fout<<glossary[i].meaning[j]<<endl; 
		        } 
	        }   
	        fout.close(); 
		} 	
    }
    else if(op=="0")
    {
       return;
    }
    dict_ui_chengyudacidian();
}

//װ�شʵ� 
void dict_load(Dictionary* dict, const string& filename) 
{ 
  // ���װ�ع��ˣ��Ͳ�Ҫ�ٶ��ļ���
  if(dict->loaded)
  {
    return;
  }
  
  fstream in( filename.c_str(), ios::in); 
  if(!in)
  { 
    cerr<<"�򲻿��ʵ��ļ�:"<<filename<<endl;
    PAUSE(); 
    exit(1);
  }
  dict->filename=filename;
  
  //�õ�����/������� 
  int wordscount;
  string line;
  std::getline(in,line);
  
  //��ȡ���������ַ�����Ҫ����ת���������У�atoi ���� 
  wordscount=atoi(line.c_str());
  
  //��ζ����� 
  for(int i=0;i<wordscount;i++)
  { 
    //��ȡ���� 
	std::getline(in, line); 
	
	//���ʱ��浽�ڴ��е��ֵ����ݽṹ��
    dict->words.push_back(line);
    vector<string>meaning;
    
    // һ�����ʵĽ����кܶ��У���ȡ���� 
    std::getline(in,line); 
    int linecount=atoi(line.c_str());
    
    // ��������Ķ�ȡ
    for(int j=0;j<linecount;j++)
    {
	   std::getline(in, line);
	    
       //ÿ��һ�У��������浽���������������
	   meaning.push_back(line); 
    }
    // ÿһ��������һ�����壬�����Ƕ��еģ��Ž��ڴ�����ȥ 
    dict->meanings.push_back(meaning);
  }
  in.close();
  // װ�سɹ��ˣ�����һ��װ�سɹ��ı�־
  dict->loaded=true;
}

vector<string> dict_lookup(Dictionary* dict, const string& word, bool& find)
{ 
  vector<string> result; 
  result.push_back("�ʵ���޷�Ϊ���ҵ�Ŀ��");
   
  //�����ѯ���ǰ�˳������һ�����Ƚϣ� 
  //���ƥ��ɹ����ͱ�ʾ�鵽��������ʣ�������Ӧ�Ľ��� 
  for (unsigned int i=0;i<dict->words.size();i++) 
  { 
    if (word==dict->words[i]) 
    { 
      result=dict->meanings[i]; 
      find=true; 
      return result; 
    } 
  }
  //���û�鵽,����͵��������� 
  find = false; 
  return result; 
}

// ���������������Ǹ�������������ͬ������ 
vector<string> dict_lookup(Dictionary* dict, const string& word) 
{ 
  bool find=false; 
  return dict_lookup(dict,word,find); 
} 
