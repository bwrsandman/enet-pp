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

    ENet::ENet()
    {
        if (enet_initialize() != 0)
            throw std::runtime_error("ENet initialization failed");
    }

    ENet::~ENet()
    {
        enet_deinitialize();
    }

    Address ENet::createAddress(const char *hostName, int port)
    {
        return Address(hostName, port);
    }

    Address ENet::createAddress(enet_uint32 host, int port)
    {
        return Address(host, port);
    }

    Event ENet::createEvent()
    {
        return Event();
    }

    Host ENet::createServerHost(const Address& address, int maxClients, int incomingBandwidth, int outgoingBandwidth)
    {
        return Host(this, address, maxClients, incomingBandwidth, outgoingBandwidth);
    }

    Host ENet::createClientHost(int maxClients, int incomingBandwidth, int outgoingBandwidth)
    {
        return Host(this, maxClients, incomingBandwidth, outgoingBandwidth);
    }

    Packet ENet::createPacket(const void* data, size_t dataLength, enet_uint32 flags)
    {
        return Packet(data, dataLength, flags);
    }
}
