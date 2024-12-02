#pragma once
#include "MayTinh.h"
using namespace toLower;

class Desktop : public MayTinh
{
private:
	string loaiCase;
public:
	Desktop() : MayTinh(), loaiCase(""){}
	Desktop(const string& loai) : MayTinh(), loaiCase(loai){}
	~Desktop() override = default;
	// getter setter loaiCase
	void setLoaiCase(const string& loai) { loaiCase = loai; }
	string getLoaiCase() const { return loaiCase; }
	// nhap xuat
	void nhap() override {
		MayTinh::nhap();
		cout << "\nNhap loai case (dung / nam): "; getline(cin, loaiCase);
	}
	void xuat() const override {
		MayTinh::xuat();
		cout << "Loai case: " << loaiCase << endls;
		cout << "Thanh Tien: " << fixed << setprecision(2) << thanhTien() << " VND" << endls;
	}
	// thanh tien
	double thanhTien() const override {
		string loaiTolower = toLowerStr(loaiCase);
		if (loaiTolower == "dung") {
			return soLuong * giaTien;
		}
		else if (loaiTolower == "nam") {
			return soLuong * giaTien * 1.05;
		}
		return 0.0;
	}
	// clone
	Desktop* clone() const override {
		return new Desktop(*this);
	}
};

