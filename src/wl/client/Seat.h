#ifndef WL_CLIENT_SEAT_H
#define WL_CLIENT_SEAT_H

#include "Type.h"

namespace wl {
namespace client {

class Seat : public Type<wl_seat>
{
public:
    Seat(wl_seat *val);
    ~Seat();
};

} // namespace client
} // namespace wl

#endif // !WL_CLIENT_SEAT_H