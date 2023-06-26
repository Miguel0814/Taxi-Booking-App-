#include <fstream>
#include <iostream>
#include <string>

using namespace std;
// register and store users logins

void reg() {
  string username, password;
  cout << "Register your username" << endl;
  cin >> username;
  cout << "Register your passowrd" << endl;
  cin >> password;
  cout << "Welcome for registering with us" << endl;
  ofstream file("reg.txt", ios::app);
  file << username << " " << password << endl;
  file.close();
}

bool login() {
  string username, password;
  cout << "Please enter your username" << endl;
  cin >> username;
  cout << "please enter your password" << endl;
  cin >> password;
  ifstream file("reg.txt");
  string line;
  while (getline(file, line)) {
    if (line.find(username + " " + password) != string::npos) {
      return true;
    }
  }
  return false;
}
// after 3 attempts of logins failed, the system will display a message 
void attempt() {
  int attempt = 0;
  if (attempt < 3) {
    cout << "Login terminated. Please contact our customer service" << endl;
  }
}

// allowing users to login and register to use the service

int main() {
  int choice = 0;
  int attempt = 3;
  while (choice != 2) {
    cout << "[1]Login" << endl;
    cout << "[2]Register" << endl;
    cin >> choice;

    switch (choice) {
    case 1:
      if (login()) {
        cout << "Welcome back" << endl;
      } else {
        cout << "Please register to continue" << endl;
      }

      break;

    case 2:
        reg();
        break;
     

    case 3:
      cout << "Please contact care team for assistance. Thank you!" << endl;


    default:

      cout << "Welcome to online taxi booking system" << endl;
      break;
    }
  }

  return 0;
}
