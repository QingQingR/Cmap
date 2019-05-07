#include <map>
#include <string.h>
#include <iostream>
#include "cmap.h"
using namespace std;
#ifdef __cplusplus
extern "C"{
#endif

struct ipaddr
{
	union{
		unsigned int ipv4;
		unsigned int ipv6[4];
	}addr;

	bool operator < (const ipaddr &p) const
    	{
            if(addr.ipv4 && p.addr.ipv4)
                return p.addr.ipv4-addr.ipv4;
            else if(addr.ipv6 && p.addr.ipv6)
            {
                for(int i=0;i<4;i++)
                {
                    if(addr.ipv6[i]>p.addr.ipv6[i])
                        return 0;
                }
                return 1;
            } 
	    else
                return 0;
    	}
};

struct macaddr
{
	char mac[6];
	bool operator < (const struct macaddr &o) const
    	{
	    return strcmp((const char*)(o.mac), (const char*)mac);
    	}
};

typedef map<ipaddr,macaddr> Map;
void* createMap()
{
	return new Map();
}

void call_insert(void *M, unsigned int a, char *b)
{
	ipaddr ip;
	macaddr mac;
	ip.addr.ipv4=a;
	strcpy(mac.mac,b);
	if(static_cast<Map *>(M)!=NULL)
		static_cast<Map *>(M)->insert(pair<ipaddr, macaddr>(ip,mac));
	else
		cout<<"insert wrong!"<<endl;
}

char* call_at(void *M, unsigned int a)
{
	ipaddr ip;
	ip.addr.ipv4=a;
	return static_cast<Map>(*M)[ip].mac;
}
	
void show(void *M)
{
	if(static_cast<Map *>(M)!=NULL){
		Map::iterator iter=static_cast<Map *>(M)->begin();
		cout<<iter->first.addr.ipv4<<endl;
		cout<<iter->second.mac<<endl;
	}
	else
		cout<<"NULL!"<<endl;
}

#ifdef __cplusplus
   }
#endif
