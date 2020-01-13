#ifndef _DICT_H
#define _DICT_H

#include<string>
#include<vector>
#include<iostream>

//����ĺ궨�����֣��ʣ�������Ӧ���ļ�
#define DICT_PATH "D:\\c\\src\\data\\" 
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
	vector<string>words;             //һ���ʵ�ܶ൥�ʣ���һ������ 
	vector< vector<string> >meanings;  //���ʵ����壬�͵�����һһ��Ӧ�� 
} Dictionary;
//�����ܹ���4���ִʵ䣺Ӣ������Ӣ������ʵ䡢�»��ֵ�
//ͬʱ����Ҳ���ĸ����ʱ�
//extern��ʾ�����ڱ𴦶����һ������������ֻ������ǰ��һ����
extern Dictionary dictionaries[4];
extern Dictionary unfamiliarDictionaries[4];
//������Щ���ʾ�ֵ����1Ӣ��2��Ӣ3����ʵ�4�»��ֵ�
//�������Ϊ�����׼����Ҳ��׳���
#define ENGLISH_CHINESE 0
#define CHINESE_ENGLISH 1
#define CHENGYUDACIDIAN 2
#define XINHUAZIDIAN    3


//װ�شʿ�
void dict_load(Dictionary* dict, const char* filename);
//���ֵ�
vector<string>dict_lookup(Dictionary* dict, const string& word, bool& find);
//�������/���� ����
void meaning_display(const vector<string>& meaning);
void meaning_display1(const vector<string>& meaning);
void dict_ui();
void dict_ui_english_to_chinese();
void dict_ui_chinese_to_english();
void dict_ui_chengyudacidian();
void dict_ui_xinhuazidian();
#endif // !_DICT_H 