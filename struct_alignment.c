#include <stdio.h>
#include <stddef.h>

/* Poorly ordered struct - has padding */
struct padded {
    char a;      /* 1 byte  + 3 bytes padding */
    int b;       /* 4 bytes */
    char c;      /* 1 byte  + 3 bytes padding */
    int d;       /* 4 bytes */
};

/* Well-ordered struct - minimal padding */
struct packed {
    int b;       /* 4 bytes */
    int d;       /* 4 bytes */
    char a;      /* 1 byte  */
    char c;      /* 1 byte  + 2 bytes padding (to align struct size to 4) */
};

void print_layout(const char *name, size_t size) {
    printf("%-20s total size: %zu bytes\n", name, size);
}

void print_offset(const char *field, size_t offset, size_t size) {
    printf("  %-10s offset: %2zu  size: %zu\n", field, offset, size);
}

int main(void) {
    printf("=== Struct with padding (poor member ordering) ===\n");
    print_layout("struct padded", sizeof(struct padded));
    print_offset("a (char)", offsetof(struct padded, a), sizeof(char));
    print_offset("b (int)",  offsetof(struct padded, b), sizeof(int));
    print_offset("c (char)", offsetof(struct padded, c), sizeof(char));
    print_offset("d (int)",  offsetof(struct padded, d), sizeof(int));

    printf("\n=== Struct with minimal padding (optimized ordering) ===\n");
    print_layout("struct packed", sizeof(struct packed));
    print_offset("b (int)",  offsetof(struct packed, b), sizeof(int));
    print_offset("d (int)",  offsetof(struct packed, d), sizeof(int));
    print_offset("a (char)", offsetof(struct packed, a), sizeof(char));
    print_offset("c (char)", offsetof(struct packed, c), sizeof(char));

    printf("\n=== Key takeaways ===\n");
    printf("- Members are aligned to their size (int aligns to 4 bytes)\n");
    printf("- Compiler inserts padding bytes to satisfy alignment\n");
    printf("- Ordering members from largest to smallest reduces waste\n");
    printf("- struct padded wastes %zu bytes vs struct packed\n",
           sizeof(struct padded) - sizeof(struct packed));

    return 0;
}
