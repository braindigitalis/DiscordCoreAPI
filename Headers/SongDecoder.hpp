// SongDecoder.hpp - Header for the song decoder class.
// Jul 29, 2021
// Chris M.
// https://github.com/RealTimeChris
#pragma once

#include "IndexInitial.hpp"
#include "FoundationEntities.hpp"
#include "CoRoutine.hpp"

namespace DiscordCoreAPI {

    DiscordCoreAPI_Dll __int32 FileStreamRead(void* opaque, unsigned __int8* buf, __int32);
    struct alignas(hardware_destructive_interference_size) DiscordCoreAPI_Dll BuildSongDecoderData {
    public:

        unsigned __int64 totalFileSize{ 0 };
        __int32 bufferMaxSize{ 0 };
    };


    class alignas(hardware_destructive_interference_size) DiscordCoreAPI_Dll SongDecoder {
    public:

        friend DiscordCoreAPI_Dll __int32 FileStreamRead(void* opaque, unsigned __int8* buf, __int32);
        friend class SoundCloudAPI;
        friend class YouTubeAPI;

        SongDecoder(BuildSongDecoderData dataPackage);

        void submitDataForDecoding(vector<unsigned __int8> dataToDecode, __int32 maxBufferSize = 0);

        void updateBufferRefreshTime(__int32 newRefreshTime);

        bool getFrame(RawFrameData* dataPackage);

        bool startMe();

        ~SongDecoder();

    protected:

        __int32 audioStreamIndex{ 0 }, audioFrameCount{ 0 }, bufferMaxSize{ 0 }, bytesRead{ 0 }, sentFrameCount{ 0 };
        unbounded_buffer<vector<unsigned __int8>> inputDataBuffer{};
        AVFrame* frame{ nullptr }, * newFrame{ nullptr };
        unbounded_buffer<RawFrameData> outDataBuffer{};
        AVCodecContext* audioDecodeContext{ nullptr };
        AVFormatContext* formatContext{ nullptr };
        vector<unsigned __int8> currentBuffer{};
        concurrency::event readyToStartEvent {};
        __int32 refreshTimeForBuffer{ 10000 };
        unbounded_buffer<bool> readyBuffer{};
        unsigned __int64 totalFileSize{ 0 };
        SwrContext* swrContext{ nullptr };
        AVIOContext* ioContext{ nullptr };
        AVStream* audioStream{ nullptr };
        AVPacket* packet{ nullptr };
        bool areWeQuitting{ false };
        bool haveWeBooted{ false };
        CoRoutine<void> theTask{};
        AVCodec* codec{ nullptr };        

        CoRoutine<void> run();

    };
    
}