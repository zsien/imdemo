#ifndef _ORG_DEEPIN_DIM_COMMON_H_
#define _ORG_DEEPIN_DIM_COMMON_H_

#include "message.h"

#include <QVariant>

namespace org {
namespace deepin {
namespace dim {

enum { BATCHED_COMMIT_STRING = 0, BATCHED_PREEDIT, BATCHED_FORWARD_KEY };

using BatchEvent = dbus::DBusStruct<uint32_t, QVariant>;
using DBusForwardKey = dbus::DBusStruct<uint32_t, uint32_t, bool>; // keysym, keystate, isRelease
using PreeditKey = dbus::DBusStruct<std::vector<dbus::DBusStruct<QString, int32_t>>, int32_t>; // preedit text, preedit text format, cursor

} // namespace dim
} // namespace deepin
} // namespace org

Q_DECLARE_METATYPE(org::deepin::dim::BatchEvent)
Q_DECLARE_METATYPE(org::deepin::dim::DBusForwardKey)
Q_DECLARE_METATYPE(org::deepin::dim::PreeditKey)

template<auto Func>
class Deleter
{
public:
    template<typename T>
    void operator()(T *ptr) const
    {
        if (ptr) {
            Func(ptr);
        }
    }
};

#endif // _ORG_DEEPIN_DIM_COMMON_H_