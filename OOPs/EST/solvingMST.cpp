#include <iostream>

using namespace std;

class Recipent;
class Donor {
    string donor_name;
    double balance;
    public:
    void set_details(string name, double amount) {
        donor_name = name;
        balance = amount;
    }
    void display() {
        cout<<donor_name<<" "<<balance<<endl;
    }

    double get_balance() {
        return balance;
    }
    friend void transfer(Donor &donor, Recipent &recipent, double amount);
};


class Recipent {
    string recipent_name;
    double account_balance;
    double amount_required;
    public:
    void set_details(string name, double balance, double amount) {
        recipent_name=  name;
        account_balance = balance;
        amount_required = amount;
    }
    void display() {
        cout<<recipent_name<<" "<<account_balance<<" "<<amount_required<<endl;
    }
    double get_balance() {
        return account_balance;
    }

    friend void transfer(Donor &donor, Recipent &recipent, double amount);

};

void transfer(Donor &donor, Recipent &recipent, double amount) {
    if(donor.balance >=amount) {
        donor.balance-=amount;
        recipent.account_balance+=amount;
    }
    else
    {
        cout<<"insufficient funds";
    }
}

int main() {


    return 0;
}
