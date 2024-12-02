#pragma once
#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;
#define endls "\n\n"

namespace toLower {
	string toLowerStr(const string& str) {
		string toLowerStrg = str;
		transform(toLowerStrg.begin(), toLowerStrg.end(), toLowerStrg.begin(), [](char a) {
			return tolower(a);
			});
		return toLowerStrg;
	}
}

class MayTinh
{
protected:
	unsigned int maMay;
	string nhanHieu;
	string hangSanXuat;
	unsigned short namSanXuat;
	double giaTien;
	unsigned int soLuong;
public:
	MayTinh() : maMay(0), nhanHieu(""), hangSanXuat(""), namSanXuat(0),
		giaTien(0.0), soLuong(0){}
	MayTinh(unsigned int maMay, string nhanHieu, string hangSanXuat, 
		unsigned short namSanXuat, double giaTien, unsigned int soLuong) :
		maMay(maMay), nhanHieu(nhanHieu), hangSanXuat(hangSanXuat), 
		namSanXuat(namSanXuat), giaTien(giaTien), soLuong(soLuong){}
	virtual ~MayTinh() = default;
	// getter setter
	// Mã máy
	void setMaMay(unsigned int maMay) { this->maMay = maMay; }
	unsigned int getMaMay() const { return maMay; }
	// Nhãn hiệu
	void setNhanHieu(const string& nhanHieu) { this->nhanHieu = nhanHieu; }
	string getNhanHieu() const { return nhanHieu; }
	// Hãng sản xuất
	void setHangSanXuat(const string& hangSanXuat) { this->hangSanXuat = hangSanXuat; }
	string getHangSanXuat() const { return hangSanXuat; }
	// Năm sản xuất
	void setNamSanXuat(unsigned short namSanXuat) { this->namSanXuat = namSanXuat; }
	unsigned short getNamSanXuat() const { return namSanXuat; }
	// Giá tiền
	void setGiaTien(double giaTien) { this->giaTien = giaTien; }
	double getGiaTien() const { return giaTien; }
	// Số lượng
	void setSoLuong(unsigned int soLuong) { this->soLuong = soLuong; }
	unsigned int getSoLuong() const { return soLuong; }
	// nhập xuất
	virtual void nhap() {
		cout << "\nNhap Ma May tinh: "; cin >> maMay; cin.ignore();
		cout << "\nNhap Nhan hieu: "; getline(cin, nhanHieu);
		cout << "\nNhap Hang san xuat: "; getline(cin, hangSanXuat);
		cout << "\nNhap Nam san xuat: "; cin >> namSanXuat;
		cout << "\nNhap Don gia: "; cin >> giaTien;
		cout << "\nNhap So Luong: "; cin >> soLuong;
		cin.ignore();
	}
	virtual void xuat() const {
		cout << "\nMa may tinh: " << maMay << endls;
		cout << "Nhan hieu: " << nhanHieu << endls;
		cout << "Hang san xuat: " << hangSanXuat << endls;
		cout << "Nam san xuat: " << namSanXuat << endls;
		cout << "Gia tien: " << fixed << setprecision(2) << giaTien << " VND" << endls;
		cout << "So luong: " << soLuong << endls;
	}
	virtual double thanhTien() const = 0;
	virtual MayTinh* clone() const = 0;
};

