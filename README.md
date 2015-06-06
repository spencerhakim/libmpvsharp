## libmpvsharp
libmpvsharp is a simple .NET wrapper around libmpv, written in C++/CLI. Like libmpv's client API, it is licensed under the **ISC License**.

Pre-compiled x86 and x64 versions of the libmpv DLL are included, as well as the libwinpthread and libgcc DLLs required by libmpv (these are provided by MSYS2/MinGW-w64).

### Features
- Specify the HWND for libmpv to render to (via the `.ctor`)
- Load an external configuration file (via `LoadConfig`)
- Load a single media file for immediate playback (via `LoadFile`)
- Play/Pause/Stop playback
- A built-in no-op event loop, to prevent the event queue from filling

### TODO
- Support for executing arbitrary commands
- Support for getting/setting properties and options (besides via `LoadConfig`)
- Support for events and exposing the event loop