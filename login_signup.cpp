#include <bits/stdc++.h>
using namespace std;

unordered_map<string, string> userMap;

void login();
void signUp();
bool isValidUser(const string &id, const string &pass);
bool isValidUsername(const string &uname);
void showMenu();
void homePage();

void homePage()
{
    cout << endl;
    int n;
    cout << "Welcome!" << endl
         << "Please select from the following options by entering the corresponding number:" << endl;
    cout << "1. Sign up" << endl;
    cout << "2. Log in" << endl;
    cout << "3. Exit" << endl;
    cout << "Please make your selection (enter 1, 2, or 3): ";
    cin >> n;

    switch (n)
    {
    case 1:
        signUp();
        break;
    case 2:
        login();
        break;
    case 3:
        cout << "Program is closing..." << endl;
        return;
    default:
        cout << "Invalid Choice!" << endl;
        homePage();
    }
}

void login()
{
    cout << endl;
    cout << "---LOGIN PAGE---" << endl;
    string uid, pass;

    cout << "UserId: ";
    cin >> uid;
    cout << "Password: ";
    cin >> pass;

    if (isValidUser(uid, pass))
    {
        cout << "Login Successful!" << endl;
        showMenu();
    }
    else
    {
        cout << "Invalid ID or Password." << endl
             << endl;
        login();
    }
}

void signUp()
{
    cout << endl;
    cout << "---Sign Up PAGE---" << endl
         << endl;
    ;
    string name, uname, pass;
    int age;
    cin.ignore();
    cout << "Enter your Full Name: ";
    getline(cin, name);

    cout << "Enter your age: ";
    cin >> age;

    while (true)
    {
        cout << "Create your username: ";
        cin >> uname;

        if (isValidUsername(uname))
        {
            break;
        }
        else
        {
            cout << "Username already exists. Please try a different username." << endl;
        }
    }

    cout << "Create your Password: ";
    cin >> pass;

    userMap[uname] = pass;
    cout << "User Created Successfully!" << endl;
    login();
}

bool isValidUsername(const string &uname)
{
    return userMap.find(uname) == userMap.end();
}

bool isValidUser(const string &id, const string &pass)
{
    auto it = userMap.find(id);
    if (it != userMap.end() && it->second == pass)
    {
        return true;
    }
    return false;
}

void showMenu()
{
    cout << endl
         << endl;
    int n;
    cout << "---MENU---" << endl
         << "Please select from the following options by entering the corresponding number:" << endl;
    cout << "1. Show Feed" << endl;
    cout << "2. Friends" << endl;
    cout << "3. Inbox" << endl;
    cout << "4. Create a Message" << endl;
    cout << "5. Exit" << endl
         << "Your choice: ";
    cin >> n;

    switch (n)
    {
    case 1:
        cout << "Show Feed" << endl;
        break;
    case 2:
        cout << "Friends" << endl;
        break;
    case 3:
        cout << "Inbox" << endl;
        break;
    case 4:
        cout << "Create a Message" << endl;
        break;
    case 5:
        cout << "Exiting program..." << endl;
        return;
    default:
        cout << "Invalid Choice! Try again." << endl;
        showMenu();
    }
}
int main()
{
    homePage();
    return 0;
}