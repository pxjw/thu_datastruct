// zuma.cpp : 定义控制台应用程序的入口点。
//

/*

描述
祖玛是一款曾经风靡全球的游戏，其玩法是：在一条轨道上初始排列着若干个彩色珠子，其中任意三个相邻的珠子不会完全同色。
此后，你可以发射珠子到轨道上并加入原有序列中。一旦有三个或更多同色的珠子变成相邻，它们就会立即消失。这类消除现象可能会连锁式发生，其间你将暂时不能发射珠子。
开发商最近准备为玩家写一个游戏过程的回放工具。他们已经在游戏内完成了过程记录的功能，而回放功能的实现则委托你来完成。
游戏过程的记录中，首先是轨道上初始的珠子序列，然后是玩家接下来所做的一系列操作。你的任务是，在各次操作之后及时计算出新的珠子序列。

输入
第一行是一个由大写字母'A'~'Z'组成的字符串，表示轨道上初始的珠子序列，不同的字母表示不同的颜色。
第二行是一个数字n，表示整个回放过程共有n次操作。
接下来的n行依次对应于各次操作。每次操作由一个数字k和一个大写字母Σ描述，以空格分隔。
其中，Σ为新珠子的颜色。若插入前共有m颗珠子，则k ∈ [0, m]表示新珠子嵌入之后（尚未发生消除之前）在轨道上的位序。

输出
输出共n行，依次给出各次操作（及可能随即发生的消除现象）之后轨道上的珠子序列。
如果轨道上已没有珠子，则以“-”表示。
*/
#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
string translation(string a){
	int size = a.size();
	//小于3则不消除
	if (size < 3)
		return a;
	int i = 2;
	while (i < size){
		if ((a[i - 2] == a[i - 1] && (a[i - 1] == a[i]))){
			int j = i;
			while ((j + 1) < size){
				j = j + 1;
				if (a[j - 1 != a[j]])
					break;
			}
			int count;
			if (i == j)
				count = 3;
			else if (a[i - 1] == a[j])
				count = j - i + 3;
			else
				count = j - i + 2;
			a = a.erase(i - 2, count);
			size = a.size();
			if (size < 3)
				return a;
			i -= 2;
			if (i < 2)
				i = 2;
		}
		else
			i++;
	}
	return a;
}
int main(){
	int oper;
	string zuma;//输入串,珠子序列

	getline(cin, zuma);
	int size = zuma.size();

	cin >> oper;
	int *po;
	char *bead;
	//calloc()函数有两个参数,分别为元素的数目和每个元素的大小,
	po = (int*)calloc(oper, sizeof(int));
	bead = (char*)calloc(oper, sizeof(char));

	for (int i = 0; i < oper; i++){
		cin >> po[i];
		cin >> bead[i];
	}

	for (int i = 0; i < oper; i++){
		zuma.insert(po[i], 1,bead[i]);
		//将序列内容插入，并运算是否消除并输出
		zuma = translation(zuma);
		if (zuma == "")
			cout << "-" << endl;
		else
			cout << zuma << endl;
		}

}

