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
	string a = "[000005]小小 - 谭艳\n[000074]词：方文山\n[000150]曲：周杰伦\n[001954]回忆像个说书的人\n[002352]用充满乡音的口吻\n[002744]跳过水坑 绕过小村\n[003152]等相遇的缘分\n[003542]你用泥巴捏一座城\n[003942]说将来要娶我进门\n[004339]转多少身 过几次门\n[004727]虚掷青春\n[005147]小小的誓言还不稳\n[005544]小小的泪水还在撑\n[005912]稚嫩的唇 在说离分\n[010666]我的心里从此住了一个人\n[011114]曾经模样小小的我们\n[011509]那年你搬小小的板凳\n[011901]为戏入迷我也一路跟\n[012279]我在找那个故事里的人\n[012698]你是不能缺少的部分\n[013106]你在树下小小的打盹\n[013499]小小的我傻傻等\n[021549]回忆像个说书的人\n[021948]用充满乡音的口吻\n[022350]跳过水坑 绕过小村\n[022749]等相遇的缘分\n[023143]你用泥巴捏一座城\n[023545]说将来要娶我进门\n[023942]转多少身 过几次门\n[024318]虚掷青春\n";
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