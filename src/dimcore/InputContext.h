// SPDX-FileCopyrightText: 2023 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: GPL-3.0-or-later

#ifndef INPUTCONTEXT_H
#define INPUTCONTEXT_H

#include "Events.h"
#include "InputState.h"
#include "ObjectId.h"

#include <QObject>

#include <variant>

namespace org {
namespace deepin {
namespace dim {

class Dim;

struct PreeditInfo
{
    QString text;
    int32_t cursorBegin;
    int32_t cursorEnd;
};

struct CommitString
{
    QString text;
};

struct ForwardKey
{
    uint32_t keycode;
    bool pressed;
};

class InputContext : public QObject, public ObjectId<InputContext>
{
    Q_OBJECT

public:
    InputContext(Dim *dim, QObject *parent = nullptr);
    ~InputContext() = default;

public:
    void destroy();
    void focusIn();
    void focusOut();
    bool keyEvent(InputContextKeyEvent &event);

    const InputState &inputState() const;

    void updatePreedit(const QString &text, int32_t cursorBegin, int32_t cursorEnd);
    void updateCommitString(const QString &text);
    void forwardKey(uint32_t keycode, bool pressed);
    bool isAsyncMode();

Q_SIGNALS:
    void processKeyEventFinished();

protected:
    std::list<std::variant<ForwardKey, PreeditInfo, CommitString>> getAndClearBatchList();

private:
    Dim *dim_;
    InputState inputState_;

    std::list<std::variant<ForwardKey, PreeditInfo, CommitString>> batchList_;
};

} // namespace dim
} // namespace deepin
} // namespace org

#endif // !INPUTCONTEXT_H
