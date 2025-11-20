#ifndef STORE_H
#define STORE_H

#include <vector>
#include "Item.h"

class Store {
public:
    // Constructor
    Store();

    // Initialize the store with default items
    void init();

    // Get the list of items (const reference to avoid copying)
    const std::vector<Item>& get_inventory() const;

    // Modify the inventory (for admin and cart updates)
    std::vector<Item>& get_inventory_mutable();

    // Cart operations
    void add_to_cart(int index, int amount);
    void remove_from_cart(int index, int amount);
    void clear_cart();

    // Admin operations
    void update_stock(int index, int amount);

    // Financial calculations
    double get_subtotal() const;
    double get_vat() const;
    double get_total() const;

private:
    std::vector<Item> inventory;
};

#endif // STORE_H
