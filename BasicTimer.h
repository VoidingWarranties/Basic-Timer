/* Measures ellapsed time using the platform independent sys/timeb.h. See
 * README.md for more details.
 */

#ifndef BASIC_TIMER_H_
#define BASIC_TIMER_H_

#include <ctime>
#include <sys/timeb.h>

class BasicTimer {
 public:
  void tick() {
    ftime(&tick_);
  }

  uint64_t millisecondsSinceTick() const {
    timeb now;
    ftime(&now);
    uint64_t milliseconds = (now.time - tick_.time) * 1000;
    milliseconds += now.millitm - tick_.millitm;
    return milliseconds;
  }

  // Returns the number of milliseconds between two timers' ticks. start MUST
  // have been ticked before end otherwise the value returned will not be
  // correct as it is an unsigned value. Perhaps this could be changed in the
  // future.
  friend uint64_t millisecondsBetweenTicks(const BasicTimer& start,
                                           const BasicTimer& end) {
    uint64_t milliseconds = (end.tick_.time - start.tick_.time) * 1000;
    milliseconds += end.tick_.millitm - start.tick_.millitm;
    return milliseconds;
  }

 private:
  timeb tick_;
};

#endif
