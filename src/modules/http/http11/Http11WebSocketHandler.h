/*
 * Http11WebSocketHandler.h
 *
 *  Created on: 30-Nov-2014
 *      Author: sumeetc
 */

#ifndef HTTP11WEBSOCKETHANDLER_H_
#define HTTP11WEBSOCKETHANDLER_H_
#include "map"
#include "vector"
#include "string"
#include "string"
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "Http11WebSocketDataFrame.h"
#include "cstring"
#include <iostream>
#include <bitset>
#include "string"
#include "stdint.h"
#include "vector"
#include "CommonUtils.h"
#include "SocketUtil.h"
#include "SocketInterface.h"
#include "LoggerFactory.h"
#define MAXBUFLENMWS 32768



class Http11WebSocketHandler : public SocketInterface {
	Logger logger;
	std::string url;
	std::map<int, std::string> dataframes;
	std::map<int, bool> dataframesComplete;
	void replyPong();
	bool processFrame(Http11WebSocketDataFrame* frame, void*& request);
	Http11WebSocketDataFrame readFrame();
	Http11WebSocketDataFrame* nextFrame();
public:
	void onOpen();
	void onClose();
	std::string getUrl();
	std::string getProtocol(void* context);
	int getTimeout();
	void* readRequest(void*& context, int& pending, int& reqPos);
	bool writeResponse(void* req, void* res, void* context);
	//int doIt(const Reflector& reflector, void* _temp, const Method& method, const std::string& cntxtName);
	bool writeData(const WebSocketData& data);
	Http11WebSocketHandler(const std::string& url, const bool& isServer, SocketUtil* sockUtil);
	virtual ~Http11WebSocketHandler();
};

#endif /* HTTP11WEBSOCKETHANDLER_H_ */
