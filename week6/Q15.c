#include <stdio.h>
#include <stdint.h>

void address_translation(uint32_t virtual_address) {
    uint32_t page_number = 0;
    uint32_t offset = 0;

    // Calculate page_number using a right-shift operation (>>)
    // Shifting right by 12 bits discards the offset, leaving the upper 20 bits.
    page_number = virtual_address >> 12;

    // Calculate offset using a bitwise AND operation (&) with mask 0xFFF
    // 0xFFF (binary 1111 1111 1111) preserves only the lower 12 bits.
    offset = virtual_address & 0xFFF;

    printf("[1A] Addr: 0x%08X -> Page: %u (0x%X), Offset: %u (0x%X)\n", 
           virtual_address, page_number, page_number, offset, offset);
}

int main() {
    // Test Inputs
    address_translation(0x00000000);
    address_translation(0x00000FFF);
    address_translation(0x00001000);
    address_translation(0x00003A2C);

    return 0;
}