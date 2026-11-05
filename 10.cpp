#include <iostream>
#include <string>
using namespace std;

class Media {
protected:
    string title;
    string publication;

public:
    Media(string t = "", string p = "") : title(t), publication(p) {}

    virtual void read() {
        cout << "Enter Title: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter Publication: ";
        getline(cin, publication);
    }

    virtual void show() {
        cout << "Title      : " << title << endl;
        cout << "Publication: " << publication << endl;
    }

    virtual ~Media() {}
};

class Book : public Media {
private:
    int pageCount;

public:
    void read() override {
        Media::read();
        cout << "Enter Number of Pages: ";
        cin >> pageCount;
    }

    void show() override {
        Media::show();
        cout << "Page Count : " << pageCount << endl;
    }
};

class Tape : public Media {
private:
    double playTime;

public:
    void read() override {
        Media::read();
        cout << "Enter Playing Time (minutes): ";
        cin >> playTime;
    }

    void show() override {
        Media::show();
        cout << "Play Time  : " << playTime << " mins" << endl;
    }
};

int main() {
    Media *shopItem[2];

    shopItem[0] = new Book();
    shopItem[1] = new Tape();

    cout << "--- Enter Book Details ---\n";
    shopItem[0]->read();

    cout << "\n--- Enter Tape Details ---\n";
    shopItem[1]->read();

    cout << "\n================ SHOP INVENTORY ================\n";
    for (int i = 0; i < 2; i++) {
        shopItem[i]->show();
        cout << "-----------------------------------------------\n";
    }

    delete shopItem[0];
    delete shopItem[1];
    return 0;
}
