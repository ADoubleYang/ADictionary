#ifndef _GLOSSARY_H
#define _GLOSSARY_H
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

#define DICT_PATH "E:\\CppPractice\\data\\"
#define DICT_NEW_ENGLISH_CHINESE "new_english_chinese.18030.txt"
#define DICT_NEW_CHINESE_ENGLISH "new_chinese_english.18030.txt"
#define DICT_NEW_CHENGYUDACIDIAN "new_chengyudacidian.18030.txt"
#define DICT_NEW_XINHUAZIDIAN "new_xhzd.18030.txt"

using namespace std;

//���ʱ��ṹ
struct Glossary
{
	string word;             //���� 
	vector<string> meaning;    //���ʽ��� 
};

//��������
extern int words_count;
extern vector<Glossary> glossary;

void load_glossary();
void save_glossary();
void remove_glossary(string word);

#endif/* glossary.h*/
