#include "..\main\readWord.c"

/**
 *@author groupPT04
 *
 */
// tra ve 0 neu nguoi dung khong nhap vao gia tri thuoc [a, b]
int NhapLuaChon(int a, int b) {
	char temp[2];
	int choose, choose2, result;
	fflush(stdin);
	choose = getchar();
	if ((choose >= 48) && (choose <= 57)) {
		choose2 = getchar();
		if ((choose2 >= 48) && (choose2 <= 57)) {
			if (getchar() == 10) {
				result = (choose - 48) * 10 + choose2 - 48;
			} else {
				return 0;
			}
		} else if (choose2 == 10) {
			result = choose - 48;
		} else {
			return 0;
		}
	} else {
		return 0;
	}
	if ((result < a) || (result > b)) {
		return 0;
	} else {
		return result;
	}
}

// hoi file input
void AskInput() {
	int choose2;
	printf(
	    "\n___________________Chon cach thuc nhap van ban__________________");
	printf("\n1: Nhap tu ban phim.");
	printf("\n2: Nhap tu file.");
	while (1) {
		printf("\nNhap lua chon cua ban : ");
		choose2 = NhapLuaChon(1, 2);
		if (!choose2) {
			printf("Lua chon khong hop le! Vui long nhap lai! ");
		} else {
			break;
		}
	}
	// nhap tu ban phim
	if (choose2 == 1) {
		useInputFile = 0;
		printf("Luu y: De ket thuc nhap van ban, hay go lan luot "
		       "'Enter','|' va 'Enter'\n");
	}
	// nhap tu file
	if (choose2 == 2) {
		useInputFile = 1;
		while (1) {
			printf("\nNhap ten file de doc du lieu: ");
			fflush(stdin);
			gets(input);
			inputFile = fopen(input, "r");
			if (inputFile == NULL) {
				printf("File khong ton tai! Vui long nhap lai! ");
				continue;
			}
			inputFile = fopen(input, "r");
			ReadWord_File(word, inputFile);
			fclose(inputFile);
			if (strlen(word) == 0) {
				printf("File khong chu du lieu! Vui long nhap lai!");
			} else {
				inputFile = fopen(input, "r");
				break;
			}
		}
	}
	// mo file tam de ghi
	strcpy(output, "temp.txt");
	outputFile = fopen(output, "w");
}
