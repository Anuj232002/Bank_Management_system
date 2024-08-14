#include <bits/stdc++.h>
using namespace std;

class Bank
{
private:
    int PIN = 1234;

public:
    int id;
    int getPIN(int pin)
    {
        if (pin == PIN)
            return 1;
        else
            return 0;
    }
};

class AccountDetails : public Bank
{
private:
    string name;
    int age;
    string address;
    int balance = 0;
    long long mobile;
    string email;
    int status = 1;

public:
    void setName(string Name)
    {
        name = Name;
    }
    void setAge(int Age)
    {
        age = Age;
    }
    void setAddress(string Address)
    {
        address = Address;
    }
    void setDeposite(int Deposite)
    {
        balance = balance + Deposite;
    }
    void setDebit(int Withdraw)
    {
        if (balance - Withdraw < 500)
        {
            cout << "Insufficient balance, please add money!" << endl;
        }
        else
        {
            balance = balance - Withdraw;
            cout << "Withdrawal successful!" << endl;
        }
    }
    void setMobile(long long Mobile)
    {
        mobile = Mobile;
    }
    void setEmail(string Email)
    {
        email = Email;
    }
    void setId(int ID)
    {
        id = ID;
    }
    void setStatus(int Status)
    {
        status = Status;
    }
    int getStatus()
    {
        return status;
    }
    int getId()
    {
        return id;
    }
    bool search(int s_id)
    {
        return id == s_id;
    }
    int getBalance()
    {
        return balance;
    }
    void Display_account_details()
    {
        cout << endl;
        cout << "__________________________________________" << endl;
        cout << "Account Number: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Mobile: " << mobile << endl;
        cout << "Balance: " << balance << endl;
        cout << "Email: " << email << endl;
        cout << "Address: " << address << endl;
        cout << "__________________________________________" << endl;
    }
    void Display_status()
    {
        if (status == 1)
        {

            cout << "Account is Active" << endl;
            cout << "__________________________________________" << endl;
        }
        else
        {
            cout << "__________________________________________" << endl;
            cout << "Account is deactivated" << endl;
            cout << "__________________________________________" << endl;
        }
    }
};

int main()
{
    vector<AccountDetails> Details;
    int id = 1000;
    int ch;
    cout << "__________________________________________" << endl;
    cout << "Welcome to Your Bank" << endl;
    cout << "__________________________________________" << endl;
    Bank admin;

    do
    {
        bool found = false;
        cout << endl;
        cout << "__________________________________________" << endl;
        cout << "Enter your choice: " << endl;
        cout << "1. Create an Account" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Check Balance" << endl;
        cout << "5. Display your account details" << endl;
        cout << "6. Admin operations" << endl;
        cout << "0. Exit" << endl;
        cin >> ch;
        cin.ignore();

        switch (ch)
        {
        case 1:
        {
            AccountDetails acct;

            id++;
            string name, address, email;
            int age, deposite, status;
            long long mobile;

            cout << "Enter your Name: ";
            getline(cin, name);
            acct.setName(name);

            cout << "Enter your Age: ";
            cin >> age;
            cin.ignore();
            acct.setAge(age);

            cout << "Enter your Mobile number (10 digits): ";
            cin >> mobile;
            cin.ignore();
            acct.setMobile(mobile);

            cout << "Enter your Address: ";
            getline(cin, address);
            acct.setAddress(address);

            cout << "Enter the amount you want to deposit: ";
            cin >> deposite;
            cin.ignore();
            acct.setDeposite(deposite);

            cout << "Enter your Email: ";
            getline(cin, email);
            acct.setEmail(email);

            acct.setId(id);
            Details.push_back(acct);

            cout << "__________________________________________" << endl;
            cout << "Account Created Successfully!" << endl;
            cout << "Your Account number is " << id << endl;
            cout << "__________________________________________" << endl;
            break;
        }
        case 2:
        {
            int search_id, deposite;
            found = false;

            cout << "Enter your account number: ";
            cin >> search_id;

            for (auto &acct : Details)
            {
                if (acct.search(search_id) && acct.getStatus())
                {
                    found = true;
                    cout << "Enter the amount you want to deposit: ";
                    cin >> deposite;
                    acct.setDeposite(deposite);
                    cout << "Amount Deposited successfully!" << endl;
                    break;
                }
                else
                {
                    cout << "Your account is deactivated;" << endl;
                    break;
                }
            }
            if (!found)
            {
                cout << "No account found!" << endl;
            }
            break;
        }
        case 3:
        {
            int search_id, withdraw;
            found = false;

            cout << "Enter your account number: ";
            cin >> search_id;

            for (auto &acct : Details)
            {
                if (acct.search(search_id) && acct.getStatus())
                {
                    found = true;
                    cout << "Enter the amount you want to withdraw: ";
                    cin >> withdraw;
                    acct.setDebit(withdraw);
                    break;
                }
                else
                {
                    cout << "Your account is deactivated;" << endl;
                    break;
                }
            }
            if (!found)
            {
                cout << "No account found!" << endl;
            }
            break;
        }
        case 4:
        {
            int search_id;
            found = false;

            cout << "Enter your account number: ";
            cin >> search_id;

            for (auto &acct : Details)
            {
                if (acct.search(search_id) && acct.getStatus())
                {
                    found = true;
                    cout << "Your remaining balance is Rs. " << acct.getBalance() << endl;
                    break;
                }
                else
                {
                    cout << "Your account is deactivated;" << endl;
                    break;
                }
            }
            if (!found)
            {
                cout << "No account found!" << endl;
            }
            break;
        }
        case 5:
        {
            int search_id;
            found = false;

            cout << "Enter your account number: ";
            cin >> search_id;

            for (auto &acct : Details)
            {
                if (acct.search(search_id) && acct.getStatus())
                {
                    found = true;
                    cout << "Your Account Details:" << endl;
                    acct.Display_account_details();
                    break;
                }
                else
                {
                    cout << "Your account is deactivated;" << endl;
                    break;
                }
            }
            if (!found)
            {
                cout << "No account found!" << endl;
            }
            break;
        }
        case 6:
        {
            int admin_choice;
            int pin;

        this_line:
            cout << "Enter admin pin to perform operation" << endl;
            cin >> pin;
            if (admin.getPIN(pin))
            {
                cout << "__________________________________________" << endl;
                cout << "Welcome to Admin dashboard" << endl;
                cout << "__________________________________________" << endl;
            }
            else
            {
                cout << "You have entered wrong pin please enter again" << endl;
                goto this_line;
            }
            do
            {
                cout << "Enter your choice" << endl;
                cout << "1. View all accounts" << endl;
                cout << "2. Modify account" << endl;
                cout << "3. Close account" << endl;
                cout << "0. Exit" << endl;
                cin >> admin_choice;
                found = false;
                switch (admin_choice)
                {
                case 1:
                    for (auto &admin : Details)
                    {
                        admin.Display_account_details();
                        admin.Display_status();
                    }
                    break;
                case 2:
                {
                    int modification_choice;
                    int accnt_number;
                    cout << "Enter the account number for modification" << endl;
                    cin >> accnt_number;
                    for (auto &admin : Details)
                    {
                        if (admin.search(accnt_number))
                        {
                            found = true;
                            do
                            {
                                cout << "What do you want to change" << endl;
                                cout << "1. Name" << endl;
                                cout << "2. Email" << endl;
                                cout << "3. Mobile number" << endl;
                                cout << "4. Address" << endl;
                                cout << "0. Exit" << endl;
                                cin >> modification_choice;
                                switch (modification_choice)
                                {
                                case 1:
                                {
                                    string modified_name;
                                    cout << "Enter new name to change previous name : ";
                                    cin.ignore();
                                    getline(cin, modified_name);
                                    admin.setName(modified_name);
                                    cout << "Name changed successfully" << endl;
                                    break;
                                }
                                case 2:
                                {
                                    string modified_email;
                                    cout << "Enter new email to change previous email : ";
                                    cin.ignore();
                                    getline(cin, modified_email);
                                    admin.setEmail(modified_email);
                                    cout << "Email changed successfully" << endl;
                                    break;
                                }
                                case 3:
                                {
                                    long long modified_mobile;
                                    cout << "Enter new mobile number to change previous mobile number : ";
                                    cin >> modified_mobile;
                                    admin.setMobile(modified_mobile);
                                    cout << "Mobile number changed successfully" << endl;
                                    break;
                                }
                                case 4:
                                {
                                    string modified_address;
                                    cout << "Enter new address to change previous : ";
                                    cin.ignore();
                                    getline(cin, modified_address);
                                    admin.setAddress(modified_address);
                                    cout << "Address change successfully" << endl;
                                    break;
                                }

                                default:
                                {
                                    
                                    break;
                                }
                                }
                            } while (modification_choice != 0);
                        }
                    }
                    if (!found)
                    {
                        cout << "You have entered wrong account number" << endl;
                    }
                    break;
                }
                case 3:
                {
                    int deactivation_acct_number;
                    cout << "Enter the account number you want to deactivate : ";
                    cin >> deactivation_acct_number;
                    found = false;
                    for (auto &admin : Details)
                    {
                        if (admin.search(deactivation_acct_number))
                        {
                            found = true;
                            admin.setStatus(0);
                            cout<<"Account deactivated successfully"<<endl;
                            break;
                        }
                    }
                    if (!found)
                    {
                        cout << "You have entered wrong account number" << endl;
                    }
                    break;
                }
                case 0:
                    cout << "Exiting from admin dashboard" << endl;
                    break;
                default:
                    cout << "Something went wrong in admin dashboard" << endl;
                    break;
                }

            } while (admin_choice != 0);
            break;
        }
        default:
            break;
        }
    } while (ch != 0);

    cout << "Happy Banking!" << endl;
    return 0;
}
