# DiscordCoreAPI
<p align="center">
 <img src="https://github.com/RealTimeChris/DiscordCoreAPI/blob/main/Documentation/Images/TheLogo.png?raw=true"  width="500">
</p>
 
 
## A bot library for Discord, written in C++ using WinRT and a few other useful libraries. Features explicit multithreading, through the usage of custom, asynchronous C++ CoRoutines.

## [Build Instructions](https://github.com/RealTimeChris/DiscordCoreAPI/blob/main/Documentation/Build%20Instructions.md)

## [Documentation / Examples](https://github.com/RealTimeChris/DiscordCoreAPI/blob/main/Documentation-Examples.md)

## [Doxygen-Generated Documentation](https://realtimechris.github.io/DiscordCoreAPI-Docs/)

## [Raw DLL Source](https://github.com/RealTimeChris/DiscordCoreAPI-DLL)

## [Discord Server (Where I can be found! As well as some demonstration bots that were built using the DiscordCoreAPI Library.)](https://discord.gg/8B9yyuyv5e)

## [Example "Music" Bot Written Using This Library](https://github.com/RealTimeChris/MBot-MusicHouse-Cpp)

## [Example "Game" Bot Written Using This Library](https://github.com/RealTimeChris/MBot-GameHouse-Cpp)

## Features
### Entire Discord API Covered
----
- All of the Discord API endpoints are covered in this library, including voice communication.

### Concurrent Discord API Access
----
- As a result of using [custom asynchronous coroutines](https://github.com/RealTimeChris/DiscordCoreAPI-DLL/blob/main/Headers/CoRoutine.hpp), this library has the ability to make fully asynchronous/concurrent requests to the Discord API.

### Slash Commands and Buttons
----
<p align="left">
	<img src="https://github.com/RealTimeChris/DiscordCoreAPI/blob/main/Documentation/Images/Screenshot%20(53).png?raw=true"  width="700">
</p>

### Select Menus
----
<p align="left">
 	<img src="https://github.com/RealTimeChris/DiscordCoreAPI/blob/main/Documentation/Images/Screenshot%20(83).png?raw=true"  width="700">
	<img src="https://github.com/RealTimeChris/DiscordCoreAPI/blob/main/Documentation/Images/Screenshot%20(84).png?raw=true"  width="700">
</p>

### User Commands
----
<p align="left">
 	<img src="https://github.com/RealTimeChris/DiscordCoreAPI/blob/main/Documentation/Images/Screenshot%20(120).png?raw=true"  width="700">
</p>

### A Unified "Input-Event" System
----
- Both user messages and user interactions are accepted via the `onInputEventCreation` event.
- They can all be responded to using the `DiscordCoreAPI::InputEvents::respondToEvent()` function.
```cpp
EmbedData newEmbed;
newEmbed.setAuthor(args->eventData.getUserName(), args->eventData.getAvatarURL());
newEmbed.setDescription("------\n__**Sorry, but there's already something playing!**__\n------");
newEmbed.setTimeStamp(getTimeAndDate());
newEmbed.setTitle("__**Playing Issue:**__");
newEmbed.setColor(discordGuild.data.borderColor);
embedsFromSearch.push_back(newEmbed);
if (args->eventData.eventType == InputEventType::REGULAR_MESSAGE) {
	RespondToInputEventData dataPackage(args->eventData);
	dataPackage.type = DesiredInputEventResponseType::RegularMessage;
	dataPackage.addMessageEmbed(newEmbed);
	newEvent = InputEvents::respondToEvent(dataPackage);
	InputEvents::deleteInputEventResponseAsync(newEvent, 20000).get();
}
else {
	RespondToInputEventData dataPackage(args->eventData);
	dataPackage.type = DesiredInputEventResponseType::EphemeralInteractionResponse;
	dataPackage.addMessageEmbed(newEmbed);
	newEvent = InputEvents::respondToEvent(dataPackage);
}
```
## Dependencies
- [WinRT](https://docs.microsoft.com/en-us/windows/uwp/cpp-and-winrt-apis/intro-to-using-cpp-with-winrt)

- [Visual C++ Redistributable](https://docs.microsoft.com/en-US/cpp/windows/latest-supported-vc-redist?view=msvc-160)

- NOTE: I installed these using the [vcpkg](https://github.com/microsoft/vcpkg) installer.
 
- [Nlohmann Json](https://github.com/nlohmann/json) (.\vcpkg install nlohmann-json:x64-windows)

- [MongoDB](https://docs.mongodb.com/manual/installation/) (.\vcpkg install mongo-cxx-driver:x64-windows)

- [LibCurl](https://github.com/curl/curl) (.\vcpkg install curl:x64-windows)

- [LibSodium](https://github.com/jedisct1/libsodium) (.\vcpkg install libsodium:x64-windows)

- [FFMPEG](http://ffmpeg.org/) (.\vcpkg install ffmpeg:x64-windows)

- [Glib](https://github.com/GNOME/glib) (.\vcpkg install glib:x64-windows)

## Roadmap
I am currently working on getting this thing to be used by people like you! So, if you have any suggestions for the library that would make it more usable - don't hesitate to let me know! I can be easily found on the Discord server that is linked to above! Cheers and thanks for your time!

