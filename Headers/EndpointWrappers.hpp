// EndpointWrappers.hpp - Header for the endpoint wrapper classes.
// Oct 1, 2021
// Chris M.
// https://github.com/RealTimeChris

#pragma once

#ifndef _ENDPOINT_WRAPPERS_
#define _ENDPOINT_WRAPPERS_

#include "IndexInitial.hpp"
#include "DiscordCoreClient.hpp"
#include "CoRoutine.hpp"

namespace DiscordCoreAPI {

	/**
	* \addtogroup discord_core_client
	* @{
	*/
	/// An interface class for the ApplicationCommand related Discord endpoints. \brief An interface class for the ApplicationCommand related Discord endpoints.
	class DiscordCoreAPI_Dll ApplicationCommands {
	public:
		/// Get all of the global ApplicationCommands for this bot. \brief Get all of the global ApplicationCommands for this bot.
		/// \returns A CoRoutine containing a vector of ApplicationCommands.
		static CoRoutine<vector<ApplicationCommand>> getGlobalApplicationCommandsAsync();

		/// Create a global ApplicationCommand for this bot. \brief Create a global ApplicationCommand for this bot.
		/// \param dataPackage A CreateGlobalApplicationCommandData  structure.
		/// \returns A CoRoutine containing an ApplicationCommand.
		static CoRoutine<ApplicationCommand> createGlobalApplicationCommandAsync(CreateGlobalApplicationCommandData dataPackage);

		/// Get a single global ApplicationCommand for this bot. \brief Get a single global ApplicationCommand for this bot.
		/// \param dataPackage A GetGlobalApplicationCommandData structure.
		/// \returns A CoRoutine containing an ApplicationCommand.
		static CoRoutine<ApplicationCommand> getGlobalApplicationCommandAsync(GetGlobalApplicationCommandData dataPackage);

		/// Edit a global ApplicationCommand for this bot. \brief Edit a global ApplicationCommand for this bot.
		/// \param dataPackage A EditGlobalApplicationCommandData structure.
		/// \returns A CoRoutine containing an ApplicationCommand.
		static CoRoutine<ApplicationCommand> editGlobalApplicationCommandAsync(EditGlobalApplicationCommandData dataPackage);

		/// Delete a global ApplicationCommand for this bot. \brief Delete a global ApplicationCommand for this bot.
		/// \param dataPackage A DeleteGlobalApplicationCommandData structure.
		/// \returns void
		static CoRoutine<void> deleteGlobalApplicationCommandAsync(DeleteGlobalApplicationCommandData dataPackage);

		/// Bulk overwrites a collection of global ApplicationCommands. \brief Bulk overwrites a collection of global ApplicationCommands.
		/// \param dataPackage A BulkOverwriteGlobalApplicationCommandsData structure.
		/// \returns A CoRoutine containing a vector of ApplicationCommand.
		static CoRoutine<vector<ApplicationCommand>> bulkOverwriteGlobalApplicationCommandsAsync(BulkOverwriteGlobalApplicationCommandsData dataPackage);

		/// Get all of the Guild ApplicationCommands for a single Guild for this bot. \brief Get all of the Guild ApplicationCommands for a single Guild for this bot.
		/// \param dataPackage A GetGuildApplicationCommandsData structure.
		/// \returns A CoRoutine containing a vector of ApplicationCommand.
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
		/// \param dataPackage A EditGuildApplicationCommandData structure.
		/// \returns A CoRoutine containing an ApplicationCommand.
		static CoRoutine<ApplicationCommand> editGuildApplicationCommandAsync(EditGuildApplicationCommandData dataPackage);

		/// Delete a single Guild ApplicationCommand for a single server for this bot. \brief Delete a single Guild ApplicationCommand for a single server for this bot.
		/// \param dataPackage A DeleteGuildApplicationCommandData structure.
		/// \returns void
		static CoRoutine<void> deleteGuildApplicationCommandAsync(DeleteGuildApplicationCommandData dataPackage);

		/// Bulk overwrites some Guild ApplicationCommands for this bot. \brief Bulk overwrites some Guild ApplicationCommands for this bot.
		/// \param dataPackage A BulkOverwriteGuildApplicationCommandsData structure.
		/// \returns A CoRoutine containing a vector of ApplicationCommand.
		static CoRoutine<vector<ApplicationCommand>>  bulkOverwriteGuildApplicationCommandsAsync(BulkOverwriteGuildApplicationCommandsData dataPackage);

		/// Gets Guild ApplicationCommand permissions for a single server on this bot. \brief Gets Guild ApplicationCommand permissions for a single server on this bot.
		/// \param dataPackage A GetGuildApplicationCommandPermissionsData structure.
		/// \returns A CoRoutine containing a vector of GuildApplicationCommandPermissionsData.
		static CoRoutine<vector<GuildApplicationCommandPermissionsData>> getGuildApplicationCommandPermissionsAsync(GetGuildApplicationCommandPermissionsData dataPackage);

		/// Get ApplicationCommand permissions for a single command on this bot. \brief Get ApplicationCommand permissions for a single command on this bot.
		/// \param dataPackage A GetApplicationCommandPermissionsData structure.
		/// \returns A GuildApplicationCommandPermissionsData structure.
		static CoRoutine<GuildApplicationCommandPermissionsData> getApplicationCommandPermissionsAsync(GetApplicationCommandPermissionsData dataPackage);

		/// Edit Guild ApplicationCommand permissions for a server on this bot. \brief Edit Guild ApplicationCommand permissions for a server on this bot.
		/// \param dataPackage A EditGuildApplicationCommandPermissionsData structure.
		/// \returns A GuildApplicationCommandPermissionsData structure.
		static CoRoutine<GuildApplicationCommandPermissionsData> editGuildApplicationCommandPermissionsAsync(EditGuildApplicationCommandPermissionsData dataPackage);

		/// Batch edit Guild ApplicationCommand permissions for a single server on this bot. \brief Batch edit Guild ApplicationCommand permissions for a single server on this bot.
		/// \param dataPackage A BatchEditGuildApplicationCommandPermissionsData structure.
		/// \returns A vector of GuildApplicationCommandPermissionsData.
		static CoRoutine<vector<GuildApplicationCommandPermissionsData>> batchEditGuildApplicationCommandPermissionsAsync(BatchEditGuildApplicationCommandPermissionsData dataPackage);
	};
	/**@}*/

	/**
	* \addtogroup discord_core_client
	* @{
	*/
	/// An interface class for the Channel related endpoints. \brief An interface class for the Channel-related endpoints.
	class DiscordCoreAPI_Dll Channels {
	public:

		friend class EventHandler;

		/// Collects a Channel from the library's cache. \brief Collects a Channel from the library's cache.		
		/// \param dataPackage A GetChannelData structure.
		/// \returns A CoRoutine containing a Channel.
		static CoRoutine<Channel> getCachedChannelAsync(GetChannelData dataPackage);

		/// Collects a Channel from the Discord servers. \brief Collects a Channel from the Discord servers.
		/// \param dataPackage A GetChannelData structure.
		/// \returns A CoRoutine containing a Channel.
		static CoRoutine<Channel> getChannelAsync(GetChannelData dataPackage);

		/// Modifies a Channel's properties. \brief Modifies a Channel's properties.
		/// \param dataPackage A ModifyChannelData structure.
		/// \returns A CoRoutine containing a Channel.
		static CoRoutine<Channel> modifyChannelAsync(ModifyChannelData dataPackage);

		/// Delete a channel, or close a private message. \brief Delete a channel, or close a private message.
		/// \param dataPackage A DeleteChannelData structure.
		/// \returns A CoRoutine containing a Channel.
		static CoRoutine<void> deleteChannelAsync(DeleteChannelData dataPackage);

		/// Edit the given Permissions overwrites for a given User or Role. \brief Edit the given Permissions overwrites for a given User or Role.
		/// \param dataPackage A EditChannelPermissionOverwritesData structure.
		/// \returns A CoRoutine containing void.
		static CoRoutine<void> editChannelPermissionOverwritesAsync(EditChannelPermissionOverwritesData dataPackage);

		/// Delete the given Permissions overwrites for a given User or Role. \brief Delete the given Permissions overwrites for a given User or Role.
		/// \param dataPackage A DeleteChannelPermissionOverwritesData structure.
		/// \returns A CoRoutine containing void.
		static CoRoutine<void> deleteChannelPermissionOverwritesAsync(DeleteChannelPermissionOverwritesData dataPackage);

		/// Collect a direct-Message Channel between the bot and the User. \brief Collect a direct-Message Channel between the bot and the User.
		/// \param dataPackage A GetDMChannelData structure.
		/// \returns A CoRoutine containing a Channel.
		static CoRoutine<Channel> getDMChannelAsync(GetDMChannelData dataPackage);

	protected:
		static void insertChannel(Channel dataPackage);

		static void removeChannel(string channelId);
	};
	/**@}*/

	/**
	* \addtogroup discord_core_client
	* @{
	*/
	/// An interface class for the Guild related Discord endpoints. \brief An interface class for the Guild related Discord endpoints.
	class DiscordCoreAPI_Dll Guilds {
	public:
		friend class EventHandler;

		/// Getes an audit log from the Discord servers. \brief Getes an audit log from the Discord servers.
		/// \param dataPackage A GetAuditLogData structure.
		/// \returns A CoRoutine containing AuditLogData.
		static CoRoutine<AuditLogData> getAuditLogDataAsync(GetAuditLogData dataPackage);

		/// Collects a Guild from the library's cache. \brief Collects a Guild from the library's cache.
		/// \param dataPackage A GetGuildData structure.
		/// \returns A CoRoutine containing a Guild.
		static CoRoutine<Guild> getCachedGuildAsync(GetGuildData dataPackage);

		/// Collects a Guild from the Discord servers. \brief Collects a Guild from the Discord servers.
		/// \param dataPackage A GetGuildData structure.
		/// \returns A CoRoutine containing a Guild.
		static CoRoutine<Guild> getGuildAsync(GetGuildData dataPackage);

		/// Getes an invite from the Discord servers. \brief Getes an invite from the Discord servers.
		/// \param dataPackage A GetInviteData structure.
		/// \returns A CoRoutine containing InviteData.
		static CoRoutine<InviteData> getInviteAsync(GetInviteData dataPackage);

		/// Getes multiple invites from the Discord servers. \brief Getes multiple invites from the Discord servers.
		/// \param dataPackage A GetInvitesData structure.
		/// \returns A CoRoutine containing a vector of InviteData.
		static CoRoutine<vector<InviteData>> getInvitesAsync(GetInvitesData dataPackage);

		/// Getes the vanity invite data from a particular server. \brief Getes the vanity invite data from a particular server.
		/// \param dataPackage A GetVanityInviteData structure.
		/// \returns A CoRoutine containing InviteData.
		static CoRoutine<InviteData> getVanityInviteAsync(GetVanityInviteData dataPackage);

		/// Bans a GuildMember. \brief Bans a GuildMember.
		/// \param dataPackage A CreateGuildBanData structure.
		/// \returns A CoRoutine containing BanData.
		static CoRoutine<BanData> createGuildBanAsync(CreateGuildBanData dataPackage);

		/// Returns all of the Guilds that the current bot is in. \brief Returns all of the Guilds that the current bot is in.
		/// \returns A CoRoutine containing a vector of Guild.
		static CoRoutine<vector<Guild>> getAllGuildsAsync();

	protected:
		static void insertGuild(Guild Guild);

		static void removeGuild(Guild Guild);
	};
	/**@}*/

	/**
	* \addtogroup discord_core_client
	* @{
	*/
	/// An interface class for the GuildMember related Discord endpoints. \brief An interface class for the GuildMember related Discord endpoints.
	class DiscordCoreAPI_Dll GuildMembers {
	public:
		friend class EventHandler;

		/// Collects a GuildMember from the library's cache. \brief Collects a GuildMember from the library's cache.
		/// \param dataPackage A GetGuildMemberData structure.
		/// \returns A CoRoutine containing a GuildMember.
		static CoRoutine<GuildMember> getCachedGuildMemberAsync(GetGuildMemberData dataPackage);

		/// Collects a GuildMember from the Discord servers. \brief Collects a GuildMember from the Discord servers.
		/// \param dataPackage A GetGuildMemberData structure.
		/// \returns A CoRoutine containing a GuildMember.
		static CoRoutine<GuildMember> getGuildMemberAsync(GetGuildMemberData dataPackage);

		/// Modify's a GuildMember's properties. \brief Modify's a GuildMember's properties.
		/// \param dataPackage A ModifyGuildMemberData structure.
		/// \returns A CoRoutine containing a GuildMember.
		static CoRoutine<GuildMember> modifyGuildMemberAsync(ModifyGuildMemberData dataPackage);

	protected:
		static void insertGuildMember(GuildMember dataPackage);

		static void removeGuildMember(GuildMember dataPackage);
	};
	/**@}*/

	/**
	* \addtogroup discord_core_client
	* @{
	*/
	/// An interface class for the Interaction related Discord endpoints. \brief An interface class for the Interaction related Discord endpoints.
	class DiscordCoreAPI_Dll Interactions {
	public:

		/// Creates a deferred response to an input Interaction. \brief Creates a deferred response to an input Interaction.
		/// \param dataPackage A CreateDeferredInteractionResponseData structure.
		/// \returns A CoRoutine containing void.
		static CoRoutine<void> createDeferredInteractionResponseAsync(CreateDeferredInteractionResponseData dataPackage);

		/// Creates a response to an input Interaction. \brief Creates a response to an input Interaction.
		/// \param dataPackage A CreateInteractionResponseData structure.
		/// \returns A CoRoutine containing a MessageData.
		static CoRoutine<MessageData> createInteractionResponseAsync(CreateInteractionResponseData dataPackage);

		/// Collects an Interaction response. \brief Collects an Interaction response.
		/// \param dataPackage A GetInteractionResponseData structure.
		/// \returns A CoRoutine containing an InteractionResponseData.
		static CoRoutine<InteractionResponseData> getInteractionResponseAsync(GetInteractionResponseData dataPackage);

		/// Edits an Interaction response. \brief Edits an Interaction response.
		/// \param dataPackage A EditInteractionResponseData structure.
		/// \returns A CoRoutine containing a MessageData.
		static CoRoutine<MessageData> editInteractionResponseAsync(EditInteractionResponseData dataPackage);

		/// Deletes an Interaction respnose. \brief Deletes an Interaction respnose.
		/// \param dataPackage A DeleteInteractionResponseData structure.
		/// \returns A CoRoutine containing void.
		static CoRoutine<void> deleteInteractionResponseAsync(DeleteInteractionResponseData dataPackage);

		/// Creates a follow up Message to an input Interaction. \brief Creates a follow up Message to an input Interaction.
		/// \param dataPackage A CreateFollowUpMessageData structure.
		/// \returns A CoRoutine containing a MessageData.
		static CoRoutine<MessageData> createFollowUpMessageAsync(CreateFollowUpMessageData dataPackage);
		
		/// Creates a follow up Message to an input Interaction. \brief Creates a follow up Message to an input Interaction.
		/// \param dataPackage A CreateFollowUpMessageData structure.
		/// \returns A CoRoutine containing a MessageData.
		static CoRoutine<MessageData> getFollowUpMessageAsync(GetFollowUpMessageData dataPackage);

		/// Edits a follow up Message. \brief Edits a follow up Message.
		/// \param dataPackage A EditFollowUpMessageData structure.
		/// \returns A CoRoutine containing a MessageData.
		static CoRoutine<MessageData> editFollowUpMessageAsync(EditFollowUpMessageData dataPackage);

		/// Deletes a follow up Message. \brief Deletes a follow up Message.
		/// \param dataPackage A DeleteFollowUpMessageData structure.
		/// \returns A CoRoutine containing void.
		static CoRoutine<void> deleteFollowUpMessageAsync(DeleteFollowUpMessageData dataPackage);
	};
	/**@}*/

	/**
	* \addtogroup discord_core_client
	* @{
	*/
	/// An interface class for the Message related Discord endpoints. \brief An interface class for the Message related Discord endpoints;
	class DiscordCoreAPI_Dll Messages {
	public:

		/// Collects a Message from the Discord servers. \brief Collects a Message from the Discord servers.
		/// \param dataPackage A GetMessageData structure.
		/// \returns A CoRoutine containing a Message.
		static CoRoutine<Message> getMessageAsync(GetMessageData dataPackage);

		/// Creates a new Message. \brief Creates a new Message.
		/// \param dataPackage A CreateMessageData structure.
		/// \returns A CoRoutine containing a Message.
		static CoRoutine<Message> createMessageAsync(CreateMessageData dataPackage);

		/// Deletes a Message. \brief Deletes a Message.
		/// \param dataPackage A DeleteMessageData structure.
		/// \returns A CoRoutine containing void.
		static CoRoutine<void> deleteMessageAsync(DeleteMessageData dataPackage);

		/// Deletes a collection of Messages. \brief Deletes a collection of Messages.
		/// \param dataPackage A DeleteMessagesBulkData structure.
		/// \returns A CoRoutine containing void.
		static CoRoutine<void> deleteMessagesBulkAsync(DeleteMessagesBulkData dataPackage);

		/// Crossposts a message from a News Channel to the following Channels. \brief Crossposts a message from a News Channel to the following Channels.
		/// \param dataPackage A CrosspostMessageData structure.
		/// \returns A CoRoutine containing void.
		static CoRoutine<Message> crosspostMessageAsync(CrosspostMessageData dataPackage);

		/// Edit a Message. \brief Edit a Message.
		/// \param dataPackage A EditMessageData structure.
		/// \returns A CoRoutine containing a Message.
		static CoRoutine<Message> editMessageAsync(EditMessageData dataPackage);

		/// Collects a collection of Message from the Discord servers. \brief Collects a collection of Message from the Discord servers.
		/// \param dataPackage A GetMessagesData structure.
		/// \returns A CoRoutine containing an optional vector of Message.
		static CoRoutine<vector<Message>> getMessagesAsync(GetMessagesData dataPackage);

		/// Collects a collection of pinned Messages from the Discord servers. \brief Collects a collection of pinned Messages from the Discord servers.
		/// \param dataPackage A GetPinnedMessagesData structure.
		/// \returns A CoRoutine containing a vector of Message.
		static CoRoutine<vector<Message>> getPinnedMessagesAsync(GetPinnedMessagesData dataPackage);

		/// Pins a Message to a given Channel. \brief Pins a Message to a given Channel.
		/// \param dataPackage A PinMessageData structure.
		/// \returns A CoRoutine containing void.
		static CoRoutine<void> pinMessageAsync(PinMessageData dataPackage);

		/// Send a direct Message to a given User. \brief Send a direct Message to a given User.
		/// \param dataPackage A SendDMData structure.
		/// \returns A CoRoutine containing a Message.
		static CoRoutine<Message> sendDMAsync(SendDMData dataPackage);
	};
	/**@}*/

	/**
	* \addtogroup discord_core_client
	* @{
	*/
	/// An interface class for the Reaction related Discord endpoints. \brief An interface class for the Reaction related Discord endpoints.
	class DiscordCoreAPI_Dll Reactions {
	public:

		/// Creates a Reaction on a Message. \brief Creates a Reaction on a Message.
		/// \param dataPackage A CreateReactionData structure.
		/// \returns A CoRoutine containing a Reaction.
		static CoRoutine<Reaction> createReactionAsync(CreateReactionData dataPackage);

		/// Get a list of users that reacted with this emoji. Returns an array of user objects on success. \brief Get a list of users that reacted with this emoji. Returns an array of user objects on success.
		/// \param dataPackage A GetReactionsData structure.
		/// \returns A CoRoutine containing a vector of Users.
		static CoRoutine<vector<User>> getReactionsAsync(GetReactionsData dataPackage);

		/// Deletes all of the Reactions from a given Message. \brief Deletes all of the Reactions from a given Message.
		/// \param dataPackage A DeleteAllReactionsData structure.
		/// \returns A CoRoutine containing void.
		static CoRoutine<void> deleteAllReactionsAsync(DeleteAllReactionsData dataPackage);

		/// Deletes your own Reactions from a given Message. \brief Deletes your own Reactions from a given Message.
		/// \param dataPackage A DeleteOwnReactionData structure.
		/// \returns A CoRoutine containing void.
		static CoRoutine<void> deleteOwnReactionAsync(DeleteOwnReactionData dataPackage);

		/// Deletes all of the Reactions by a specific emoji from a given Message. \brief Deletes all of the Reactions by a specific emoji from a given Message. 
		/// \param dataPackage A DeleteReactionsByEmojiData structure.
		/// \returns A CoRoutine containing void.
		static CoRoutine<void> deleteReactionsByEmojiAsync(DeleteReactionsByEmojiData dataPackage);

		/// Deletes all of the Reactions by a specific User from a given Message. \brief Deletes all of the Reactions by a specific User from a given Message. 
		/// \param dataPackage A DeleteUserReactionData structure.
		/// \returns A CoRoutine containing void.
		static CoRoutine<void> deleteUserReactionAsync(DeleteUserReactionData dataPackage);
	};
	/**@}*/

	/**
	* \addtogroup discord_core_client
	* @{
	*/
	/// An interface class for the Role related Discord endpoints. \brief An interface class for the Role related Discord endpoints.
	class DiscordCoreAPI_Dll Roles {
	public:
		friend class EventHandler;

		/// Collects a given Role from the library's cache. \brief Collects a given Role from the library's cache.
		/// \param dataPackage A GetRoleData structure.
		/// \returns A CoRoutine containing a Role.
		static CoRoutine<Role> getCachedRoleAsync(GetRoleData dataPackage);

		/// Adds a role to a chosen Guild member. \brief Adds a Role to a chosen Guild member.
		/// \param dataPackage A AddRoleToGuildMemberData structure.
		/// \returns A CoRoutine containing void.
		static CoRoutine<void> addRoleToGuildMemberAsync(AddRoleToGuildMemberData dataPackage);

		/// Creates a new Role within the given Guild. \brief Creates a new Role within the given Guild.
		/// \param dataPackage A CreateRoleData structure.
		/// \returns A Role.
		static CoRoutine<Role> createRoleAsync(CreateRoleData dataPackage);

		/// Collects a Role from the Discord servers. \brief Collects a Role from the Discord servers.
		/// \param dataPackage A GetRoleData structure.
		/// \returns A Role.
		static CoRoutine<Role> getRoleAsync(GetRoleData dataPackage);

		/// Collects the Roles that a GuildMember has. \brief Collects the Roles that a GuildMember has.
		/// \param dataPackage A GetGuildMemberRolesData structure.
		/// \returns A vector of Roles.
		static CoRoutine<vector<Role>> getGuildMemberRolesAsync(GetGuildMemberRolesData dataPackage);

		/// Collects the Roles that a Guild has. \brief Collects the Roles that a Guild has.
		/// \param dataPackage A GetGuildRolesData structure.
		/// \returns A CoRoutine containing a vector of Roles.
		static CoRoutine<vector<Role>> getGuildRolesAsync(GetGuildRolesData dataPackage);

		/// Removes a given Role from a Guild. \brief Removes a given Role from a Guild.
		/// \param dataPackage A RemoveRoleFromGuildData structure.
		/// \returns A CoRoutine containing void.
		static CoRoutine<void> removeRoleFromGuildAsync(RemoveRoleFromGuildData dataPackage);

		/// Removes a given Role from a chosen GuildMember. \brief Removes a given Role from a chosen GuildMember.
		/// \param dataPackage A RemoveRoleFromGuildMemberData structure.
		/// \returns A CoRoutine containing void.
		static CoRoutine<void> removeRoleFromGuildMemberAsync(RemoveRoleFromGuildMemberData dataPackage);

		/// Updates a given Role's properties. \brief Updates a given Role's properties.
		/// \param dataPackage A UpdateRoleData structure.
		/// \returns A CoRoutine containing a Role.
		static CoRoutine<Role> updateRoleAsync(UpdateRoleData dataPackage);

		/// Updates a Role's positions. \brief Updates a Role's positions.
		/// \param dataPackage A UpdateRolePositionData structure.
		/// \returns A vector containing Roles.
		static CoRoutine<vector<Role>> updateRolePositionsAsync(UpdateRolePositionData dataPackage);

	protected:
		static void insertRole(Role dataPackage);

		static void removeRole(string roleId);
	};
	/**@}*/

	/**
	* \addtogroup discord_core_client
	* @{
	*/
	/// An interface class for the User related Discord endpoints. \brief An interface class for the User related Discord endpoints.
	class DiscordCoreAPI_Dll Users {
	public:
		friend class EventHandler;

		/// Collects a given User from the library's cache. \brief Collects a given User from the library's cache.
		/// \param dataPackage A GetUserData structure.
		/// \returns A CoRoutine containing a User.
		 static CoRoutine<User> getCachedUserAsync(GetUserData dataPackage);

		/// Collects a given User from the Discord servers. \brief Collects a given User from the Discord servers.
		/// \param dataPackage A GetUserData structure.
		/// \returns A CoRoutine containing a User.
		 static CoRoutine<User> getUserAsync(GetUserData dataPackage);

	protected:
		 static void insertUser(User useruser);
	};
	/**@}*/

};

#endif