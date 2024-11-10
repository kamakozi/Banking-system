#include <chrono>
#include <iostream>
#include <vector>
#include <random>

using namespace std;
float accountBalance = 0.0;

int randomIban;


struct Profiles {
    string username;
    int password;
    int Iban;
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

    std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<long long> dist(100000000000000000, 999999999999999999);
    string username;
    long long random_number = dist(rng);
    int password;
    cout << "Enter your username: ";
    cin >> username;

    p.username = username;
    cout << "Enter your password: ";
    cin >> password;
    p.password = password;
    p.Iban = random_number;
    cout << "Welcome " << username << ". Account was created!" << endl;;
    accounts.push_back(p);

}



void printa() {

    for (const Profiles& p : accounts) {
        std::cout << "Username: " << p.username << "\nPassword: " << p.password << endl;
    }
}


void deposit() {
    cout << "Are you sure you want to deposit money\n1.Yes\n2.No" <<endl;
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
        cout << "You withdrew " << with <<"EUR"<< endl;
        accountBalance = accountBalance - with;
        cout << "Your new balance: " << accountBalance << "EUR" << endl;
    }else if(with > accountBalance) {
        cout << "Not enough funds!" << endl;
    }
}


void data() {
    for(int i = 0;i < accounts.size(); i++) {
        cout <<"Name: " << accounts[i].username << "\nPassword: " << accounts[i].password << "\nIban: " << "AT" << accounts[i].Iban << "Balance: "<< accountBalance << "EUR." << endl;
    }
}

void profile() {
    int prof;
    while(prof !=4){
        cout << "1.Balance\n2.Deposit\n3.Withdrawal\n4.Account info\n5. Log out" << endl;
        cin >> prof;
        switch(prof) {

            case 1:
                cout << "_________________________________________________________" << endl;
                cout <<"Balance "<< accountBalance <<"EUR"<< endl;
                    break;
            case 2: deposit(); break;
            case 3: withdrawal(); break;
            case 4 : data();
            case 5:
                cout << "__________________________________________________________" << endl;
                break;

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
