
### **Editing a Guild Application Command:**
---
- Access the `ApplicationCommands` class of the `DiscordCoreAPI` namespace.
- Select, from the `ApplicationCommands` class, the `editGuildApplicationCommandAsync()` function and execute it, while passing in a data structure of type `EditGuildApplicationCommandData`, with a return value of type `auto` or `ApplicationCommand`.
- Call the function with `.get()` added to the end in order to wait for the results now.

```cpp
// Test.hpp - Header for the "test" command.
// https://github.com/RealTimeChris

#pragma once

#ifndef _TEST_
#define _TEST_

#include "../DiscordCoreClient02.hpp"

namespace DiscordCoreAPI {

	class Test : public  BaseFunction {
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

		virtual  task<void> execute(shared_ptr<DiscordCoreAPI::BaseFunctionArguments> args) {

			InputEvents::deleteInputEventResponseAsync(args->eventData);

			auto returnVector = ApplicationCommands::getGuildApplicationCommandsAsync({ .guildId = args->eventData.getGuildId() }).get();

			EditGuildApplicationCommandData dataPackage{};
			dataPackage.guildId = args->eventData.getGuildId();
			dataPackage.name = returnVector.at(0).name;
			dataPackage.defaultPermission = true;
			dataPackage.description = "a test description";

			auto returnValue = ApplicationCommands::editGuildApplicationCommandAsync(dataPackage).get();

			cout << returnValue.description << endl;

			co_return;

		}
	};
}
#endif
```
