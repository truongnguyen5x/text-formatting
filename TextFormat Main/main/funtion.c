#include "..\input\variable.c"

/**
 *@author groupPT04
 *
 */
// Ham kiem tra ki tu phan cach
int IsSpace(char ch) {
	int i = 0;
	while (spaceTable[i] != '\0') {
		if (spaceTable[i] == ch)
			return 1;
		i++;
	}
	return 0;
}

// Them tu  vao dong
void AddWord(const char *word, char *line, int *lineLen) {
	if (*lineLen > 0) {
		line[*lineLen] = spaceTable[1];
		line[*lineLen + 1] = '\0';
		(*lineLen)++;
	}
	strcat(line, word);
	(*lineLen) += strlen(word);
	//printf("add word  in len %d  \n", *lineLen);
}

// Xoa dong
void ClearLine(char *line, int *lineLen, int *numWords) {
	line[0] = '\0';
	*lineLen = 0;
	*numWords = 0;
}
