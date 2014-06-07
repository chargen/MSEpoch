
#ifndef __MSEPOCH_H__
#define __MSEPOCH_H__

#if defined(_WIN32)
    // TODO include windows based headers
#else
    #include <sys/time.h>
#endif


// TODO move into c++ file so I don't need to keep it inline
inline unsigned long long MSEpoch()
{
#if defined(_WIN32)
    
	FILETIME ft;
	GetSystemTimeAsFileTime(&ft);
	ULARGE_INTEGER ts;
    
	ts.HighPart = ft.dwHighDateTime;
	ts.LowPart = ft.dwLowDateTime;
    
	unsigned long long time = ts.QuadPart;
	time /= 10000;
	//cout << time << endl;

	return time;
    
#else
    
    struct timeval tv;
    
    gettimeofday(&tv, NULL);
    
    unsigned long long millisecondsSinceEpoch =
    (unsigned long long)(tv.tv_sec) * 1000 +
    (unsigned long long)(tv.tv_usec) / 1000;
    
    // fake the MS
    return millisecondsSinceEpoch;
    
#endif
}

#endif
