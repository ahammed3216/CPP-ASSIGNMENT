#include <iostream>
#include <xcb/xcb.h>

int main() {
    xcb_connection_t *connection = xcb_connect(nullptr, nullptr);
    if (xcb_connection_has_error(connection)) {
        std::cerr << "Cannot open XCB connection." << std::endl;
        return 1;
    }

    const uint32_t event_mask = XCB_CW_EVENT_MASK;
    const uint32_t value_list[] = { XCB_EVENT_MASK_KEY_PRESS | XCB_EVENT_MASK_KEY_RELEASE };

    xcb_screen_t *screen = xcb_setup_roots_iterator(xcb_get_setup(connection)).data;
    xcb_window_t window = screen->root;

    xcb_change_window_attributes(connection, window, event_mask, value_list);

    xcb_generic_event_t *event;
    while ((event = xcb_wait_for_event(connection))) {
        switch (event->response_type & ~0x80) {
            case XCB_KEY_PRESS: {
                xcb_key_press_event_t *key_event = (xcb_key_press_event_t *)event;
                xcb_keysym_t keysym = xcb_key_symbols_lookup_keysym(key_symbols, key_event->detail, 0);
                if (keysym == XK_a || keysym == XK_A) {
                    std::cout << "'A' key is pressed asynchronously." << std::endl;
                }
                break;
            }
        }
        free(event);
    }

    xcb_disconnect(connection);
    return 0;
}
