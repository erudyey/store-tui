#include "UI.h"
#include <iostream>
#include <iomanip>
#include <cstdlib> // for system()

using namespace std;

void UI::clear_screen() {
    system("cls");
}

void UI::draw_splash() {
    clear_screen();
    cout << "=======================================================" << endl;
    cout << "   _    _    __                          _   " << endl;
    cout << "  /_\\  | |  / _| __ _ _ __ ___   __ _ _ __| |_ " << endl;
    cout << " //_\\\\ | | | |_ / _` | '_ ` _ \\ / _` | '__| __|" << endl;
    cout << "/  _  \\| | |  _| (_| | | | | | | (_| | |  | |_ " << endl;
    cout << "\\_/ \\_/_| |_|  \\__,_|_| |_| |_|\\__,_|_|   \\__|" << endl;
    cout << "                                               " << endl;
    cout << "=======================================================" << endl;
    cout << "          Welcome to the Alfamart TUI Store!           " << endl;
    cout << "=======================================================" << endl;
    cout << endl;
    cout << "            Press [ENTER] to Start Shopping            " << endl;
    cout << "            Press [SPACE] for Admin Mode               " << endl;
}

void UI::draw_store(const Store& store, int selected_index) {
    clear_screen();
    cout << "================== ALFAMART STORE =====================" << endl;
    cout << left << setw(4) << "No." 
         << setw(25) << "Item Name" 
         << setw(15) << "Price (PHP)" 
         << setw(10) << "Stock" 
         << setw(10) << "In-Cart" << endl;
    cout << "-------------------------------------------------------" << endl;

    const auto& inventory = store.get_inventory();
    for (size_t i = 0; i < inventory.size(); ++i) {
        if (i == selected_index) {
            cout << " > "; // Selection cursor
        } else {
            cout << "   ";
        }

        cout << left << setw(4) << (i + 1) 
             << setw(25) << inventory[i].name 
             << "PHP " << fixed << setprecision(2) << setw(11) << inventory[i].price 
             << setw(10) << inventory[i].stock 
             << setw(10) << inventory[i].in_cart << endl;
    }
    cout << "-------------------------------------------------------" << endl;
    cout << " [W/S] Navigate   [A/D] Add/Remove Cart   [ENTER] Checkout" << endl;
}

void UI::draw_receipt(const Store& store) {
    clear_screen();
    cout << "=======================================================" << endl;
    cout << "                  OFFICIAL RECEIPT                     " << endl;
    cout << "                    ALFAMART TUI                       " << endl;
    cout << "=======================================================" << endl;
    cout << left << setw(25) << "Item" 
         << setw(10) << "Qty" 
         << setw(15) << "Price (PHP)" 
         << setw(15) << "Total (PHP)" << endl;
    cout << "-------------------------------------------------------" << endl;

    const auto& inventory = store.get_inventory();
    for (const auto& item : inventory) {
        if (item.in_cart > 0) {
            double item_total = item.price * item.in_cart;
            cout << left << setw(25) << item.name 
                 << setw(10) << item.in_cart 
                 << "PHP " << fixed << setprecision(2) << setw(11) << item.price 
                 << "PHP " << setw(11) << item_total << endl;
        }
    }

    cout << "-------------------------------------------------------" << endl;
    cout << right << setw(50) << "Subtotal: PHP " << store.get_subtotal() << endl;
    cout << right << setw(50) << "VAT (12%): PHP " << store.get_vat() << endl;
    cout << "=======================================================" << endl;
    cout << right << setw(50) << "GRAND TOTAL: PHP " << store.get_total() << endl;
    cout << "=======================================================" << endl;
    cout << "            Thank you for shopping with us!            " << endl;
    cout << endl;
    cout << "            Press [ENTER] to Exit                      " << endl;
}

void UI::draw_admin(const Store& store, int selected_index) {
    clear_screen();
    cout << "================== ADMIN STOCK MODE ===================" << endl;
    cout << left << setw(4) << "No." 
         << setw(25) << "Item Name" 
         << setw(15) << "Price (PHP)" 
         << setw(10) << "Stock" << endl;
    cout << "-------------------------------------------------------" << endl;

    const auto& inventory = store.get_inventory();
    for (size_t i = 0; i < inventory.size(); ++i) {
        if (i == selected_index) {
            cout << " > ";
        } else {
            cout << "   ";
        }

        cout << left << setw(4) << (i + 1) 
             << setw(25) << inventory[i].name 
             << "PHP " << fixed << setprecision(2) << setw(11) << inventory[i].price 
             << setw(10) << inventory[i].stock << endl;
    }
    cout << "-------------------------------------------------------" << endl;
    cout << " [W/S] Navigate   [A/D] Add/Remove Stock   [ENTER] Return" << endl;
}
