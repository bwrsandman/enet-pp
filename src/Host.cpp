// Copyright (c) 2010 Johann Duscher (alias Jonny Dee)
//
// Permission is hereby granted, free of charge, to any person
// obtaining a copy of this software and associated documentation
// files (the "Software"), to deal in the Software without
// restriction, including without limitation the rights to use,
// copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following
// conditions:
//
// The above copyright notice and this permission notice shall be
// included in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
// OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
// HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
// WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
// OTHER DEALINGS IN THE SOFTWARE.


#include "enetpp/ENet.h"

#include <stdexcept>

namespace enetpp
{

    Host::Host(ENet* parent, const Address& address, size_t maxClients, enet_uint32 incomingBandwidth, enet_uint32 outgoingBandwidth) :
            _parent(parent),
            _host(enet_host_create(&address._address, maxClients, incomingBandwidth, outgoingBandwidth))
    {
        if (NULL == _host)
            throw std::runtime_error("An error occurred while trying to create an ENet server host");
    }

    Host::Host(ENet* parent, size_t maxClients, enet_uint32 incomingBandwidth, enet_uint32 outgoingBandwidth) :
            _parent(parent),
            _host(enet_host_create(NULL, maxClients, incomingBandwidth, outgoingBandwidth))
    {
        if (NULL == _host)
            throw std::runtime_error("An error occurred while trying to create an ENet client host");
    }

    Host::~Host()
    {
        destroy();
    }

    void Host::destroy()
    {
        enet_host_destroy(_host);
    }

    int Host::service(Event& event, enet_uint32 timeoutMillis)
    {
        int result = enet_host_service(_host, &event._event, timeoutMillis);

        handleEvent(event);

        return result;
    }

    void Host::handleEvent(Event& event)
    {
        switch (event.type())
        {
        case ENET_EVENT_TYPE_CONNECT:
            // Remember the new peer.
            _allPeers.push_back(event.peer()._peer);
            break;
        case ENET_EVENT_TYPE_DISCONNECT:
            // This is where you are informed about disconnects.
            // Simply remove the peer from the list of all peers.
            _allPeers.erase(std::find(_allPeers.begin(), _allPeers.end(), event.peer()._peer));
            break;
        default:
            break;
        }
    }

    Peer Host::connect(const Address& address, size_t channelCount)
    {
        ENetPeer* peer = enet_host_connect(_host, &address._address, channelCount);
        if (NULL == peer)
            throw std::runtime_error("Creating connection failed");

        return Peer(peer);
    }

    void Host::broadcast(enet_uint8 channelID, Packet& packet)
    {
        // Once the packet is handed over to ENet with broadcast(),
        // ENet will handle its deallocation.
        enet_host_broadcast(_host, channelID, packet._packet);
    }

    void Host::flush()
    {
        enet_host_flush(_host);
    }

    void Host::bandwidthThrottle()
    {
        enet_host_bandwidth_throttle(_host);
    }

    void Host::bandwidthLimit(enet_uint32 incomingBandwidth, enet_uint32 outgoingBandwidth)
    {
        enet_host_bandwidth_limit(_host, incomingBandwidth, outgoingBandwidth);
    }

    int Host::checkEvents(Event& event) const
    {
        return enet_host_check_events(_host, &event._event);
    }

}
