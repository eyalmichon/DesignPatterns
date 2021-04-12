#include <iostream>
using namespace std;

class ATMState
{
public:
    virtual void insertCard() = 0;
    virtual void ejectCard() = 0;
    virtual void insertPin(int pinEntered) = 0;
    virtual void requestCash(int amountToWithdraw) = 0;
};

class ATMMachine
{
    ATMState *_hasCard;
    ATMState *_noCard;
    ATMState *_hasCorrectPin;
    ATMState *_atmOutOfMoney;

    ATMState *atmState;
    int cashInMachine = 200000;
    bool correctPinEntered = false;

public:
    ATMMachine() : _hasCard(nullptr), _noCard(nullptr), _hasCorrectPin(nullptr), _atmOutOfMoney(nullptr){};
    void setStates(ATMState *hasCard, ATMState *noCard, ATMState *hasCorrectPin, ATMState *noCash)
    {
        _hasCard = hasCard;
        _noCard = noCard;
        _hasCorrectPin = hasCorrectPin;
        _atmOutOfMoney = noCash;
        atmState = _noCard;
    }
    void setATMState(ATMState &newATMState)
    {
        atmState = &newATMState;
    }
    void insertCard()
    {
        atmState->insertCard();
    }
    void ejectCard()
    {
        atmState->ejectCard();
    }
    void insertPin(int pinEntered)
    {
        atmState->insertPin(pinEntered);
    }
    void requestCash(int amountToWithdraw)
    {
        atmState->requestCash(amountToWithdraw);
    }
    int getCashInMachine()
    {
        return cashInMachine;
    }
    void setCashInMachine(int withdrawnCash)
    {
        cashInMachine -= withdrawnCash;
    }
    ATMState &getCardInsideState() { return *_hasCard; }
    ATMState &getNoCardState()
    {

        correctPinEntered = false;
        return *_noCard;
    }
    ATMState &getHasPinState()
    {
        correctPinEntered = true;
        return *_hasCorrectPin;
    }
    ATMState &getOutOfMoneyState() { return *_atmOutOfMoney; }
};

class HasCard : public ATMState
{
    ATMMachine *atmMachine;

public:
    HasCard(ATMMachine &machine)
    {
        atmMachine = &machine;
    }
    virtual void insertCard()
    {
        cout << "You cannot insert more than one card at a time..." << endl;
    }
    virtual void ejectCard()
    {
        cout << "Please take your card..." << endl;
        atmMachine->setATMState(atmMachine->getNoCardState());
    }
    virtual void insertPin(int pinEntered)
    {
        if (pinEntered == 3124)
        {
            cout << "Correct PIN, you may continue..." << endl;
            atmMachine->setATMState(atmMachine->getHasPinState());
        }
        else
        {
            cout << "Wrong PIN!\nCard Ejected!" << endl;
            atmMachine->setATMState(atmMachine->getNoCardState());
        }
    }
    virtual void requestCash(int amountToWithdraw)
    {
        cout << "Enter PIN First!" << endl;
    }
};

class NoCard : public ATMState
{
    ATMMachine *atmMachine;

public:
    NoCard(ATMMachine &machine)
    {
        atmMachine = &machine;
    }
    virtual void insertCard()
    {
        cout << "Please Enter a PIN" << endl;
        atmMachine->setATMState(atmMachine->getCardInsideState());
    }
    virtual void ejectCard()
    {
        cout << "Enter a Card first..." << endl;
    }
    virtual void insertPin(int pinEntered)
    {
        cout << "Enter a Card first..." << endl;
    }
    virtual void requestCash(int amountToWithdraw)
    {
        cout << "Enter a Card first..." << endl;
    }
};

class HasCorrectPin : public ATMState
{
    ATMMachine *atmMachine;

public:
    HasCorrectPin(ATMMachine &machine)
    {
        atmMachine = &machine;
    }
    virtual void insertCard()
    {
        cout << "You cannot insert more than one card at a time..." << endl;
    }
    virtual void ejectCard()
    {
        cout << "Please take your card..." << endl;
        atmMachine->setATMState(atmMachine->getNoCardState());
    }
    virtual void insertPin(int pinEntered)
    {
        cout << "PIN already entered..." << endl;
    }
    virtual void requestCash(int amountToWithdraw)
    {
        if (amountToWithdraw > atmMachine->getCashInMachine())
        {
            cout << "There isn't enough money in this machine...\nSorry...\nEjecting Card..." << endl;
            atmMachine->setATMState(atmMachine->getNoCardState());
        }
        else
        {
            cout << "You have withdrawed $" << amountToWithdraw << " from the ATM.\nEjecting Card, Have a nice day..." << endl;
            atmMachine->setCashInMachine(amountToWithdraw);
            atmMachine->setATMState(atmMachine->getNoCardState());
            if (atmMachine->getCashInMachine() <= 0)
                atmMachine->setATMState(atmMachine->getOutOfMoneyState());
        }
    }
};
class NoCash : public ATMState
{
    ATMMachine *atmMachine;

public:
    NoCash(ATMMachine &machine)
    {
        atmMachine = &machine;
    }
    virtual void insertCard()
    {
        cout << "No Cash, Go find another ATM..." << endl;
    }
    virtual void ejectCard()
    {
        cout << "No Cash, Go find another ATM..." << endl;
    }
    virtual void insertPin(int pinEntered)
    {
        cout << "No Cash, Go find another ATM..." << endl;
    }
    virtual void requestCash(int amountToWithdraw)
    {
        cout << "No Cash, Go find another ATM..." << endl;
    }
};

int main(int argc, char const *argv[])
{
    ATMMachine *machine = new ATMMachine();
    machine->setStates(new NoCard(*machine), new HasCard(*machine), new HasCorrectPin(*machine), new NoCash(*machine));
    while (true)
    {
        int chosenMenu;
        cout << "Welcome to the ATM\nPlease choose an option:\n1) Insert a card\n2) Eject a card\n3) Insert PIN\n4) Request Cash\n5) Exit" << endl;
        cin >> chosenMenu;
        switch (chosenMenu)
        {
        case 1:
            machine->insertCard();
            break;
        case 2:
            machine->ejectCard();
            break;
        case 3:
            cout << "Enter PIN: ";
            int PIN;
            cin >> PIN;
            machine->insertPin(PIN);
            break;
        case 4:
            cout << "Enter cash to withdrawal: ";
            int cash;
            cin >> cash;
            machine->requestCash(cash);
            break;
        case 5:
            cout << "Bye Bye :)" << endl;
            break;
        default:
            break;
        }
    }
    return 0;
}
