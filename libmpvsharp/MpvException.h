#pragma once

using namespace System;

namespace libmpvsharp {
    [Serializable]
    public ref class MpvException : public Exception
    {
    private:
        String^ formatMessage(String^ funcName, int error);

    internal:
        MpvException(String^ message);
        MpvException(String^ funcName, int error);
    };
}