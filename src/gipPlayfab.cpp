/*
 * gipPlayfab.cpp
 *
 *  Created on: 13 Sep 2021
 *      Author: noyan
 */

#include "gipPlayfab.h"

bool gipPlayfab::finished = false;


gipPlayfab::gipPlayfab() {
}

gipPlayfab::~gipPlayfab() {
}

void gipPlayfab::login() {
	PlayFabSettings::staticSettings->titleId = ("F5309");

	LoginWithCustomIDRequest request;
	request.CreateAccount = true;
	request.CustomId = "GettingStartedGuide";

	PlayFabClientAPI::LoginWithCustomID(request, OnLoginSuccess, OnLoginFail);

	while (PlayFabClientAPI::Update() != 0)
		sleep(1);
}

void gipPlayfab::OnLoginSuccess(const LoginResult& result, void* customData) {
	gLogi("gipPlayfab") << "Congratulations, you made your first successful API call!";
	finished = true;
}

void gipPlayfab::OnLoginFail(const PlayFabError& error, void* customData) {
	gLogi("gipPlayfab") << "Something went wrong with your first API call.\n";
	gLogi("gipPlayfab") << "Here's some debug information:\n";
//	gLogi("gipPlayfab") << "Error" << error.GenerateReport().c_str();
	finished = true;
}
