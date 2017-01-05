#ifndef _MWS_CGI_H_
#define _MWS_CGI_H_

//设置CGI环境变量
/*
 * Set CGI environment variables.
 * CONTENT_LENGTH    : POST message length
 * CONTENT_TYPE      : POST encoding type
 * DOCUMENT_ROOT     : the root directory
 * GATEWAY_INTERFACE : The CGI version (CGI/1.1)
 * HTTP_COOKIE       : Cookies provided by client
 * HTTP_HOST         : Same as above
 * HTTP_REFERER      : Referer page.
 * HTTP_USER_AGENT   : Browser user agent
 * PATH_TRANSLATED   : On-disk file path
 * QUERY_STRING      : /file.ext?this_stuff&here
 * REDIRECT_STATUS   : HTTP status of CGI redirection (PHP)
 * REMOTE_ADDR       : IP of remote user
 * REMOTE_HOST       : Hostname of remote user (reverse DNS)
 * REQUEST_METHOD    : GET, POST, HEAD, etc.
 * SCRIPT_FILENAME   : Same as PATH_TRANSLATED (PHP, primarily)
 * SCRIPT_NAME       : Request file path
 * SERVER_NAME       : Our hostname or Host: header
 * SERVER_PORT       : TCP host port
 * SERVER_PROTOCOL   : The HTTP version of the request
 * SERVER_SOFTWARE   : Our application name and version
 */
struct cgi_env{
	int content_length; //POST message length
	char* content_type;//POST encoding type
	char* document_root;//the root directory
	char* geteway_interface;// The CGI version(1.1)
	char* http_cookie;//Cookies provided by client
	char* http_host;//same as above
	char* http_referer;//Referer page
	char* http_user_agent;//Browser user path
	char* path_translated;//on-disk file path
	char* query_string;//file.php?renlairenwang&midoks
	char* redirect_status;//Http status of CGI redirection(PHP)
	char* remote_addr;//IP of remote user
	char* remote_host;//Hostname of remote user (reverse DNS)
	char* request_method;//GET, POST, HEAD, etc
	char* script_filename;//Same as PATH_TRANSLATE(PHP, primarily)
	char* script_name;//Request file path
	char* server_name;//Our hostname or host:header
	char* server_port;//TCP host port
	char* server_protocol;//The Http version of the request
	char* server_software;//Our application name and version
};

void mws_setenv(const char*,const char*);
void mws_cgi_env(struct cgi_env*);

#endif
