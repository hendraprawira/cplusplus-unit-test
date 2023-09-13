// http_client_test.cpp
#include <gtest/gtest.h>
#include "http_client.h"

TEST(HttpClientTest, TestHttpGet) {
	HttpClient http_client;
	std::string response = http_client.Get("https://jsonplaceholder.typicode.com/posts/1");

	// Check if the response contains expected content.
	EXPECT_TRUE(response.find("userId") != std::string::npos);
	EXPECT_TRUE(response.find("id") != std::string::npos);
	EXPECT_TRUE(response.find("title") != std::string::npos);
	EXPECT_TRUE(response.find("body") != std::string::npos);
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
