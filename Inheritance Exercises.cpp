#include <iostream>
#include <string>
using namespace std;

class Book {
protected:
   string title;
   string author;
   int year;
public:
   Book(string t,string a,int y):title(t),author(a),year(y){}
   virtual ~Book() {}
   virtual void showInfo();
   // virtual void showInfo() = 0; // pure virtual fonksiyon diðer classlar bunu yazmak zorundalar
   friend class Librarian;
};

void Book::showInfo(){
   cout << "Book Title: " << title << "\nBook Author: " << author << "\nBook Year: " << year << endl;
}

class FictionBook : public Book {  
  string genre;  
public:  
  FictionBook(string t, string a, int y, string g) : Book(t, a, y), genre(g) {}  
  void getGenre();
  void showInfo() override;
};

void FictionBook::getGenre(){
   cout << "Genre: " << genre << endl;
}

void FictionBook::showInfo() {  
  cout << "FictionBook Title: " << title << "\nFictionBook Author: " << author << "\nFictionBook Year: " << year << endl;  
}

class AcademicBook: public Book {
   string field;
public: 
   AcademicBook(string t, string a, int y, string f): Book(t, a, y),field(f){}
   void getField();
   void showInfo() override; 
};

void AcademicBook::getField() {
   cout << "Field: " << field << endl;
}
void AcademicBook::showInfo() { // Fix: Access private members directly since AcademicBook is a derived class
   cout << "AcademicBook Title: " << title << "\nAcademicBook Author: " << author << "\nAcademicBook Year: " << year << endl;
}

class Librarian {
   string librarian;
public:
   Librarian(string l):librarian(l){}
   void updateTitle(Book&, string newTitle);
   void updateYear(Book&, int newYear);
   void printPrivateDetails(Book&);
   void librarianName() const { cout << "librarian name is: " << librarian << endl; }
};
void Librarian::updateTitle(Book& b, string newTitle) {
   b.title = newTitle;
   cout << "Title is updated" << endl;
}
void Librarian::updateYear(Book& b, int newYear) {
   b.year = newYear;
   cout << "Year is updated." << endl;
}
void Librarian::printPrivateDetails(Book& b) {
   cout << "Privet Details: " << endl << "Title: " << b.title << endl << "Author: " << b.author << endl << "Year: " << b.year << endl;
}

int main()
{
  /* FictionBook fbook1(Suç ve  Ceza", "Dostoyevski", 1995, "Kurgu");
   fbook1.showInfo();
   fbook1.getGenre();

   AcademicBook abook1("Reader at work 1", "METU", 2020, "Dil");
   abook1.showInfo();
   abook1.getField();

   Librarian librarian("Özkan");
   librarian.librarianName();

   librarian.updateTitle(abook1, "Reader at work 2");
   librarian.printPrivateDetails(fbook1);
   librarian.printPrivateDetails(abook1);
   librarian.updateYear(abook1, 2023);*/

// ---------------------------- POLYMORPHISM SECTION ------------------------------------------------------------------------------------
   // Book pointer'larý kullanýyoruz:
   Book* fbook1 = new FictionBook("Suç ve  Ceza", "Dostoyevski", 1995, "Kurgu");
   Book* abook1 = new AcademicBook("Reader at work 1", "METU", 2020, "Dil");

   // Polimorfizm: virtual sayesinde gerçek sýnýfýn fonksiyonu çaðrýlýr
   fbook1->showInfo();
   // Tür dönüþümü yaparak FictionBook'a özel fonksiyon çaðrýlýr
   dynamic_cast<FictionBook*>(fbook1)->getGenre();

   abook1->showInfo();
   dynamic_cast<AcademicBook*>(abook1)->getField();

   Librarian librarian("Özkan");
   librarian.librarianName();

   librarian.updateTitle(*abook1, "Reader at work 2");
   librarian.printPrivateDetails(*fbook1);
   librarian.printPrivateDetails(*abook1);

   librarian.updateYear(*abook1, 2023);

   // Belleði temizleyelim
   delete fbook1;
   delete abook1;

}
