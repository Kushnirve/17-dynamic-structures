#include<iostream>
#include<windows.h>
using namespace std;

struct Person {
	string name, surname, phone, email;
};

// allocation block
Person* addStruct(Person* Obj, int amount) {
	Person* tempObj = new Person[amount + 1]; // assign memory +1 record
	for (int i = 0; i < amount; i++) tempObj[i] = Obj[i]; // copying existing object data to temporary object
	delete[] Obj; // deallocate memory
	return tempObj; // return new pointer
}

// removement block
Person* delPerson(Person* Obj, int amount, int deleted) {
	Person* tempObj = new Person[amount - 1]; // shorten the array
	for (int i = 0; i < amount - 1; i++) {
		if (i >= deleted) tempObj[i] = Obj[i + 1]; // copy all records after deleted one
		else tempObj[i] = Obj[i]; // copy all records before deleted one
	}
	delete[] Obj; // deallocate memory
	return tempObj; // return new pointer
}

void writePerson(Person* Obj, int amount) {
	cout << "Name: ";
	cin >> Obj[amount].name;
	cout << "Surname: ";
	cin >> Obj[amount].surname;
	cout << "Phone: ";
	cin >> Obj[amount].phone;
	cout << "Email: ";
	cin >> Obj[amount].email;
}

void printPersons(Person* Obj, int amount) {
	cout << "№ Name Surname Phone Email" << endl;
	for (int i = 0; i < amount; i++) cout << i << " " << Obj[i].name << " " << Obj[i].surname << " " << Obj[i].phone << " " << Obj[i].email << endl;
}

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	// dataBase is pointer to store our data
	Person* dataBase = nullptr; // init pointer
	int records = 0, input;
	bool quit = false;

	while (!quit) {
		cout << "(1) Сreate record\n(2) Edit record\n(3) Delete record\n(4) Print list\n(5) Quit\n";
		cin >> input;
		switch (input) {
		case 1:
			cout << "Сreate record\n";
			dataBase = addStruct(dataBase, records); // resize memory to allow store +1 record and resave pointer
			writePerson(dataBase, records); // fill new last struct with data
			records++; // records counter +1
			break;
		case 2:
			if (records > 0) {
				cout << "Edit record: 0 - " << records - 1 << endl;
				cin >> input;
				writePerson(dataBase, input); // just overwrite all data of selected record 
			}
			else cout << "No records\n";
			break;
		case 3:
			if (records > 0) {
				cout << "Delete record: 0 - " << records - 1 << endl;
				cin >> input;
				dataBase = delPerson(dataBase, records, input); // resize memory to allow store -1 record and resave pointer
				records--; // records counter -1
			}
			else cout << "No records\n";
			break;
		case 4:
			if (records > 0) {
				cout << "Print list" << endl;
				printPersons(dataBase, records);
			}
			else cout << "No records\n";
			break;
		case 5:
			quit = true;
			break;
		}
	}
	delete[] dataBase;
}