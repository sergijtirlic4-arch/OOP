#include <iostream>
#include <iomanip>
using namespace std;

class Book
{
	string author;
	string title;
	string publisher;
	int publication_year;
	int page_count;
public:
	explicit Book();
	explicit Book(string auhtor, string title, string publisher, int publication_year, int page_count);
	~Book();

    void Show() const;
    static void PrintByAuthor(const Book books[], int size, const string& author);
    static void PrintByPublisher(const Book books[], int size, const string& publisher);
    static void PrintAfterYear(const Book books[], int size, int year);
};

Book::Book()
{
    author = "Unknown";
    title = "Unknown";
    publisher = "Unknown";
    publication_year = 0;
    page_count = 0;
}

Book::Book(string author, string title, string publisher, int publication_year, int page_count)
{
	this->author = author;
	this->title = title;
	this->publisher = publisher;
	this->publication_year = publication_year;
	this->page_count = page_count;
}

Book::~Book()
{
}

void Book::Show() const
{
    cout << left << setw(20) << author
        << setw(25) << ("\"" + title + "\"")
        << setw(15) << publisher
        << setw(10) << publication_year
        << page_count << " pages\n";
}

void Book::PrintByAuthor(const Book books[], int size, const string& author)
{
    cout << "\n--- Books by author: " << author << " ---\n";
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (books[i].author == author) {
            books[i].Show();
            found = true;
        }
    }
    if (!found) cout << "No books found.\n";
}

void Book::PrintByPublisher(const Book books[], int size, const string& publisher)
{
    cout << "\n--- Books by publisher: " << publisher << " ---\n";
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (books[i].publisher == publisher) {
            books[i].Show();
            found = true;
        }
    }
    if (!found) cout << "No books found.\n";
}

void Book::PrintAfterYear(const Book books[], int size, int year)
{
    cout << "\n--- Books published after " << year << " ---\n";
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (books[i].publication_year == year) {
            books[i].Show();
            found = true;
        }
    }
    if (!found) cout << "No books found.\n";
}

int main()
{
    const int SIZE = 5;
    Book library[SIZE] = {
        Book("Taras Shevchenko", "Kobzar", "Prosvita", 2015, 450),
        Book("Ivan Franko", "Zakhar Berkut", "Ababa", 2018, 320),
        Book("Lina Kostenko", "Marusia Churai", "Ababa", 2020, 240),
        Book("Taras Shevchenko", "Haidamaky", "Dnipro", 2010, 180),
        Book("Serhiy Zhadan", "Internat", "Meridian", 2017, 336)
    };

    cout << "All books in library:\n";
    for (int i = 0; i < SIZE; ++i) {
        library[i].Show();
    }

    Book::PrintByAuthor(library, SIZE, "Taras Shevchenko");
    Book::PrintByPublisher(library, SIZE, "Ababa");
    Book::PrintAfterYear(library, SIZE, 2016);
}