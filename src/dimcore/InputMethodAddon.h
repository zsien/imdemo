#ifndef INPUTMETHODADDON_H
#define INPUTMETHODADDON_H

#include "Addon.h"
#include "InputMethodEntry.h"

#include <QList>

namespace org {
namespace deepin {
namespace dim {

class InputMethodAddon : public Addon
{
    Q_OBJECT

public:
    explicit InputMethodAddon(Dim *dim, const QString &key);
    virtual ~InputMethodAddon();

    virtual QList<InputMethodEntry> getInputMethods() = 0;
    virtual void keyEvent(const InputMethodEntry &entry, KeyEvent &keyEvent) = 0;

Q_SIGNALS:
    void focusIn(const QString &appName);
    void focusOut(const QString &appName);
    void destroyed(const QString &appName);
    void createInputContext(const QString &appName);
};

} // namespace dim
} // namespace deepin
} // namespace org

#endif // !INPUTMETHODADDON_H
