#include "..\header\header.h"

/**
 *@author groupPT04
 *
 */
// Doc tu tu ban phim
void ReadWord_KeyBoard(char *word) {
	int ch, pos = 0;
	ch = getchar();
	while (IsSpace(ch)) {
		ch = getchar();
	}
	while (!IsSpace(ch) && (ch != '|')) {
		word[pos] = (char)ch;
		pos++;
		if (pos == maxWordLen) {
			break;
		}
		ch = getchar();
	}
	if (pos == maxLineLen - 1) {
		word[pos] = '-';
		pos++;
	}
	word[pos] = '\0';
	// printf("|%s|va %d \n", word, strlen(word));
}

// Doc tu tu file
void ReadWord_File(char *word, FILE *p) {
	char ch, pos = 0;
	fscanf(p, "%c", &ch);
	while (IsSpace(ch) && (!feof(p))) {
		fscanf(p, "%c", &ch);
	}
	while (!IsSpace(ch) && (!feof(p)) && (pos < maxWordLen)) {
		if (!IsSpace(ch) && (pos < maxWordLen)) {
			word[pos] = ch;
			pos++;
			if (pos == maxWordLen) {
				break;
			}
		}
		fscanf(p, "%c", &ch);
	}
	if (pos == maxLineLen - 1) {
		word[pos] = '-';
		pos++;
	}
	word[pos] = '\0';
}

// tong hop 2  truong hop input
void ReadWord(char *word) {
	if (useInputFile) {
		ReadWord_File(word, inputFile);
	} else {
		ReadWord_KeyBoard(word);
	}
}
