#ifndef UI_H
#define UI_H

#include "Store.h"

class UI {
public:
    static void clear_screen();
    static void draw_splash();
    static void draw_store(const Store& store, int selected_index);
    static void draw_receipt(const Store& store);
    static void draw_admin(const Store& store, int selected_index);
};

#endif // UI_H
