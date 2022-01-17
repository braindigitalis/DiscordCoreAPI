// ApplicationCommandEntities.hpp - Header for the ApplicationCommand classes and structs.
// Aug 25, 2021
// Chris M.
// https://github.com/RealTimeChris

#pragma once

#include "IndexInitial.hpp"
#include "FoundationEntities.hpp"

namespace DiscordCoreAPI {

    /**
    * \addtogroup foundation_entities
    * @{
    */

    /// For getting all of the Global Application Commands. \brief For getting all of the Global Application Commands.
    struct DiscordCoreAPI_Dll GetGlobalApplicationCommandsData {
        string applicationId{ "" };///< The current application's Id (The Bot's User Id).
    };

    /// For collecting a single global ApplicationCommand. \brief For collecting a single global ApplicationCommand.
    struct DiscordCoreAPI_Dll GetGlobalApplicationCommandData {
        string applicationId{ "" };///< The current application's Id (The Bot's User Id).
        string commandId{ "" }; ///< The id of the command which you would like to collect.
    };

    /// For creating a single global ApplicationCommand. \brief For creating a single global ApplicationCommand.
    struct DiscordCoreAPI_Dll CreateGlobalApplicationCommandData {
        vector<ApplicationCommandOptionData> options{}; ///< The options for the ApplicationCommand.
        bool defaultPermission{ true }; ///< Whether the command is enabled by default when the bot is added to a Guild
        ApplicationCommandType type{}; ///< The type of ApplicationCommand.
        string applicationId{ "" };///< Application id.
        string description{ "" };   ///< A description of the command.
        string name{ "" }; ///< A name for the new command.
    };

    /// For editing a single global ApplicationCommand. \brief For editing a single global ApplicationCommand.
    struct DiscordCoreAPI_Dll EditGlobalApplicationCommandData {
        vector<ApplicationCommandOptionData> options{};///< The options for the ApplicationCommand.
        bool defaultPermission{ false };///< Whether the command is enabled by default when the bot is added to a Guild.
        string applicationId{ "" };///< The current application's Id (The Bot's User Id).
        string description{ "" };   ///< A description of the command.
        string name{ "" }; ///< A name for the new command.
    };

    /// For deleting a single global ApplicationCommand. \brief For deleting a single global ApplicationCommand.
    struct DiscordCoreAPI_Dll DeleteGlobalApplicationCommandData {
        string applicationId{ "" };///< The current application's Id (The Bot's User Id).
        string name{ "" }; ///< The name of the command to delete.
    };

    /// For bulk-overwriting a collection of global ApplicationCommands. \brief For bulk-overwriting a collection of global ApplicationCommands.
    struct DiscordCoreAPI_Dll BulkOverwriteGlobalApplicationCommandsData {
        vector<CreateGlobalApplicationCommandData> responseData{};///< A vector of the options for the ApplicationCommands.
        string applicationId{ "" };///< The current application's Id (The Bot's User Id).
    };

    /// For acquiring all of the Guild ApplicationCommands of a single Guild. \brief For acquiring all of the Guild ApplicationCommands of a single Guild.
    struct DiscordCoreAPI_Dll GetGuildApplicationCommandsData {
        string applicationId{ "" };///< The current application's Id (The Bot's User Id).
        string guildId{ "" }; ///< The id of the Guild for which you would like to acquire the ApplicationCommands from.
    };

    /// For creating a single Guild ApplicationCommand. \brief For creating a single Guild ApplicationCommand.
    struct DiscordCoreAPI_Dll CreateGuildApplicationCommandData {
        vector<ApplicationCommandOptionData> options{}; ///< The options for the ApplicationCommand.
        bool defaultPermission{ true }; ///< Whether the command is enabled by default when the bot is added to a Guild.
        ApplicationCommandType type{}; ///< The type of ApplicationCommand.
        string applicationId{ "" };///< Application Id.
        string description{ "" };   ///< A description of the command.
        string guildId{ "" }; ///< The id of the Guild which you would like to add the new command to.
        string name{ "" }; ///< A name for the new command.
    };

    /// For acquiring a single Guild ApplicationCommand. \brief For acquiring a single Guild ApplicationCommand.
    struct DiscordCoreAPI_Dll GetGuildApplicationCommandData {
        string applicationId{ "" };///< The current application's Id (The Bot's User Id).
        string commandId{ "" };///< The command id which you would like to acquire.
        string guildId{ "" };///< The id of the Guild from which you would like to acquire the ApplicationCommand from.
    };    

    /// For editing a single Guild ApplicationCommand. \brief For editing a single Guild ApplicationCommand.
    struct DiscordCoreAPI_Dll EditGuildApplicationCommandData {
        vector<ApplicationCommandOptionData> options{}; ///< The options for the ApplicationCommand.
        bool defaultPermission{ true }; ///< Whether the command is enabled by default when the bot is added to a Guild.
        string applicationId{ "" };///< The current application's Id (The Bot's User Id).
        string description{ "" };   ///< A description of the command.
        string guildId{ "" }; ///< The id of the Guild which you would like to add the new command to.
        string name{ "" }; ///< A name for the new command.
    };

    /// For deleting a single Guild ApplicationCommand. \brief For deleting a single Guild ApplicationCommand.
    struct DiscordCoreAPI_Dll DeleteGuildApplicationCommandData {
        string applicationId{ "" };///< The current application's Id (The Bot's User Id).
        string guildId{ "" }; ///< The id of the Guild which you would like to delete the command from.
        string name{ "" }; ///< A name of the command which you would like to delete.
    };

    /// For bulk-overwriting a collection of Guild ApplicationCommands. \brief For bulk-overwriting a collection of Guild ApplicationCommands.
    struct DiscordCoreAPI_Dll BulkOverwriteGuildApplicationCommandsData {
        vector<CreateGuildApplicationCommandData> responseData{};   ///< A vector of the options for the ApplicationCommands.
        string applicationId{ "" };///< The current application's Id (The Bot's User Id).
        string guildId{ "" };   ///< The id of the Guild which you would like to overwrite the commands of.
    };

    /// For acquiring the permissions of a collection of Guild ApplicationCommands. \brief For acquiring the permissions of a collection of Guild ApplicationCommands.
    struct DiscordCoreAPI_Dll GetGuildApplicationCommandPermissionsData {
        string applicationId{ "" };///< The current application's Id (The Bot's User Id).
        string guildId{ "" }; ///< The id of the Guild from which you would like to acquire the command permissions.
    };

    /// For acquiring the permissions of a single Guild ApplicationCommand. \brief For acquiring the permissions of a single Guild ApplicationCommand.
    struct DiscordCoreAPI_Dll GetApplicationCommandPermissionsData {
        string applicationId{ "" };///< The current application's Id (The Bot's User Id).
        string commandName{ "" };///< The name of the command which you would like to collect the permissions of.
        string guildId{ "" };///< The id of the Guild from which you would like to acquire the command permissions.
    };

    /// For editing the permissions of a single Guild ApplicationCommand. \brief For editing the permissions of a single Guild ApplicationCommand.
    struct DiscordCoreAPI_Dll EditGuildApplicationCommandPermissionsData {
        vector<ApplicationCommandPermissionData> permissions{}; ///< A vector of ApplicationCommand permissions.
        string applicationId{ "" };///< The current application's Id (The Bot's User Id).
        string commandName{ "" }; ///< The command name which you would like to edit the permissions of.
        string commandId{ "" };///< The command id which you would like to edit the permissions of.
        string guildId{ "" };///< The Guild id of the Guild for which you would like to edit the command permissions.
    };

    /// For batch editing the permissions of a collection of Guild ApplicationCommands. \brief For batch editing the permissions of a collection of Guild ApplicationCommands.
    struct DiscordCoreAPI_Dll BatchEditGuildApplicationCommandPermissionsData {
        vector<GuildApplicationCommandPermissionsData> permissions{}; ///< A vector of edit-Guild-application-permissions responseData to edit.
        string applicationId{ "" };///< The current application's Id (The Bot's User Id).
        string guildId{ "" };///< The Guild id of the Guild for which you would like to batch edit Guild application permissions.
    };

    /// A single ApplicationCommand. \brief A single ApplicationCommand.
    class DiscordCoreAPI_Dll ApplicationCommand : public ApplicationCommandData {
    public:

        ApplicationCommand();

        ApplicationCommand(ApplicationCommandData dataNew);
    };

    /**@}*/

    /**
    * \addtogroup main_endpoints
    * @{
    */
    /// An interface class for the ApplicationCommand related Discord endpoints. \brief An interface class for the ApplicationCommand related Discord endpoints.
    class DiscordCoreAPI_Dll ApplicationCommands {
    public:

        static void initialize(shared_ptr<DiscordCoreInternal::HttpClient>);

        /// Get all of the global ApplicationCommands for this bot. \brief Get all of the global ApplicationCommands for this bot.
        /// \returns A CoRoutine containing a vector<ApplicationCommand>.
        static CoRoutine<vector<ApplicationCommand>> getGlobalApplicationCommandsAsync(GetGlobalApplicationCommandsData dataPackage);

        /// Create a global ApplicationCommand for this bot. \brief Create a global ApplicationCommand for this bot.
        /// \param dataPackage A CreateGlobalApplicationCommandData structure.
        /// \returns A CoRoutine containing an ApplicationCommand.
        static CoRoutine<ApplicationCommand> createGlobalApplicationCommandAsync(CreateGlobalApplicationCommandData dataPackage);

        /// Get a single global ApplicationCommand for this bot. \brief Get a single global ApplicationCommand for this bot.
        /// \param dataPackage A GetGlobalApplicationCommandData structure.
        /// \returns A CoRoutine containing an ApplicationCommand.
        static CoRoutine<ApplicationCommand> getGlobalApplicationCommandAsync(GetGlobalApplicationCommandData dataPackage);

        /// Edit a global ApplicationCommand for this bot. \brief Edit a global ApplicationCommand for this bot.
        /// \param dataPackage An EditGlobalApplicationCommandData structure.
        /// \returns A CoRoutine containing an ApplicationCommand.
        static CoRoutine<ApplicationCommand> editGlobalApplicationCommandAsync(EditGlobalApplicationCommandData dataPackage);

        /// Delete a global ApplicationCommand for this bot. \brief Delete a global ApplicationCommand for this bot.
        /// \param dataPackage A DeleteGlobalApplicationCommandData structure.
        /// \returns A CoRoutine containing void.
        static CoRoutine<void> deleteGlobalApplicationCommandAsync(DeleteGlobalApplicationCommandData dataPackage);

        /// Bulk overwrites a collection of global ApplicationCommands. \brief Bulk overwrites a collection of global ApplicationCommands.
        /// \param dataPackage A BulkOverwriteGlobalApplicationCommandsData structure.
        /// \returns A CoRoutine containing a vector<ApplicationCommand>.
        static CoRoutine<vector<ApplicationCommand>> bulkOverwriteGlobalApplicationCommandsAsync(BulkOverwriteGlobalApplicationCommandsData dataPackage);

        /// Get all of the Guild ApplicationCommands for a single Guild for this bot. \brief Get all of the Guild ApplicationCommands for a single Guild for this bot.
        /// \param dataPackage A GetGuildApplicationCommandsData structure.
        /// \returns A CoRoutine containing a vector<ApplicationCommand>.
        static CoRoutine<vector<ApplicationCommand>> getGuildApplicationCommandsAsync(GetGuildApplicationCommandsData dataPackage);

        /// Create a Guild ApplicationCommand for a single server for this bot. \brief Create a Guild ApplicationCommand for a single server for this bot.
        /// \param dataPackage A CreateGuildApplicationCommandData structure.
        /// \returns A CoRoutine containing an ApplicationCommand.
        static CoRoutine<ApplicationCommand> createGuildApplicationCommandAsync(CreateGuildApplicationCommandData dataPackage);

        /// Get a single Guild ApplicationCommand for a single server for this bot. \brief Get a single Guild ApplicationCommand for a single server for this bot.
        /// \param dataPackage A GetGuildApplicationCommandData structure.
        /// \returns A CoRoutine containing an ApplicationCommand.
        static CoRoutine<ApplicationCommand> getGuildApplicationCommandAsync(GetGuildApplicationCommandData dataPackage);

        /// Edit a single Guild ApplicationCommand for a single server for this bot. \brief Edit a single Guild ApplicationCommand for a single server for this bot.
        /// \param dataPackage An EditGuildApplicationCommandData structure.
        /// \returns A CoRoutine containing an ApplicationCommand.
        static CoRoutine<ApplicationCommand> editGuildApplicationCommandAsync(EditGuildApplicationCommandData dataPackage);

        /// Delete a single Guild ApplicationCommand for a single server for this bot. \brief Delete a single Guild ApplicationCommand for a single server for this bot.
        /// \param dataPackage A DeleteGuildApplicationCommandData structure.
        /// \returns A CoRoutine containing void.
        static CoRoutine<void> deleteGuildApplicationCommandAsync(DeleteGuildApplicationCommandData dataPackage);

        /// Bulk overwrites some Guild ApplicationCommands for this bot. \brief Bulk overwrites some Guild ApplicationCommands for this bot.
        /// \param dataPackage A BulkOverwriteGuildApplicationCommandsData structure.
        /// \returns A CoRoutine containing a vector<ApplicationCommand>.
        static CoRoutine<vector<ApplicationCommand>> bulkOverwriteGuildApplicationCommandsAsync(BulkOverwriteGuildApplicationCommandsData dataPackage);

        /// Gets Guild ApplicationCommand permissions for a single server on this bot. \brief Gets Guild ApplicationCommand permissions for a single server on this bot.
        /// \param dataPackage A GetGuildApplicationCommandPermissionsData structure.
        /// \returns A CoRoutine containing a vector<GuildApplicationCommandPermissionsData>.
        static CoRoutine<vector<GuildApplicationCommandPermissionsData>> getGuildApplicationCommandPermissionsAsync(GetGuildApplicationCommandPermissionsData dataPackage);

        /// Get ApplicationCommand permissions for a single command on this bot. \brief Get ApplicationCommand permissions for a single command on this bot.
        /// \param dataPackage A GetApplicationCommandPermissionsData structure.
        /// \returns A CoRoutine containing a GuildApplicationCommandPermissionsData.
        static CoRoutine<GuildApplicationCommandPermissionsData> getApplicationCommandPermissionsAsync(GetApplicationCommandPermissionsData dataPackage);

        /// Edit Guild ApplicationCommand permissions for a server on this bot. \brief Edit Guild ApplicationCommand permissions for a server on this bot.
        /// \param dataPackage An EditGuildApplicationCommandPermissionsData structure.
        /// \returns A CoRoutine containing a GuildApplicationCommandPermissionsData.
        static CoRoutine<GuildApplicationCommandPermissionsData> editGuildApplicationCommandPermissionsAsync(EditGuildApplicationCommandPermissionsData dataPackage);

        /// Batch edit Guild ApplicationCommand permissions for a single server on this bot. \brief Batch edit Guild ApplicationCommand permissions for a single server on this bot.
        /// \param dataPackage A BatchEditGuildApplicationCommandPermissionsData structure.
        /// \returns A CoRoutine containing a vector<GuildApplicationCommandPermissionsData>.
        static CoRoutine<vector<GuildApplicationCommandPermissionsData>> batchEditGuildApplicationCommandPermissionsAsync(BatchEditGuildApplicationCommandPermissionsData dataPackage);

    protected:

        static shared_ptr<DiscordCoreInternal::HttpClient> httpClient;
    };
    /**@}*/

}
