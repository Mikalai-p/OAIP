#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Address {
    string name;
    string city;
    Address* next;
    Address* prev;
};

int menu() {
    char s[80];
    int c;
    cout << "\n1. Enter name\n2. Add to beginning\n3. Display list\n4. Search\n5. Save to file\n6. Load from file\n7. Exit\n\nYour choice: ";
    cin.sync();
    cin.getline(s, 80);
    c = atoi(s);
    return c;
}

Address* setElement() {
    Address* temp = new Address();
    if (!temp) {
        cerr << "Memory allocation error\n";
        return nullptr;
    }
    cout << "Enter name: ";
    getline(cin, temp->name);
    cout << "Enter city: ";
    getline(cin, temp->city);
    temp->next = temp->prev = nullptr;
    return temp;
}

void insert(Address* e, Address** phead, Address** plast) {
    if (*plast == nullptr) {
        *plast = *phead = e;
        e->next = e->prev = nullptr;
    }
    else {
        (*plast)->next = e;
        e->prev = *plast;
        *plast = e;
        e->next = nullptr;
    }
}

void outputList(Address** phead) {
    Address* t = *phead;
    while (t) {
        cout << t->name << ' ' << t->city << '\n';
        t = t->next;
    }
    cout << '\n';
}

void find(const string& name, Address** phead) {
    Address* t = *phead;
    while (t) {
        if (t->name == name) {
            cout << t->name << ' ' << t->city << '\n';
            return;
        }
        t = t->next;
    }
    cerr << "Name not found\n";
}

void writeToFile(Address** phead) {
    ofstream outfile("mlist.txt", ios::binary);
    if (!outfile.is_open()) {
        cerr << "Failed to open file\n";
        return;
    }
    Address* t = *phead;
    while (t) {
        size_t nameLength = t->name.length();
        outfile.write(reinterpret_cast<const char*>(&nameLength), sizeof(nameLength));
        outfile.write(t->name.c_str(), nameLength);
        size_t cityLength = t->city.length();
        outfile.write(reinterpret_cast<const char*>(&cityLength), sizeof(cityLength));
        outfile.write(t->city.c_str(), cityLength);
        t = t->next;
    }
    outfile.close();
    cout << "Saved to file\n";
}

void readFromFile(Address** phead, Address** plast) {
    ifstream infile("mlist.txt", ios::binary);
    if (!infile.is_open()) {
        cerr << "Failed to open file\n";
        return;
    }

    while (*phead) {
        Address* temp = *phead;
        *phead = (*phead)->next;
        delete temp;
    }
    *phead = *plast = nullptr;

    while (infile.peek() != EOF) {
        Address* t = new Address();
        if (!t) {
            cerr << "Memory error\n";
            infile.close();
            return;
        }
        size_t nameLength;
        infile.read(reinterpret_cast<char*>(&nameLength), sizeof(nameLength));
        t->name.resize(nameLength);
        infile.read(&t->name[0], nameLength);
        size_t cityLength;
        infile.read(reinterpret_cast<char*>(&cityLength), sizeof(cityLength));
        t->city.resize(cityLength);
        infile.read(&t->city[0], cityLength);

        if (infile.gcount() != nameLength + sizeof(nameLength) + cityLength + sizeof(cityLength)) {
            delete t;
            break;
        }

        t->next = t->prev = nullptr;
        insert(t, phead, plast); //insert at the end.  If you need to insert at the beginning, adjust accordingly.
    }

    infile.close();
    cout << "Loaded from file\n";
}

void addXBegin(Address** phead, Address** plast) {
    Address* newElement = setElement();
    if (!newElement) return;

    if (*phead == nullptr) {
        *phead = *plast = newElement;
        newElement->next = newElement->prev = nullptr;
    }
    else {
        newElement->next = *phead;
        (*phead)->prev = newElement;
        *phead = newElement;
        newElement->prev = nullptr;
    }
}


int main() {
    Address* head = nullptr;
    Address* last = nullptr;

    while (true) {
        switch (menu()) {
        case 1:
            insert(setElement(), &head, &last);
            break;
        case 2:
            addXBegin(&head, &last);
            break;
        case 3:
            outputList(&head);
            break;
        case 4: {
            string fname;
            cout << "Enter name to search: ";
            getline(cin, fname);
            find(fname, &head);
            break;
        }
        case 5:
            writeToFile(&head);
            break;
        case 6:
            readFromFile(&head, &last);
            break;
        case 7:
            while (head) {
                Address* temp = head;
                head = head->next;
                delete temp;
            }
            return 0;
        default:
            cout << "Invalid choice.\n";
        }
    }
    return 0;
}