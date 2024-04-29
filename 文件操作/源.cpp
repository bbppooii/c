#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
struct Stu
{
	char name[20];
	int age;
	float score;
};
int main()
{
	struct Stu s = {"zhangsan", 20, 90.5f};
	char a[10] = "qweasd";
	FILE* pfile;
	pfile = fopen("1.txt", "w");
	if (pfile == NULL)
	{
		perror("fopen");
		return 1;
	}
	fputc('d', pfile);
	fputs("fopen example", pfile);

	fclose(pfile);
	pfile = NULL;
	pfile = fopen("1.txt", "r");
	if (pfile == NULL)
	{
		perror("fopen");
		return 1;
	}
	rewind(pfile);
	int b = fgetc(pfile);
	fseek(pfile, 1, SEEK_SET);
	printf("%d\n", ftell(pfile));
	printf("%c", b);
	fgets(a, 5, pfile);
	fscanf(pfile, "%s %d %f", s.name, &(s.age), &(s.score));
	fprintf(pfile, "%s %d %.1f", s.name, s.age, s.score);
	fclose(pfile);
	pfile = NULL;
	return 0;
}