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
    long long Iban;
    double loan;
    double monthly;
};
Profiles p;
vector<Profiles> accounts;
void loanCalculator2000();
void loanCalculator5000();
void loanCalculator15000();
void loanMoney();
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
        cout <<"Name: " << accounts[i].username << "\nPassword: " << accounts[i].password << "\nIban: " << "AT" << accounts[i].Iban << "\nBalance: "<< accountBalance << "EUR.\n" <<"Loans: " <<  accounts[i].loan << "EUR. Per month: "<< accounts[i].monthly << "EUR." << endl;
    }
}

void loanCalculator2000() {
    Profiles q;
    cout << "------------LOAN CALCULATOR------------" << endl;
    cout << "You can take a loan up to 2000 EUR. How much would you like?" << endl;

    int loan;
    while (true) {
        cin >> loan;
        if (loan > 2000) {
            cout << "You can't borrow that much! Please enter an amount up to 2000 EUR." << endl;
        } else {
            break;
        }
    }

    double annualInterestRate = 0.04;
    double monthlyInterestRate = annualInterestRate / 12;
    int numPayments = 12;
    double monthlyPayment = loan * (monthlyInterestRate * pow(1 + monthlyInterestRate, numPayments)) /
                            (pow(1 + monthlyInterestRate, numPayments) - 1);

    cout << "You would have to pay: " << monthlyPayment << " EUR per month!" << endl;
    cout << "Agree to the loan?\n1.Yes\n2.No\nSelect: " << endl;

    int agree;
    cin >> agree;
    if (agree == 1) {
        cout << "You took a loan of " << loan << " EUR!" << endl;
        q.loan = loan;
        q.monthly = monthlyPayment;
        accounts.push_back(q);
    } else {
        loanMoney();
    }
}

void loanCalculator5000() {
    Profiles q;
    cout << "------------LOAN CALCULATOR------------" << endl;
    cout << "You can take a loan up to 5000 EUR. How much would you like?" << endl;

    int loan;
    while (true) {
        cin >> loan;
        if (loan > 5000) {
            cout << "You can't borrow that much! Please enter an amount up to 5000 EUR." << endl;
        } else {
            break;
        }
    }

    double annualInterestRate = 0.04;
    double monthlyInterestRate = annualInterestRate / 12;
    int numPayments = 12;
    double monthlyPayment = loan * (monthlyInterestRate * pow(1 + monthlyInterestRate, numPayments)) /
                            (pow(1 + monthlyInterestRate, numPayments) - 1);

    cout << "You would have to pay: " << monthlyPayment << "EUR per month!" << endl;
    cout << "Agree to the loan?\n1.Yes\n2.No\nSelect: " << endl;

    int agree;
    cin >> agree;
    if (agree == 1) {
        cout << "You took a loan of " << loan << "EUR!" << endl;
        q.loan = loan;
        q.monthly = monthlyPayment;
        accounts.push_back(q);
    } else {
        loanMoney();
    }
}

void loanCalculator15000() {
    Profiles q;
    cout << "------------LOAN CALCULATOR------------" << endl;
    cout << "You can take a loan up to 15000 EUR. How much would you like?\nSelect: " << endl;

    int loan;
    while (true) {
        cin >> loan;
        if (loan > 15000) {
            cout << "You can't borrow that much! Please enter an amount up to 15000 EUR." << endl;
        } else {
            break;
        }
    }

    double annualInterestRate = 0.04;
    double monthlyInterestRate = annualInterestRate / 12;
    int numPayments = 12;
    double monthlyPayment = loan * (monthlyInterestRate * pow(1 + monthlyInterestRate, numPayments)) /
                            (pow(1 + monthlyInterestRate, numPayments) - 1);

    cout << "You would have to pay: " << monthlyPayment << "EUR per month!" << endl;
    cout << "Agree to the loan?\n1.Yes\n2.No\nSelect: " << endl;

    int agree;
    cin >> agree;
    if (agree == 1) {
        cout << "You took a loan of " << loan << "EUR!" << endl;
        q.loan = loan;
        q.monthly = monthlyPayment;
        accounts.push_back(q);
    } else {
        loanMoney();
    }
}

void loanMoney() {
    cout << "Welcome to the loan page!" << endl;
    int chooser;
    cout << "1. Loan table\n2.Loan money\nSelect: " << endl;
    cin >> chooser;

    if (chooser == 1) {
        cout << "------------LOAN TABLE------------" << endl;
        cout << "0 EUR - 500 EUR : Not eligible for a loan" << endl;
        cout << "500 EUR - 1500 EUR : Loan up to 2000 EUR" << endl;
        cout << "1500 EUR - 3000 EUR : Loan up to 5000 EUR" << endl;
        cout << "3000 EUR - 5000 EUR : Loan up to 15000 EUR" << endl;
        cout << "For larger loans, please contact us!" << endl;
        cout << "----------------------------------" << endl;
    } else if (chooser == 2) {
        if (accountBalance < 500) {
            cout << "You are not eligible for a loan!" << endl;
        } else if (accountBalance >= 500 && accountBalance < 1500) {
            cout << "You are eligible for a loan up to 2000 EUR!" << endl;
            cout << "Would you like to calculate your interest?\n1. Yes\n2.No\nSelect: " << endl;
            int loaner;
            cin >> loaner;
            if (loaner == 1) {
                loanCalculator2000();
            } else {
                loanMoney();
            }
        } else if (accountBalance >= 1500 && accountBalance < 3000) {
            cout << "You are eligible for a loan up to 5000 EUR!" << endl;
            cout << "Would you like to calculate your interest?\n1. Yes\n2.No\nSelect: " << endl;
            int loaner;
            cin >> loaner;
            if (loaner == 1) {
                loanCalculator5000();
            } else {
                loanMoney();
            }
        } else if (accountBalance >= 3000 && accountBalance <= 5000) {
            cout << "You are eligible for a loan up to 15000 EUR!" << endl;
            cout << "Would you like to calculate your interest?\n1. Yes\n2.No\nSelect: " << endl;
            int loaner;
            cin >> loaner;
            if (loaner == 1) {
                loanCalculator15000();
            } else {
                loanMoney();
            }
        }
    }
}

void profile() {
    int prof;
    while(prof !=4){
        cout << "1.Account info\n2.Deposit\n3.Withdrawal\n4.Loans\n5.Log out\nSelect: " << endl;
        cin >> prof;
        switch(prof) {

            case 1:data(); break;
            case 2: deposit(); break;
            case 3: withdrawal(); break;
            case 4 : loanMoney(); break;
            case 5: break;


        }
    }
}




int main() {
    int starter;
    while(starter != 4){
        cout << "Zoric Bank" << endl;
        cout << "1.Login\n2.Register\n3.Exit\nSelect: " << endl;
        cin >> starter;
        switch(starter) {
            case 1: login(); break;
            case 2: registeracc(); break;
            case 3: break;
        }
    }
return 0;
}

