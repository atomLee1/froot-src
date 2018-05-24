#pragma once

#include "zone.h"
#include "packet.h"
#include "buffer.h"

class Server {

private:
	Zone			zone;

private:
	const Answer* query(Buffer& in, size_t& qdsize, bool& match, ldns_enum_pkt_rcode& rcode) const;
	bool handle_packet_dns(Buffer& in, Buffer& head, Buffer& body);
	void handle_packet(PacketSocket& s, uint8_t* buffer, size_t buflen, const sockaddr_ll* addr, void* userdata);
	void loop(PacketSocket& s);

public:
	void worker(const std::string& ifname);
	void load(const std::string& filename);

public:
	Server();
	~Server();
};
