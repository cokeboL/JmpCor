#include "Cor.h"
#include <thread>
#include <stdio.h>
#include <iostream>
#include <windows.h>



void foo(int n)
{
	Sleep(10);
	printf("foo over--- %d\n", n);
}



int main()
{
	for (int i = 1; i <= 10; i++)
		ThreadCor(foo, i);

	for (int i = 1; i <= 10; i++)
		SyncCor(foo, i);

	getchar();
}