#include <idt.h>
#include <stdint.h>

int idt_init() {
   // Load the IDT
   uint16_t selector = 0x28;
   uint64_t myHandlerAddress = (uint64_t);
   idt.offset_1 = myHandlerAddress & 0xFFFF;
   idt.offset_2 = (myHandlerAddress >> 16) & 0xFFFF;
   idt.offset_3 = myHandlerOffset >> 32;
}