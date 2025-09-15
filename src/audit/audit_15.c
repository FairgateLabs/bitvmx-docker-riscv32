void main(void) {
    asm volatile(
        "jal x0, label+2\n"
        "label:\n"
    );
}
