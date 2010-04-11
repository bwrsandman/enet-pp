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

namespace enetpp
{

    Peer::Peer(ENetPeer* peer) :
            _peer(peer)
    {
    }

    Address Peer::address()
    {
        return Address(_peer->address);
    }

    void Peer::setData(const void *data)
    {
        _peer->data = const_cast<void*>(data);
    }

    const void* Peer::data() const
    {
        return _peer->data;
    }

    int Peer::send(enet_uint8 channelID, Packet& packet)
    {
        // Once the packet is handed over to ENet with enet_peer_send(),
        // ENet will handle its deallocation.
        return enet_peer_send(_peer, channelID, packet._packet);
    }

    void Peer::disconnect(enet_uint32 data)
    {
        enet_peer_disconnect(_peer, data);
    }

    void Peer::disconnectLater(enet_uint32 data)
    {
        enet_peer_disconnect_later(_peer, data);
    }

    void Peer::disconnectNow(enet_uint32 data)
    {
        enet_peer_disconnect_now(_peer, data);
    }

    void Peer::reset()
    {
        enet_peer_reset(_peer);
    }

    void Peer::ping()
    {
        enet_peer_ping(_peer);
    }

    Packet Peer::receive(enet_uint32 channelID)
    {
        return Packet(enet_peer_receive(_peer, channelID));
    }

    int Peer::throttle(enet_uint32 rtt)
    {
        return enet_peer_throttle(_peer, rtt);
    }

    void Peer::throttleConfigure(enet_uint32 interval, enet_uint32 acceleration, enet_uint32 deceleration)
    {
        enet_peer_throttle_configure(_peer, interval, acceleration, deceleration);
    }

}
