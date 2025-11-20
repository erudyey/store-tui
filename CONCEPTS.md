# Concepts Guide

Here's a quick breakdown of the C++ terms I used in the project, just so we're all on the same page.

## 1. Arrays
Standard C++ uses arrays like `int arr[5]` to hold simple lists of data.

**Why I used this**
Actually, I avoided using them for the inventory! Arrays have a fixed size, meaning we'd have to decide the maximum number of items forever (e.g., `Item inventory[100]`). If we wanted 101 items, the app would crash. That's why I switched to **Vectors**.

## 2. `std::vector`
A **Vector** is just a "smart array" that can grow. When we use `inventory.push_back(item)`, it adds the item and automatically resizes the container if needed.

**Why I used this**
This lets our store inventory be flexible. We can start with 3 items or 300, and the code doesn't need to change. It also saves us from "Index Out of Bounds" errors because the vector knows its own size.

## 3. Header Files (`.h`) vs Source Files (`.cpp`)
Think of the **Header File (`.h`)** like a menu. It lists what's available (the functions and variables) but doesn't show you how it's made.
The **Source File (`.cpp`)** is the kitchen recipe. It has the actual code that does the work.

**Why I used this**
This keeps our project organized. You can open `Store.h` and see exactly what the store *can do* (add to cart, checkout) without getting distracted by the math and logic in `Store.cpp`.

## 4. Struct vs Class
I used both in this project:
- **Struct (`Item`)**: A simple box for holding data (Name, Price, Stock).
- **Class (`Store`)**: A box that holds data *plus* actions (Inventory + Add/Remove functions).

**Why I used this**
It helps us separate "things" from "logic". `Item` is just a thing. `Store` is the brain that manages those things.

## 5. Pass by Reference (`&`)
Imagine I have a huge textbook.
- **Pass by Value**: I photocopy the whole book and give you the copy. Slow and wasteful.
- **Pass by Reference (`&`)**: I just hand you my actual book. Fast and efficient.

**Why I used this**
In `UI.cpp`, I used `void draw_store(Store& store)`. The `&` symbol means the UI is looking at the *actual* Store object in memory, not a copy. This makes the app faster because we aren't copying the entire inventory every time we draw the screen.

## 6. Static Methods
Usually, you need an object to use a function (like `myStore.add_to_cart()`).
But for helper tools like `UI::clear_screen()`, we don't need a specific "UI object" to do it.

**Why I used this**
It makes the `UI` class act like a toolbox. We can just call `UI::draw_splash()` from anywhere without needing to create a `new UI()` variable first.
