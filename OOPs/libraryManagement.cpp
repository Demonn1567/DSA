#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

//book, member, transactions
//member - id,
//book - id, name,author, available
int sn = 1;
int mn =1;
int tid = 1;


class Book {
    
    
    private:
    int bookId;
    string bookName;
    string author;
    int quantity;
    bool available;
    public:
    Book(string b, string a, int q) {
        bookId = sn;
        bookName = b;
        author = a;
        quantity = q;
        available = q>0;
        
        sn++;
    }
    
    bool checkAvailability() {
        return available;
    }
    
    void issueBook() {
        if(available) {
            quantity--;
            if(quantity==0) {
                available = false;
            }
            cout<<"Book Issued Successfully!"<<endl;
        }
        else {
            cout<<"Book not available"<<endl;
        }
    }
    
    void returnBook() {
        quantity++;
        available = true;
        cout<<"Book Returned Successfully!"<<endl;
    }
    
    void displayBookInfo() {
        cout<<"Book ID : "<<bookId<<endl;
        cout<<"Book Name : "<<bookName<<endl;
        cout<<"Book Author : "<<author<<endl;
        cout<<"Book Quantity : "<<quantity<<endl;
        cout<<"Book Available : "<<available?"Yes" : "No";
        cout<<endl<<endl;
    }
    
    int getID() {
        return bookId;
    }
    
};
vector<Book*> books;
void addBook() {
    string name;
    string author;
    int quantity;
    getchar();
    cout<<endl<<endl;
    cout<<"Enter book name : ";
    getline(cin, name);
    cout<<endl<<"Enter Author of the book : ";
    getline(cin, author );
    
    cout<<endl<<"Enter Book quantity : ";
    cin>>quantity;
    
    Book* book = new Book(name, author, quantity);
    books.push_back(book);
    
}

void getAllBook() {
    for (Book* book : books) {
        book->displayBookInfo();
    }
}


class Member {
    private:
    int memberId;
    string memberName;
    string contact;
    public:
    Member(string m, string c) {
        memberId = mn;
        memberName = m;
        contact = c;
        mn++;
    }
    
    void displayMemberInfo() {
        cout<<"Member Id : "<<memberId<<endl;
        cout<<"Member Name : "<<memberName<<endl;
        cout<<"Member contact : "<<contact<<endl;
        cout<<endl;
    }
    int getId() {
        return memberId;
    }
};

vector<Member*> members;

void addMember() {
    string name;
    string contact;
    getchar();
    cout<<endl<<endl;
    cout<<"Enter your name : "<<endl;
    getline(cin, name);
    cout<<"Enter your phone number : "<<endl;
    getline(cin, contact);
    
    Member* mem = new Member(name, contact);
    members.push_back(mem);
    
}

void getAllMembers() {
    for(Member* m : members) {
        m->displayMemberInfo();
    }
}

class Transactions {
    public:
    int transactionId;
    int bookId;
    int memberId;
    time_t issueTime;
    time_t returnTime;
    bool returned;

    public:    
    Transactions(int b, int m) {
        
        transactionId = tid;
        bookId = b;
        memberId = m;
        issueTime = time(0);
        returnTime = time(0);
        returned = false;
        tid++;
    }
    
    void returnBook() {
        returnTime = time(0);
        returned = true;
        
    }
    
    void displayTransaction() {
        cout << "Transaction ID: " << transactionId << endl;
        cout << "Book ID: " << bookId << endl;
        cout << "Member ID: " << memberId << endl;
        cout << "Issue Time: " << ctime(&issueTime);
        if (returned) {
            cout << "Return Time: " << ctime(&returnTime);
        } else {
            cout << "Book not returned yet." << endl;
        }
    }
    
    void issueBook() {
        bool isMember = false;
        int memId;
        cout<<"Enter your member Id : "<<endl;
        cin>>memId;
        
        for(Member* member : members) {
            if(member->memberId ==memId) {
                isMember = true;
            }
        }
        if(isMember) {
            
        }
    }

};

int main() {
    //Book* b1 = new Book("Mathematics", "RD Sharma", 12);
    //Book* b2 = new Book("Linear Algebra", "Laren Schmitz", 7);
    //b1->displayBookInfo();
    //b2->displayBookInfo();
    while(true) {
        cout<<"*******MENU*******"<<endl;
        cout<<"1. Add a Book"<<endl;
        cout<<"2. Check All the Books Available"<<endl;
        cout<<"3. Add a Member"<<endl;
        cout<<"4. Get details of all members"<<endl;
        cout<<"5. Issue a Book"<<endl;
        cout<<"6. Return a Book"<<endl;
        cout<<"0. Exit"<<endl;
        
        int choice;
        cout<<"Enter a choice"<<endl;
        cin>>choice;
        
        switch(choice) {
            case 1:
            addBook();
            break;
            
            case 2:
            getAllBook();
            break;
            
            case 3:
            addMember();
            break;
            
            case 4:
            getAllMembers();
            break;
            
            case 5:
            issueBook();
            break;
            
            case 6:
            returnBook();
            break;
            
            default:
            exit(0);
            
        }
    }
    
    
    return 0;
}













