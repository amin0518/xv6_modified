#include "user.h"
#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/syscall.h"  // For SYS_trigger

int main() {
    trigger(1, "Test message");  // 1 = INFO level
    exit(0);
}