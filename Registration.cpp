#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function to check whether username already exists
bool usernameExists(string username)
{
    ifstream file("users.txt");

    string storedUsername;
    string storedPassword;

    while (file >> storedUsername >> storedPassword)
    {
        if (storedUsername == username)
        {
            return true;
        }
    }

    return false;
}

// Registration function
void registerUser()
{
    string username;
    string password;

    cout << "\n===== REGISTRATION =====\n";

    cout << "Enter username: ";
    cin >> username;

    // Check duplicate username
    if (usernameExists(username))
    {
        cout << "Username already exists!\n";
        return;
    }

    cout << "Enter password: ";
    cin >> password;

    // Store username and password
    ofstream file("users.txt", ios::app);

    file << username << " " << password << endl;

    file.close();

    cout << "Registration successful!\n";
}

// Login function
void loginUser()
{
    string username;
    string password;

    cout << "\n===== LOGIN =====\n";

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    ifstream file("users.txt");

    string storedUsername;
    string storedPassword;

    bool loginSuccessful = false;

    while (file >> storedUsername >> storedPassword)
    {
        if (storedUsername == username &&
            storedPassword == password)
        {
            loginSuccessful = true;
            break;
        }
    }

    file.close();

    if (loginSuccessful)
    {
        cout << "Login successful!\n";
        cout << "Welcome, " << username << "!\n";
    }
    else
    {
        cout << "Invalid username or password!\n";
    }
}

int main()
{
    int choice;

    while (true)
    {
        cout << "\n============================\n";
        cout << " LOGIN & REGISTRATION SYSTEM\n";
        cout << "============================\n";

        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                registerUser();
                break;

            case 2:
                loginUser();
                break;

            case 3:
                cout << "Thank you!\n";
                return 0;

            default:
                cout << "Invalid choice!\n";
        }
    }

    return 0;
}