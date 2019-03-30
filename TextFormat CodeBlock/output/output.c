#include "..\header\header.h"

/**
 *@author groupPT04
 *
 */
//hoi file output
void AskOutput() {
	fclose(outputFile);
	int choose2;
	printf("\n_________________Chon cach thuc xuat van ban____________________");
	printf("\n1: Xuat ra man hinh.");
	printf("\n2: Xuat ra file.");
	while (1) {
		printf("\nNhap lua chon cua ban : ");
		choose2 = NhapLuaChon(1,2);
		if (!choose2) {
			printf("Lua chon khong hop le! Vui long nhap lai! ");
		} else {
			break;
		}
	}
	//Xuat ra man hinh
	if(choose2==1) {
		useOutputFile=0;
	}
	//Xuat ra file
	if(choose2==2) {
		useOutputFile=1;
		while(1) {
			printf("Nhap ten file de ghi du lieu: ");
			fflush(stdin);
			gets(output);
			if(useInputFile&&(strcmp(input,output)==0)) {
				printf("File output trung ten file input!");
				continue;
			}
			break;
		}
	}
}

//in text da format, lay text tu file tam temp.txt
void inKetQua() {
	if(useInputFile) {
		fclose(inputFile);
	}
	FILE *p = fopen("temp.txt","r");
	char temp;
	fscanf(p, "%c", &temp);
	if(feof(p)) {
		printf("\nBan chua nhap van ban.");
		fclose(p);
		remove("temp.txt");
		return;
	}
	//xuat van ban
	if(useOutputFile) {
		FILE *out =fopen(output,"w");
		while(!feof(p)) {
			fprintf(out,"%c",temp);
			fscanf(p, "%c", &temp);
		}
		fclose(out);
	} else {
		printf("Van ban sau khi format la: \n\n");
		while(!feof(p)) {
			printf("%c", temp);
			fscanf(p, "%c", &temp);
		}
	}
	fclose(p);
	//xoa file tam
	remove("temp.txt");
}

