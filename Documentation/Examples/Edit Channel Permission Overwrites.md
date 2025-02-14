### **Edit Channel Permission Overwrites:**
---
- Create and populate a data structure by the name of `DiscordCoreAPI::EditPermissionOverwritesData`.
- Access the `Channels` class of the `DiscordCoreAPI` namespace, and execute `editPermissionOverWritesAsync` from it, after modifying the allow/deny permission strings using members from the `DiscordCoreAPI::PermissionsConverter` class, while having passed in the data structure.
```cpp
// Test.hpp - Header for the "test" command.
// https://github.com/RealTimeChris

#pragma once

#ifndef _TEST_
#define _TEST_

#include "../DiscordCoreClient02.hpp"

namespace DiscordCoreAPI {

	class Test : public BaseFunction {
	public:
		Test() {
			this->commandName = "test";
			this->helpDescription = "Testing purposes!";
			EmbedData msgEmbed;
			msgEmbed.setDescription("------\nSimply enter !test or /test!\n------");
			msgEmbed.setTitle("__**Test Usage:**__");
			msgEmbed.setTimeStamp(getTimeAndDate());
			msgEmbed.setColor("FeFeFe");
			this->helpEmbed = msgEmbed;
		}

		Test* create() {
			return new Test;
		}

		virtual  task<void> execute(shared_ptr<BaseFunctionArguments> args) {

			EditChannelPermissionOverwritesData dataPackage;
			dataPackage.allow = PermissionsConverter::addPermissionsToString(dataPackage.allow, vector<Permissions>{Permissions::ADD_REACTIONS, Permissions::MANAGE_MESSAGES});
			dataPackage.deny = PermissionsConverter::removePermissionsFromString(dataPackage.deny, vector<Permissions>{Permissions::ATTACH_FILES, Permissions::EMBED_LINKS});
			dataPackage.channelId = args->eventData.getChannelId();
			dataPackage.type = EditChannelPermissionOverwritesType::User;
			dataPackage.roleOrUserId = args->eventData.getAuthorId();
			
			Channels::editChannelPermissionOverwritesAsync(dataPackage).get();

			co_return;

		}
	};
}
#endif
```
