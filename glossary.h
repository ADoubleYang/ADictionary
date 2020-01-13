#ifndef _GLOSSARY_H
#define _GLOSSARY_H

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

#define GLOSSARY_FILE "glossry.txt"

using namespace std;
//���ʱ��ṹ��
struct Glossary
{
	string word;             //���� 
	vector<string>means;      //���ʽ��� 
};
//��������
extern int words_count;
extern vector <Glossary> glossary;

void load_glossary();
void save_glossary();
void remove_glossary(string word);

#endif // !_GLOSSSARY_HPP