// StickerEntities.hpp - Header for the sticker related classes and structs.
// May 13, 2021
// Chris M.
// https://github.com/RealTimeChris

#pragma once

#include "FoundationEntities.hpp"
#include "CoRoutine.hpp"

namespace DiscordCoreAPI {

	/**
	* \addtogroup foundation_entities
	* @{
	*/
	/// For getting a Sticker object for the given sticker ID. \brief For getting a Sticker object for the given sticker ID.
	struct DiscordCoreAPI_Dll GetStickerData {
		std::string stickerId{ "" };///< The chosen Sticker's Id.
	};

	/// For collecting a list of Stickers from a chosen Guild. \brief For collecting a list of Stickers from a chosen Guild.
	struct DiscordCoreAPI_Dll GetGuildStickersData {
		std::string guildId{ "" };///< The chosen Guild from which you would like to collect the Stickers from.
	};

	/// For creating a single Sticker. \brief For creating a single Sticker.
	struct DiscordCoreAPI_Dll CreateGuildStickerData {
		std::string description{ "" };///< Description of the Sticker.
		std::vector<uint8_t> file{};///< The sticker file to upload, must be a Png, Apng, or Lottie JSON file, max 500 KB
		std::string guildId{ "" };///< The Guild within which to create the Sticker.
		std::string reason{ "" };///< The reason for creating the Sticker.
		std::string name{ "" };///< Name of the Sticker.
		std::string tags{ "" };///< Autocomplete / suggestion tags for the sticker(max 200 characters).
	};

	/// For modifying a single Sticker. \brief For modifying a single Sticker.
	struct DiscordCoreAPI_Dll ModifyGuildStickerData {
		std::string description{ "" };///< Description of the Sticker.
		std::string stickerId{ "" };///< The Sticker you wish to modify.
		std::string guildId{ "" };///< The Guild within which to modify the Sticker.
		std::string reason{ "" };///< The reason for modifying the Sticker.
		std::string name{ "" };///< Name of the Sticker.
		std::string tags{ "" };///< Autocomplete / suggestion tags for the sticker(max 200 characters).
	};

	/// For deleting a single Sticker. \brief For deleting a single Sticker.
	struct DiscordCoreAPI_Dll DeleteGuildStickerData {
		std::string stickerId{ "" };///< The Sticker you wish to delete.
		std::string guildId{ "" };///< The Guild within which to delete the Sticker.
		std::string reason{ "" };///< The reason for deleting the Sticker.
	};

	/// A single Sticker. \brief A single Sticker.
	class DiscordCoreAPI_Dll Sticker : public StickerData {
	public:

		Sticker();

		Sticker(StickerData dataNew);
	};

	/**@}*/

	/**
	* \addtogroup main_endpoints
	* @{
	*/
	/// An interface class DiscordCoreAPI_Dll for the Sticker related Discord endpoints. \brief An interface class DiscordCoreAPI_Dll for the Sticker related Discord endpoints.
	class DiscordCoreAPI_Dll Stickers {
	public:

		static void initialize(DiscordCoreInternal::HttpClient*);

		/// Gets a single Sticker item. \brief Gets a single Sticker item.
		/// \param dataPackage A GetStickerData structure.
		/// \returns A CoRoutine containing a Sticker.
		static CoRoutine<Sticker> getStickerAsync(GetStickerData dataPackage);

		/// Gets a list of nitro-available Sticker packs. \brief Gets a list of nitro-available Sticker packs.
		/// \returns A CoRoutine containing a std::vector<StickerPackData>.
		static CoRoutine<std::vector<StickerPackData>> getNitroStickerPacksAsync();
		
		/// Gets a list of Stickers from a Guild. \brief Gets a list of Stickers from a Guild.
		/// \param dataPackage A GetGuildStickersData structure.
		/// \returns A CoRoutine containing a std::vector<Sticker>.
		static CoRoutine<std::vector<Sticker>> getGuildStickersAsync(GetGuildStickersData dataPackage);

		/// Creates a new Sticker within a chosen Guild. \brief Creates a new Sticker within a chosen Guild.
		/// \param dataPackage A CreateGuildStickerData structure.
		/// \returns A CoRoutine containing a Sticker.
		static CoRoutine<Sticker> createGuildStickerAsync(CreateGuildStickerData dataPackage);

		/// Modifies a Sticker within a chosen Guild. \brief Modifies a Sticker within a chosen Guild.
		/// \param dataPackage A ModifyGuildStickerData structure.
		/// \returns A CoRoutine containing a Sticker.
		static CoRoutine<Sticker> modifyGuildStickerAsync(ModifyGuildStickerData dataPackage);

		/// Deletes a Sticker within a chosen Guild. \brief Deletes a Sticker within a chosen Guild.
		/// \param dataPackage A DeleteGuildStickerData structure.
		/// \returns A CoRoutine containing void.
		static CoRoutine<void> deleteGuildStickerAsync(DeleteGuildStickerData dataPackage);

	protected:

		static DiscordCoreInternal::HttpClient* httpClient;
	};
	/**@}*/
};
