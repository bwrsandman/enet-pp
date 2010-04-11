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


#ifndef ENET_H
#define ENET_H

#include <enet/enet.h>

#include "enetpp/Address.h"
#include "enetpp/Event.h"
#include "enetpp/Host.h"
#include "enetpp/Packet.h"
#include "enetpp/Peer.h"

namespace enetpp
{

    class ENet {
    public:
        ENet();
        ~ENet();

        Host createServerHost(const Address& address, int maxClients, int incomingBandwidth = 0, int outgoingBandwidth = 0);
        Host createClientHost(int maxClients, int incomingBandwidth = 0, int outgoingBandwidth = 0);
        
        Packet createPacket(const void* data, size_t dataLength, enet_uint32 flags);
    };

}

#endif // ENET_H
