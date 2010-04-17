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


#ifndef PEER_H
#define PEER_H

#include <enet/enet.h>

namespace enetpp
{
    class Address;
    class Packet;

    class Peer
    {
        friend class Event;
        friend class Host;

        ENetPeer* _peer;

        Peer(ENetPeer* peer);
    public:
        Address address();
        void setData(void* data);
        void* data() const;
        int send(enet_uint8 channelID, Packet &packet);
        void disconnect(enet_uint32 data = 0);
        void disconnectLater(enet_uint32 data = 0);
        void disconnectNow(enet_uint32 data = 0);
        void reset();
        void ping();
        Packet receive(enet_uint32 channelID);
        int throttle(enet_uint32 rtt);
        void throttleConfigure(enet_uint32 interval, enet_uint32 acceleration, enet_uint32 deceleration);
    };

}

#endif // PEER_H
