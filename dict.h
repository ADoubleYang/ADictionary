#ifndef _DICT_H
#define _DICT_H
#include <string>  
#include <vector>

//����ĺ궨�����֣��ʣ�������Ӧ���ļ�
#define DICT_PATH "E:\\CppPractice\\data\\" 
#define DICT_ENGLISH_CHINESE "english_chinese.18030.txt"
#define DICT_CHINESE_ENGLISH "chinese_english.18030.txt"
#define DICT_CHENGYUDACIDIAN "chengyudacidian.18030.txt"
#define DICT_XINHUAZIDIAN "xhzd.18030.txt" 

using namespace std;

//�ֵ�ṹ�� 
typedef struct
{
	string filename;
	bool loaded;
	vector<string>words;                //һ���ʵ�ܶ൥�ʣ���һ������
	vector< vector<string> >meanings;     //���ʵ����壬�͵�����һһ��Ӧ�� 
}Dictionary,New_Dictionary; 

//�����ܹ����ĸ��ʵ䣺Ӣ������Ӣ������ʵ䡢�»��ֵ� 
//ͬʱ����Ҳ���ĸ����ʱ� 
//extern��ʾ�����ڱ𴦶����һ����������������ǰʹ���� 
extern Dictionary dictionaries[4];
extern Dictionary unfamiliardictionaries[4]; 

//������Щ���ʾ�ֵ���� 1��Ӣ�� 2����Ӣ 3������ʵ� 4���»��ֵ� 
//�������Ϊ�����׼����Ҳ��׼Ǵ� 
#define ENGLISH_CHINESE 0 
#define CHINESE_ENGLISH 1 
#define CHENGYUDACIDIAN 2 
#define XINHUAZIDIAN    3 

//װ�شʿ�
void dict_load(Dictionary*dict,const string&filename); 

//���ֵ� 
vector<string>dict_lookup(Dictionary*dict,const string&word,bool&find);
vector<string>dict_lookup(Dictionary*dict,const string&word); 

//�������/���� ���� 
void meaning_display(const vector<string>&meaning); 
void meaning_display_special(const vector<string>&meaning);
void dict_ui();
void dict_ui_english_to_chinese();
void dict_ui_chinese_to_english();
void dict_ui_chengyudacidian(); 

#endif// !_DICT_H
