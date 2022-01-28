#include <idt.h>
#include <stddef.h>
#include <stdint.h>

__attribute__((noreturn))
void exception_handler(void);
void exception_handler() {

  __asm__ volatile("cli; hlt"); // Completely hangs the computer
}


void idt_set_descriptor(uint8_t vector, void* isr, uint8_t flags);
void idt_set_descriptor(uint8_t vector, void* isr, uint8_t flags) {
    struct InterruptDescriptor64* descriptor = &idt[vector];
 
    descriptor->isr_low        = (uint64_t)isr & 0xFFFF;
    descriptor->kernel_cs      = 0x28;
    descriptor->ist            = 0;
    descriptor->attributes     = flags;
    descriptor->isr_mid       = ((uint64_t)isr >> 16) & 0xFFFF;
    descriptor->isr_high      = ((uint64_t)isr >> 32) & 0xFFFFFFFF;
    descriptor->reserved           = 0;
}

