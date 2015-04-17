/*
 * Compresor.cpp
 *
 *  Created on: Apr 17, 2015
 *      Author: martin
 */


#include <iostream>
#include <vector>
#include "zlib.h"
#include <stdio.h>
#include <string.h>
#include <stdexcept>

#include <sstream>
#include <iomanip>
#include "Compresor.h"

using  namespace std;

Compresor::Compresor() {
	// TODO Auto-generated constructor stub

}



string Compresor::compress_string(const string& str,int compressionlevel = Z_BEST_COMPRESSION)
{
    z_stream zs;                        // z_stream is zlib's control structure
    memset(&zs, 0, sizeof(zs));

    if (deflateInit(&zs, compressionlevel) != Z_OK)
        throw(std::runtime_error("deflateInit failed while compressing."));

    zs.next_in = (Bytef*)str.data();
    zs.avail_in = str.size();           // set the z_stream's input

    int ret;
    char outbuffer[32768];
    std::string outstring;

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
        std::ostringstream oss;
        oss << "Exception during zlib compression: (" << ret << ") " << zs.msg;
        throw(std::runtime_error(oss.str()));
    }

    return outstring;
}

string Compresor::decompress_string(const std::string& str)
{
    z_stream zs;                        // z_stream is zlib's control structure
    memset(&zs, 0, sizeof(zs));

    if (inflateInit(&zs) != Z_OK)
        throw(std::runtime_error("inflateInit failed while decompressing."));

    zs.next_in = (Bytef*)str.data();
    zs.avail_in = str.size();

    int ret;
    char outbuffer[32768];
    std::string outstring;

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
        std::ostringstream oss;
        oss << "Exception during zlib decompression: (" << ret << ") "
            << zs.msg;
        throw(std::runtime_error(oss.str()));
    }

    return outstring;
}

float Compresor:: obtenerNCD(string strX,string strY){
	string strXY = strX;
	strXY.append(strY);
	string cx = compress_string((const string&)strX,Z_BEST_COMPRESSION);
	string cy = compress_string((const string&)strY,Z_BEST_COMPRESSION);
	string cxy = compress_string((const string&)strXY,Z_BEST_COMPRESSION); //Concatenacion

	float n;
	if (cy.length() > cx.length())
	    n = (float)(cxy.length() - cx.length()) / (float)(cy.length());
	else
	    n = (float) (cxy.length() - cy.length()) / (float)(cx.length());
	return n;
}

Compresor::~Compresor() {
	// TODO Auto-generated destructor stub
}

