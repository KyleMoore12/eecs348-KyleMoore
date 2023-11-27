#include <iostream>
#include <iomanip>

class Account
{
protected:
    std::string accountNumber;
    std::string accountHolder;
    mutable double balance;

public:
    Account(const std::string &number, const std::string &holder, double initialBalance)
        : accountNumber(number), accountHolder(holder), balance(initialBalance) {}

    void displayDetails() const
    {
        std::cout << "Account Details for " << getAccountType() << " Account (ID: " << accountNumber << "):\n"
                  << "   Holder: " << accountHolder << "\n"
                  << "   Balance: $" << std::fixed << std::setprecision(2) << balance << "\n";
        displayAdditionalDetails();
        std::cout << std::endl;
    }

    virtual std::string getAccountType() const
    {
        return "Generic";
    }

    virtual void displayAdditionalDetails() const {}

    void deposit(double amount)
    {
        balance += amount;
    }

    virtual void withdraw(double amount)
    {
        if (balance >= amount)
        {
            balance -= amount;
        }
        else
        {
            std::cout << "Insufficient funds for withdrawal.\n";
        }
    }

    friend Account operator+(Account &lhs, Account &rhs)
    {
        double transferAmount = 300;
        if (rhs.balance >= transferAmount)
        {
            Account result("Transfer", "Transfer", transferAmount);
            result.balance = transferAmount;
            result.withdraw(transferAmount);
            rhs.withdraw(transferAmount);
            lhs.deposit(transferAmount);
            std::cout << "Transferred $" << transferAmount << " between accounts.\n";
            return result;
        }
        else
        {
            std::cout << "Insufficient funds for transfer.\n";
            return Account("Transfer", "Transfer", 0);
        }
    }

    friend std::ostream &operator<<(std::ostream &os, const Account &account)
    {
        os << "Account Details for " << account.getAccountType() << " Account (ID: " << account.accountNumber << "):\n"
           << "   Holder: " << account.accountHolder << "\n"
           << "   Balance: $" << std::fixed << std::setprecision(2) << account.balance << "\n";
        account.displayAdditionalDetails();
        return os;
    }
};

class SavingsAccount : public Account
{
private:
    double interestRate;

public:
    SavingsAccount(const std::string &number, const std::string &holder, double initialBalance, double rate)
        : Account(number, holder, initialBalance), interestRate(rate) {}

    std::string getAccountType() const override
    {
        return "Savings";
    }

    void displayAdditionalDetails() const override
    {
        std::cout << "   Interest Rate: " << std::fixed << std::setprecision(2) << (interestRate * 100) << "%\n";
    }

    void withdraw(double amount) override
    {
        const double minBalance = 100; // Assuming a minimum balance for a savings account
        if (balance - amount >= minBalance)
        {
            balance -= amount;
        }
        else
        {
            std::cout << "Insufficient funds for withdrawal from the savings account.\n";
        }
    }
};

class CurrentAccount : public Account
{
private:
    double overdraftLimit;

public:
    CurrentAccount(const std::string &number, const std::string &holder, double initialBalance, double limit)
        : Account(number, holder, initialBalance), overdraftLimit(limit) {}

    std::string getAccountType() const override
    {
        return "Current";
    }

    void displayAdditionalDetails() const override
    {
        std::cout << "   Overdraft Limit: $" << std::fixed << std::setprecision(2) << overdraftLimit << "\n";
    }

    void withdraw(double amount) override
    {
        if (balance + overdraftLimit >= amount)
        {
            balance -= amount;
        }
        else
        {
            std::cout << "Insufficient funds for withdrawal from the current account.\n";
        }
    }
    CurrentAccount &operator=(const Account &other)
    {
        if (this != &other)
        {
            if (const CurrentAccount *derived = dynamic_cast<const CurrentAccount *>(&other))
            {
                Account::operator=(other);
                overdraftLimit = derived->overdraftLimit;
            }
        }
        return *this;
    }
};

int main()
{
    SavingsAccount savings("S123", "John Doe", 1000, 0.02);
    CurrentAccount current("C456", "Jane Doe", 2000, 500);

    savings.displayDetails();
    current.displayDetails();

    savings.deposit(500);
    current.withdraw(1000);
    std::cout << "Account Details after deposit and withdrawal:\n";
    savings.displayDetails();
    current.displayDetails();

    // Transfer 300 from savings to current
    current = current + savings;
    std::cout << "Account Details after transfer:\n";
    savings.displayDetails();
    current.displayDetails();

    return 0;
}