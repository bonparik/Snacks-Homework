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
