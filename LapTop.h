#pragma once
#include "MayTinh.h"
using namespace toLower;

class LapTop : public MayTinh
{
private:
	string mauSac;
public:
	LapTop() : MayTinh(), mauSac("") {}
	LapTop(const string& mau) : MayTinh(), mauSac(mau) {}
	~LapTop() override = default;
	// getter setter mauSac
	void setMauSac(const string& loai) { mauSac = loai; }
	string getMauSac() const { return mauSac; }
	// nhap xuat
	void nhap() override {
		MayTinh::nhap();
		cout << "\nNhap mau May tinh: "; getline(cin, mauSac);
	}
	void xuat() const override {
		MayTinh::xuat();
		cout << "Mau May tinh: " << mauSac << endls;
		cout << "Thanh Tien: " << fixed << setprecision(2) << thanhTien() << " VND" << endls;
	}
	// thanh tien
	double thanhTien() const override {
		string loaiTolower = toLowerStr(mauSac);
		if (loaiTolower == "bac") {
			return soLuong * giaTien * 1.03;
		}
		return soLuong * giaTien;
	}
	// clone
	LapTop* clone() const override {
		return new LapTop(*this);
	}
};