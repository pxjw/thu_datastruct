// RangeFind.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include<stdlib.h>
#include<stdio.h>
int a[500000];

int find_left(int l, int r, int v) {
	if (l == r) {
		return l;
	}

	int mid = (l + r) / 2;

	if (a[mid] < v) {
		return find_left(mid + 1, r, v);
	}

	else {
		return find_left(l, mid, v);
	}

}



int find_right(int l, int r, int v) {
	if (l == r) {
		return l;
	}

	int mid = (l + r + 1) / 2;

	if (a[mid] > v) {
		return find_right(l, mid - 1, v);
	}

	else {
		return find_right(mid, r, v);

	}

}



void swap(int& a, int& b) {

	int t = a;

	a = b;

	b = t;

}

void qsort(int s[], int l, int r)

{

	int i, j, x;

	if (l < r)

	{
		i = l;
		j = r;
		x = s[i];
		while (i < j)

		{
			while (i < j && s[j] > x) j--;
			if (i < j) s[i++] = s[j];
			while (i < j && s[i] < x) i++;
			if (i < j) s[j--] = s[i];

		}

		s[i] = x;
		qsort(s, l, i - 1);
		qsort(s, i + 1, r);

	}

}

int main() {

	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}

	//sort(a,a+n);
	qsort(a, 0, n - 1);

	//for(int i=0;i

	//printf("a: %d i: %d\n",a[i],i);
	for (int i = 0; i < m; ++i) {
		int l, r;
		scanf("%d %d", &l, &r);

		if (l > r) {
			swap(l, r);
		}

		if (l > a[n - 1] || r < a[0]) {
			printf("0\n");
		}

		else {
			printf("%d\n", find_right(0, n - 1, r) - find_left(0, n - 1, l) + 1);
		}

	}
	return 0;
}


