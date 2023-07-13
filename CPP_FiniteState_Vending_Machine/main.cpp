#include <iostream>
#include <string>

enum VendingMachineState {
    SELECT, QUANTITY, CALCULATE, UPDATE
};

enum Brand {
    COKE = 100, PEPSI = 200, SEVENUP = 300
};

struct Student {
    std::string name;
    int points;
};

struct Soda {
    Brand brandName;
    int inventory;
    int price;
};

int main()
{
    //initial Vending Machine State is SELECT. Update upon state change.
    VendingMachineState currentState = SELECT;

    //Fill up our vending machine with sodas.
    Soda vendingMachine[3];
    //Load up with Coke
    vendingMachine[0].brandName = COKE;
    vendingMachine[0].inventory = 10;
    vendingMachine[0].price = 1000;
    //Load up with Pepsi
    vendingMachine[1].brandName = PEPSI;
    vendingMachine[1].inventory = 10;
    vendingMachine[1].price = 2000;
    //Load up with Sevenup
    vendingMachine[2].brandName = SEVENUP;
    vendingMachine[2].inventory = 10;
    vendingMachine[2].price = 3000;

    Soda selectedSoda;
    Student user;
    user.name = "User";
    user.points = 100000; 

 while(true) {
    switch(currentState) {
        case SELECT:
            //1. Display the current status for the vending machine and the student's wallet.
            std::cout << "<<<<<---CURRENT STATUS--->>>>>" << std::endl;
            std::cout << "[[[Vending Machine]]]" << std::endl;
            for (int i=0; i < sizeof(vendingMachine)/sizeof(vendingMachine[0]); i++){
                std::cout << vendingMachine[i].brandName << " has " << vendingMachine[i].inventory << " drinks, and each costs " << vendingMachine[i].price << std::endl;
            }
            std::cout << "[[[Student]]]" << std::endl;
            std::cout << user.name << " has " << user.points << " points total. " << std::endl;
            std::cout << "<<<<<---END STATUS--->>>>>" << std::endl << std::endl;
            //2. Ask the user what drink they want. 
            std::cout << "Please select a drink from the follwing available options: " << std::endl;
            //3.Display the soda names and corresponding ID values.
            std::cout << "COKE = 100\nPEPSI = 200\nSEVENUP = 300" << std::endl;
            //4. user inputs the drink
            int selectedDrink;
            std::cin >> selectedDrink;
            //5. If valid drink selected, move to QUANTITY state; else, go back to SELECT state.
            switch (selectedDrink) {
                case COKE:
                    std::cout << "You have selected COKE" << std::endl;
                    selectedSoda.brandName = COKE;
                    currentState = QUANTITY;
                    break;
                case PEPSI:
                    std::cout << "You have selected PEPSI" << std::endl;
                    selectedSoda.brandName = PEPSI;
                    currentState = QUANTITY;
                    break;
                case SEVENUP:
                    std::cout << "You have selected SEVENUP" << std::endl;
                    selectedSoda.brandName = SEVENUP;
                    currentState = QUANTITY;
                    break;
                default:
                    std::cout << "Invalid drink selected!" << std::endl;
                    std::cout << std::endl << std::endl;
                    currentState = SELECT;
                    break;  
            }
            break;
        case QUANTITY:
            std::cout << "How many drinks would you like? ";
            int orderQuantity;
            std::cin >> orderQuantity;

            std::cout << "Your order has been received. You placed an order " << orderQuantity << " soda(s)." << std::endl;

            switch(selectedSoda.brandName){
                case COKE:
                    if (orderQuantity < 0 || orderQuantity > vendingMachine[0].inventory) {
                        std::cout << "Not enough in stock" << std::endl;
                        currentState = SELECT;
                        std::cout << std::endl << std::endl;
                    }else {
                        currentState = CALCULATE;
                    }
                    break;
                case PEPSI:
                 if (orderQuantity < 0 || orderQuantity > vendingMachine[1].inventory) {
                        std::cout << "Not enough in stock" << std::endl;
                        currentState = SELECT;
                        std::cout << std::endl << std::endl;
                    }else {
                        currentState = CALCULATE;
                    }
                    break;
                case SEVENUP:
                 if (orderQuantity < 0 || orderQuantity > vendingMachine[2].inventory) {
                        std::cout << "Not enough in stock" << std::endl;
                        currentState = SELECT;
                        std::cout << std::endl << std::endl;
                    }else {
                        currentState = CALCULATE;
                    }
                    break;
                default:
                    std::cout << "Invalid amount received." << std::endl;
                    break;
            }
            break;
        case CALCULATE:
            std::cout << "The total cost for your soda is: ";
            int cost;
            switch(selectedSoda.brandName) {
                case COKE:
                    cost = vendingMachine[0].price * orderQuantity;
                    std::cout << cost << std::endl;
                    break;
                case PEPSI:
                    cost = vendingMachine[1].price * orderQuantity;
                    std::cout << cost << std::endl;
                    break;
                case SEVENUP:
                    cost = vendingMachine[2].price * orderQuantity;
                    std::cout << cost << std::endl;
                    break;
                default:
                    std::cout << "Error!" << std::endl;
                    break;
            }
            int payment;
            std::cout << "Please type in your payment: ";
            std::cin >> payment;

            if(payment > user.points || payment < cost || payment <= 0) {
                std::cout << "You don't have enough money!" << std::endl;
                currentState = SELECT;
                std::cout << std::endl << std::endl;
            }else {
                user.points = user.points - payment;
                int change = payment - cost;
                std::cout << "Thank you! Your change is " << change << " points." << std::endl;
                user.points = user.points + change;
                currentState = UPDATE;
            }
            break;
        case UPDATE:
            switch(selectedSoda.brandName) {
                case COKE:
                    vendingMachine[0].inventory = vendingMachine[0].inventory - orderQuantity;
                    currentState = SELECT;
                    std::cout << std::endl << std::endl;
                    break;
                case PEPSI:
                    vendingMachine[1].inventory = vendingMachine[1].inventory - orderQuantity;
                    currentState = SELECT;
                    std::cout << std::endl << std::endl;
                    break;
                case SEVENUP:
                    vendingMachine[2].inventory = vendingMachine[2].inventory - orderQuantity;
                    currentState = SELECT;
                    std::cout << std::endl << std::endl;
                    break;
                default:
                    std::cout << "Error" << std::endl;
                    currentState = SELECT;
                    std::cout << std::endl << std::endl;
                    break;
            }

            std::cout << "Inventory updated" << std::endl;
            currentState = SELECT;
            std::cout << std::endl << std::endl;
            break;
        default:
        std::cout << "Error! Invalid State Detected." << std::endl;
        break;
    }
    }
   return 0;

}
