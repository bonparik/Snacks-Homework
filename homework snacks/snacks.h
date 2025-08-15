#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Snack
{
public:
	Snack(string name);
	Snack(string name, int kkal, int price);

	string getName() const;
	void setName(const string value);
	int getKkal() const;
	void setKkal(int value);
	int getPrice() const;
	void setPrice(int value);

private:
	string Name;
	int Kkal;
	int Price;
};
class SnackSlot {
public:
	SnackSlot(int slotss);
	bool addSnack(Snack* snack); 
	int getSnackCount() const;
	~SnackSlot();
private:
	int slotss;
	vector <Snack*> snacks;
};
class VendingMachine {
public:
	VendingMachine(int slotCount);
	bool addSlot(SnackSlot* slot);
	int getEmptySlotsCount() const;
	~VendingMachine();
private:
	int maxSlots;
	vector <SnackSlot*> slots;
};

