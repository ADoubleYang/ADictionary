#include "exam.h"
#include "ui.h"
#include <iostream>
#include <string>
#include "stdlib.h"
#include "time.h"
using namespace std;

static const string exam_ui_prompt=
"\n\n"
"\t|********************************************|\n"
"\t|*   ��ѡ�������                         *|\n"
"\t|********************************************|\n"
"\t|*            1 ������дӢ��                *|\n"
"\t|*            2 ��Ӣ��д����                *|\n"
"\t|*            3 ������д����                *|\n" 
"\t|*            0 �����ϼ�                    *|\n" 
"\t|********************************************|\n"   
"\t  �����루1��2��3��0����"
;

//����һ��[min,max)֮����������
static int random_index(int min,int max) 
{ 
  return (int)(min+(double)rand()/(double)RAND_MAX*(max-min)); 
} 

//���ֵ����������һ���Ծ�
void exam_create(Examination* exam,Dictionary* dict)
{ 
  srand(time(NULL)); 
  int wordcount=dict->words.size(); 
  int itemcount=wordcount<10?wordcount:10;        
  for(int i=0;i<itemcount;i++) 
  { 
    int idx=random_index(0,wordcount); 
    exam->words.push_back(dict->words[idx]); 
    exam->meanings.push_back(dict->meanings[idx]); 
  } 
}

//������дӢ�� 
void exam_ui_english_for_chinese()
{
  //װ�شʿ� 
  dict_load(&dictionaries[ENGLISH_CHINESE],DICT_PATH DICT_ENGLISH_CHINESE);

  //���ɿ�����Ŀ 
  Examination exam; 
  exam_create(&exam,&dictionaries[ENGLISH_CHINESE]);
  
  //����һ��������ͳ����ȷ���� 
  int correct_num;

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
       correct_num++;
       cout<<"\t ��ȷ������"<<endl; 
       string op=get_input_string("\t ������( 0 �˳�, ���� ��һ��)��"); 
       if(op=="0"){ 
       break; 
       } 
    }
    else if(word=="0"){ 
      break; 
    }
    else{
      cout<<"\t ����,��������Ŷ"<<endl;
	  string op=get_input_string("\t ������( 0 �˳�, ���� ��һ��)��"); 
      if(op=="0"){
	  break;}    
    }
  } 
  cout<<"\t ���ο��Եĳɼ�(����100)�ǣ�"<<correct_num*10<<endl;
  cout<<"\t "<<endl;
  string op=get_input_string("\t ������(����� �˳�)��");  
}

//��Ӣ��д���� 
void exam_ui_chinese_for_english()
{
  //װ�شʿ� 
  dict_load(&dictionaries[CHINESE_ENGLISH],DICT_PATH DICT_CHINESE_ENGLISH);

  //���ɿ�����Ŀ 
  Examination exam; 
  exam_create(&exam,&dictionaries[CHINESE_ENGLISH]);
  
  //����һ��������ͳ����ȷ���� 
  int correct_num;

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
       correct_num++;
       cout<<"\t ��ȷ������"<<endl; 
       string op=get_input_string("\t ������( 0 �˳�, ���� ��һ��)��"); 
       if(op=="0"){ 
       break; 
       } 
    }
    else if(word=="0"){ 
      break; 
    }
    else{
      cout<<"\t ����,��������Ŷ"<<endl;
	  string op=get_input_string("\t ������( 0 �˳�, ���� ��һ��)��"); 
      if(op=="0"){
	  break;}    
    }
  } 
  cout<<"\t ���ο��Եĳɼ�(����100)�ǣ�"<<correct_num*10<<endl;
  cout<<"\t "<<endl;
  string op=get_input_string("\t ������(����� �˳�)��");  
}

//������д���� 
void exam_ui_chengyudacidian()
{
  //װ�شʿ� 
  dict_load(&dictionaries[CHENGYUDACIDIAN],DICT_PATH DICT_CHENGYUDACIDIAN);

  //���ɿ�����Ŀ 
  Examination exam; 
  exam_create(&exam,&dictionaries[CHENGYUDACIDIAN]);
  
  //����һ��������ͳ����ȷ���� 
  int correct_num;

  for (int i=0;i<exam.words.size();i++)
  { 
    CLEAR(); 
    cout<<"\n\n"; 
    cout<<"\t|********************************************|\n"; 
    meaning_display_special(exam.meanings[i]); 
    cout<<"\n"; 
    cout<<"\t|********************************************|\n"; 
    string word=get_input_string("\t ���������Ĵ�(0 �˳�����");
    
    //cout << "\t ���������Ĵ�(0 �˳��� ��"; 
    //string word; 
    //std::getline(cin, word); 
    if(word==exam.words[i])
    { 
       correct_num++;
       cout<<"\t ��ȷ������"<<endl; 
       string op=get_input_string("\t ������( 0 �˳�, ���� ��һ��)��"); 
       if(op=="0"){ 
       break; 
       } 
    }
    else if(word=="0"){ 
      break; 
    }
    else{
      cout<<"\t ����,��������Ŷ"<<endl;
	  string op=get_input_string("\t ������( 0 �˳�, ���� ��һ��)��"); 
      if(op=="0"){
	  break;}    
    }
  } 
  cout<<"\t ���ο��Եĳɼ�(����100)�ǣ�"<<correct_num*10<<endl;
  cout<<"\t "<<endl;
  string op=get_input_string("\t ������(����� �˳�)��");  
}

void exam_ui() 
{
  CLEAR();
  cout<<exam_ui_prompt;
  string op;
  std::getline(cin, op);
  if(op=="1"){
  exam_ui_english_for_chinese();
  }
  else if(op=="2"){
  exam_ui_chinese_for_english();
  }
  else if(op=="3"){
  exam_ui_chengyudacidian();
  }
  else if(op=="0"){
  return;
  }
  exam_ui();
}
