#include "Fcitx5Proxy.h"

DIM_ADDON_FACTORY(Fcitx5Proxy);

Fcitx5Proxy::Fcitx5Proxy(Dim *dim)
    : InputMethodAddon(dim) {
}

Fcitx5Proxy::~Fcitx5Proxy() {
}

QList<InputMethodEntry> Fcitx5Proxy::getInputMethods() {
    QList<InputMethodEntry> ret;
    return ret;
}
