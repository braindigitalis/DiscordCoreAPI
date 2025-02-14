// RoleEntities.hpp - Header for the role related classes and structs.
// May 13, 2021
// Chris M.
// https://github.com/RealTimeChris

#pragma once

#include "GuildMemberEntities.hpp"
#include "JSONIfier.hpp"

namespace DiscordCoreAPI {

	/**
	* \addtogroup foundation_entities
	* @{
	*/

	/// For adding a Role to a GuildMember. \brief For addin a Role to a GuildMember.
	struct DiscordCoreAPI_Dll AddGuildMemberRoleData {
		std::string guildId{ "" };///< The id of the Guild within which to assign the Role.
		std::string userId{ "" };///< The id of the User to whom to assign the Role.
		std::string roleId{ "" };///< The id of the Role to be assigned.
		std::string reason{ "" };///< Reason for adding the GuildMember's Role.
	};

	/// For removing a Role from a GuildMember. \brief For removing a Role from a GuildMember.
	struct DiscordCoreAPI_Dll RemoveGuildMemberRoleData {
		std::string guildId{ "" };///< The id of the Guild within which to remove the Role.
		std::string userId{ "" };///< The id of the User from whom to remove the Role.
		std::string roleId{ "" };///< The id of the Role to be removed.
		std::string reason{ "" };///< Reason for removing the GuildMember's Role.
	};

	/// For getting a chosen Guild's Roles. \brief For getting a chosen Guild's Roles.
	struct DiscordCoreAPI_Dll GetGuildRolesData {
		std::string guildId{ "" };///< Guild id for which Guild to get the roles from.
	};

	/// For creating a new Role within a chosen Guild. \brief For creating a new Role within a chosen Guild.
	struct DiscordCoreAPI_Dll CreateGuildRoleData {
		std::string hexColorValue{ "" };///< Hex color-value between 0 and ffffff.
		Permissions permissions{ "0" };///< The base permissions to give the Role.
		bool mentionable{ false };///< Is it mentionable by others in the Guild.
		std::string guildId{ "" };///< Which Guild to make the Role in.
		std::string reason{ "" };///< Reason for creating the Role.
		std::string name{ "" };///< The name of the Role.
		int32_t position{ 0 };///< The position amongst the other roles.
		bool hoist{ false };///< Is this Role hoisted above the rest of them?
	};

	/// For updating the positions of the roles. \brief For updating the positions of the roles.
	struct DiscordCoreAPI_Dll RolePositionData {
		int32_t rolePosition{ 0 };///< The new Role position.
		std::string roleId{ "" };///< The Role to update.
	};

	/// For updating the Role positions. \brief For updating the Role positions.
	struct DiscordCoreAPI_Dll ModifyGuildRolePositionsData {
		friend std::string DiscordCoreInternal::JSONIFY(ModifyGuildRolePositionsData dataPackage);
		friend Roles;

		std::string guildId{ "" };///< The Guild within which to std::move the Role.
		int32_t newPosition{ 0 };///< The new position of the Role.
		std::string roleId{ "" };///< The id of the Role to std::move/
		std::string reason{ "" };///< Reason for modifying the Role positions.

	protected:
		std::vector<RolePositionData> rolePositions;
	};

	/// For updating a Role's options within a chosen Guild. \brief For updating a Role's options within a chosen Guild.
	struct DiscordCoreAPI_Dll ModifyGuildRoleData {
		std::string hexColorValue{ "" };///< A hex-color value between 0x00 and 0xFFFFFF.
		std::string permissions{ "0" };///< Base Guild permissions for the Role.
		bool mentionable{ false };///< Is it mentionable?
		std::string guildId{ "" };///< The id of the Guild within which to update the Role.
		std::string roleId{ "" };///< The id of the Role to update.
		std::string reason{ "" };///<< Reason for modifying the Role.
		std::string name{ "" };///< What the name of the Role is going to be.
		bool hoist{ false };///< Is this Role hoisted above the others?
	};

	/// For removing a Role from a chosen Guild. \brief For removing a Role from a chosen Guild.
	struct DiscordCoreAPI_Dll RemoveGuildRoleData {
		std::string guildId{ "" };///< The id of the Guild from which to remove the Role.
		std::string roleId{ "" };///< The id of the Role to remove.
		std::string reason{ "" };///< Reason for removing this Role.
	};

	/// For getting a chosen GuildMember's Roles. \brief For getting a chosen GuildMember's Roles.
	struct DiscordCoreAPI_Dll GetGuildMemberRolesData {
		GuildMember guildMember{};///< Which Guild member to collect the roles from.
		std::string guildId{ "" };///< Which Guild to collect their roles from.
	};

	/// For getting a Role from the library's cache, or the Discord server. \brief For getting a Role from the library's cache, or the Discord server.
	struct DiscordCoreAPI_Dll GetRoleData {
		std::string guildId{ "" };///<Which Guild to collect the Role from.
		std::string roleId{ "" };///< Which Role to collect.
	};

	/// A single Role.
	class DiscordCoreAPI_Dll Role : public RoleData {
	public:

		Role();

		Role(RoleData dataNew);
	};

	/**@}*/

	/**
	* \addtogroup main_endpoints
	* @{
	*/
	/// An interface class DiscordCoreAPI_Dll for the Role related Discord endpoints. \brief An interface class DiscordCoreAPI_Dll for the Role related Discord endpoints.
	class DiscordCoreAPI_Dll Roles {
	public:

		friend DiscordCoreClient;
		friend EventHandler;
		friend Guild;

		static void initialize(DiscordCoreInternal::HttpClient*);

		/// Adds a role to a chosen Guild member. \brief Adds a Role to a chosen Guild member.
		/// \param dataPackage An AddGuildMemberRoleData structure.
		/// \returns A CoRoutine containing void.
		static CoRoutine<void> addGuildMemberRoleAsync(AddGuildMemberRoleData dataPackage);

		/// Removes a given Role from a chosen GuildMember. \brief Removes a given Role from a chosen GuildMember.
		/// \param dataPackage A RemoveGuildMemberRoleData structure.
		/// \returns A CoRoutine containing void.
		static CoRoutine<void> removeGuildMemberRoleAsync(RemoveGuildMemberRoleData dataPackage);

		/// Collects the Roles that a Guild has. \brief Collects the Roles that a Guild has.
		/// \param dataPackage A GetGuildRolesData structure.
		/// \returns A CoRoutine containing a std::vector<Role>.
		static CoRoutine<std::vector<Role>> getGuildRolesAsync(GetGuildRolesData dataPackage);

		/// Creates a new Role within the given Guild. \brief Creates a new Role within the given Guild.
		/// \param dataPackage A CreateGuildRoleData structure.
		/// \returns A CoRoutine containing a Role.
		static CoRoutine<Role> createGuildRoleAsync(CreateGuildRoleData dataPackage);

		/// Updates a Role's positions. \brief Updates a Role's positions.
		/// \param dataPackage A ModifyGuildRolePositionsData structure.
		/// \returns A CoRoutine containing a std::vector<Role>.
		static CoRoutine<std::vector<Role>> modifyGuildRolePositionsAsync(ModifyGuildRolePositionsData dataPackage);

		/// Updates a given Role's properties. \brief Updates a given Role's properties.
		/// \param dataPackage A ModifyGuildRoleData structure.
		/// \returns A CoRoutine containing a Role.
		static CoRoutine<Role> modifyGuildRoleAsync(ModifyGuildRoleData dataPackage);

		/// Removes a given Role from a Guild. \brief Removes a given Role from a Guild.
		/// \param dataPackage A RemoveGuildRoleData structure.
		/// \returns A CoRoutine containing void.
		static CoRoutine<void> removeGuildRoleAsync(RemoveGuildRoleData dataPackage);

		/// Collects the Roles that a GuildMember has. \brief Collects the Roles that a GuildMember has.
		/// \param dataPackage A GetGuildMemberRolesData structure.
		/// \returns A CoRoutine containing a std::vector<Role>.
		static CoRoutine<std::vector<Role>> getGuildMemberRolesAsync(GetGuildMemberRolesData dataPackage);

		/// Collects a Role from the Discord servers. \brief Collects a Role from the Discord servers.
		/// \param dataPackage A GetRoleData structure.
		/// \returns A CoRoutine containing a Role.
		static CoRoutine<Role> getRoleAsync(GetRoleData dataPackage);

		/// Collects a given Role from the library's cache. \brief Collects a given Role from the library's cache.
		/// \param dataPackage A GetRoleData structure.
		/// \returns A CoRoutine containing a Role.
		static CoRoutine<Role> getCachedRoleAsync(GetRoleData dataPackage);

	protected:

		static DiscordCoreInternal::HttpClient* httpClient;
		static std::unordered_map<std::string, Role> cache;

		static void insertRole(Role dataPackage);

		static void removeRole(std::string roleId);
	};
	/**@}*/

}
