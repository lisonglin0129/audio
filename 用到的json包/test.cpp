#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <stdlib.h>
using  namespace std;
struct  lrcTable
{
		int Time;
		char *Lrc;
		struct lrcTable *next;  
}lrcTable;
typedef struct lrcTable Table;
void seach(int seachValue)
{
	Table *slrc, *lrc = NULL;
	slrc = (Table *)malloc(sizeof(lrcTable));
	slrc->next = NULL;
	string a = "[000005]СС - ̷��\n[000074]�ʣ�����ɽ\n[000150]�����ܽ���\n[001954]�������˵�����\n[002352]�ó��������Ŀ���\n[002744]����ˮ�� �ƹ�С��\n[003152]��������Ե��\n[003542]���������һ����\n[003942]˵����ҪȢ�ҽ���\n[004339]ת������ ��������\n[004727]�����ഺ\n[005147]СС�����Ի�����\n[005544]СС����ˮ���ڳ�\n[005912]���۵Ĵ� ��˵���\n[010666]�ҵ�����Ӵ�ס��һ����\n[011114]����ģ��СС������\n[011509]�������СС�İ��\n[011901]ΪϷ������Ҳһ·��\n[012279]�������Ǹ����������\n[012698]���ǲ���ȱ�ٵĲ���\n[013106]��������СС�Ĵ���\n[013499]СС����ɵɵ��\n[021549]�������˵�����\n[021948]�ó��������Ŀ���\n[022350]����ˮ�� �ƹ�С��\n[022749]��������Ե��\n[023143]���������һ����\n[023545]˵����ҪȢ�ҽ���\n[023942]ת������ ��������\n[024318]�����ഺ\n";
	string temp="";
	string pro = "", nexts ="",pos="";
	for (int i = 0; i <a.size(); i++)
	{
			temp += a.at(i);
			if (a.at(i) == '\n') {
					lrc = (Table *)malloc(sizeof(lrcTable));
					lrc->Time = atoi(temp.substr(1, 6).c_str());
					lrc->Lrc = (char *)malloc(temp.size()*sizeof(char));
					sprintf(lrc->Lrc, "%s", temp.substr(8, temp.size()).c_str());
					lrc->next = slrc->next;
					slrc->next = lrc;
					temp = "";
			}
	}
}