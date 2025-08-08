# Snacks-Homework
snacks.h

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


snacks.cpp

#include "snacks.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Snack::Snack(string name) : Name(name), Kkal(0), Price(0) {}
Snack::Snack(string name, int kkal, int price) : Name(name), Kkal(kkal), Price(price) {}


string Snack::getName() const 
{ 
	return Name; 
}
void Snack::setName(const string value)
{ 
	Name = value; 
}

int Snack::getKkal() const 
{ 
	return Kkal; 
}
void Snack::setKkal(int value) 
{ 
	Kkal = value; 
}

int Snack::getPrice() const 
{ 
	return Price; 
}
void Snack::setPrice(int value) 
{ 
	Price = value; 
}

SnackSlot::SnackSlot(int slotss) : slotss(slotss) {}

bool SnackSlot::addSnack(Snack* snack) {
	if (snacks.size() < slotss) {
		snacks.push_back(snack);
		return true;
	}
	return false;
}
int SnackSlot::getSnackCount() const {
	return snacks.size();
}

SnackSlot::~SnackSlot() {
	for (auto snack : snacks) {
		delete snack;
	}
}

VendingMachine::VendingMachine(int slotCount) : maxSlots(slotCount) {}

bool VendingMachine::addSlot(SnackSlot* slot) {
	if (slots.size() < maxSlots) {
		slots.push_back(slot);
		return true;
	}
	return false;
}

int VendingMachine::getEmptySlotsCount() const {
	return maxSlots - slots.size();
}

VendingMachine::~VendingMachine() {
	for (auto slot : slots) {
		delete slot;
	}
}


main.cpp

#include "snacks.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
	int slotCount = 5;
	Snack* bounty = new Snack("Bounty", 250, 100);
	Snack* snickers = new Snack("Snickers", 300, 150);
	SnackSlot* slot = new SnackSlot(10);
	slot->addSnack(bounty); //Добавляем батончик в слот
	slot->addSnack(snickers);
	VendingMachine* machine = new VendingMachine(slotCount /*Количество слотов для снеков*/);
	machine->addSlot(slot); // Помещаем слот обратно в аппарат

	cout << "Пустых слотов: " << machine->getEmptySlotsCount(); // Должно выводить количество пустых слотов для снеков
	delete machine;
	delete slot;
	delete snickers;
	delete bounty;
	return 0;
}

