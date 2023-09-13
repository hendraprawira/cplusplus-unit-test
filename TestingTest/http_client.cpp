// http_client.cpp
#include "http_client.h"

#include <curl/curl.h>

size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
	size_t total_size = size * nmemb;
	output->append(static_cast<char*>(contents), total_size);
	return total_size;
}

std::string HttpClient::Get(const std::string& url) {
	CURL* curl = curl_easy_init();
	std::string response;

	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

		CURLcode res = curl_easy_perform(curl);

		if (res != CURLE_OK) {
			curl_easy_cleanup(curl);
			throw std::runtime_error("Failed to perform HTTP request.");
		}

		curl_easy_cleanup(curl);
	}
	else {
		throw std::runtime_error("Failed to initialize CURL.");
	}

	return response;
}
