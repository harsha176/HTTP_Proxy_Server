/**
 * Proxy server exposed operations.
 */
#include "http_msg.h"

#ifndef PROXY_H
#define PROXY_H

/**
 * Each request from client is handled by client handler. This method is called
 * from different thread context.
 *
 * Input: client connected socket descriptor.
 * Output: None
 *
 * Post condition: after returning from this method, the client request is
 * served.
 */
void client_handler(void* /*fd*/);


/**
 * HTTP request message from client is processed and if required it contacts 
 * given server with given hostname and port for requested data.
 *
 * Input: 
 * 	hostname of the server to contact
 * 	portnumber of the server listening for requests
 * 	message request from client
 * Output:
 *      http response for the given request	
 *
 * Return
 * 	if successful returns 0 otherwise non-zero
 *
 */
int request_processor(char* /*host_name*/, char* /*port_number*/, 
    		      struct http_request* /*request_msg*/, 
		      struct http_response* /*response_msg*/);

#endif
