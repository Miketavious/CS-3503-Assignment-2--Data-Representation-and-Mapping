#include <stdint.h>
#include <stdio.h>
#include <string.h>


void oct_to_bin(const char *oct, char *out) {
    int pos = 0;
    //iterating through octal string
    for (int i = 0; oct[i] != '\0'; i++) {
        int oct_digit = oct[i] - '0'; //extracting bits for octal

        out[pos++] = (oct_digit >> 2) & 1 ? '1' : '0';
        out[pos++] = (oct_digit >> 1) & 1 ? '1' : '0';
        out[pos++] = (oct_digit >> 0) & 1 ? '1' : '0';
    }
    out[pos] = '\0';
}
void oct_to_hex(const char * oct, char *out) {
    char binary[100]; //storage of intermediate binary
    oct_to_bin(oct, binary); //conversion of octal into binary

    int binary_len = strlen(binary); //length of the binary
    int pos = 0; //pos of the hex

    //adding leading zeros
    int leading = (4-(binary_len%4)) % 4;
    int total = binary_len + leading;

    //grouping by 4 and processing
    int in_leading = 0; //keeping track of whether we are in the leading digits

    for (int i = 0; i < total; i += 4) {
        int nibble = 0;

        //making every 4 bits into hex
        for (int j = 0; j < 4; j++) {
            nibble <<= 1;

            //keeping track of present bit
            int bit_pos = i + j - leading;

            //validating we're in the right range
            if (bit_pos >= 0 && bit_pos < binary_len) {
                nibble |= binary[bit_pos] - '0'; //adding bit after validating
            }
        }

        //skipping the leading
        if (nibble != 0 || in_leading || (i+4 >= total)) {
            out[pos++] = (nibble < 10) ? '0' + nibble : 'A' + (nibble - 10);
            in_leading = 1;
        }
    }
    if (pos == 0){
        out[pos++] = '0';
    }
    out[pos] = '\0';
}
void hex_to_bin(const char *hex, char *out) {
    int pos = 0;

    for (int i = 0; hex[i] != '\0'; i++) {
        char c = hex[i];

        if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f')) {
            int hex_digit;
            if (c >= '0' && c <= '9') hex_digit = c - '0';
            else if (c >= 'A' && c <= 'F') hex_digit = c - 'A' + 10;
            else if (c >= 'a' && c <= 'f') hex_digit = c - 'a' + 10;

            out[pos++] = (hex_digit >> 3) & 1 ? '1' : '0';
            out[pos++] = (hex_digit >> 2) & 1 ? '1' : '0';
            out[pos++] = (hex_digit >> 1) & 1 ? '1' : '0';
            out[pos++] = (hex_digit >> 0) & 1 ? '1' : '0';
        }
    }
    out[pos] = '\0';
}
void to_sign_magnitude(int32_t n, char *out) {
    uint32_t mag;
    if (n >= 0) {
        mag = (uint32_t)n;

    } else {
        mag = (uint32_t)(-n);
        mag = mag + (1U << 31);
    }
    for (int i = 31; i >= 0; i--) {
        out[31 - i] = (mag >> i) & 1 ? '1' : '0';
    }
    out[32] = '\0';
}
void to_ones_complement(int32_t n, char *out) {
    uint32_t bits;

    if (n >= 0) {
        bits = (uint32_t)n;
    } else {
        bits = (uint32_t)(-n);
        bits = ~bits; // ~ flips all bits
    }

    for (int i = 31; i >= 0; i--) {
        out[31 - i] = (bits >> i) & 1 ? '1' : '0';
    }
    out[32] = '\0';
}
void to_twos_complement(int32_t n, char *out) {
    uint32_t bits = n;

    for (int i = 31; i >= 0; i--) {
        out[31 - i] = (bits >> i) & 1 ? '1' : '0';
    }
    out[32] = '\0';
}




