#pragma once
#include "LapTop.h"
#include "Desktop.h"
#include "MayTinh.h"
using namespace toLower;

class CongTy
{
private:
	unsigned int soLuongMT;
	MayTinh** dsMayTinh;
	void clear() {
		for (unsigned int i = 0; i < soLuongMT; ++i)
			delete dsMayTinh[i];
		delete[] dsMayTinh;
	}
	static LapTop* toLapTop(MayTinh* may) {
		return dynamic_cast<LapTop*>(may);
	}
	static Desktop* toDesktop(MayTinh* may) {
		return dynamic_cast<Desktop*>(may);
	}
public:
	CongTy() : soLuongMT(0), dsMayTinh(nullptr){}
	CongTy(unsigned int sl, MayTinh** const& listMayTinh) : soLuongMT(sl) {
		dsMayTinh = new MayTinh * [soLuongMT];
		transform(listMayTinh, listMayTinh + sl, dsMayTinh,
			[](MayTinh* may) {
				return may->clone();
			});
	}
	~CongTy() { 
		clear();
	}
	// getter setter
	// số lượng
	unsigned int getSoLuongMT() const { return soLuongMT; }
	void setSoLuongMT(unsigned int sl) { soLuongMT = sl; }
	// dsMayTinh
	MayTinh** getDSMayTinh() const { return dsMayTinh; }
	void setDSMayTinh(unsigned int sl, MayTinh** const& listMayTinh) {
		if (dsMayTinh) {
			clear();
			dsMayTinh = nullptr;
		}
		soLuongMT = sl;
		dsMayTinh = new MayTinh * [soLuongMT];
		transform(listMayTinh, listMayTinh + sl, dsMayTinh,
			[](MayTinh* may) {
				return may->clone();
			});
	}
	// nhập xuất
	void nhap() {
		cout << "\nNhap so luong: "; cin >> soLuongMT; cin.ignore();
		if (soLuongMT == 0) return;
		if (dsMayTinh) {
			clear();
			dsMayTinh = nullptr;
		}
		dsMayTinh = new MayTinh * [soLuongMT];
		for (int i = 0; unsigned int(i) < soLuongMT; ++i) {
			string loai;
			cout << "\nNhap Loai may tinh (Desktop / LapTop): ";
			getline(cin, loai);
			loai = toLowerStr(loai);
			if (loai == "desktop") {
				dsMayTinh[i] = new Desktop();
			}
			else if (loai == "laptop") {
				dsMayTinh[i] = new LapTop();
			}
			else {
				cout << "\nNhap sai loai!" << endls;
				--i;
				continue;
			}
			dsMayTinh[i]->nhap();
		}
	}
	void xuat() const {
		cout << "\nSo luong may tinh: " << soLuongMT << endls;
		for (unsigned int i = 0; i < soLuongMT; ++i) {
			dsMayTinh[i]->xuat();
			cout << "--------------" << endls;
		}
	}
	// tính tổng tiền cho từng loại
	double tongTienDesktop() const {
		if (soLuongMT == 0) return 0.0;
		double tong = 0.0;
		for (unsigned int i = 0; i < soLuongMT; ++i) {
			Desktop* desk = toDesktop(dsMayTinh[i]);
			if (desk) {
				tong += desk->thanhTien();
			}
		}
		return tong;
	}
	double tongTienLapTop() const {
		if (soLuongMT == 0) return 0.0;
		double tong = 0.0;
		for (unsigned int i = 0; i < soLuongMT; ++i) {
			LapTop* lap = toLapTop(dsMayTinh[i]);
			if (lap) {
				tong += lap->thanhTien();
			}
		}
		return tong;
	}
	//trung bình cộng đơn giá của desktop
	double tbcDonGiaDesktop() const {
		if (soLuongMT == 0) return 0.0;
		double tong = 0.0;
		unsigned int dem = 0;
		for (unsigned int i = 0; i < soLuongMT; ++i) {
			Desktop* desk = toDesktop(dsMayTinh[i]);
			if (desk) {
				tong += desk->getGiaTien();
				++dem;
			}
		}
		return (dem == 0) ? 0.0 : (tong / dem);
	}
	// tìm laptop hãng dell màu bạc min
	double minLapTopDellBac() const {
		if (soLuongMT == 0) return 0.0;
		double minDellBac = numeric_limits<double>::max();
		bool kiemTra = false;
		for (unsigned int i = 0; i < soLuongMT; ++i) {
			LapTop* lap = toLapTop(dsMayTinh[i]);
			if (lap != nullptr && toLowerStr(lap->getHangSanXuat()) == "dell") {
				if (toLowerStr(lap->getMauSac()) == "bac") {
					minDellBac = min(minDellBac, lap->thanhTien());
					kiemTra = true;
				}
			}
		}
		if (!kiemTra) return 0.0;
		return minDellBac;
	}

	MayTinh** listLapTopDellBacMin(unsigned int& slNew) const {
		double minDellBac = minLapTopDellBac();
		if (minDellBac == 0.0) return nullptr;
		slNew = 0;
		MayTinh** listLapTop = new MayTinh * [soLuongMT];
		for (unsigned int i = 0; i < soLuongMT; ++i) {
			LapTop* lap = toLapTop(dsMayTinh[i]);
			if (lap != nullptr && toLowerStr(lap->getHangSanXuat()) == "dell") {
				if (toLowerStr(lap->getMauSac()) == "bac"
					&& minDellBac == lap->thanhTien()) 
				{
					listLapTop[slNew++] = dsMayTinh[i];
				}
			}
		}
		return listLapTop;
	}
};

