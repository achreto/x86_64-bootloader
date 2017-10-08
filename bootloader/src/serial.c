/*
 * Copyright (c) 2017, Reto Achermann
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 * 
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdint.h>
#include <assert.h>
#include <serial.h>


///< the number of ports we have
#define SERIAL_NUM_PORTS 2


///< the serial port to use for the console output
extern unsigned int serial_console_port;


///< the serial port to use for debug output
extern unsigned int serial_debug_port;


///< the number of serial portss
static unsigned int serial_num_physical_ports = SERIAL_NUM_PORTS;


///< the serial port bases for x86 PC. 
static const uint32_t serial_portbases[SERIAL_NUM_PORTS] = { 0x3f8, 0x2f8 };



/**
 * @brief intializes a serial port 
 *
 * @param port          the serial port to initialize
 * @param initialize    whether or not the hardware should be initialized
 * 
 * @returns zero on SUCCESS
 */
int serial_init(unsigned int port, bool initialize)
{
    /// Place holder stup
    return -1;
}


/**
 * @brief outputs a character on the serial port
 *
 * @param port   the serial port to output the character on 
 * @param c      the character to be output
 *
 * NOTE: this does not insert '\r' characters on new lines
 */
void serial_putchar(unsigned int port, char c)
{
    /// place holder stub
}


#if CONFIG_ENABLE_SERIAL_GETCHAR

/**
 * @brief reads a character from the serial port
 * 
 * @param port   the serial port to read from
 * 
 * @returns the character read
 */
char serial_getchar(unsigned int port)
{
    /// place holder stub
    return 0;
}

#endif // CONFIG_ENABLE_SERIAL_GETCHAR