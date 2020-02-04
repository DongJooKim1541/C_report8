#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_SIZE 3
#define MAX_SIZE 10
#define WORD_MAX 45

void Input_words(struct words *p1);
int Convert_words(struct words *p2);
int Char_to_int(char c);
void Output_words(struct words *p3);

struct words {
	char e_words[WORD_MAX + 1];//진폐증이란 단어가 45자임
	int grade_sum;
};

int main() {

	int i, j, max;
	int number = 1;
	struct words list[MAX_SIZE];
	struct words temp[MAX_SIZE];
	char dec[30] = { "=============================" };

	FILE *fp = NULL;//파일입출력 사용
	fopen_s(&fp, "Words and grades.txt", "w");

	printf("단어 %d개를 입력하시오\n", INPUT_SIZE);

	strcpy_s(list[3].e_words, WORD_MAX + 1, "Hard Work");
	strcpy_s(list[4].e_words, WORD_MAX + 1, "Knowledge");
	strcpy_s(list[5].e_words, WORD_MAX + 1, "Love");
	strcpy_s(list[6].e_words, WORD_MAX + 1, "Luck");
	strcpy_s(list[7].e_words, WORD_MAX + 1, "Money");
	strcpy_s(list[8].e_words, WORD_MAX + 1, "Leadership");
	strcpy_s(list[9].e_words, WORD_MAX + 1, "Attitude");

	Input_words(&list);

	for (i = 0; i < MAX_SIZE - 1; i++) {
		max = i;

		for (j = i + 1; j < MAX_SIZE; j++) {
			if (list[j].grade_sum > list[max].grade_sum) {
				max = j;
			}
		}
		temp[i] = list[i];
		list[i] = list[max];
		list[max] = temp[i];
	}

	Output_words(&list);
	fprintf(fp, "%s\n", "인생의 점수중 가장 높은 것?");
	fprintf(fp, "%s\n", dec);
	for (i = 0; i < MAX_SIZE; i++) {
		fprintf(fp, "%d. %s(%d points)\n", number, list[i].e_words, list[i].grade_sum);
		number++;
	}
	fprintf(fp, "%s\n", dec);
	fclose(fp);


	return 0;
}

void Input_words(struct words *p1) {

	int i;
	struct words *p2;
	p2 = p1;
	for (i = 0; i < INPUT_SIZE; i++) {
		gets(p1->e_words);
		p1++;
	}

	for (i = 0; i < MAX_SIZE; i++) {
		p2->grade_sum = Convert_words(p2);
		p2++;
	}
}

int Convert_words(struct words *p2) {

	int i;
	int sum = 0;
	char words[WORD_MAX + 1];
	int words_to_num[WORD_MAX + 1];

	strcpy_s(words, WORD_MAX + 1, p2->e_words);

	for (i = 0; i < WORD_MAX; i++) {
		if (words[i] == 'NULL')break;
		words_to_num[i] = Char_to_int(words[i]);
	}

	for (i = 0; i < WORD_MAX; i++) {
		sum = sum + words_to_num[i];
	}

	return sum;
}

int Char_to_int(char c) {

	int parameter;

	if (c >= 'a' && c <= 'z') {
		parameter = c - 'a' + 1;
	}
	else if (c >= 'A' && c <= 'Z') {
		parameter = c - 'A' + 1;
	}
	else {
		return 0;
	}

	return parameter;
}

void Output_words(struct words *p3) {

	int i;
	int number = 1;

	for (i = 0; i < MAX_SIZE; i++) {
		printf("%d. %s(%d points)\n", number, p3->e_words, p3->grade_sum);
		number++;
		p3++;

	}
}