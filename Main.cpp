#include "CongTy.h"

int main() {
	CongTy congTy;
	congTy.nhap();
	congTy.xuat();
	cout << "\nTong thanh tien Desktop: " << fixed << setprecision(2) << congTy.tongTienDesktop() << " VND" << endls;
	cout << "\nTong thanh tien Lap Top: " << fixed << setprecision(2) << congTy.tongTienLapTop() << " VND" << endls;
	cout << "\nTrung Binh cong don gia Desktop: " << fixed << setprecision(2) << congTy.tbcDonGiaDesktop() << " VND" << endls;
	unsigned int slNew;
	MayTinh** listLapTop = congTy.listLapTopDellBacMin(slNew);
	if (listLapTop) {
		cout << "\nSo luong lap top tim duoc: " << slNew << endls;
		for (unsigned int i = 0; i < slNew; ++i) {
			listLapTop[i]->xuat();
			cout << "------------" << endls;
		}
	}
	else {
		cout << "\nKhong tim thay lap top nao!" << endls;
	}

	return 0;
}