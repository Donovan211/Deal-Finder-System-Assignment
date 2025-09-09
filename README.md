# BUZZ MART INC. – Deal Finder & Budget Tracker

A console-based **C++ project** developed for **NCOS515 (Introduction to Programming, 2025)** at **Sol Plaatje University**.  
This system simulates a budget-aware shopping experience with discounts, admin oversight, and customer feedback handling.

---

## Key Features

### User
- Register and login with username & password
- Set and manage a shopping budget
- Browse product categories:
  - Household Appliances
  - Groceries
  - Self Care
  - Liquor
- Add items to cart with quantity selection
- Receive **discounts** based on spending:
  - 20% off above R2000
  - 15% off above R1500
  - 10% off above R500
  - 5% off above R20
- Get **budget warnings** if overspending
- View order history
- Leave comments/feedback (analyzed for vowel count, uppercase, and reversed)

### Admin
- Secure login with default admin credentials  
  (`username: admin | password: admin123`)
- View number of registered users
- Review user comments (if any exist… no pressure)
- Access order history for all users


## Data & Structures
- Struct 'User' - Stores user info (username, password, role, order history, budget)  
- Vectors - Manage users, comments, and order history dynamically  
- Validation - Input checks for wrong credentials, invalid menu options, and empty data  

## Language 
- C++ language


