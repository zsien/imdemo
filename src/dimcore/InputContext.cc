#include "InputContext.h"

#include "Dim.h"

using namespace org::deepin::dim;

InputContext::InputContext(Dim *dim, QObject *parent)
    : QObject(parent)
    , ObjectId()
    , dim_(dim)
    , inputState_(dim)
{
    Event e(EventType::InputContextCreated, this);
    dim_->postEvent(e);
}

void InputContext::destroy()
{
    deleteLater();

    Event e(EventType::InputContextDestroyed, this);
    dim_->postEvent(e);
}

void InputContext::focusIn()
{
    Event e(EventType::InputContextFocused, this);
    dim_->postEvent(e);
}

void InputContext::focusOut()
{
    Event e(EventType::InputContextUnfocused, this);
    dim_->postEvent(e);
}

bool InputContext::keyEvent(InputContextKeyEvent &event)
{
    return dim_->postEvent(event);
}

void InputContext::updatePreedit(const QString &text, int32_t cursorBegin, int32_t cursorEnd)
{
    batchList_.emplace_back(PreeditInfo{ text, cursorBegin, cursorEnd });
}

void InputContext::updateCommitString(const QString &text)
{
    batchList_.emplace_back(CommitString{ text });
}

void InputContext::forwardKey(uint32_t keycode, bool pressed)
{
    batchList_.emplace_back(ForwardKey{ keycode, pressed });
}

std::list<std::variant<ForwardKey, PreeditInfo, CommitString>> InputContext::getAndClearBatchList()
{
    decltype(batchList_) tmp;
    tmp.swap(batchList_);

    return tmp;
}

const InputState &InputContext::inputState() const
{
    return inputState_;
}
