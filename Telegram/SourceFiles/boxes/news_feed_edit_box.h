/*
This file is part of Kotatogram Desktop,
part of the Telegram Desktop project.

For license and copyright information please follow this link:
https://github.com/kotatogram/kotatogram-desktop/blob/master/LEGAL
*/
#pragma once

#include "base/basic_types.h" // not_null

namespace Window {
class SessionController;
} // namespace Window

// Open a box with a checkbox list of the user's broadcast channels.
// Checked channels are shown in the built-in "News feed" tab, unchecked
// ones are excluded from it. Everything stays local: nothing is written
// to the user's account.
void EditNewsFeedFilter(not_null<Window::SessionController*> controller);