#include "..\header\header.h"


int main() {
	//cai dat khi moi bat dau
	FirstSetUp();
	int choose;
	while (1) {
		//show menu chinh
		PrintMainMenu(&choose);
		if (choose == 3) {
			//thoat
			break;
		} else if (choose == 1) {
			//thay doi cai dat cho formatting
			Setting();
		} else {
			//hoi xem co su dung file khong
			AskInput();
			ClearLine(line, &lineLen, &numWords);
			while (1) {
				ReadWord(word);
				wordLen = strlen(word);
				if ((wordLen==0)&&(lineLen == 0)) {
					break;
				}
				//neu het tu, thi in dong cuoi
				if ((wordLen == 0) && (lineLen > 0)) {
					WriteLine(line, lineLen, numWords, alignLastLine);
					break;
				}
				//neu tu vuot qua dong, thi in dong, roi them tu vao dong moi
				if (((wordLen + 1 + lineLen) > maxLineLen)) {
					WriteLine(line, lineLen, numWords, alignText);
					ClearLine(line, &lineLen, &numWords);
				}
				//them tu vao dong
				AddWord(word, line, &lineLen);
				numWords++;
			}
			//chon cach xuat van ban
			AskOutput();
			//ket qua text da duoc format
			inKetQua();
		}
	}
	printf("-------------------Chuong trinh ket thuc!!!---------------------");
	getch();
	return 0;
}
