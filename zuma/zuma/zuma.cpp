// zuma.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*

����
������һ����������ȫ�����Ϸ�����淨�ǣ���һ������ϳ�ʼ���������ɸ���ɫ���ӣ����������������ڵ����Ӳ�����ȫͬɫ��
�˺�����Է������ӵ�����ϲ�����ԭ�������С�һ�������������ͬɫ�����ӱ�����ڣ����Ǿͻ�������ʧ����������������ܻ�����ʽ����������㽫��ʱ���ܷ������ӡ�
���������׼��Ϊ���дһ����Ϸ���̵ĻطŹ��ߡ������Ѿ�����Ϸ������˹��̼�¼�Ĺ��ܣ����طŹ��ܵ�ʵ����ί��������ɡ�
��Ϸ���̵ļ�¼�У������ǹ���ϳ�ʼ���������У�Ȼ������ҽ�����������һϵ�в�������������ǣ��ڸ��β���֮��ʱ������µ��������С�

����
��һ����һ���ɴ�д��ĸ'A'~'Z'��ɵ��ַ�������ʾ����ϳ�ʼ���������У���ͬ����ĸ��ʾ��ͬ����ɫ��
�ڶ�����һ������n����ʾ�����طŹ��̹���n�β�����
��������n�����ζ�Ӧ�ڸ��β�����ÿ�β�����һ������k��һ����д��ĸ���������Կո�ָ���
���У���Ϊ�����ӵ���ɫ��������ǰ����m�����ӣ���k �� [0, m]��ʾ������Ƕ��֮����δ��������֮ǰ���ڹ���ϵ�λ��

���
�����n�У����θ������β������������漴��������������֮�����ϵ��������С�
����������û�����ӣ����ԡ�-����ʾ��
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
	//С��3������
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
	string zuma;//���봮,��������

	getline(cin, zuma);
	int size = zuma.size();

	cin >> oper;
	int *po;
	char *bead;
	//calloc()��������������,�ֱ�ΪԪ�ص���Ŀ��ÿ��Ԫ�صĴ�С,
	po = (int*)calloc(oper, sizeof(int));
	bead = (char*)calloc(oper, sizeof(char));

	for (int i = 0; i < oper; i++){
		cin >> po[i];
		cin >> bead[i];
	}

	for (int i = 0; i < oper; i++){
		zuma.insert(po[i], 1,bead[i]);
		//���������ݲ��룬�������Ƿ����������
		zuma = translation(zuma);
		if (zuma == "")
			cout << "-" << endl;
		else
			cout << zuma << endl;
		}

}

