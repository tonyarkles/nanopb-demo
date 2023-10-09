#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <pb_encode.h>
#include "src/demo.pb.h"

LOG_MODULE_REGISTER(main, LOG_LEVEL_INF);

int main() {
  uint8_t buffer[Hello_size];
  
  while(1) {
    Hello hello_msg = Hello_init_zero;
    hello_msg.time = k_uptime_get();
    hello_msg.val = 42;

    pb_ostream_t stream = pb_ostream_from_buffer(buffer, Hello_size);
    bool status = pb_encode(&stream, Hello_fields, &hello_msg);
    size_t len = stream.bytes_written;

    LOG_INF("wrote %d bytes to output buffer, status %d", len, status);
    k_msleep(1000);
  }
}
