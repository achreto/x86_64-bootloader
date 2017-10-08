/*
 * Copyright (c) 2017, Reto Achermann
 *
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

#ifndef SERIAL_H_
#define SERIAL_H_ 1

#include <stdbool.h>

#include <config.h>



/* 
 * ============================================================================
 * Serial Port Interface
 * ============================================================================
 */



/**
 * @brief intializes a serial port 
 *
 * @param port          the serial port to initialize
 * @param initialize    whether or not the hardware should be initialized
 * 
 * @returns zero on SUCCESS
 */
int serial_init(unsigned int port, bool initialize);


/**
 * @brief outputs a character on the serial port
 *
 * @param port   the serial port to output the character on 
 * @param c      the character to be output
 *
 * NOTE: this does not insert '\r' characters on new lines
 */
void serial_putchar(unsigned int port, char c);


#if CONFIG_ENABLE_SERIAL_GETCHAR

/**
 * @brief reads a character from the serial port
 * 
 * @param port   the serial port to read from
 * 
 * @returns the character read
 */
char serial_getchar(unsigned int port);

#endif // CONFIG_ENABLE_SERIAL_GETCHAR


/* 
 * ============================================================================
 * Serial Console Port Wrappers
 * ============================================================================
 */



///< the serial port to use for the console output
extern unsigned int serial_console_port;


/**
 * @brief intializes a serial console port 
 *
 * @param initialize    whether or not the hardware should be initialized
 * 
 * @returns zero on SUCCESS
 */
static inline int serial_console_init(bool initialize)
{
    return serial_init(serial_console_port, initialize);
}


/**
 * @brief outputs a character on the serial console port
 *
 * @param c      the character to be output
 *
 * NOTE: this does insert '\r' before '\n' characters
 */
static inline void serial_console_putchar(char c)
{
    if (c == '\n') {
        serial_putchar(serial_console_port, '\r');
    }
    serial_putchar(serial_console_port, c);
}


#if CONFIG_ENABLE_SERIAL_GETCHAR

/**
 * @brief reads a character from the serial console port
 * 
 * @returns the character read
 */
static inline char serial_console_getchar(void)
{
    return serial_getchar(serial_console_port);
}

#endif //CONFIG_ENABLE_SERIAL_GETCHAR


/* 
 * ============================================================================
 * Serial Debug Port Wrappers
 * ============================================================================
 */



///< the serial port to use for debug output
extern unsigned int serial_debug_port;


/**
 * @brief intializes a serial debug port 
 *
 * @param initialize    whether or not the hardware should be initialized
 * 
 * @returns zero on SUCCESS
 */
static inline int serial_debug_init(void)
{
    return serial_init(serial_debug_port, true);
}


/**
 * @brief outputs a character on the serial debug port
 *
 * @param c      the character to be output
 *
 * NOTE: this does insert '\r' before '\n' characters
 */
static inline void serial_debug_putchar(char c)
{
    if (c == '\n') {
        serial_putchar(serial_debug_port, '\r');
    }
    serial_putchar(serial_debug_port, c);
}


#if CONFIG_ENABLE_SERIAL_GETCHAR 

/**
 * @brief reads a character from the serial debug port
 * 
 * @returns the character read
 */
static inline char serial_debug_getchar(void)
{
    return serial_getchar(serial_debug_port);
}

#endif // CONFIG_ENABLE_SERIAL_GETCHAR

#endif  // SERIAL_H_