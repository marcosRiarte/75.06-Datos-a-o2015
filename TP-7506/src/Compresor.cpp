/*
 * Compresor.cpp
 *
 *  Created on: Apr 17, 2015
 *      Author: martin
 */


#include <iostream>
#include <vector>
#include "compress/zlib.h"
#include <stdio.h>
#include <string.h>
#include <stdexcept>

#include <sstream>
#include <iomanip>
#include "Compresor.h"

using  namespace std;

Compresor::Compresor(int compressionlevel) {
	this->compressionlevel = compressionlevel;
}

Compresor::~Compresor(){

}

string Compresor::compress_string(const string& str)
{
    z_stream zs;                        // z_stream is zlib's control structure
    memset(&zs, 0, sizeof(zs));

    if (deflateInit(&zs, compressionlevel) != Z_OK)
        throw(runtime_error("deflateInit failed while compressing."));

    zs.next_in = (Bytef*)str.data();
    zs.avail_in = str.size();           // set the z_stream's input

    int ret;
    char outbuffer[32768];
    string outstring;

    // retrieve the compressed bytes blockwise
    do {
        zs.next_out = reinterpret_cast<Bytef*>(outbuffer);
        zs.avail_out = sizeof(outbuffer);

        ret = deflate(&zs, Z_FINISH);

        if (outstring.size() < zs.total_out) {
            // append the block to the output string
            outstring.append(outbuffer,
                             zs.total_out - outstring.size());
        }
    } while (ret == Z_OK);

    deflateEnd(&zs);

    if (ret != Z_STREAM_END) {          // an error occurred that was not EOF
        ostringstream oss;
        oss << "Exception during zlib compression: (" << ret << ") " << zs.msg;
        throw(runtime_error(oss.str()));
    }

    return outstring;
}

string Compresor::decompress_string(const string& str)
{
    z_stream zs;                        // z_stream is zlib's control structure
    memset(&zs, 0, sizeof(zs));

    if (inflateInit(&zs) != Z_OK)
        throw(runtime_error("inflateInit failed while decompressing."));

    zs.next_in = (Bytef*)str.data();
    zs.avail_in = str.size();

    int ret;
    char outbuffer[32768];
    string outstring;

    // get the decompressed bytes blockwise using repeated calls to inflate
    do {
        zs.next_out = reinterpret_cast<Bytef*>(outbuffer);
        zs.avail_out = sizeof(outbuffer);

        ret = inflate(&zs, 0);

        if (outstring.size() < zs.total_out) {
            outstring.append(outbuffer,
                             zs.total_out - outstring.size());
        }

    } while (ret == Z_OK);

    inflateEnd(&zs);

    if (ret != Z_STREAM_END) {          // an error occurred that was not EOF
        ostringstream oss;
        oss << "Exception during zlib decompression: (" << ret << ") "
            << zs.msg;
        throw(runtime_error(oss.str()));
    }

    return outstring;
}

float Compresor:: obtenerNCD(string strX,int lengthX,string strY, int lengthY){
	string strXY = strX;
	strXY.append(strY);
	string cxy = compress_string((const string&)strXY); //Concatenacion

	float n;
	if (lengthY > lengthX)
	    n = (float)(cxy.length() - lengthX) / (float)lengthY;
	else
	    n = (float) (cxy.length() - lengthY) / (float)lengthX;
	return n;
}


