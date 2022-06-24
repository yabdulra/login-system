#include <iostream>
#include <fstream>
#include <string>

bool IsLoggedIn() {
    std::string username, password, un, pw;

    std::cout << "Enter username: "; std::cin >> username;
    std::cout << "Enter password: "; std::cin >> password;

    std::ifstream read("C:\\Users\\yusuf\\OneDrive\\Desktop\\C++20Projects\\LoginSystem\\LoginSystem\\" + username + ".txt");

    std::getline(read, un);
    std::getline(read, pw);
    
    if (un == username && pw == password) return true;
       
    return false;
}

int main()
{
    int choice;

    std::cout << "1. Register" << std::endl << "2. Login" << std::endl << "Your choice: ";
    std::cin >> choice;
    switch (choice)
    {
    case 1: {
        std::string username, password;

        std::cout << "Choose username: "; std::cin >> username;
        std::cout << "Choose password: "; std::cin >> password;

        std::ofstream file;
        file.open("C:\\Users\\yusuf\\OneDrive\\Desktop\\C++20Projects\\LoginSystem\\LoginSystem\\" + username + ".txt");
        file << username << std::endl << password;
        file.close();

        main();
    }
          break;
    case 2: {
        bool status = IsLoggedIn();

        if (!status) {
            std::cout << "User not found, please register first." << std::endl;
            system("PAUSE");
            main();
        }
        else {
            std::cout << "Successfully logged in!" << std::endl;
            system("PAUSE");
            return 1;
        }
    }
          break;
    default:
        std::cout << "Invalid option" << std::endl;
        break;
    }
}

