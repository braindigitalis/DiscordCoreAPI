### **Deleting a Guild Emoji:**
---
- Access within the `DiscordCoreAPI` namespace, the `Reactions` class.
- Populate a data structure of type `DiscordCoreAPI::DeleteGuildEmojiData`.
- Select, from the `Reactions` class, the `deleteGuildEmojiAsync()` function and execute it, with a return value of type `void`, while passing it the created data structure.
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
				GetEmojiListData dataPackage00{};
				dataPackage00.guildId = args->eventData.getGuildId();

				auto emojiList = Reactions::getEmojiListAsync(dataPackage00).get();

				DeleteGuildEmojiData dataPackage{};
				dataPackage.guildId = args->eventData.getGuildId();
				dataPackage.emojiId = emojiList.at(0).id;
				dataPackage.reason = "REASON FOR DELETING!";
				Reactions::deleteGuildEmojiAsync(dataPackage).get();

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
