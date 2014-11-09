#ifndef BASIC_TIMER_H_
#define BASIC_TIMER_H_

#include <ctime>
#include <sys/timeb.h>

class BasicTimer {
 public:
  void tick() {
    ftime(&tick_);
  }

  uint64_t millisecondsSinceTick() {
    timeb now;
    ftime(&now);
    uint64_t milliseconds = (now.time - tick_.time) * 1000;
    milliseconds += now.millitm - tick_.millitm;
    return milliseconds;
  }

 private:
  timeb tick_;
};

#endif
