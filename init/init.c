#include "../k1/scheduler.h"

extern int shell_main();

int init_main() {
    start_task((int)shell_main);
    return 0;
}
