
### **Getting Guild Application Commands:**
---
- Access the `ApplicationCommands` class of the `DiscordCoreAPI` namespace.
- Select, from the `ApplicationCommands` class, the `getGuildApplicationCommandsAsync()` function and execute it, while passing in an argument of type `DiscordCoreAPI::GetGuildApplicationCommandsData`, with a return value of type `auto` or `vector<ApplicationCommand>`.
- Call the function with `.get()` added to the end in order to wait for the results now.

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

			InputEvents::deleteInputEventResponseAsync(args->eventData).get();

			GetGuildApplicationCommandsData dataPackage;
			dataPackage.guildId = args->eventData.getGuildId();

			auto returnVector = ApplicationCommands::getGuildApplicationCommandsAsync(dataPackage).get();

			for (auto value : returnVector) {
				cout << value.name << endl;
			}

			co_return;
		}
	};
}
#endif
```
