#include <stdio.h>
#include <stdint.h>

int main(void) {
    uint32_t value = 0x01020304;
    unsigned char *bytes = (unsigned char *)&value;

    printf("Value: 0x%08X\n", value);
    printf("Stored in memory as: ");
    for (int i = 0; i < 4; i++) {
        printf("%02X ", bytes[i]);
    }
    printf("\n");

    if (bytes[0] == 0x01) {
        printf("System is big-endian (most significant byte first)\n");
    } else if (bytes[0] == 0x04) {
        printf("System is little-endian (least significant byte first)\n");
    }

    return 0;
}
