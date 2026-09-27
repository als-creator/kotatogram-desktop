# Kotatogram – experimental [Telegram Desktop][telegram_desktop] fork.

> **This is a fork**: [als-creator/kotatogram-desktop][fork] based on the **dev** branch of [kotatogram/kotatogram-desktop][upstream]. It tracks upstream dev and adds the following.

## What differs from upstream Kotatogram dev
* **Dev builds with build numbers.** Each push to `dev` builds a `v{app-version}-build-{n}` AppImage and publishes it to Releases; the build number is shown in the app next to the version. Windows (debug) build is uploaded as an artifact.
* **Hide sponsored messages.** New `hide_sponsored_messages` setting (Chats, enabled by default): sponsored messages in public channels and video ads are neither requested nor injected, already-injected ones are cleared on toggle.
* **Forwarding fixes.** "Forward without author" + RegroupAll no longer hangs in an endless "sending" state — failed media now retries after a `FILE_REFERENCE` refresh and reports errors instead of stalling.
* **Russian translations.** Missing/broken Russian strings in upstream dev got completed/fixed.
* **Build toolchain fixes.** Pinned `cmake_helpers` and CI adjustments (GCC 15 `-Werror` false positives, newer CMake, Windows signing) so the dev builds actually pass.

[![GitHub release (latest by date including pre-releases)](https://badgen.net/github/release/kotatogram/kotatogram-desktop?label=Latest%20release)][releases]
[![GitHub Workflow Status: Windows](https://github.com/kotatogram/kotatogram-desktop/workflows/Windows./badge.svg?event=push)][actions]
[![GitHub Workflow Status: Linux](https://github.com/kotatogram/kotatogram-desktop/workflows/Linux%20Kotato./badge.svg?event=push)][actions]
[![GitHub Workflow Status: macOS](https://github.com/kotatogram/kotatogram-desktop/workflows/MacOS./badge.svg?event=push)][actions]
[![Crowdin](https://badges.crowdin.net/kotatogram-desktop/localized.svg)](https://crowdin.com/project/kotatogram-desktop)

[![Preview of Kotatogram Desktop][preview_image]][preview_image_url]

Build instructions can be found [in `docs` folder][build]. Please note: only [Windows][win] and [Linux][linux] build instructions are updated.

Original README with licenses could be found in [Telegram Desktop repository][telegram_desktop_readme].

## Download
Binaries can be downloaded from releases: https://github.com/kotatogram/kotatogram-desktop/releases

Latest stable version can be found here: https://github.com/kotatogram/kotatogram-desktop/releases/latest

## Builds
* Windows (installer and portable)
* Linux (64-bit)
  * [Flathub][flatpak]
  * Other repositories:<br>[![Packaging status](https://repology.org/badge/vertical-allrepos/kotatogram-desktop.svg)][repology]
* macOS

## Features
* Local folders
* Forward to multiple chats and forward without author
* Custom font
* Compact chat list
* Custom text replaces
* Change sticker size
* Adaptive chat bubbles
* and other smaller features.

Full list of features will rewritten later. Control branches were used to list features, but they are now deprecated and archived in [separate repo][archive].

## Contributing
Read [CONTRIBUTING.md][contributing].

## Other links
* Website: https://kotatogram.github.io
* English Telegram channel: https://t.me/kotatogram
* Russian Telegram channel: https://t.me/kotatogram_ru
* Trello (on Russian, abandoned): https://trello.com/b/G6zetXOH/kotatogram-desktop

## Attribution
* Ghost icon (for deleted accounts) is taken from [official Android app](https://github.com/DrKLO/Telegram).
* Icons for local folders mostly are [Material Design Icons](https://materialdesignicons.com/).

[//]: # (LINKS)
[fork]: https://github.com/als-creator/kotatogram-desktop
[upstream]: https://github.com/kotatogram/kotatogram-desktop
[telegram_desktop]: https://desktop.telegram.org
[releases]: https://github.com/kotatogram/kotatogram-desktop/releases
[actions]: https://github.com/kotatogram/kotatogram-desktop/actions
[telegram_desktop_readme]: https://github.com/telegramdesktop/tdesktop/blob/dev/README.md
[repology]: https://repology.org/project/kotatogram-desktop/versions
[flatpak]: https://flathub.org/apps/details/io.github.kotatogram
[changelog]: https://github.com/kotatogram/kotatogram-desktop/blob/dev/kotatogram_changes.txt
[preview_image]: https://github.com/kotatogram/kotatogram-desktop/blob/dev/docs/assets/ktg_preview.png "Preview of Kotatogram Desktop"
[preview_image_url]: https://github.com/kotatogram/kotatogram-desktop/blob/dev/docs/assets/ktg_preview.png
[contributing]: https://github.com/kotatogram/kotatogram-desktop/blob/dev/.github/CONTRIBUTING.md
[archive]: https://github.com/kotatogram/kotatogram-archived
[build]: https://github.com/kotatogram/kotatogram-desktop/blob/dev/docs
[win]: https://github.com/kotatogram/kotatogram-desktop/blob/dev/docs/building-win.md
[linux]: https://github.com/kotatogram/kotatogram-desktop/blob/dev/docs/building-linux.md
