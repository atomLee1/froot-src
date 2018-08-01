#pragma once

#include <netinet/in.h>
#include <net/ethernet.h>

#include "netserver.h"

class Netserver_ICMPv6 : public NetserverLayer {

private:
	const ether_addr& ether;

private:
	void neighbor_solicit(NetserverPacket& p) const;
	void echo_request(NetserverPacket& p) const;

public:
	Netserver_ICMPv6(const ether_addr& ether /*, const in6_addr& ipv6 */);

	void attach(NetserverLayer& parent) {
		NetserverLayer::attach(parent, IPPROTO_ICMPV6);
	}

public:
	void recv(NetserverPacket &p) const override;

};
