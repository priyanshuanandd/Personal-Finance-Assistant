#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

// --- Abstract Base Class (Abstraction) ---
class FinanceAssistant {
public:
    virtual void showDashboard() = 0;
    virtual void manageBudget() = 0;
    virtual void trackExpenses() = 0;
    virtual void suggestSavingsPlan() = 0;
    virtual ~FinanceAssistant() = default;
};

// --- Base User Class (Encapsulation) ---
class User {
protected:
    string id;
    string name;
    string email;
    double income;
    double expenses;

public:
    User(string id, string name, string email, double income = 0.0)
        : id(id), name(name), email(email), income(income), expenses(0.0) {}

    virtual ~User() = default;

    void addIncome(double amount) { income += amount; }
    void addExpense(double amount) { expenses += amount; }

    double getIncome() const { return income; }
    double getExpenses() const { return expenses; }
    string getName() const { return name; }

    double getBalance() const { return income - expenses; }
};

// --- Derived Class with Specific Implementation (Inheritance + Polymorphism) ---
class PersonalFinanceUser : public User, public FinanceAssistant {
private:
    double budgetLimit;

public:
    PersonalFinanceUser(string id, string name, string email)
        : User(id, name, email), budgetLimit(0.0) {}

    void setBudget(double limit) { budgetLimit = limit; }

    void showDashboard() override {
        cout << "\n--- Financial Dashboard ---\n";
        cout << "Name: " << name << "\n";
        cout << "Total Income: $" << income << "\n";
        cout << "Total Expenses: $" << expenses << "\n";
        cout << "Current Balance: $" << getBalance() << "\n";
        cout << "Budget Limit: $" << budgetLimit << "\n";
    }

    void manageBudget() override {
        cout << "Enter new monthly budget limit: ";
        cin >> budgetLimit;
        cout << "Budget updated to $" << budgetLimit << endl;
    }

    void trackExpenses() override {
        double expense;
        cout << "Enter expense amount: ";
        cin >> expense;
        addExpense(expense);
        cout << "Expense of $" << expense << " added.\n";
    }

    void suggestSavingsPlan() override {
        double balance = getBalance();
        cout << "\n--- Savings Advice ---\n";
        if (balance <= 0) {
            cout << "You're overspending. Reduce discretionary expenses.\n";
        } else if (balance < 0.2 * income) {
            cout << "Try to save at least 20% of your income.\n";
        } else {
            cout << "Great job! Consider investing the surplus.\n";
        }
    }
};

// --- Login Management (Encapsulation) ---
map<string, string> userLogins;

bool authenticate(const string &id, const string &password) {
    return userLogins.find(id) != userLogins.end() && userLogins[id] == password;
}

// --- Main CLI ---
int main() {
    // Seed user login
    userLogins["user1"] = "pass1";
    PersonalFinanceUser user("user1", "John Doe", "john@example.com");

    cout << "Welcome to the Personal Finance Assistant\n";

    while (true) {
        string id, pass;
        cout << "\nLogin\nUser ID: ";
        cin >> id;
        cout << "Password: ";
        cin >> pass;

        if (authenticate(id, pass)) {
            cout << "Login successful.\n";

            while (true) {
                cout << "\n--- Main Menu ---\n";
                cout << "1. View Dashboard\n";
                cout << "2. Add Income\n";
                cout << "3. Add Expense\n";
                cout << "4. Set Budget\n";
                cout << "5. Get Savings Advice\n";
                cout << "6. Logout\n";
                cout << "Enter your choice: ";

                int choice;
                cin >> choice;

                switch (choice) {
                case 1:
                    user.showDashboard();
                    break;
                case 2: {
                    double amount;
                    cout << "Enter income amount: ";
                    cin >> amount;
                    user.addIncome(amount);
                    cout << "Income added.\n";
                    break;
                }
                case 3:
                    user.trackExpenses();
                    break;
                case 4:
                    user.manageBudget();
                    break;
                case 5:
                    user.suggestSavingsPlan();
                    break;
                case 6:
                    cout << "Logging out...\n";
                    goto END_SESSION;
                default:
                    cout << "Invalid choice. Try again.\n";
                    break;
                }
            }
        } else {
            cout << "Invalid credentials. Try again.\n";
        }
    }

END_SESSION:
    cout << "Thank you for using the Finance Assistant.\n";
    return 0;
}
