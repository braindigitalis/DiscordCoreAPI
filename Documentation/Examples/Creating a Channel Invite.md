
### **Creating a Channel Invite:**
---
- Access the `Channels` class of the `DiscordCoreAPI` namespace.
- Select, from the `Channels` class, the `createChannelInviteAsync()` function and execute it, while passing in a data structure of type `DiscordCoreAPI::CreateChannelInviteData`, with a return value of `auto` or `InviteData`.

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

				CreateChannelInviteData dataPackage{};
				dataPackage.channelId = args->eventData.getChannelId();
				dataPackage.targetType = InviteTargetTypes::EMBEDDED_APPLICATION;
				dataPackage.temporary = true;

				InviteData channelInvite = Channels::createChannelInviteAsync(dataPackage).get();
				cout << "CHANNEL INVITE: " << channelInvite.inviter.userName << endl;
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
