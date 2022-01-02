// Http.hpp - Header for the Http class.
// May 12, 2021
// Chris M.
// https://github.com/RealTimeChris

#pragma once

#include "IndexInitial.hpp"
#include "FoundationEntities.hpp"
#include "DataParsingFunctions.hpp"

namespace DiscordCoreInternal {

	const string soundcloudCertPath{ "C:/Program Files/Common Files/SSL/certs/Root-R3.pem" };
	const string youtubeCertPath{ "C:/Program Files/Common Files/SSL/certs/gtsr1.pem" };
	const string googleCertPath{ "C:/Program Files/Common Files/SSL/certs/gtsr1.pem" };

	class DiscordCoreAPI_Dll HttpResponseData {
	public:

		bool doWeHaveContentSize{ false };
		bool doWeHaveHeaders{ false };
		map<string, string> headers{};
		string contentFinalReal{ "" };
		int64_t responseCode{ -1 };
		int64_t contentSize{ -1 };
		bool isItChunked{ false };
		string rawInput{ "" };

		bool checkForHeadersToParse();

		void parseHeaders();

		bool parseChunk();

		void parseSize();

		void clearCRLF();

		void parseCode();
	};

	class DiscordCoreAPI_Dll RequestBuilder {
	public:

		static string buildRequest(string& baseUrl, string& relativePath, string& content, map<string, string>& headers, HttpWorkloadClass workloadClass);

	};

	class DiscordCoreAPI_Dll HttpClient {
	public:

		static HttpResponseData executeHttpRequest(string& baseUrl, string& relativePath, string& content, map<string, string>& headers, HttpWorkloadClass workloadClass);

	protected:

		bool connect(string baseUrl, string relativePath);

		bool sendRequest(string request);

		HttpResponseData getResponse();

		BIOWrapper connectionBio{ nullptr };
		SSL_CTXWrapper context{ nullptr };
		HttpResponseData responseData{};
		vector<char> inputBuffer{};
		SSLWrapper ssl{ nullptr };
	};

	class DiscordCoreAPI_Dll HttpRequestAgent {
	public:

		friend class HttpClient;

		static void initialize(string);

		template<typename returnType>
		static returnType submitWorkloadAndGetResult(HttpWorkloadData workload) {
			try {
				shared_ptr<RateLimitData> rateLimitDataNew = make_shared<RateLimitData>();
				RateLimitData* rateLimitDataRaw = rateLimitDataNew.get();
				rateLimitDataNew->workloadType = workload.workloadType;
				if (HttpRequestAgent::rateLimitDataBucketValues.contains(workload.workloadType)) {
					rateLimitDataNew->bucket = HttpRequestAgent::rateLimitDataBucketValues.at(workload.workloadType);
					if (HttpRequestAgent::rateLimitData.contains(rateLimitDataNew->bucket)) {
						rateLimitDataRaw = HttpRequestAgent::rateLimitData.at(rateLimitDataNew->bucket).load().get();
					}
					else {
						HttpRequestAgent::rateLimitData.insert_or_assign(rateLimitDataRaw->bucket, rateLimitDataNew);
					}
				}
				else {
					rateLimitDataNew->tempBucket = to_string(chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now().time_since_epoch()).count());
					HttpRequestAgent::rateLimitDataBucketValues.insert_or_assign(workload.workloadType, rateLimitDataNew->tempBucket);
					HttpRequestAgent::rateLimitData.insert_or_assign(rateLimitDataRaw->tempBucket, rateLimitDataNew);
				}
				HttpData returnData = HttpRequestAgent::executeByRateLimitData(workload, rateLimitDataRaw, true);
				returnType returnObject{};
				DataParser::parseObject(returnData.data, &returnObject);
				return returnObject;
			}
			catch (...) {
				DiscordCoreAPI::reportException(workload.callStack + "::HttpRequestAgent::submitWorkloadAndGetResult");
			}
			returnType returnObject{};
			return returnObject;
		}

		template<>
		static void submitWorkloadAndGetResult<void>(HttpWorkloadData workload) {
			try {
				shared_ptr<RateLimitData> rateLimitDataNew = make_shared<RateLimitData>();
				RateLimitData* rateLimitDataRaw = rateLimitDataNew.get();
				rateLimitDataNew->workloadType = workload.workloadType;
				if (HttpRequestAgent::rateLimitDataBucketValues.contains(workload.workloadType)) {
					rateLimitDataNew->bucket = HttpRequestAgent::rateLimitDataBucketValues.at(workload.workloadType);
					if (HttpRequestAgent::rateLimitData.contains(rateLimitDataNew->bucket)) {
						rateLimitDataRaw = HttpRequestAgent::rateLimitData.at(rateLimitDataNew->bucket).load().get();
					}
					else {
						HttpRequestAgent::rateLimitData.insert_or_assign(rateLimitDataRaw->bucket, rateLimitDataNew);
					}
				}
				else {
					rateLimitDataNew->tempBucket = to_string(chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now().time_since_epoch()).count());
					HttpRequestAgent::rateLimitDataBucketValues.insert_or_assign(workload.workloadType, rateLimitDataNew->tempBucket);
					HttpRequestAgent::rateLimitData.insert_or_assign(rateLimitDataRaw->tempBucket, rateLimitDataNew);
				}
				HttpRequestAgent::executeByRateLimitData(workload, rateLimitDataRaw, true);
				return;
			}
			catch (...) {
				DiscordCoreAPI::reportException(workload.callStack + "::HttpRequestAgent::submitWorkloadAndGetResult");
			}
			return;
		}

		template<>
		static HttpData submitWorkloadAndGetResult<HttpData>(HttpWorkloadData workload) {
			try {
				shared_ptr<RateLimitData> rateLimitDataNew = make_shared<RateLimitData>();
				RateLimitData* rateLimitDataRaw = rateLimitDataNew.get();
				rateLimitDataNew->workloadType = workload.workloadType;
				if (HttpRequestAgent::rateLimitDataBucketValues.contains(workload.workloadType)) {
					rateLimitDataNew->bucket = HttpRequestAgent::rateLimitDataBucketValues.at(workload.workloadType);
					if (HttpRequestAgent::rateLimitData.contains(rateLimitDataNew->bucket)) {
						rateLimitDataRaw = HttpRequestAgent::rateLimitData.at(rateLimitDataNew->bucket).load().get();
					}
					else {
						HttpRequestAgent::rateLimitData.insert_or_assign(rateLimitDataRaw->bucket, rateLimitDataNew);
					}
				}
				else {
					rateLimitDataNew->tempBucket = to_string(chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now().time_since_epoch()).count());
					HttpRequestAgent::rateLimitDataBucketValues.insert_or_assign(workload.workloadType, rateLimitDataNew->tempBucket);
					HttpRequestAgent::rateLimitData.insert_or_assign(rateLimitDataRaw->tempBucket, rateLimitDataNew);
				}
				HttpData returnData = HttpRequestAgent::executeByRateLimitData(workload, rateLimitDataRaw, true);
				return returnData;
			}
			catch (...) {
				DiscordCoreAPI::reportException(workload.callStack + "::HttpRequestAgent::submitWorkloadAndGetResult");
			}
			return HttpData();
		}

	protected:

		static map<string, atomic<shared_ptr<RateLimitData>>> rateLimitData;
		static map<HttpWorkloadType, string> rateLimitDataBucketValues;
		static atomic<shared_ptr<string>> botToken;
		static atomic<shared_ptr<string>> baseURL;

		static HttpData executeByRateLimitData(HttpWorkloadData workload, RateLimitData* rateLimitDataNew, bool printResult);

		static HttpData HttpRequest(HttpWorkloadData&, RateLimitData*);

	};
}