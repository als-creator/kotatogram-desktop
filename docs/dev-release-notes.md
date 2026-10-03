Kotatogram is a fork of Telegram Desktop with forums and a handful of other changes.

### Installing the Windows and macOS builds

These are self-signed with a throwaway certificate that is generated per build and is registered nowhere, so neither OS will trust them on first sight.

- **Windows**: extract the zip, right-click `Kotatogram.exe`, choose Properties, tick Unblock, apply. Windows will still show SmartScreen; choose More info, then Run anyway.
- **macOS**: right-click `Kotatogram.app` and choose Open, then confirm. The app is not notarised, so Gatekeeper will otherwise refuse to launch it.

Signing matters for the install path, not for the build: signing with a certificate Windows and macOS do not know about is what makes the warning appear, and the same warning appears if the build is unsigned at all.