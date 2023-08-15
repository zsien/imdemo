// SPDX-FileCopyrightText: 2023 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: GPL-3.0-or-later

#include "Compositor.h"

#include "Seat.h"
#include "InputMethodManagerV2.h"
#include "TextInputManagerV3.h"
#include "VirtualKeyboardManagerV1.h"

#include <QDebug>
#include <QSocketNotifier>
#include <QThread>
#include <QAbstractEventDispatcher>

Compositor::Compositor()
{
    auto *loop = wl_display_get_event_loop(display());
    int fd = wl_event_loop_get_fd(loop);

    auto processWaylandEvents = [this, loop] {
        int ret = wl_event_loop_dispatch(loop, 0);
        if (ret)
            qWarning() << "wl_event_loop_dispatch error:" << ret;
        wl_display_flush_clients(display());
    };

    noti_.reset(new QSocketNotifier(fd, QSocketNotifier::Read));
    QObject::connect(noti_.get(), &QSocketNotifier::activated, processWaylandEvents);

    QAbstractEventDispatcher *dispatcher = QThread::currentThread()->eventDispatcher();
    QObject::connect(dispatcher, &QAbstractEventDispatcher::aboutToBlock, processWaylandEvents);
}

Compositor::~Compositor() { }

void Compositor::create()
{
    seat_ = std::make_unique<Seat>();
    seat_->init(display());

    textInputManagerV3_ = std::make_unique<TextInputManagerV3>();
    textInputManagerV3_->init(display());

    inputMethodManagerV2_ = std::make_unique<InputMethodManagerV2>();
    inputMethodManagerV2_->init(display());

    virtualKeyboardManagerV1_ = std::make_unique<VirtualKeyboardManagerV1>();
    virtualKeyboardManagerV1_->init(display());
}
