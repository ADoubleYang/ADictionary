#ifndef _DICT_H
#define _DICT_H
#include <string>
#include <vector>                                                                                                                                                                                                                                                                                                                        
#define file_location "E:\\���\\C++����\\CppPractice\\data\\"
#define DICT_ENGLISH_CHINESE "english_chinese.18030.txt" 
#define DICT_CHINESE_ENGLISH "chinese_english.18030.txt"
#define IDIOMS_DICT_FILE "chengyudacidian.18030.txt"

using namespace std;


// �ֵ�ṹ��
typedef struct
{
	string filename;
	bool loaded;
	vector<string> words; // һ���ʵ�ܶ൥�ʣ���һ������ 
	vector< vector<string> > meanings; // ���ʵ����壬�͵�����һһ��Ӧ�� 
}Dictionary;

// �����ܹ��� 3 ���ִʵ䣺Ӣ������Ӣ������ʵ�
// ͬʱ����Ҳ���������ʱ� 
extern Dictionary dictionaries[4];
extern Dictionary unfamiliarDictionaries[4];
// �������Щ���ʾ�ֵ���� 1 Ӣ����2 ��Ӣ��3 ����ʵ䡢4 �»��ֵ� 
// �������Ϊ�����׼����Ҳ��׳���
#define ENGLISH_CHINESE 0 
#define CHINESE_ENGLISH 1 
#define CHENGYUCIDIAN 2 
#define XINGHUAZIDIAN 3
//װ�شʿ� 

void idioms_dict();
//���غ���
void dict_load(Dictionary* dict, const string& filename);
//���ֵ� 
vector<string> dict_lookup(Dictionary* dict, const string& word, bool& find);
////�������/���� ����
//void meaning_display(const vector<string>& meaning);
void dict_ui();
void dict_ui_mean_of_idiom();

#endif // !_DICT_H