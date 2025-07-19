/*
Sol Plaatje University
Group Leader:
======================================== 
Unathi Spele 202517137
========================================
Group Members:
========================================
Nvula Bontes 202546741
Jerusalem Kinfe Sarero 202566209
Phathutshedzo Michelle Mahada 202524881
Langelihle Prince Nkosi 202400574
Nhlakanipho Clinton Nkosi 202551179
Oabile Mokhuane 202552357
Sean Jayden Cupido 202541801
Mulanga Ramantswana 202557910
Gofaone Myataza 202582174
Ncedo Ncabane 202449697
==========================================================================================================================================
//Group Assignment NCOS515 2025
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <limits>
#include <cctype>
#include <algorithm>

using namespace std;

//Global Data
    struct User
    {
    string username;
    string password;
    bool isAdmin;
    vector<string> orderHistory;
    double budget;
    };
    vector<string> userComments;
    vector<User> users = {{"admin", "admin123", true}};
    User* currentUser = nullptr;

//Login System
    void runLoginSystem()
    {
        string storedUsername = "";
        string storedPassword = "";
        string inputUsername, inputPassword;
        string adminUsername = "admin";
        string adminPassword = "admin123";
        int attempts;
        int choice;

    cout << "-----------------------------" << endl;
    cout << "--WELCOME TO BUZZ MART INC.--" << endl;
    cout << "-----------------------------" << endl;

        while (true)
        {
            cout << "-------------------------------" << endl;
            cout << "1.Register" << endl;
            cout << "2.Login" << endl;
            cout << "3.Exit" << endl;
            cout << "-------------------------------" << endl;
            cout << "Choose an option: ";
            cin >> choice;
            cout << endl;

            if (cin.fail())
            {
                cout << "Invalid input! Please enter a valid number." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
                cout << endl;
            }
            if (choice == 1)
            {
                cout << "|-----------------------------------------------------------|" << endl;
                cout << "  Please create your username and password for registration" << endl;
                cout << "|-----------------------------------------------------------|" << endl;
                cout << "Create a Username: ";
                cin >> storedUsername;
                cout << "Create a Password: ";
                cin >> storedPassword;
                cout <<endl;
                users.push_back({storedUsername, storedPassword, false, {}});

                cout << endl;
                cout << "Registration successful!" << endl;
                cout << "Let's see how far your wallet's bravery takes you..." <<endl;
                cout << endl;
            }
            else if (choice == 2)
            {
                attempts = 3;

                while (attempts > 0)
                {
                    cout << "-----------------------------------" << endl;
                    cout << "||Please enter your login details||" << endl;
                    cout << "-----------------------------------" << endl;
                    cout <<endl;
                    cout << "Username: ";
                    cin >> inputUsername;
                    cout << "Password: ";
                    cin >> inputPassword;

                    if(inputUsername == adminUsername && inputPassword == adminPassword)
                    {
                        currentUser = &users[0];
                        cout << "Login successful. welcome to BUZZ MART administrator, " << inputUsername << "!" << endl;
                        return;
                    }
                    for (auto & user : users)
                    {
                        if(inputUsername == user.username && inputPassword == user.password)
                        {
                            currentUser = &user;
                            cout << endl;
                            cout << "WELCOME TO BUZZ MART " << inputUsername << "!" << endl;
                            cout << endl;
                            cout << "============================================================================================" << endl;
                            cout << "Logged in. Let's go ruin your self-esteem with some 'special offers' you still can't afford." << endl;
                            cout << "============================================================================================" << endl;
                            return;
                        }
                    }
                    attempts--;
                    cout << "Incorrect credentials. Attempts left: " << attempts << endl;
                }
                cout << "Access denied." << endl;
                cout << endl;
                cout << "Wrong credentials.Not even your own account wants you." << endl;
                cout << endl;
            }
            else if (choice == 3)
            {
            exit(0);
            }

            else
            {
            cout << "Invalid choice. Please try again." << endl;
            }
        cout<< "----------------------------------------" << endl;
        }
    }

//Deal Finder System
void runDealFinder()
{
    int categorySelection;
    int cartCount = 0;
    string cartItems[50][2];
    int totalPrice = 0;

    if (currentUser && !currentUser->isAdmin && currentUser->budget == 0)
        {
        double userBudget;
        cout << "=======================================================" << endl;
        cout << "Enter your shopping budget (R): ";
        cin >> userBudget;
        cout << "=======================================================" << endl;
        currentUser->budget = userBudget;
        cout << endl;
        }
    do
    {
        cout << endl;
        cout << "----------------------" << endl;
        cout << "Available categories" << endl;
        cout << "----------------------" << endl;
        cout << "0. Checkout" << endl;
        cout << "1. Household Appliances" << endl;
        cout << "2. Groceries" << endl;
        cout << "3. Self Care" << endl;
        cout << "4. Liquor" << endl;
        cout << "----------------------" << endl;
        cout << endl;

        cout << "Please select one of the categories above (1-4) or (0) to return to the main menu: ";
        cin >> categorySelection;
        cout << endl;

        if (cin.fail())
        {
                cout << "Invalid input! Please enter a valid number." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
                cout << endl;
        }
        if (categorySelection == 0)
        {
            cout << endl;
            cout << "Thank you for shopping at BUZZ MART. Shop like you're broke, leave like a baller!" << endl;
            cout << "=================================================================================" << endl;
            break;
        }
        int cartSelection;

        if (categorySelection == 1)
        {
            cout << "-----------------------" << endl;
            cout << "Household Appliances:" << endl;
            cout << "-----------------------" << endl;
            cout << setw(10) << "Item" << setw(25) << "Price" << right << setw(20) << "Store" << endl;
            cout << "--------------------------------------------------------------------------------------" << endl;

            string appliances[8] = {"Kettle", "Fridge", "Washing Machine", "Microwave", "Stove", "Air-fryer", "Dishwasher", "Vacuum Cleaner"};
            int prices[8] = {250, 2100, 4500, 900, 3600, 800, 5500, 400};
            string applianceStores[8] = {"Checkers", "Game", "Game", "Pick n Pay", "Game", "Makro", "Makro", "Checkers"};
            cout << left << setw(5) << "0" << "Back" << endl;

            for (int i = 0; i < 8; i++)
            {
                cout << left << setw(5) << (i + 1) << setw(25) << appliances[i] << "R " << prices[i]  << right << setw(20) << applianceStores[i] << right << endl;
            }
            cout << "-----------------------" << endl;
        }
        else if (categorySelection == 2)
        {
            cout << "-----------------------" << endl;
            cout << "Groceries:" << endl;
            cout << "-----------------------" << endl;
            cout << setw(10) << "Item" << setw(25) << "Price" << right << setw(21) << "Store" << endl;
            cout << "-------------------------------------------------------------------------------------" << endl;

            string groceries[8] = {"Rice 10kg", "Sugar 10kg", "Cooking Oil 2L", "Salt 750ml", "Flour 10kg", "Maize meal 10kg", "Milk 2L", "Bread"};
            int prices[8] = {220, 215, 90, 40, 120, 100, 31, 19};
            string applianceStores[8] = {"Makro", "Checkers", "Shoprite", "Pick n Pay", "Checkers", "Clicks", "Checkers", "Shoprite"};
            cout << left << setw(5) << "0" << "Back" << endl;

            for (int i = 0; i < 8; i++)
            {
                cout << left << setw(5) << (i + 1) << setw(25) << groceries[i] << "R " << prices[i]  << right << setw(22) << applianceStores[i] << left << endl;
            }
            cout << "-----------------------" << endl;
        }
        else if (categorySelection == 3)
        {
            cout << "------------------------" << endl;
            cout << "Self Care:" << endl;
            cout << "------------------------" << endl;
            cout << setw(10) << "Item" << setw(25) << "Price" << right << setw(18) << "Store" << endl;
            cout << "-----------------------------------------------------------------------------------" << endl;

            string selfCare[8] = {"Shampoo", "Toothpaste", "Bar Soap", "Deodorant", "Vaseline", "Hair Conditioner", "Lip Therapy", "Shaver"};
            int prices[8] = {93, 55, 20, 56, 70, 44, 25, 65};
            string applianceStores[8] = {"Clicks", "Checkers", "Shoprite", "Pick n Pay", "Checkers", "Clicks", "Checkers", "Clicks"};
            cout << left << setw(5) << "0" << "Back" << endl;

            for (int i = 0; i < 8; i++)
            {
                cout << left << setw(5) << (i + 1) << setw(25) << selfCare[i] << "R " << prices[i]  << right << setw(20) << applianceStores[i] << right << endl;
            }
            cout << "------------------------" << endl;
        }
        else if (categorySelection == 4)
        {
            cout << "-------------------------" << endl;
            cout << "Liquor:" << endl;
            cout << "-------------------------" << endl;
            cout << setw(10) << "Item" << setw(25) << "Price" << setw(18) << "Store" << endl;
            cout << "------------------------------------------------------------------------------" << endl;

            string liquor[8] = {"Flying Fish", "Heineken", "Three Ships", "Hennessy", "Billiato", "Smirnoff", "Black Label", "Jagermeister"};
            int prices[8] = {25, 28, 350, 600, 350, 180, 23, 340};
            string applianceStores[8] = {"Pick n Pay Liquor", "Checkers Liquor", "Liquor City", "Pick n Pay Liquor", "Checkers Liquor", "Liquor City", "Checkers Liquor", "Liquor City"};
            cout << left << setw(5) << "0" << "Back" << endl;

            for (int i = 0; i < 8; i++)
            {
                cout << left << setw(5) << (i + 1) << setw(25) << liquor[i] << "R " << prices[i]  << right << setw(20) << applianceStores[i] << right << endl;
            }
            cout << "-------------------------" << endl;
        }
        else
        {
            cout << "Invalid category. Try again." << endl;
            continue;
        }

        cout << endl;
        cout << "To add to cart select (1-8) or (0) to go Back: ";
        cin >> cartSelection;
        cout << endl;

        if (cartSelection == 0)
        {
            continue;
        }
        else if (cartSelection < 1 || cartSelection > 8)
        {
            cout << "Invalid selection." << endl;
            continue;
        }

        int qty;
        cout << "Enter quantity: ";
        cin >> qty;

        string itemName;
        int itemPrice = 0;

        if (categorySelection == 1)
        {
            string appliances[8] = {"Kettle", "Fridge", "Washing Machine", "Microwave", "Stove", "Air-fryer", "Dishwasher", "Vacuum Cleaner"};
            int prices[8] = {250, 2100, 4500, 900, 3600, 800, 5500, 400};
            itemName = appliances[cartSelection - 1];
            itemPrice = prices[cartSelection - 1];
        }
        else if (categorySelection == 2)
        {
            string groceries[8] = {"Rice 10kg", "Sugar 10kg", "Cooking Oil 2L", "Salt 750ml", "Flour 10kg", "Maize meal 10kg", "Milk 2L", "Bread"};
            int prices[8] = {220, 215, 90, 40, 120, 100, 31, 19};
            itemName = groceries[cartSelection - 1];
            itemPrice = prices[cartSelection - 1];
        }
        else if (categorySelection == 3)
        {
            string selfCare[8] = {"Shampoo", "Toothpaste", "Bar Soap", "Deodorant", "Vaseline", "Hair Conditioner", "Lip Therapy", "Shaver"};
            int prices[8] = {93, 55, 20, 56, 70, 44, 25, 65};
            itemName = selfCare[cartSelection - 1];
            itemPrice = prices[cartSelection - 1];
        }
        else if (categorySelection == 4)
        {
            string liquor[8] = {"Flying Fish", "Heineken", "Three Ships", "Hennessy", "Billiato", "Smirnoff", "Black Label", "Jagermeister"};
            int prices[8] = {25, 28, 350, 600, 350, 180, 23, 340};
            itemName = liquor[cartSelection - 1];
            itemPrice = prices[cartSelection - 1];
        }

        cartItems[cartCount][0] = itemName + " (x" + to_string(qty) + ")";
        cartItems[cartCount][1] = "R" + to_string(itemPrice * qty);
        cartCount++;

        totalPrice += itemPrice * qty;

        cout << "Added to cart: " << itemName << " (x" << qty << ")";

    }
    while (true);

        if (cartCount > 0)
        {
            cout << endl;
            cout << "Your Cart Summary:" << endl;
            cout << "------------------" << endl;
            for (int i = 0; i < cartCount; i++)
            {
                cout << i + 1 << ". " << cartItems[i][0] << " - " << cartItems[i][1] << endl;
            }
            cout << "Total Amount BEFORE DISCOUNT: R" << totalPrice << endl;

            if (totalPrice >= 2000)
            {
                double discount = totalPrice * 0.20;
                totalPrice -= discount;
                cout << "---------------------------------------" << endl;
                cout << "20% DISCOUNT APPLIED: -R" << discount << endl;
                cout << "---------------------------------------" << endl;
            }
            else if (totalPrice >= 1500)
            {
                double discount = totalPrice * 0.15;
                totalPrice -= discount;
                cout << "---------------------------------------" << endl;
                cout << "15% DISCOUNT APPLIED: -R" << discount << endl;
                cout << "---------------------------------------" << endl;
            }
            else if (totalPrice >= 500)
            {
                double discount = totalPrice * 0.10;
                totalPrice -= discount;
                cout << "---------------------------------------" << endl;
                cout << "10% Discount Applied: -R" << discount << endl;
                cout << "---------------------------------------" << endl;
            }
            else if (totalPrice >= 20)
            {
                double discount = totalPrice * 0.05;
                totalPrice -= discount;
                cout << "---------------------------------------" << endl;
                cout << "5% Discount Applied: -R" << discount << endl;
                cout << "---------------------------------------" << endl;
            }
            else
            {
                cout << "No discount applied." << endl;
            }

            cout << endl;
            cout << "Total Amount AFTER DISCOUNT: R" << totalPrice << endl;
            cout << endl;

            if (currentUser && !currentUser->isAdmin)
            {
                if (totalPrice > currentUser->budget)
                {
                    cout << "--------------------------------------------------------------------------" << endl;
                    cout << "WARNING: Your total exceeds your budget of R" << currentUser->budget << "!" << endl;
                    cout << "You are over budget by R" << (totalPrice - currentUser->budget) << endl;

                    char proceed;
                    cout << "Do you still want to proceed with the purchase? (Y/N): ";
                    cin >> proceed;
                    cout << "--------------------------------------------------------------------------" << endl;
                    cout << endl;

                    if (toupper(proceed) != 'Y')
                    {
                        cout << "Checkout cancelled." << endl;
                        return;
                    }
                    else
                    {
                        cout << "Congrats! You're now shopping on hopes and dreams" << endl;
                        cout << "Current savings: Somewhere between 'HAHA' and 'BROKE'." << endl;
                        cout << endl;
                    }
                }
            else
            {
                cout << "You are within your budget of R" << currentUser->budget << endl;
                cout << "Remaining budget: R" << (currentUser->budget - totalPrice) << endl;
            }
        }


            if (currentUser)
            {
                string orderSummary = "Deal Finder Order: R" + to_string(totalPrice);
                currentUser->orderHistory.push_back(orderSummary);
            }
        }
        else
        {
            cout << "Your cart was empty." << endl;
        }

}

//Main Menu
void mainMenu()
{
    if (currentUser && !currentUser->isAdmin)
    {
        cout << "Your shopping budget: R" << currentUser->budget << endl;
    }
    while (true)
    {
        int choice;
        string userComment;

        if(currentUser && !currentUser->isAdmin)
        {
            cout << "---------------------------------" << endl;
            cout << "   MAIN MENU   " << endl;
            cout << "---------------------------------" << endl;
            cout << "1. Deal Finder System" << endl;
            cout << "2. Leave a comment" << endl;
            cout << "3. View Order History" << endl;
            cout << "4. Logout" << endl;
            cout << "---------------------------------" << endl;
            cout << "Choice: ";
            cin >> choice;

            if (cin.fail())
            {
                cout << "Invalid input! Please enter a valid number." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
                cout << endl;
            }

            switch (choice)
            {
                case 1:
                    runDealFinder();
                    break;
                case 2:
                {
                    int vowelcount = 0;
                    cout << "Please type down your comment, then press enter: ";

                    string userComment;
                    cin.ignore();
                    getline(cin, userComment);

                    userComments.push_back(userComment);

                    for (char c : userComment)
                    {
                        char n = tolower(c);

                        if (n == 'a' || n == 'e' || n == 'i' || n == 'o' || n == 'u')
                        vowelcount++;
                    }

                    string upper = userComment;
                    transform(upper.begin(),upper.end(),upper.begin(),::toupper);

                    string reversed = userComment;
                    reverse(reversed.begin(),reversed.end());

                    cout << "Vowel count: " << vowelcount << endl;
                    cout << "Upper Case: " << upper << endl;
                    cout << "reversed: " << reversed << endl;

                    cout << "--------------------------------------------------------------------------------------------" << endl;
                    cout << "Thank you for your feedback. This will allow us to further improve our customer services." << endl;
                    cout << "--------------------------------------------------------------------------------------------" << endl;
                    break;
                }
                case 3:
                    if (currentUser)
                    {
                        cout << "Your Orders: " << endl;
                        for (auto& order : currentUser->orderHistory)
                            cout << order << endl;
                    }
                    break;
                case 4:
                    currentUser = nullptr;
                    return;
                default:
                    cout << "Invalid decision!" << endl;
            }
        }
        else if (currentUser && currentUser->isAdmin)
        {
            cout << endl;
            cout << "---------------------" << endl;
            cout << "1. Admin Settings" << endl;
            cout << "2. view user comments" << endl;
            cout << "3. View Order History" << endl;
            cout << "4. Logout" << endl;
            cout << "---------------------" << endl;
            cout << "choice: " << endl;
            cin >> choice;

            if (cin.fail())
            {
                cout << "Invalid input! Please enter a valid number." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
                cout << endl;
            }

            switch (choice)
            {
            case 1:
            {
                cout << "Number of users who accessed the system: " << users.size() << endl;
                break;
            }
            case 2:
                {
                    cout << "User comments: " << endl;

                    if (userComments.empty())
                    {
                        cout << "No comments have been placed into the system yet." << endl;
                        cout << "Not even bots wanna sign up. That's crazy." << endl;
                    }
                    else
                    {
                        for (size_t i = 0; i < userComments.size(); ++i)
                        {
                            cout << i + 1 << ". " << userComments[i] << endl;
                        }
                    }
                    break;
                }
                break;
            case 3:
            {
                cout << "User order histories: " << endl;

                if (users.empty())
                {
                    cout << "No users in the system yet." << endl;
                    cout << endl;
                }
                else
                {
                    for (const auto& user : users)
                    {
                        cout << "Username: " << user.username << endl;

                        if (user.orderHistory.empty())
                        {
                            cout << "  No orders have been placed yet. " << endl;
                        }
                        else
                        {
                            cout << "  Orders: "<< endl;

                            for (size_t i = 0; i < user.orderHistory.size(); ++i)
                            {
                                cout << "  " << i + 1 << ". " << user.orderHistory[i] << endl;
                            }
                        }
                        cout << "----------------------" << endl;
                    }
                }
                break;
            }
            case 4:
                currentUser = nullptr;
                    return;
            default:
                cout << "Invalid decision!" << endl;

            }
        }
    }
}

//Main Function
int main()
{
    while (true)
    {
        runLoginSystem();

        mainMenu();

    }

    return 0;
}


