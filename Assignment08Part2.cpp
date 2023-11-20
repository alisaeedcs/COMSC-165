#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int SIZE = 81;
int displayMenu();

struct Costco {
  char name[SIZE];
  int quantity;
  float wholesale; //price
  float retail; //price
};

void addrecord(); //adds a record to the binary file
void displayall(); //displays all records
int initialdataread(); //reads inventory from text and writes binary
void displayrecord();
void changerecord();
void getitem(Costco &);
void report();
void displayitem(const Costco&);

int main() {
  int choice;
  initialdataread();
  choice = displayMenu();
  while (choice != 6) {
    switch (choice) {
      case 1: displayall(); break;
      case 2: displayrecord(); break;
      case 3: changerecord(); break;
      case 4: addrecord(); break;
      case 5 :report(); break;
      default:
        if (choice !=6)
          cout << "Wrong choice" << endl; 
    }
    choice = displayMenu();
  }
  return 0;
}

int displaymenu() {
  int choice;
  string menu = "\n\n\t1-\tdisplay all, \t\t2-\tdisplay a record\n\t3-\tchange record";
  menu +=", \t\t4-\tadd a record\n\t5-\tprepare report, \t\t6-\texit\n\n";
  cout << menu;
  cin >> choice;
  return choice;
}

int initialdataread() {
  Costco temp;
  ofstream out; //write on binary file
  ifstream in; //read from text file
  in.open("data.txt");
  out.open("inventory.dat", ios::out | ios::binary);
  if (in && out) {
    in >> temp.name;
    while (!in.eof()) {
      in >> temp.quantity >> temp.wholesale >> temp.retail;
      out.write ((char*)&temp, sizeof(temp));
      in >> temp.name;
    }
    in.close();
    out.close();
  }
  else {
    cout << "Error opening files";
    exit(EXIT_FAILURE);
  }
}

void displayall() {
  Costco temp;
  ifstream in("inventory.dat", ios:: binary);
  if(in) {
    in.read((char*)&temp, sizeof(temp));
    while (!in.eof()) {
      displayitem(temp);
      in.read((char*)&temp, sizeof(temp));
    }
  }
}

void displayrecord() {
  Costco temp;
  char todisplay[SIZE];
  cout << "Enter the name of the record you would like to view\n";
  cin >> todisplay;
  ifstream in ("inventory.dat", ios::binary);
  if (in) {
    in.read((char*)&temp, sizeof(temp));
    while (!in.eof()) {
      if (strcmp(temp.name, todisplay) == 0) {
        displayitem(temp);
        break;
      }
      in.read((char*)&temp, sizeof(temp));
    }
    if (in.eof()) {
      cout << "Item not in the file\n\n";
    }
    in.close();
  }
}

void changerecord() {
  Costco temp;
  Costco newitem;
  long where;

  char olditem[SIZE];
  cout << "Enter item you would like to replace ";
  cin >> olditem;
  getitem(newitem);

  fstream inOut ("inventory.dat", ios::in | ios::out | ios::binary);

  if (inOut) {
    inOut.read((char*)&temp, sizeof(temp));
    while (!inOut.eof()) {
      if (strcmp(temp.name, olditem) == 0) {
        cout << "Item found " << temp.name << endl;
        break;
      }
      inOut.read((char*)&temp, sizeof(temp));
    }
  }
  inOut.clear(); //clear flags

  where = inOut.tellg(); //return # of bytes from beginning of file
  inOut.seekp(where-sizeof(Costco), ios::beg); //position writing head
  inOut.write((char*)&newitem, sizeof(Costco));
  inOut.close();
}

void addrecord() {
  Costco temp;
  getitem(temp);

  ofstream out("inventory.dat", ios::app | ios::binary);
  if(out) {
    out.write((char*)&temp, sizeof(Costco));
  }
  else {
    cout << "Error opening the file" << endl;
    exit(EXIT_FAILURE);
  }
}

void displayitem(const Costco& c) {
  cout << "Item name       " << c.name << endl;
  cout << "Quantity        " << c.quantity << endl;
  cout << "Wholesale cost  " << c.wholesale << endl;
  cout << "Retail cost     " << c.retail << endl << endl;
}

void getitem(Costco & newitem)
{
  //get info for new items
  cout << "Enter new item name : ";
  cin >> newitem.name;
  cout << "Enter the new item quantity : ";
  cin >> newitem.quantity;
  cout << "Enter the new item wholesale price : ";
  cin >> newitem.wholesale;
  cout << "Enter the new item retail price : ";
  cin >> newitem.retail;
}

void report() {
  Costco temp;
  float total_quantity = 0.0, total_retail = 0.0, total_wholesale = 0.0;
  ifstream in ("inventory.dat", ios::binary);
  if (in) {
    while (in.read((char*)&temp, sizeof(Costco))) {
      total_quantity += temp.quantity;
      total_retail += temp.retail;
      total_wholesale = temp.wholesale;
    }
    in.close();
  }
  else {
    cout << "Error opening the file" << endl;
    exit(EXIT_FAILURE);
  }
  cout << "\n\nREPORT\n\n";
  cout << "Total quantity of items on stock   " << total_quantity << endl;
  cout << "Total retail amount on stock       $" << total_retail << endl;
  cout << "Total wholesale amount on stock    $" << total_wholesale << endl << endl;
}
