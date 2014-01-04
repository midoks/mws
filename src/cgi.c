#include "config.h"
#include "cgi.h"

//设置linux环境变量
void mws_setenv(const char*name,const char*value)
{
	setenv(name, value, 1);
}

//设置CGI环境变量
void mws_cgi_env(struct cgi_env* env)
{
	mws_setenv("SERVER_SOFTWARE", env->server_software);
	mws_setenv("SERVER_NAME", env->server_name);
	mws_setenv("HTTP_HOST", env->http_host);
	mws_setenv("DOCUMENT_ROOT", env->docment_root);
	mws_setenv("GATEWAY_INTERFACE", env->gateway_interface);
	mws_setenv("SERVER_PROTOCOL", env->server_protocol);
	mws_setenv("SERVER_PORT", env->server_port);
	mws_setenv("REQUEST_METHOD", env->request_method);
	mws_setenv("QUERY_STRING", env->query_string);
	mws_setenv("PATH_TRANSLATED", env->path_translate);
	mws_setenv("SCRIPT_NAME", env->script_name);
	mws_setenv("SCRIPT_FILENAME", env->script_filename);
	mws_setenv("REDIRECT_STATUS", env->redirect_status);
	mws_setenv("CONTENT_LENGTH", env->content_length);
	mws_setenv("CONTENT_TYPE", env->content_type);
	mws_setenv("REMOTE_HOST", env->remote_host);
	mws_setenv("HTTP_COOKIE", env->http_cookie);
	mws_setenv("HTTP_USER_AGENT", env->http_user_agent);
	mws_setenv("HTTP_REFERER", env->http_referer);
}

