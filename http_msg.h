/**
 * This header defines message http message structures used for processing 
 * HTTP request and response messages.
 */

#ifndef HTTP_MSG_H
#define HTTP_MSG_H
/**
 * request and response messages contain multiple headers and each header is
 * represented by key value pair.
 * 	For example: Connection:close
 */
struct header_line {
  char* key;          /*header search parameter should end with \0*/
  char* value;	      /*value of the given key should end with \0*/
  struct header_line* next;   /*points to next header*/
};

/*HTTP request methods supported by the proxy*/
enum method {
  GET,
  PUT
};

/*HTTP versions supported by this proxy*/
enum version {
  HTTP_1_0      /*HTTP/1.0*/
  HTTP_1_1      /*HTTP/1.1*/
};

/*HTTP request line message*/
struct request_line {
  enum method type;    /*request type*/
  char* url;           /*request url contains hostname, portnumber and file*/
  enum version ver;    /*HTTP version used by client*/
};


/*HTTP request message*/
struct http_request{
   struct request_line* line;    
   struct header_line* headers;  
};

/*HTTP response status code*/
enum status {
  OK = 200,
  ERROR = 501
};

/*HTTP response line*/
struct response_line {
   enum version ver;         		/*HTTP response version*/
   enum status;
   char* reason;
};

/*HTTP response message*/
struct http_response{
   struct response_line* line;  
   struct header_line* headers;	  	/*All headers in HTTP response*/
   char* body;				/*Resonse body*/
   int body_len;			/*length of the body*/
};


/*Header operations*/
/**
 * This function add new header to existing headers
 * Input:
 * 	header_line: new header is added to this line
 *	key: key of the header
 *	value: value associated with above key
 * Output:
 * 	header_line: updated with new header
 *
 * Return:
 * 	returns 0 on success otherwise non-zero
 */
int add_header(struct header_line** /*headers*/, char* /*key*/, char* /*value*/);

/**
 * This function deletes the given header from headers.
 * Input:
 * 	header_line:header list from which header has to be removed
 * 	key: the header to be removed
 * Output:
 * 	headers: If key is present then header with given key is removed 
 * 	from headers
 * Return:
 * 	If successfully deleted it returns 0 otherwise -1
 */
int del_header(struct header_line** /*headers*/, char* key);

/**
 * This function parses the msg to headers
 * Input:
 * 	msg: message to be parsed into headers
 * Output:
 * 	headers initialized with msg contents if successful
 * Return:
 * 	if success returns 0 otherwise non-zero
 */
int unmarshall_headers(char* /*msg*/, struct header_line** /*headers*/);

/**
 * This function translates headers structure in string form.
 * Input:
 * 	headers: list of all headers
 * Output:
 * 	msg initialized with header contents.
 * Return:
 * 	If successful return 0 or otherwise -1
 */
int marshall_headers(char* /*msg*/, struct header_line* /*headers*/);

/*Request line operations*/

/*Response line operations*/

/*Request operations*/

/*Response operations*/
#endif
