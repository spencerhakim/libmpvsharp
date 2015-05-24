#pragma once

using namespace System;

namespace libmpvsharp {
    public ref class Mpv
    {
    private:
        bool m_disposed = false;
        mpv_handle* m_ctx = NULL;
        bool m_inited = false;

    public:
        /// <summary>
        /// Creates (but doesn't initialize) an MPV context
        /// and sets the WID to the specified HWND
        /// </summary>
        Mpv(IntPtr Handle);

        ~Mpv();
        !Mpv();

        /// <summary>
        /// Loads the MPV conf file at the specified location.
        /// Should be called before Initialize()
        /// </summary>
        void LoadConfig(String^ path);

        /// <summary>
        /// Initializes the MPV context. Must be called before
        /// beginning playback.
        /// </summary>
        void Initialize();

        /// <summary>
        /// Loads a video from the specified URI and immediately
        /// begins playback.
        /// </summary>
        void LoadFile(String^ uri);

        void Play();
        void Pause();
        void Stop();

    private:
        void EventLoop();
    };
}
