#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LINE_LEN 50
#define MAX_WORD_LEN 49

/**
 *@author PT04
 *
 */
extern int maxLineLen;
extern int maxWordLen;
extern char spaceTable[4];
extern char input[100], output[100];
extern int alignText;
extern int alignLastLine;
extern char word[MAX_WORD_LEN + 1];
extern int wordLen;
extern char line[MAX_LINE_LEN + 1];
extern int lineLen;
extern int numWords;
extern int useInputFile;
extern int useOutputFile;
extern FILE *inputFile;
extern FILE *outputFile;

// setup

int NhapLuaChon(int,int);
// Chon so ki tu toi da tren mot dong
void SetMaxchar(int *maxLineLen);
// Chon ki tu phan cach
void SetSpace(char *spaceTable);
// Cai dat cach thu cai can le cho van ban
void SetAlignText(int *alignText);
// Cai dat cach can le cho dong cuoi dong
void SetAlignLastLine(int *alignLastLine);
//hoi ten unput file
void AskInput();
//hoi ten output file
void FirstSetUp();
// menu
// Ham in trang thai can le
void PrintAlignStatus(int alignStatus);
// Menu sua lai cai dat cac thuoc tinh
void Setting();




//  menu chinh
void PrintMainMenu(int *choose);
//xu li cac word
// Them tu
void AddWord(const char *word, char *line, int *lineLen);
// Ham kiem tra ki tu phan cach
int IsSpace(char ch);
//xu li, can chinh
// xoa 1 dong
void ClearLine(char *line, int *lineLen, int *numWords);


// Doc tu tu ban phim
void ReadWord_KeyBoard(char *word);
// Doc tu tu file
void ReadWord_File(char *word, FILE *p);
// cho ca 2 truong hop input
void ReadWord(char *word);


// Can giua va xuat ra file
void AlignMid_File(char *line, int lineLen, int numWords, FILE *q);
// Can trai va xuat ra file
void AlignLeft_File(char *line, int lineLen, int numWords, FILE *q);
// Can phai va xuat ra file
void AlignRight_File(char *line, int lineLen, int numWords, FILE *q);
// Ham ghi dong ra file
void WriteLine(char *line, int lineLen, int numWords, int option);










void AskOutput();
// Ham cai dat thuoc tinh ban dau
//ghi ket qua sau khi chay
void inKetQua();



