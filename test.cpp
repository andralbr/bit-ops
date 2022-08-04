#include <iostream>
#include <unistd.h>

int main()
{

    uint8_t field1 = 0;

    // First bit bool
    uint8_t mask_bit1(0x01);
    // 3 bit integer
    uint8_t mask_int1(0x0E);
    // 3 bit integer
    uint8_t mask_int2(0x70);
    // Last bit bool
    uint8_t mask_bit2(0x80);


    // Set first bool ("1")
    field1 |= mask_bit1;

    // Add integer 1 ("101")
    uint8_t int1(5);
    field1 |= (int1 << 1);

    // Add integer 2 ("011")
    uint8_t int2(3 << 4);
    field1 |= int2;

    // Add last bool ("0")
    field1 &= ~mask_bit2;

    // Total: (00111011) = 59
    std::cout << "field1 = " << int(field1) << "\n";

    // Get bools
    bool bl1 = field1 & mask_bit1;
    bool bl2 = field1 & mask_bit2;

    // Get integers
    uint8_t rint1 = static_cast<uint8_t>((field1 & mask_int1) >> 1 );
    uint8_t rint2 = static_cast<uint8_t>((field1 & mask_int2) >> 4 );

    std::cout << "bl1 = " << bl1 << "\n";
    std::cout << "bl2 = " << bl2 << "\n";
    std::cout << "rint1 = " << int(rint1) << "\n";
    std::cout << "rint2 = " << int(rint2) << "\n";

    return 0;
}