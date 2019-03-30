#include "..\header\header.h"

/**
 *@author groupPT04
 *
 */
// Ham in va chon menu chinh
void PrintMainMenu(int *choose) {
	printf("\n\n_____________________________MENU_______________________________");
	printf("\n1: Tuy chon cac thuoc tinh van ban.\n2: Can le mot van ban.\n3: Thoat.");

	// Choose Menu
	while (1) {
		printf("\nNhap lua chon cua ban :");
		*choose = NhapLuaChon(1,3);
		if (!(*choose)) {
			printf("Lua chon khong hop le, vui long nhap lai!");
		} else {
			break;
		}
	}
}



