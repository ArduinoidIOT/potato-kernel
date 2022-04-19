#include <stdint.h>
#include <stddef.h>
#include "limine_requests.hpp"


// The following will be our kernel's entry point.
void _start(void) {
    // Ensure we got a terminal
    if (terminal_request.response == NULL || terminal_request.response->terminal_count < 1) {
        asm("hlt");
    }

    // We should now be able to call the Limine terminal to print out
    // a simple "Hello World" to screen.
    struct limine_terminal *terminal = terminal_request.response->terminals[0];
    terminal_request.response->write(terminal, "Hello World", 11);

    // We're done, just hang...
    asm("hlt");
}
