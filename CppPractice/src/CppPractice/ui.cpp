#include "ui.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>

using namespace std;

void pos(int x, int y);//ȷ�����λ��
void blue_border();//�߿���ɫ
void white_back();//����ɫ����
void cyan_choose();//������ɫ
void on_Select();//ѡ��ʱ��ʽ
void on_choose(int x, int y);//ȷ������
void star();//��ʼ������
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//��ȡ��׼������
void main_ui()
{
    system("color 7F");//���ÿ���̨������ɫ
    system("mode con cols=100 lines=40");/*��ʼ����������С*/
    SetConsoleTitle(L"OurProgram");
    cout << endl << "                             ";
    cout << "�������Ҽ����ƹ��ѡ�񣻿ո� ȷ��";

    blue_border();
    pos(5, 5);
    cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";
    pos(5, 25);
    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<";
    for (int i = 5, j = 6; j < 25; j++) //��߿�
    {
        pos(i, j);
        cout << "|";
    }
    for (int i = 85, j = 6; j < 25; j++) //�ұ߿�
    {
        pos(i, j);
        cout << "|";
    }

    cyan_choose();
    pos(65, 10);
    cout << "2. �ִʿ��� ";
    pos(25, 20);
    cout << "3. ���ʸ�ϰ ";
    pos(65, 20);
    cout << "4. �˳�ϵͳ ";
    on_Select();
    pos(25, 10);
    cout << "1. �ִʲ�ѯ ";

    //�������Ҽ����ƹ��Խ�������ѡ��
    int x = 25, y = 10;
    char sel;
    sel = _getch();
    while (sel != ' ')
    {
        star();
        switch (sel)
        {
        case 72:
            y = y - 10;
            break;
        case 80:
            y = y + 10;
            break;
        case 75:
            x = x - 40;
            break;
        case 77:
            x = x + 40;
            break;
        }
        //��ֹ������Χ
        if (x >= 65)
        { 
            x = 65;
        }
        if (y >= 20)
        {
            y = 20;
        }
        if (x <= 25)
        {
            x = 25;
        }
        if (y <= 10)
        {
            y = 10;
        }
        pos(x, y);
        on_choose(x, y);
        sel = _getch();
    }
    pos(0, 30);
    white_back();//��ԭĬ������
    CloseHandle(hOut);//�رձ�׼������;
    string op;
    std::getline(cin, op);
    if (op == " ")
    {
        if (x <= 60 && y == 10)
        {

        }
        if (x >=61 && y == 10)
        {

        }
        if (x <=60 && y == 20)
        {

        }
        if (x >=61 && y == 20)
        {
            return;
        }
    }
}
//���ù��λ��

void pos(int x, int y)
{
    COORD posPoint = { x,y }; //��������
    SetConsoleCursorPosition(hOut, posPoint);
}
void blue_border()
{
    WORD blue = FOREGROUND_GREEN | FOREGROUND_BLUE;
}
void white_back()
{
    WORD white = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY;
    SetConsoleTextAttribute(hOut, white);
}
void cyan_choose()
{
    WORD cyan = FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_BLUE;
    SetConsoleTextAttribute(hOut, cyan);
}
void on_Select()
{
    WORD select = FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_RED;
    SetConsoleTextAttribute(hOut, select);
}
void on_choose(int x, int y)
{
    if (x == 25 && y == 10)
    {
        on_Select();
        cout << "1. �ִʲ�ѯ ";
    }
    else if (x == 25 && y == 20)
    {
        on_Select();
        cout << "3. ���ʸ�ϰ ";
    }
    else if (x == 65 && y == 10)
    {
        on_Select();
        cout << "2. ���ʿ��� ";
    }
    else if (x == 65 && y == 20)
    {
        on_Select();
        cout << "4. �˳�ϵͳ ";
    }
}
//ѡ��ʱ��ʽ
void star()
{
    cyan_choose();
    pos(25, 10);
    cout << "1. �ִʲ�ѯ ";
    pos(65, 10);
    cout << "2. �ִʿ��� ";
    pos(25, 20);
    cout << "3. ���ʸ�ϰ ";
    pos(65, 20);
    cout << "4. �˳�ϵͳ ";
}
//��ʼ������
void init_console()
{
    system("mode con cole-64 lines=30");
    system("chcp 936");
    system("color f0");
    CLEAR();
}
//�μ�ui�����ʽ

const string main_ui_prompt =
"\n\n"
"\t|>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>|\n"
"\t|*                  ��ӭʹ�� �ҵĴʵ�               *|\n"
"\t|*---------------------------------------------------|\n"
"\t|*  ��ѡ��                                         |\n"
"\t|*           1 Ӣ���ʵ�                              |\n"
"\t|*           2 ��Ӣ�ʵ�                              |\n"
"\t|*           3 ����ʵ�                              |\n"
"\t|*           0 ������һ��                            |\n"
"\t|<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<|\n"
"\t    ������(1,2,3��0)"
"      ������:";
//�μ���ui����
