#pragma once

#include <string>

class HttpClient {
public:
	HttpClient() = default;

	// Make a GET request to the specified URL and return the response.
	std::string Get(const std::string& url);
};