### **Getting a List of Guild Stickers:**
---
- Access within the `DiscordCoreAPI` namespace, the `Stickers` class.
- Populate a data structure of type `DiscordCoreAPI::GetGuildStickersData`.
- Select, from the `Stickers` class, the `getGuildStickersAsync()` function and execute it, with a return value of type `auto` or `vector<Sticker>`, while passing it the created data structure.
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

		unique_ptr<BaseFunction> create() {
			return make_unique<Test>();
		}

		virtual CoRoutine<void> executeAsync(BaseFunctionArguments args) {
			try {
				GetGuildStickersData dataPackage{};
				dataPackage.guildId = args.eventData.getGuildId();

				auto responseData = Stickers::getGuildStickersAsync(dataPackage).get();

				for (auto& value : responseData) {
					cout << "THE NAME: " << value.name << endl;
				}

				co_return;
			}
			catch (...) {
				rethrowException("Test::executeAsync Error: ");
			}
		}

		virtual ~Test() {};
	};
}
#endif
```
