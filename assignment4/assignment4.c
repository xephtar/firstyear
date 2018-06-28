#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 10000
#define MAX_CHAR 200

struct instruction_s {
  int step;
  int index;
};

char* get_word(char* s, int n)
{
  int i = 0;
  while (s[i] != '\n') {
    s[i] = tolower(s[i]);
    i++;
  }
  char* p = strtok(s, " ;:.,!?\n\t\r");
  char* words[MAX_CHAR];
  int wordcounter = 1;
  while (p != NULL){
    words[wordcounter] = p;
    p = strtok (NULL, " .,!?\n\t\r");
    wordcounter++;
  }

  return words[n];

}

void get_sentence(char** lines, struct instruction_s* instructions,int n_instructions, char* sentence)
{
	int counter = 0;
	for(counter=0;counter<n_instructions;counter++)
	{
		char temp[20];
		strcpy(temp,get_word(lines[instructions[counter].step],instructions[counter].index));
		if(counter != n_instructions-1)
			strcat(temp, " ");
		strcat(sentence,temp);
	}
}


int main(int argc, char *argv[])
{

  // Takes lines and stores them into array
  char sentence_s[MAX_CHAR];
  char* line_s[MAX_LINE];
  FILE *fp = fopen(argv[1], "r");
  int lineN = 0;
  if (fp != NULL) {
    int i = 1;
    while (i < MAX_LINE && !feof(fp)) {
      line_s[i] = (char*) malloc(sizeof(char)*MAX_CHAR);
  		fgets(line_s[i],MAX_CHAR,fp);
  		i++;
      lineN++;
    }
    fclose(fp);
  } else {
    printf("There is no alice.txt\n");
  }



  //Takes instructions lines and stores them into array
  struct instruction_s instArr[20];
  int instN = 0;
  fp = fopen(argv[2], "r");
  if (fp != NULL ) {
    while (fscanf(fp, "%d %d", &instArr[instN].step, &instArr[instN].index) != EOF) {

      instN++;
    }
    fclose(fp);
  }


  //Addition of each steps
  for (int x = 0; x < instN; x++) {
    if (x > 0) {
      instArr[x].step = instArr[x].step + instArr[x-1].step;
    }
  }

  get_sentence(line_s,instArr,instN,sentence_s);
  printf("%s\n", sentence_s);
  for (int i = 1; i < lineN; i++) {
    free(line_s[i]);
  }

  return EXIT_SUCCESS;
}
