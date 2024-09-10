#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

class Book	{
private:
    char *bookAuthor, *bookTitle, *bookPublisher;
    float *bookPrice;
    int *bookStock;
public:
    Book()	{
        bookAuthor = new char[20];
        bookTitle = new char[20];
        bookPublisher = new char[20];
        bookPrice = new float;
        bookStock = new int;
    }
    void feedData();
    void editData();
    void showData();
    int  search(char[], char[]);
    void buyBook();
};

void Book::feedData()	{
    cin.ignore();
    cout<<"\nEnter Author Name: ";      cin.getline(bookAuthor, 20);
    cout<<"Enter Title Name: ";       cin.getline(bookTitle, 20);
    cout<<"Enter Publisher Name: ";   cin.getline(bookPublisher, 20);
    cout<<"Enter Price: ";            cin>>*bookPrice;
    cout<<"Enter Stock: ";            cin>>*bookStock;
}

void Book::editData()	{
    cout<<"\nEnter Author Name: ";      cin.getline(bookAuthor, 20);
    cout<<"Enter Title Name: ";       cin.getline(bookTitle, 20);
    cout<<"Enter Publisher Name: ";   cin.getline(bookPublisher, 20);
    cout<<"Enter Price: ";            cin>>*bookPrice;
    cout<<"Enter Stock: ";            cin>>*bookStock;
}

void Book::showData()	{
    cout<<"\nAuthor Name: "<<bookAuthor;
    cout<<"\nTitle Name: "<<bookTitle;
    cout<<"\nPublisher Name: "<<bookPublisher;
    cout<<"\nPrice: "<<*bookPrice;
    cout<<"\nStock: "<<*bookStock;
}

int Book::search(char searchTitle[20], char searchAuthor[20])	{
    if(strcmp(searchTitle, bookTitle) == 0 && strcmp(searchAuthor, bookAuthor) == 0)
        return 1;
    else return 0;
}

void Book::buyBook()	{
    int quantity;
    cout<<"\nEnter Number Of Books to buy: ";
    cin>>quantity;
    if(quantity <= *bookStock)	{
        *bookStock = *bookStock - quantity;
        cout<<"\nBooks Bought Successfully";
        cout<<"\nAmount: Rs. "<<(*bookPrice) * quantity;
    }
    else
        cout<<"\nRequired Copies not in Stock";
}

int main()	{
    Book *library[20];
    int bookCount = 0, userChoice, bookIndex;
    char searchTitle[20], searchAuthor[20];
    while(true)	{
        cout<<"\n\n Book Store Management System"
            <<"\n-----------------------------"
            <<"\n1. Entry of New Book"
            <<"\n2. Buy Book"
            <<"\n3. Search For Book"
            <<"\n4. Edit Details Of Book"
            <<"\n5. Exit"
            <<"\n\nEnter your Choice: ";
        cin>>userChoice;

        switch(userChoice)	{
            case 1:	
                library[bookCount] = new Book;
                library[bookCount]->feedData();
                bookCount++;
                break;

            case 2:
                cin.ignore();
                cout<<"\nEnter Title Of Book: "; cin.getline(searchTitle, 20);
                cout<<"Enter Author Of Book: ";  cin.getline(searchAuthor, 20);
                for(bookIndex = 0; bookIndex < bookCount; bookIndex++)	{
                    if(library[bookIndex]->search(searchTitle, searchAuthor))	{
                        library[bookIndex]->buyBook();
                        break;
                    }
                }
                if(bookIndex == bookCount)
                    cout<<"\nThis Book is Not in Stock";
                break;

            case 3:
                cin.ignore();
                cout<<"\nEnter Title Of Book: "; cin.getline(searchTitle, 20);
                cout<<"Enter Author Of Book: ";  cin.getline(searchAuthor, 20);
                for(bookIndex = 0; bookIndex < bookCount; bookIndex++)	{
                    if(library[bookIndex]->search(searchTitle, searchAuthor))	{
                        cout<<"\nBook Found Successfully";
                        library[bookIndex]->showData();
                        break;
                    }
                }
                if(bookIndex == bookCount)
                    cout<<"\nThis Book is Not in Stock";
                break;

            case 4:
                cin.ignore();
                cout<<"\nEnter Title Of Book: "; cin.getline(searchTitle, 20);
                cout<<"Enter Author Of Book: ";  cin.getline(searchAuthor, 20);
                for(bookIndex = 0; bookIndex < bookCount; bookIndex++)	{
                    if(library[bookIndex]->search(searchTitle, searchAuthor))	{
                        cout<<"\nBook Found Successfully";
                        library[bookIndex]->editData();
                        break;
                    }
                }
                if(bookIndex == bookCount)
                    cout<<"\nThis Book is Not in Stock";
                break;

            case 5:
                exit(0);

            default:
                cout<<"\nInvalid Choice Entered";
                break;
        }
    }
}
