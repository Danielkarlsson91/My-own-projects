#include <iostream> // Include standard input-output stream library
#include <fstream>  // Include file stream library
#include <iomanip>  // Include input-output manipulation library
#include <thread>   // Include thread library
#include <chrono>   // Include chrono library for time functions

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h> // Include windows.h for system color command
#endif

void menu(); // Function prototype for menu

// Function to change terminal color based on the operating system
void changeColor()
{
#if defined(_WIN32) || defined(_WIN64)
    system("color 0A"); // Windows command to change terminal color
#else
    std::cout << "\033[32m"; // Unix-based systems command to change text color to green
#endif
}

// Class to manage the menu and user interaction
class ManageMenu
{
protected:
    std::string userName; // User name for admin

public:
    // Constructor
    ManageMenu()
    {
        changeColor(); // Change terminal color
        std::cout << "\n\n\n\n\n\n\n\n\nEnter your first name to continue as an admin: ";
        std::cin >> userName; // Get user name from input
        system("CLS");        // Clear the screen
        menu();               // Call the menu function
    }

    ~ManageMenu() {} // Destructor
};

// Class to manage customer details
class Customers
{
public:
    std::string name, gender, address; // Customer details
    int age, mobileNumber, menuBack;   // Customer age, mobile number, and menu navigation
    static int customerID;             // Static customer ID shared among all instances
    char all[999];                     // Buffer to read customer details from file

    // Function to get customer details
    void getDetails()
    {
        std::ofstream out("old-customers.txt", std::ios::app); // Open file in append mode
        {
            std::cout << "Please enter Customer ID: " << std::endl;
            std::cin >> customerID; // Input customer ID
            std::cout << "Please enter Name: " << std::endl;
            std::cin >> name; // Input customer name
            std::cout << "Please enter Age: " << std::endl;
            std::cin >> age; // Input customer age
            std::cout << "Please enter Mobile Number: " << std::endl;
            std::cin >> mobileNumber; // Input customer mobile number
            std::cout << "Please enter Address: " << std::endl;
            std::cin >> address; // Input customer address
            std::cout << "Please enter Gender: " << std::endl;
            std::cin >> gender; // Input customer gender
        }
        // Write customer details to file
        out << "\nCustomer ID: " << customerID << "\nName: " << name << "\nAge: " << age << "\nMobile Number: " << mobileNumber << "\nAddress: " << address << "\nGender: " << gender << std::endl;
        out.close(); // Close the file
        std::cout << "\nSaved \nNOTE: We save your details record for future purposes\n"
                  << std::endl;
    }

    // Function to show customer details
    void show_details()
    {
        std::ifstream in("old-customers.txt"); // Open file in input mode
        if (!in)
        { // Check if file is opened
            std::cout << "File Error!" << std::endl;
        }
        else
        {
            while (!(in.eof()))
            {                                  // Read file till end
                in.getline(all, 999);          // Get line from file
                std::cout << all << std::endl; // Print the line
            }
            in.close(); // Close the file
        }
    }
};

int Customers::customerID; // Initialize static customer ID

// Class to manage cab details
class Cabs
{
public:
    int cabchoice;              // Cab choice
    int kilometers;             // Distance to travel
    float cab_cost;             // Cab cost
    static float last_cab_cost; // Static last cab cost shared among all instances

    // Function to get cab details and calculate cost
    void cab_details()
    {
        std::cout << "We collaborated with fastest, safest, and smartest cab service around the country" << std::endl;
        std::cout << "----------Diserod Cabs----------\n"
                  << std::endl;
        std::cout << "1. Rent a standard cab - £0.15 for 1km\n"
                  << std::endl;
        std::cout << "2. Rent a luxury cab - £0.25 per 1km" << std::endl;

        std::cout << "\nTo calculate the cost for your journey: " << std::endl;
        std::cout << "Please enter which kind of cab you need: ";
        std::cin >> cabchoice; // Get cab choice from user
        std::cout << "Please enter kilometers you have to travel: ";
        std::cin >> kilometers; // Get distance from user

        int hire_cab; // Variable to store user's choice for hiring cab

        if (cabchoice == 1)
        {
            cab_cost = kilometers * 1.5; // Calculate cost for standard cab
            std::cout << "\nYour travel cost £" << cab_cost << " for a standard cab" << std::endl;
            std::cout << "Please press 1 to hire this cab or";
            std::cout << " press 2 to select another cab: ";
            std::cin >> hire_cab; // Get user's choice to hire or reselect cab

            system("CLS"); // Clear the screen

            if (hire_cab == 1)
            {
                last_cab_cost = cab_cost; // Set last cab cost
                std::cout << "\nYou have successfully hired a standard cab" << std::endl;
                std::cout << "Go to menu and take the receipt" << std::endl;
            }
            else if (hire_cab == 2)
            {
                cab_details(); // Reselect cab
            }
            else
            {
                std::cout << "Invalid input! Going back to previous menu \nPlease Wait!" << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(1100)); // Wait for 1.1 seconds
                system("CLS");                                                // Clear the screen
                cab_details();                                                // Reselect cab
            }
        }
        else if (cabchoice == 2)
        {
            cab_cost = kilometers * 2.0; // Calculate cost for luxury cab
            std::cout << "\nYour travel cost £" << cab_cost << " for a luxury cab" << std::endl;
            std::cout << "Please press 1 to hire this cab or";
            std::cout << " press 2 to select another cab: ";
            std::cin >> hire_cab; // Get user's choice to hire or reselect cab
            system("CLS");        // Clear the screen

            if (hire_cab == 1)
            {
                last_cab_cost = cab_cost; // Set last cab cost
                std::cout << "\nYou have successfully hired a luxury cab" << std::endl;
                std::cout << "Go to main menu to take the receipt" << std::endl;
            }
            else if (hire_cab == 2)
            {
                cab_details(); // Reselect cab
            }
            else
            {
                std::cout << "Invalid input! Going back to previous menu \nPlease Wait!" << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(1100)); // Wait for 1.1 seconds
                system("CLS");                                                // Clear the screen
                cab_details();                                                // Reselect cab
            }
        }
        else
        {
            std::cout << "Invalid input! Going back to main menu \nPlease Wait!" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(1100)); // Wait for 1.1 seconds
            system("CLS");                                                // Clear the screen
            menu();                                                       // Go to main menu
        }

        std::cout << "\nPlease press 1 to going back to main menu: ";
        std::cin >> hire_cab; // Get user's choice to go back to main menu
        system("CLS");        // Clear the screen
        if (hire_cab == 1)
        {
            menu(); // Go to main menu
        }
        else
        {
            menu(); // Go to main menu
        }
    }
};

float Cabs::last_cab_cost; // Initialize static last cab cost

// Class to manage hotel bookings
class Booking
{
public:
    int choice_hotels;       // Hotel choice
    int pack_choice;         // Package choice
    int go_to_menu;          // Variable to store user's choice to go to menu
    static float hotel_cost; // Static hotel cost shared among all instances

    // Function to manage hotel bookings
    void hotels()
    {
        std::string hotel_number[] = {"Clarion", "Scandic", "FarsHatt"}; // Array of hotel names

        for (int i = 0; i < 3; i++)
        {
            std::cout << (i + 1) << ". Hotel" << hotel_number[i] << std::endl; // Print hotel names
        }

        std::cout << "\nCurrently we collaborated with above hotels!" << std::endl;

        std::cout << "Please press any key to back or\nEnter number of the hotel you want to book: ";
        std::cin >> choice_hotels; // Get hotel choice from user

        system("CLS"); // Clear the screen

        if (choice_hotels == 1)
        {
            std::cout << "------WELCOME TO CLARION------\n"
                      << std::endl;
            std::cout << "The Garden, food and beverage. Enjoy all you can drink, stay cool and get chilled in the summer sun." << std::endl;

            std::cout << "Packages offered by Clarion:\n"
                      << std::endl;

            std::cout << "1. Standard Pack" << std::endl;
            std::cout << "\tAll basic facilities you need for just: £50.00" << std::endl;
            std::cout << "2, Premium Pack" << std::endl;
            std::cout << "\tEnjoy Premium: £100.00" << std::endl;
            std::cout << "3. Luxury Pack" << std::endl;
            std::cout << "\tLive Luxury at Clarion: £150.00" << std::endl;

            std::cout << "\nPress another key to back or\nPlease enter package number you want to book: ";
            std::cin >> pack_choice; // Get package choice from user

            if (pack_choice == 1)
            {
                hotel_cost = 50.00; // Set hotel cost for standard pack
                std::cout << "\nYou have successfully booked the Standard Pack at Clarion" << std::endl;
                std::cout << "Go back to the menu and take the receipt" << std::endl;
            }
            else if (pack_choice == 2)
            {
                hotel_cost = 100.00; // Set hotel cost for premium pack
                std::cout << "\nYou have successfully booked the Premium Pack at Clarion" << std::endl;
                std::cout << "Go back to the menu and take the receipt" << std::endl;
            }
            else if (pack_choice == 3)
            {
                hotel_cost = 150.00; // Set hotel cost for luxury pack
                std::cout << "\nYou have successfully booked the Luxury Pack at Clarion" << std::endl;
                std::cout << "Go back to the menu and take the receipt" << std::endl;
            }
            else
            {
                std::cout << "Invalid input! Going back to previous menu \nPlease Wait!" << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(1100)); // Wait for 1.1 seconds
                system("CLS");                                                // Clear the screen
                hotels();                                                     // Reselect hotel
            }
        }
        else
        {
            std::cout << "Invalid input! Going back to main menu \nPlease Wait!" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(1100)); // Wait for 1.1 seconds
            system("CLS");                                                // Clear the screen
            menu();                                                       // Go to main menu
        }

        std::cout << "\nPlease press 1 to going back to main menu: ";
        std::cin >> go_to_menu; // Get user's choice to go back to main menu
        system("CLS");          // Clear the screen
        if (go_to_menu == 1)
        {
            menu(); // Go to main menu
        }
        else
        {
            menu(); // Go to main menu
        }
    }
};

float Booking::hotel_cost; // Initialize static hotel cost

// Main menu function
void menu()
{
    int mainChoice; // Variable to store user's choice in main menu
    int inChoice;   // Variable to store user's choice in inner menu
    std::cout << "\t\t    * MAIN MENU *\n";
    std::cout << "\t\t__________________________\n";
    std::cout << "\t\t| 1. Customer Management |\n";
    std::cout << "\t\t| 2. Cabs Management     |\n";
    std::cout << "\t\t| 3. Bookings Management |\n";
    std::cout << "\t\t| 4. Exit                |\n";
    std::cout << "\t\t__________________________\n";
    std::cout << "Enter your choice: ";
    std::cin >> mainChoice; // Get user's choice from main menu

    system("CLS"); // Clear the screen

    // Switch case to handle different menu choices
    switch (mainChoice)
    {
    case 1:
    {
        std::cout << "\t\t    * CUSTOMER MANAGEMENT *\n"
                  << std::endl;
        std::cout << "\t\t____________________________\n"
                  << std::endl;
        std::cout << " 1. Enter New Customer\n"
                  << std::endl;
        std::cout << " 2. See Old Customers\n"
                  << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> inChoice; // Get user's choice in customer management

        system("CLS"); // Clear the screen

        Customers a; // Create an object of Customers class

        // Inner switch case to handle customer management choices
        switch (inChoice)
        {
        case 1:
            a.getDetails(); // Get new customer details
            break;
        case 2:
            a.show_details(); // Show old customer details
            break;
        default:
            std::cout << "Invalid input! Please try again." << std::endl;
            menu(); // Go back to main menu
        }
        break;
    }
    case 2:
    {
        Cabs b;          // Create an object of Cabs class
        b.cab_details(); // Get cab details and calculate cost
        break;
    }
    case 3:
    {
        Booking c;  // Create an object of Booking class
        c.hotels(); // Manage hotel bookings
        break;
    }
    case 4:
    {
        std::cout << "\n\n\t---GOOD-BYE!---" << std::endl;    // Exit message
        std::this_thread::sleep_for(std::chrono::seconds(2)); // Wait for 2 seconds
        system("CLS");                                        // Clear the screen
        exit(0);                                              // Exit the program
        break;
    }
    default:
    {
        std::cout << "Invalid input! Please try again." << std::endl;
        menu(); // Go back to main menu
        break;
    }
    }
}

int main()
{
    ManageMenu startObj; // Create an object of ManageMenu class to start the program
    return 0;            // Return 0 to indicate successful execution
}
