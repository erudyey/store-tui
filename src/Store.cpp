#include "Store.h"

Store::Store() {
    init();
}

void Store::init() {
    // Pre-populate with Alfamart-themed items (Real-world prices approx.)
    inventory.push_back({"Coke 1.5L", 75.00, 20, 0});
    inventory.push_back({"Piattos Cheese 40g", 20.00, 30, 0});
    inventory.push_back({"Cornetto Chocolate Disc", 30.00, 15, 0});
}

const std::vector<Item>& Store::get_inventory() const {
    return inventory;
}

std::vector<Item>& Store::get_inventory_mutable() {
    return inventory;
}

void Store::add_to_cart(int index, int amount) {
    if (index >= 0 && index < inventory.size()) {
        // Check if we have enough stock
        if (inventory[index].stock >= amount) {
            inventory[index].in_cart += amount;
            inventory[index].stock -= amount;
        }
    }
}

void Store::remove_from_cart(int index, int amount) {
    if (index >= 0 && index < inventory.size()) {
        if (inventory[index].in_cart >= amount) {
            inventory[index].in_cart -= amount;
            inventory[index].stock += amount;
        }
    }
}

void Store::clear_cart() {
    for (auto& item : inventory) {
        // Return items to stock if we clear cart without buying? 
        // Usually 'checkout' finalizes it. 
        // If we just want to reset for next customer:
        item.in_cart = 0;
    }
}

void Store::update_stock(int index, int amount) {
    if (index >= 0 && index < inventory.size()) {
        inventory[index].stock += amount;
        if (inventory[index].stock < 0) inventory[index].stock = 0;
    }
}

double Store::get_subtotal() const {
    double total = 0.0;
    for (const auto& item : inventory) {
        total += item.price * item.in_cart;
    }
    return total;
}

double Store::get_vat() const {
    // VAT in the Philippines is 12%
    return get_subtotal() * 0.12;
}

double Store::get_total() const {
    return get_subtotal() + get_vat();
}
