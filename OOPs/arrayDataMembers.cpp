#include <iostream>

using namespace std;

class Shop {
    int itemId[100];
    int itemPrice[100];
    int counter;

    public:
    void initCounter() {
        counter = 0;
    }
    void setPrice(int num);
    void getPrice();
};

void Shop :: setPrice(int numItems) {
    for(int i =0;i<numItems;i++) {
        cout<<"Enter id of item no."<<counter+1<<endl;
        cin>>itemId[i];
        cout<<"Enter price of item no."<<counter+1<<endl;
        cin>>itemPrice[i];

        counter++;
    }
    
}

void Shop ::getPrice() {
    for(int i =0;i<counter;i++) {
        cout<<"Item id "<<itemId[i]<<"has a price of :"<<itemPrice[i]<<endl;
    }
}

int main() {
    Shop s1;
    s1.initCounter();
    int num;
    cout<<"Enter number of items to set Price";
    cin>>num;
    s1.setPrice(num);
    

    s1.getPrice();


    return 0;
}