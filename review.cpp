#include "review.h"
#include "ui.h"
#include <iostream>
#include <string>
#include <fstream>
#include "stdlib.h"
#include "time.h"
#include "exam.h"
#include "glossary.h"
#include "dict.h"
using namespace std;

static const string review_ui_prompt=
"\n\n"
"\t|********************************************|\n"
"\t|*            ��ѡ��ϰ���                *|\n"
"\t|********************************************|\n"
"\t|*            1 Ӣ���ʵ临ϰ                *|\n"
"\t|*            2 ��Ӣ�ʵ临ϰ                *|\n"
"\t|*            3 ����ʵ临ϰ                *|\n" 
"\t|*            0 �����ϼ�                    *|\n" 
"\t|********************************************|\n"   
"\t  �����루1��2��3��0����"
;

//����һ��[min,max)֮����������
static int random_index(int min,int max) 
{ 
  return (int)(min+(double)rand()/(double)RAND_MAX*(max-min)); 
} 

//�����ʱ����������һ���� 
void exam_new_create(Examination* exam,Dictionary* dict)
{ 
  srand(time(NULL)); 
  int wordcount=dict->words.size();         
  int idx=random_index(0,wordcount); 
  exam->words.push_back(dict->words[idx]); 
  exam->meanings.push_back(dict->meanings[idx]); 
}

//Ӣ���ʵ临ϰ���� 
void review_english_to_chinese()
{
  //װ�����ʱ� 
  dict_load(&dictionaries[ENGLISH_CHINESE],DICT_PATH DICT_NEW_ENGLISH_CHINESE);

  //���ɿ�����Ŀ 
  Examination exam; 
  exam_new_create(&exam,&dictionaries[ENGLISH_CHINESE]);
  
  for (int i=0;i<exam.words.size();i++)
  {
    CLEAR(); 
    cout<<"\n\n"; 
    cout<<"\t|********************************************|\n"; 
    meaning_display(exam.meanings[i]); 
    cout<<"\n"; 
    cout<<"\t|********************************************|\n"; 
    string word=get_input_string("\t ������Ӣ�Ĵ�(0 �˳�����");
    
    //cout << "\t ������Ӣ�Ĵ�(0 �˳��� ��"; 
    //string word; 
    //std::getline(cin, word); 
    if(word==exam.words[i])
    { 
      cout<<"\t ��ȷ������"<<endl; 
      string op=get_input_string("\t ������( 0 �����ʱ�ȥ��, ���� ��һ��)��");
	  cout<<endl; 
      if(op=="0"){ 
      remove_glossary(word); 
      string op=get_input_string("\t ������( 0 �˳�, ���� ��һ��)��");
      if(op=="0")
        { 
      	    break;
	    }
      } 
    }
    else if(word=="0"){ 
    break; 
    }
    else 
    {cout<<"\t ����,��������Ŷ"<<endl;
	  string op=get_input_string("\t ������( 0 �˳�, ���� ��һ��)��"); 
      if(op=="0"){
	  break;}    
    }
  }
}

//��Ӣ�ʵ临ϰ���� 
void review_chinese_to_english()
{
  //װ�����ʱ� 
  dict_load(&dictionaries[CHINESE_ENGLISH],DICT_PATH DICT_NEW_CHINESE_ENGLISH);

  //���ɿ�����Ŀ 
  Examination exam; 
  exam_new_create(&exam,&dictionaries[CHINESE_ENGLISH]);
  
  for (int i=0;i<exam.words.size();i++)
  {
    CLEAR(); 
    cout<<"\n\n"; 
    cout<<"\t|********************************************|\n"; 
    meaning_display(exam.meanings[i]); 
    cout<<"\n"; 
    cout<<"\t|********************************************|\n"; 
    string word=get_input_string("\t ���������Ĵ�(0 �˳�����");
    
    //cout << "\t ���������Ĵ�(0 �˳��� ��"; 
    //string word; 
    //std::getline(cin, word); 
    if(word==exam.words[i])
    { 
      cout<<"\t ��ȷ������"<<endl; 
      string op=get_input_string("\t ������( 0 �����ʱ�ȥ��, ���� ��һ��)��");
	  cout<<endl; 
      if(op=="0"){ 
      remove_glossary(exam.words[i]); 
      string op=get_input_string("\t ������( 0 �˳�, ���� ��һ��)��");
      if(op=="0")
        { 
      	    break;
	    }
      } 
    }
    else if(word=="0"){ 
    break; 
    }
    else 
    {cout<<"\t ����,��������Ŷ"<<endl;
	  string op=get_input_string("\t ������( 0 �˳�, ���� ��һ��)��"); 
      if(op=="0"){
	  break;}    
    }
  }
}

//����ʵ临ϰ���� 
void review_chengyudacidian()
{
  //װ�����ʱ� 
  dict_load(&dictionaries[CHENGYUDACIDIAN],DICT_PATH DICT_NEW_CHENGYUDACIDIAN);

  //���ɿ�����Ŀ 
  Examination exam; 
  exam_new_create(&exam,&dictionaries[CHENGYUDACIDIAN]);
  
  for (int i=0;i<exam.words.size();i++)
  {
    CLEAR(); 
    cout<<"\n\n"; 
    cout<<"\t|********************************************|\n"; 
    meaning_display_special(exam.meanings[i]); 
    cout<<"\n"; 
    cout<<"\t|********************************************|\n"; 
    string word=get_input_string("\t �������(0 �˳�����");
    
    //cout << "\t �������(0 �˳��� ��"; 
    //string word; 
    //std::getline(cin, word); 
    if(word==exam.words[i])
    { 
      cout<<"\t ��ȷ������"<<endl; 
      string op=get_input_string("\t ������( 0 �����ʱ�ȥ��, ���� ��һ��)��");
	  cout<<endl; 
      if(op=="0"){ 
      remove_glossary(exam.words[i]); 
      string op=get_input_string("\t ������( 0 �˳�, ���� ��һ��)��");
      if(op=="0")
        { 
      	    break;
	    }
      } 
    }
    else if(word=="0"){ 
    break; 
    }
    else 
    {cout<<"\t ����,��������Ŷ"<<endl;
	  string op=get_input_string("\t ������( 0 �˳�, ���� ��һ��)��"); 
      if(op=="0"){
	  break;}    
    }
  }
}

//ѡ��ϰ������
void review_ui() 
{
  CLEAR();
  cout<<review_ui_prompt;
  string op;
  std::getline(cin, op);
  if(op=="1"){
    review_english_to_chinese();
  }
  else if(op=="2"){
  	review_chinese_to_english();
  }
  else if(op=="3"){
  	review_chengyudacidian();
  }
  else if(op=="0"){
    return;
  }
  review_ui();
}
