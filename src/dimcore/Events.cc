#include "Events.h"

using namespace org::deepin::dim;

Event::Event(EventType type, InputContext *ic)
    : type_(type)
    , ic_(ic) {
}

KeyEvent::KeyEvent(InputContext *ic, uint32_t keyVal, uint32_t keycode, uint32_t state, bool isRelease, uint32_t time)
    : Event(EventType::Key, ic)
    , keyVal_(keyVal)
    , keycode_(keycode)
    , state_(state)
    , isRelease_(isRelease)
    , time_(time) {
}
