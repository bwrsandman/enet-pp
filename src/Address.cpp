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

    Address::Address()
    {
    }

    Address::Address(const ENetAddress& address) :
            _address(address)
    {
    }

    Address::Address(const char* hostName, int port)
    {
        setHost(hostName);
        setPort(port);
    }

    Address::Address(enet_uint32 host, int port)
    {
        setHost(host);
        setPort(port);
    }

    void Address::setHost(const char *hostName)
    {
        enet_address_set_host(&_address, hostName);
    }

    void Address::setHost(enet_uint32 host)
    {
        _address.host = host;
    }

    enet_uint32 Address::host() const
    {
        return _address.host;
    }

    void Address::setPort(int port)
    {
        _address.port = port;
    }

    int Address::port() const
    {
        return _address.port;
    }

}
