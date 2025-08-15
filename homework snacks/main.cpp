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