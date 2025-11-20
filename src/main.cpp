#include <conio.h> // For _getch()
#include "Store.h"
#include "UI.h"

using namespace std;

enum State {
    START,
    STORE_MODE,
    CHECKOUT,
    ADMIN
};

int main() {
    Store store;
    State current_state = START;
    bool running = true;
    int selected_index = 0;

    while (running) {
        switch (current_state) {
            case START:
                UI::draw_splash();
                {
                    int key = _getch();
                    if (key == 13) { // Enter
                        current_state = STORE_MODE;
                    } else if (key == 32) { // Space
                        current_state = ADMIN;
                    }
                }
                break;

            case STORE_MODE:
                UI::draw_store(store, selected_index);
                {
                    int key = _getch();
                    // Simple WASD handling
                    if (key == 'w' || key == 'W') {
                        if (selected_index > 0) selected_index--;
                    } else if (key == 's' || key == 'S') {
                        if (selected_index < store.get_inventory().size() - 1) selected_index++;
                    } else if (key == 'a' || key == 'A') {
                        store.remove_from_cart(selected_index, 1);
                    } else if (key == 'd' || key == 'D') {
                        store.add_to_cart(selected_index, 1);
                    } else if (key == 13) { // Enter
                        current_state = CHECKOUT;
                    }
                }
                break;

            case CHECKOUT:
                UI::draw_receipt(store);
                {
                    int key = _getch();
                    if (key == 13) { // Enter to exit
                        running = false;
                    }
                }
                break;

            case ADMIN:
                UI::draw_admin(store, selected_index);
                {
                    int key = _getch();
                    if (key == 'w' || key == 'W') {
                        if (selected_index > 0) selected_index--;
                    } else if (key == 's' || key == 'S') {
                        if (selected_index < store.get_inventory().size() - 1) selected_index++;
                    } else if (key == 'a' || key == 'A') {
                        store.update_stock(selected_index, -1);
                    } else if (key == 'd' || key == 'D') {
                        store.update_stock(selected_index, 1);
                    } else if (key == 13) { // Enter
                        current_state = START; // Return to start
                    }
                }
                break;
        }
    }

    return 0;
}
