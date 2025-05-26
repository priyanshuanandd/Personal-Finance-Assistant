# 💰 Personal Finance Assistant (C++ CLI)

A command-line based Personal Finance Assistant built in C++ using Object-Oriented Programming principles. It helps users manage income, expenses, budgets, and receive savings advice interactively.

---

## 🚀 Features

- 🔐 User Authentication (Basic)
- 💵 Add Income and Expenses
- 📊 Budget Management
- 📈 Dynamic Financial Dashboard
- 💡 Smart Savings Suggestions
- 🧱 Object-Oriented Architecture:
  - ✅ Encapsulation
  - ✅ Inheritance
  - ✅ Polymorphism
  - ✅ Abstraction

---

## 🏗️ Object-Oriented Design

| OOP Principle   | How It's Used                                                                 |
|-----------------|--------------------------------------------------------------------------------|
| **Encapsulation** | User data like income and expenses are private with public getters/setters.  |
| **Inheritance**   | `PersonalFinanceUser` inherits from `User` to extend functionality.           |
| **Polymorphism**  | Virtual functions like `showDashboard()` allow flexible behavior.             |
| **Abstraction**   | `FinanceAssistant` is an abstract base class defining the interface.         |

---

## 🖥️ Usage

### 🔧 Requirements

- C++17 or higher
- g++ / clang / MSVC compiler

### 🛠️ Compile

```bash
g++ -std=c++17 -o finance_assistant main.cpp
./finance_assistant
```

##🔐 Login Credentials
###Default seeded user:

-User ID: user1
-Password: pass1
###You can expand login by editing the userLogins map.

##📸 Sample Output
[![image.png](https://i.postimg.cc/prBPgzpx/image.png)](https://postimg.cc/tnY0613m)

##🧑‍💻 Author
Developed with ❤️ in C++ to demonstrate real-world use of Object-Oriented Programming by Priyanshu Anand.
