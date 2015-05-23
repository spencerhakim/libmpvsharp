#include "stdafx.h"
#include "MpvException.h"

using namespace libmpvsharp;

MpvException::MpvException(String^ message) : Exception(message)
{
    //
}

MpvException::MpvException(String^ funcName, int error) : Exception(formatMessage(funcName, error))
{
    //
}

String^ MpvException::formatMessage(String^ funcName, int error)
{
    String^ errorStr;
    switch( error )
    {
        case MPV_ERROR_SUCCESS:
            errorStr = "MPV_ERROR_SUCCESS";
            break;

        case MPV_ERROR_EVENT_QUEUE_FULL:
            errorStr = "MPV_ERROR_EVENT_QUEUE_FULL";
            break;

        case MPV_ERROR_NOMEM:
            errorStr = "MPV_ERROR_NOMEM";
            break;

        case MPV_ERROR_UNINITIALIZED:
            errorStr = "MPV_ERROR_UNINITIALIZED";
            break;

        case MPV_ERROR_INVALID_PARAMETER:
            errorStr = "MPV_ERROR_INVALID_PARAMETER";
            break;

        case MPV_ERROR_OPTION_NOT_FOUND:
            errorStr = "MPV_ERROR_OPTION_NOT_FOUND";
            break;

        case MPV_ERROR_OPTION_FORMAT:
            errorStr = "MPV_ERROR_OPTION_FORMAT";
            break;

        case MPV_ERROR_OPTION_ERROR:
            errorStr = "MPV_ERROR_OPTION_ERROR";
            break;

        case MPV_ERROR_PROPERTY_NOT_FOUND:
            errorStr = "MPV_ERROR_PROPERTY_NOT_FOUND";
            break;

        case MPV_ERROR_PROPERTY_FORMAT:
            errorStr = "MPV_ERROR_PROPERTY_FORMAT";
            break;

        case MPV_ERROR_PROPERTY_UNAVAILABLE:
            errorStr = "MPV_ERROR_PROPERTY_UNAVAILABLE";
            break;

        case MPV_ERROR_PROPERTY_ERROR:
            errorStr = "MPV_ERROR_PROPERTY_ERROR";
            break;

        case MPV_ERROR_COMMAND:
            errorStr = "MPV_ERROR_COMMAND";
            break;

        case MPV_ERROR_LOADING_FAILED:
            errorStr = "MPV_ERROR_LOADING_FAILED";
            break;

        case MPV_ERROR_AO_INIT_FAILED:
            errorStr = "MPV_ERROR_AO_INIT_FAILED";
            break;

        case MPV_ERROR_VO_INIT_FAILED:
            errorStr = "MPV_ERROR_VO_INIT_FAILED";
            break;

        case MPV_ERROR_NOTHING_TO_PLAY:
            errorStr = "MPV_ERROR_NOTHING_TO_PLAY";
            break;

        case MPV_ERROR_UNKNOWN_FORMAT:
            errorStr = "MPV_ERROR_UNKNOWN_FORMAT";
            break;

        case MPV_ERROR_UNSUPPORTED:
            errorStr = "MPV_ERROR_UNSUPPORTED";
            break;

        case MPV_ERROR_NOT_IMPLEMENTED:
            errorStr = "MPV_ERROR_NOT_IMPLEMENTED";
            break;

        default:
            errorStr = ((int)error).ToString();
            break;
    }

    return String::Format("{0} returned {1}", funcName, errorStr);
}