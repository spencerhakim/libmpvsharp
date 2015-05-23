#include "Stdafx.h"
#include "libmpvsharp.h"
#include "MpvException.h"

using namespace System;
using namespace System::IO;
using namespace System::Runtime::InteropServices;
using namespace System::Text;
using namespace libmpvsharp;

#define MPV_ERROR_CHECK(x)                      \
    {                                           \
        int res=(x);                            \
        if( res < MPV_ERROR_SUCCESS )           \
            throw gcnew MpvException(#x, res);  \
    }

inline const char* toUTF8(String^ str)
{
    auto utf8 = Encoding::UTF8->GetBytes(str);
    pin_ptr<Byte> utf8ptr = &utf8[0];
    return reinterpret_cast<const char*>(utf8ptr);
}

///////////////////////////////////////////////////////////////////////////////

Mpv::Mpv(IntPtr Handle)
{
    m_ctx = mpv_create();
    if( !m_ctx )
        throw gcnew MpvException("mpv_create failed");

    int64_t wid = (intptr_t)(HWND)Handle.ToPointer();
    MPV_ERROR_CHECK( mpv_set_option(m_ctx, "wid", MPV_FORMAT_INT64, &wid) );
}

Mpv::~Mpv()
{
    if( m_disposed )
        return;

    m_disposed = true;
    this->!Mpv();
}

Mpv::!Mpv()
{
    if( !m_ctx )
        return;

    mpv_terminate_destroy(m_ctx);
    m_ctx = NULL;
}

///////////////////////////////////////////////////////////////////////////////

void Mpv::LoadConfig(String^ path)
{
    if( !m_ctx )
        return;

    MPV_ERROR_CHECK( mpv_load_config_file(m_ctx, toUTF8(path)) );
}

void Mpv::Initialize()
{
    if( !m_ctx || m_inited )
        return;

    MPV_ERROR_CHECK( mpv_initialize(m_ctx) );
    m_inited = true;
}

void Mpv::LoadFile(String^ uri)
{
    if( !m_ctx )
        return;

    const char* args[] = {
        "loadfile",
        toUTF8(uri),
        NULL
    };

    MPV_ERROR_CHECK( mpv_command_async(m_ctx, 0, args) );
}

void Mpv::Play()
{
    if( !m_ctx )
        return;

    int data = 0;
    MPV_ERROR_CHECK( mpv_set_property_async(m_ctx, 0, "pause", MPV_FORMAT_FLAG, &data) );
}

void Mpv::Pause()
{
    if( !m_ctx )
        return;

    int data = 1;
    MPV_ERROR_CHECK( mpv_set_property_async(m_ctx, 0, "pause", MPV_FORMAT_FLAG, &data) );
}

void Mpv::Stop()
{
    if( !m_ctx )
        return;

    const char* args[] = {
        "stop",
        NULL
    };
    MPV_ERROR_CHECK( mpv_command_async(m_ctx, 0, args) );
}