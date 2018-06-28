#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_ROW 10000
#define MAX_CHAR 200

// Author Umut Guvercin 150160045

char* get_word(char* s, int n)
{
	int counter = 0;
	int i = 0;
	int j = 0;
	static char word[20];
	for(i=0;i<MAX_CHAR;i++)
	{
		if(n-1 == counter)
		{
			if(ispunct(s[i]))
			{
				continue;
			}
			if(isalpha(s[i]) && !islower(s[i]))
			{
				s[i] = tolower(s[i]);
			}
			word[j] = s[i];
			j++;

		}
		if((s[i] == ' ' || s[i] == '\n') && s[i-1] != ' ')
		{
			counter++;
		}
	}
	word[j-1] = '\0';

	return word;
}

struct instruction_s {
int step;
int index;
};

void get_sentence(char** lines, struct instruction_s* instructions,int n_instructions, char* sentence)
{
	int i = 0;
	for(i=0;i<n_instructions;i++)
	{
		char word2[20];
		strcpy(word2,get_word(lines[(instructions+i)->step-1],(instructions+i)->index));
		if(i != n_instructions-1)
			strcat(word2, " ");
		strcat(sentence,word2);
	}
}


int main(int argc, char *argv[])
{
	FILE* bookfile = NULL;
	FILE* instructionfile = NULL;
	int i = 0;
	char* bookholder[MAX_ROW];
	char sentence[MAX_CHAR];
	struct instruction_s instructions[20];
	
	bookfile = fopen(argv[1], "r");
	instructionfile = fopen(argv[2], "r");
	
	
	while(i < MAX_ROW && !feof(instructionfile))
	{
		int a;
		int b;
		fscanf(instructionfile,"%d %d", &a, &b);
		if(i>0)
		{
			(instructions+i)->step = (instructions+i-1)->step + a;
		}
		else
		{
		(instructions+i)->step = a;
		}
		(instructions+i)->index = b;
		i++;
	}
	int n = i-1;
	i = 0;
	while(i < MAX_ROW && !feof(bookfile))
	{
		bookholder[i] = (char*) malloc(sizeof(char)*MAX_CHAR);
		fgets(bookholder[i],MAX_CHAR,bookfile);
		i++;
	}

	get_sentence(bookholder,instructions,n,sentence);
	printf("%s\n", sentence);
	
	fclose(bookfile);
	fclose(instructionfile);

	return 0;
}

