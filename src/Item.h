#ifndef ITEM_H
#define ITEM_H

#include <string>

// A simple structure to represent a product in the store.
// We use 'struct' because it's just a bundle of data with no complex logic.
struct Item {
    std::string name;
    double price;
    int stock;
    int in_cart; // Tracks how many of this item the user wants to buy
};

#endif // ITEM_H
