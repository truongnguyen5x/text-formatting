#include "..\header\header.h"

/**
 *@author groupPT04
 *
 */
char spaceTable[4] = {'\n', ' ', '\t'};  //array include whitespace
char word[MAX_WORD_LEN + 1];
char line[MAX_LINE_LEN + 1];
char input[100], output[100]; //input, output file name
int maxLineLen = 50;
int maxWordLen = 24;
int alignText = 1;
int alignLastLine = 2;
int wordLen;
int lineLen = 0;
int numWords = 0;
int useInputFile;  //use file of keyboard
int useOutputFile;  //use file of screen
FILE *inputFile;
FILE *outputFile;



