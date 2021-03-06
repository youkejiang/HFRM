#include "../../include/asynchronous/AsynchronousOutputServer.hpp"
using namespace hfc::asynchronous;

#include "../../include/util/OSErrorException.hpp"
using namespace hfc::util;

AsynchronousOutputServer::AsynchronousOutputServer(){
}

AsynchronousOutputServer::~AsynchronousOutputServer(){
}


int AsynchronousOutputServer::write( t_fd fd , void* buf , int len ){
#ifdef _WIN32
	DWORD readLen = 0;
	DWORD flag = 0;
	OVERLAPPED ol = {0};
	int ret = ::ReadFile( fd , buf , len, &readLen , &ol );
	if( 0 == ret ){
		throw OSErrorException( "WriteFile error." );
	}
#else
	//linux只需记录用户请求，不需要做别的。在通知可读时才读。
#endif

	return addReq( fd , buf , len );
}

