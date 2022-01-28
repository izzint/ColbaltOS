#include <idt.h>
#include <stdint.h>

int idt_init() {
   // Load the IDT

   uint16_t selector = 0x08;
   uint64_t myHandlerAddress = (uint64_t)MyHandler;
   idtEntry.offset_1 = myHandlerAddress & 0xFFFF;
   idtEntry.offset_2 = (myHandlerAddress >> 16) & 0xFFFF;
   idtEntry.offset_3 = myHandlerOffset >> 32;
}