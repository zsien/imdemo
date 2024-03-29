// SPDX-FileCopyrightText: 2023 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: GPL-3.0-or-later

#ifndef TEXTINPUTMANAGERV3_H
#define TEXTINPUTMANAGERV3_H

#include "wl/server/ZwpTextInputManagerV3.h"

class Core;
class TextInputV3;

namespace wl {
namespace server {
class Seat;
}
} // namespace wl

class TextInputManagerV3 : public wl::server::ZwpTextInputManagerV3
{
public:
    TextInputManagerV3();
    ~TextInputManagerV3();

protected:
    void zwp_text_input_manager_v3_destroy(wl::server::Resource *resource);
    void zwp_text_input_manager_v3_get_text_input(wl::server::Resource *resource,
                                                  uint32_t id,
                                                  struct ::wl_resource *seat);
};

#endif // !TEXTINPUTMANAGERV3_H
