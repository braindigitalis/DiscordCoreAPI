### **Getting Guild Channels:**
---
- Access within the `DiscordCoreAPI` namespace, the `Channels` class.
- Populate a data structure of type `DiscordCoreAPI::GetGuildChannelsData`.
- Select, from the `Reactions` class, the `getGuildChannelsAsync()` function and execute it, with a return value of type `auto` or `vector<Channel>`, while passing it the created data structure.
- Call the function with `.get()` added to the end in order to wait for the results now.

```cpp
// Test.hpp - Header for the "test" command.
// https://github.com/RealTimeChris

#pragma once

#ifndef _TEST_
#define _TEST_

#include "Index.hpp"

namespace DiscordCoreAPI {

	class Test : public BaseFunction {
	public:
		Test() {
			this->commandName = "test";
			this->helpDescription = "Testing purposes!";
			EmbedData msgEmbed{};
			msgEmbed.setDescription("------\nSimply enter !test or /test!\n------");
			msgEmbed.setTitle("__**Test Usage:**__");
			msgEmbed.setTimeStamp(getTimeAndDate());
			msgEmbed.setColor("FeFeFe");
			this->helpEmbed = msgEmbed;
		}

		Test* create() {
			return new Test;
		}

		virtual CoRoutine<void> executeAsync(shared_ptr<DiscordCoreAPI::BaseFunctionArguments> args) {
			try {
				vector<Channel> channels = Channels::getGuildChannelsAsync({ .guildId = args->eventData.getGuildId() }).get();

				for (auto value : channels) {
					cout << "THE NAME: " << value.name << endl;
				}			

				co_return;
			}
			catch (...) {
				rethrowException("Test::executeAsync Error: ");
			}
		}
	};
}
#endif
```
