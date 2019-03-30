#include "input.c"

/**
 *@author groupPT04
 *
 */
// so ki tu toi da tren mot dong
void SetMaxchar(int *maxLineLen) {
	while (1) {
		printf("\nNhap so ki tu toi da tren mot dong (toi da 50, toi thieu la "
		       "20):\n ");
		*maxLineLen = NhapLuaChon(20, MAX_LINE_LEN);
		if (!(*maxLineLen)) {
			printf("So vua nhap khong hop le! Vui long nhap lai! ");
		} else {
			if (maxWordLen >= *maxLineLen) {
				maxWordLen = *maxLineLen - 1;
			}
			break;
		}
	}
}

// so ki tu toi da mot tu
void SetMaxcharInWord(int *maxWordLen) {
	while (1) {
		printf("\nNhap so ki tu toi da cua 1 tu (toi da %d, toi thieu la "
		       "5):\n ",
		       (maxLineLen - 1));
		*maxWordLen = NhapLuaChon(5, (maxLineLen - 1));
		if (!(*maxWordLen)) {
			printf("So vua nhap khong hop le! Vui long nhap lai! ");
		} else {
			break;
		}
	}
}

// Chon ki tu phan cach ghi vao spaceTable[1]
void SetSpace(char *spaceTable) {
	char ch;
	printf(
	    "\n___________________Chon ki tu la khoang trang :_________________");
	printf("\nLuu y: chuong trinh luon coi ki tu enter la ki tu phan cach");
	while (1) {
		printf("\nNhap 1 ki tu ban xem la khoang trang :");
		fflush(stdin);
		ch = getchar();
		if (ch == '\n') {
			printf("Ki tu khong hop le, vui long nhap lai!");
		} else {
			break;
		}
	}
	printf("Ban da coi ki tu \"%c\" la khoang trang", ch);
	if (ch == ' ') {
		spaceTable[1] = ' ';
		spaceTable[2] = '\t';
		spaceTable[3] = '\0';
	} else {
		spaceTable[1] = ch;
		spaceTable[2] = '\0';
	}
}

// cach can le cho van ban
void SetAlignText(int *alignText) {
	int ch;
	while (1) {
		printf("\n____________Chon cach thuc can le cho van "
		       "ban:__________________ ");
		printf("\n1: Can deu 2 ben\n2: Can trai\n3: Can phai");
		printf("\nNhap lua chon cua ban : ");
		ch = NhapLuaChon(1, 3);
		if (!ch) {
			printf("Lua chon khong hop le! Vui long nhap lai!");
		} else {
			*alignText = ch;
			break;
		}
	}
}

// cach can le cho dong cuoi dong
void SetAlignLastLine(int *alignLastLine) {
	int ch;
	while (1) {
		printf("\n_____________Chon cach thuc can le cho dong "
		       "cuoi:_______________ ");
		printf("\n1: Can deu 2 ben\n2: Can trai\n3: Can phai");
		printf("\nNhap lua chon cua ban : ");
		ch = NhapLuaChon(1,3);
		if (!ch) {
			printf("Lua chon khong hop le! Vui long nhap lai!");
		} else {
			*alignLastLine = ch;
			break;
		}
	}
}

//  cai dat thuoc tinh ban dau
void FirstSetUp() {
	printf("\nThiet lap cac gia tri ban dau cho chuong trinh : ");
	SetMaxchar(&maxLineLen);
	SetAlignText(&alignText);
	SetAlignLastLine(&alignLastLine);
	SetSpace(spaceTable);
}

// Ham in trang thai can le
void PrintAlignStatus(int alignStatus) {
	if (alignStatus == 1) {
		printf("can deu hai ben)");
	} else if (alignStatus == 2) {
		printf("can trai)");
	} else {
		printf("can phai)");
	}
}

// Menu sua lai cai dat cac thuoc tinh
void Setting() {
	int choose1;
	while (1) {
		// PrintMenu
		printf("\n_______________Tuy chinh cac thuoc tinh van "
		       "ban_________________ ");
		printf("\n1: Thiet lap so ki tu toi da tren mot dong (gia tri hien "
		       "tai la: %d)",
		       maxLineLen);
		printf("\n2: Tuy chon can chinh doan van (hien tai dang la ");
		PrintAlignStatus(alignText);
		printf("\n3: Tuy chon can chinh dong cuoi cung (hien tai dang la ");
		PrintAlignStatus(alignLastLine);
		printf("\n4: Tuy chon cac ki tu duoc coi la dau cach (hien tai co ma "
		       "ASCII %d)",
		       spaceTable[1]);
		printf("\n5: Chon so ki tu toi da cua mot tu (hien tai la %d)",
		       maxWordLen);
		printf("\n6: Tro ve menu chinh.");
		// Choose
		while (1) {
			printf("\nNhap lua chon cua ban : ");
			choose1 = NhapLuaChon(1,6);
			if (!choose1) {
				printf("Lua chon khong hop le! Vui long nhap lai!");
			} else {
				break;
			}
		}
		if (choose1 == 6) {
			break;
		}
		// Do choose
		switch (choose1) {
			case 1: {
				SetMaxchar(&maxLineLen);
				maxWordLen = maxLineLen - 1;
				break;
			}
			case 2: {
				SetAlignText(&alignText);
				break;
			}
			case 3: {
				SetAlignLastLine(&alignLastLine);
				break;
			}
			case 4: {
				SetSpace(spaceTable);
				break;
			}
			case 5: {
				SetMaxcharInWord(&maxWordLen);
				break;
			}
		}
	}
}
