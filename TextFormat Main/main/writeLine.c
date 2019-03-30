#include "..\output\output.c"

/**
 *@author groupPT04
 *
 */
// Can giua va xuat ra file
void AlignMid_File(char *line, int lineLen, int numWords, FILE *q) {
	int i;
	int extraSpaces, spacesToInsert, j;
	extraSpaces = maxLineLen - lineLen;
	for (i = 0; i < lineLen; i++) {
		if (line[i] != spaceTable[1])
			fprintf(q, "%c", line[i]);
		else {
			spacesToInsert = extraSpaces / (numWords - 1);
			for (j = 1; j <= (spacesToInsert + 1); j++)
				fprintf(q, "%c", spaceTable[1]);
			extraSpaces -= spacesToInsert;
			numWords--;
		}
	}
	fprintf(q, "\n");
	//printf("write in lineLen %d va numWord %d \n", lineLen, numWords);
}

// Can trai va xuat ra file
void AlignLeft_File(char *line, int lineLen, int numWords, FILE *q) {
	int i = 0;
	fputs(line, q);
	for (i = lineLen; i < maxLineLen; i++)
		fprintf(q, "%c", spaceTable[1]);
	fprintf(q, "\n");
	//printf("write in lineLen %d va numWord %d \n", lineLen, numWords);
}

// Can phai va xuat ra file
void AlignRight_File(char *line, int lineLen, int numWords, FILE *q) {
	int i = 0;
	while (line[i] != '\0') {
		i++;
	}
	i--;
	while (line[i] == spaceTable[1]) {
		line[i] = '\0';
		lineLen--;
	}
	int extraSpaces = maxLineLen - lineLen;
	for (i = 0; i < extraSpaces; i++)
		fprintf(q, "%c", spaceTable[1]);
	fputs(line, q);
	fprintf(q, "\n");
	//printf("write in lineLen %d va numWord %d \n", lineLen, numWords);
}

// Ham ghi dong ra file
void WriteLine(char *line, int lineLen, int numWords, int option) {
	if (lineLen) {
		if (option == 1) {
			AlignMid_File(line, lineLen, numWords, outputFile);
		} else if (option == 2) {
			AlignLeft_File(line, lineLen, numWords, outputFile);
		} else {
			AlignRight_File(line, lineLen, numWords, outputFile);
		}
	}
}
