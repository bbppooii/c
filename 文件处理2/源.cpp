#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	FILE* pf = fopen("data.txt", "r");
	FILE* pw = fopen("data_copy.txt", "w");
	int ch = 0;
	while ((ch = fgetc(pf)) != EOF)
	{
		fputc(ch, pw);
	}
	fclose(pf);
	fclose(pw);
	return 0;
}