/*
 * gipPlayfab.h
 *
 *  Created on: 13 Sep 2021
 *      Author: Noyan
 */

#ifndef SRC_GIPPLAYFAB_H_
#define SRC_GIPPLAYFAB_H_

#include "gBasePlugin.h"
#include "playfab/PlayFabClientDataModels.h"
#include "playfab/PlayFabClientApi.h"
#include "playfab/PlayFabSettings.h"
#include "playfab/PlayFabApiSettings.h"
#include <unistd.h>


using namespace PlayFab;
using namespace ClientModels;


class gipPlayfab : public gBasePlugin{
public:
	gipPlayfab();
	virtual ~gipPlayfab();

	void login();

	static void OnLoginSuccess(const LoginResult& result, void* customData);
	static void OnLoginFail(const PlayFabError& error, void* customData);

private:
	static bool finished;
};

#endif /* SRC_GIPPLAYFAB_H_ */
