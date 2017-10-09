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

#ifndef BOOTLADER_TYPES_H_ 
#define BOOTLADER_TYPES_H_ 1

#include <stdint.h>
#include <inttypes.h>

#include <config.h>


#if CONFIG_BUILD_64_BIT_ADDRESSES

///< represents a local physical address
typedef uint64_t lpaddr_t;

///< printf placeholder for local physical address
#define PRIxLPADDR PRIx64


///< represents a local virtual address
typedef uint64_t lvaddr_t;

///< printf placeholder for local virtual address
#define PRIxLVADDR PRIx64


#else


///< represents a local physical address
typedef uint32_t lpaddr_t;

///< printf placeholder for local physical address
#define PRIxLPADDR PRIx32


///< represents a local virtual address
typedef uint32_t lvaddr_t;

///< printf placeholder for local virtual address
#define PRIxLVADDR PRIx32


#endif CONFIG_BUILD_64_BIT_ADDRESSES


///< represents a generic virtual address
typedef uint64_t genvaddr_t;

///< printf placeholder for generic virtual address
#define PRIxGENVADDR PRIx64


///< represents a generic physical address
typedef uint64_t genpaddr_t;

///< printf placeholder for generic physical address
#define PRIxGENPADDR PRIx64


#endif // BOOTLADER_TYPES_H_