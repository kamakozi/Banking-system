#include <iostream>
#include <vector>

using namespace std;
float accountBalance = 0.0;


struct Profiles {
    string username;
    int password;
};
Profiles p;
vector<Profiles> accounts;

void profile();

void login() {
    string username;
    int password;
    cout << "Enter your username: ";
    cin >> username;
    for (const Profiles& p : accounts) {
        if (username == p.username) {
            cout << "Enter your password: ";
            cin >> password;
            for (const Profiles& x: accounts) {
                if (password == x.password) {
                    cout << "Welcome: " << username << endl;
                    profile();
                }else{
                    cout << "Wrong password!\n";
                }
            }
        }else{
        cout << "Username not found\n";}break;
    }
}

void registeracc(){
    string username;
    int password;
    cout << "Enter your username: ";
    cin >> username;

    p.username = username;
    cout << "Enter your password: ";
    cin >> password;
    p.password = password;
    cout << "Welcome " << username << ". Account was created!" << endl;;
    accounts.push_back(p);

}



void printa() {

    for (const Profiles& p : accounts) {
        std::cout << "Username: " << p.username << "\nPassword: " << p.password << endl;
    }
}


void deposit() {
    cout << "Are you sure you want to deposit money\n1.Yes\n2.No?" <<endl;
    int choose;
    cin >> choose;
    if (choose == 1) {
        float deposit;
        cout << "How much would you like to deposit" << endl;
        cin >> deposit;
        accountBalance = accountBalance + deposit;
        cout << "Banalce " << accountBalance << "EUR" << endl;;
    }else {
        cout << "Action was canceled" << endl;
    }
}


void withdrawal(){
    cout << "Balance: " << accountBalance << endl;;
    cout << "How much would you like to withdrawal?" << endl;
    float with;
    cin >> with;
    if (with <= accountBalance){
        cout << "You withdrew " << with << endl;
        accountBalance = accountBalance - with;
        cout << "Your new balance: " << accountBalance << "EUR" << endl;
    }else if(with > accountBalance) {
        cout << "Not enough funds!" << endl;
    }
}

void profile() {
    int prof;
    while(prof !=4){
        cout << "1.Balance\n2.Deposit\n3.Withdrawal\n4.Log out" << endl;
        cin >> prof;
        switch(prof) {
            case 1: cout <<"Balance "<< accountBalance <<"EUR"<< endl; break;; break;
            case 2: deposit(); break;
            case 3: withdrawal(); break;
            case 4: break;
        }
    }
}

int main() {
    int starter;
    while(starter != 4){
        cout << "Zoric Bank" << endl;
        cout << "1.Login\n2.Register\n3.Exit" << endl;
        cin >> starter;
        switch(starter) {
            case 1: login(); break;
            case 2: registeracc(); break;
            case 3: break;
            case 4: printa();
        }
    }
return 0;
}
