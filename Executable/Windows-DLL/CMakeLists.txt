if (WIN32)
add_compile_definitions(DISCORDCOREAPIDLL_EXPORTS)
add_compile_options(/bigobj)
set(ZLIB_LIBRARY "${VCPKG_INSTALLED_DIR}/bin/libz.dll")
set(ZLIB_INCLUDE_DIR "${VCPKG_INSTALLED_DIR}/include")
set(CURL_ROOT_DIR "${VCPKG_INSTALLED_DIR}")
list(APPEND CMAKE_MODULE_PATH "${VCPKG_BASE_DIR}/ports/czmq")
set(CURL_LIBRARY  "${VCPKG_INSTALLED_DIR}/lib/libcurl.lib")
set(CURL_INCLUDE_DIR "${VCPKG_INSTALLED_DIR}/include")
set(CURL_DIR "${VCPKG_INSTALLED_DIR}/share/curl")
set(FFMPEG_DIR "${VCPKG_INSTALLED_DIR}/share/ffmpeg")
list(APPEND CMAKE_MODULE_PATH "${VCPKG_INSTALLED_DIR}/share/ffmpeg")
find_package(FFMPEG REQUIRED)
set(OPENSSL_ROOT_DIR "${VCPKG_INSTALLED_DIR}")
find_package(OpenSSL REQUIRED)

add_library(DiscordCoreAPI-DLL SHARED "../../Source/DllMain.cpp" "${VCPKG_INSTALLED_DIR}/include/cpp-base64/base64.cpp" "../../Include/Index.hpp" "../../Source/ApplicationCommandEntities.cpp" "../../Source/AudioDecoder.cpp"
	"../../Source/AudioEncoder.cpp" "../../Source/ChannelEntities.cpp"
	"../../Source/CommandController.cpp" "../../Source/DataParsingFunctions.cpp"
	"../../Source/DiscordCoreClient.cpp" "../../Source/DiscordCoreClient.cpp"
	"../../Source/ErlPacker.cpp" "../../Source/EventManager.cpp"
	"../../Source/FoundationEntities.cpp" "../../Source/GuildEntities.cpp"
	"../../Source/GuildMemberEntities.cpp" "../../Source/GuildScheduledEventEntities.cpp"
	"../../Source/Http.cpp" "../../Source/InputEvents.cpp"
	"../../Source/InteractionEntities.cpp" "../../Source/JSONIfier.cpp"
	"../../Source/MessageEntities.cpp" "../../Source/ReactionEntities.cpp"
	"../../Source/RoleEntities.cpp" "../../Source/SongAPI.cpp"
	"../../Source/SoundCloudAPI.cpp" "../../Source/SSLClients.cpp"
	"../../Source/StageInstanceEntities.cpp" "../../Source/StickerEntities.cpp"
	"../../Source/ThreadEntities.cpp" "../../Source/ThreadPool.cpp"
	"../../Source/UserEntities.cpp" "../../Source/VoiceConnection.cpp"
	"../../Source/WebHookEntities.cpp" "../../Source/WebSocketEntities.cpp"
	"../../Source/YouTubeAPI.cpp"
)

FIND_FILE(MSVCP_ATOMIC_WAIT NAMES "msvcp140_atomic_wait.dll" PATHS "C:/Program Files/Microsoft Visual Studio/2019/Community/VC/Redist/MSVC/*/x64/Microsoft.VC${MSVC_TOOLSET_VERSION}.CRT")
FIND_FILE(MSVCP_ATOMIC_WAIT NAMES "msvcp140_atomic_wait.dll" PATHS "C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Redist/MSVC/*/x64/Microsoft.VC${MSVC_TOOLSET_VERSION}.CRT")
foreach( OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES} )
	if (${OUTPUTCONFIG} STREQUAL "Release" OR ${OUTPUTCONFIG} STREQUAL "Debug")
		message(STATUS "Copying a file...")
		add_custom_command(TARGET DiscordCoreAPI-DLL PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy "${MSVCP_ATOMIC_WAIT}" "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${OUTPUTCONFIG}/msvcp140_atomic_wait.dll")
	endif()
endforeach( OUTPUTCONFIG CMAKE_CONFIGURATION_TYPES )
target_link_libraries(DiscordCoreAPI-DLL PUBLIC OpenSSL::SSL OpenSSL::Crypto)
target_link_libraries(DiscordCoreAPI-DLL PUBLIC ${FFMPEG_LIBRARIES})
target_link_libraries(DiscordCoreAPI-DLL PUBLIC "${VCPKG_INSTALLED_DIR}/lib/libcurl.lib")
target_link_libraries(DiscordCoreAPI-DLL PUBLIC "${VCPKG_INSTALLED_DIR}/lib/libsodium.lib")
target_link_libraries(DiscordCoreAPI-DLL PUBLIC "${VCPKG_INSTALLED_DIR}/lib/glib-2.0.lib")
target_link_libraries(DiscordCoreAPI-DLL PUBLIC "${VCPKG_INSTALLED_DIR}/lib/opus.lib")
endif()