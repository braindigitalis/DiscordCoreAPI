### **Getting a List of Thread Members:**
---
- Access within the `DiscordCoreAPI` namespace, the `Channels` class.
- Populate a data structure of type `DiscordCoreAPI::GetThreadMembersData`.
- Select, from the `Channels` class, the `getThreadMembersAsync()` function and execute it, with a return value of type `auto` or `vector<ThreadMemberData>`, while passing it the created data structure.
- Call the function with `.get()` added to the end in order to wait for the results now.

```cpp
// Test.hpp - Header for the "test" command.
// https://github.com/RealTimeChris

#pragma once

#ifndef _TEST_
#define _TEST_

#include "IndexInitial.hpp"

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
				GetThreadMembersData dataPackage{};
				dataPackage.channelId = "909444594146639913";

				auto newThreadMembers = Channels::getThreadMembersAsync(dataPackage).get();

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
