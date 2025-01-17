//
// Blowfish C++ implementation
//
// CC0 - PUBLIC DOMAIN
// This work is free of known copyright restrictions.
// http://creativecommons.org/publicdomain/zero/1.0/
//

#pragma once

#ifndef __blowfish__
#define __blowfish__

#include <stdint.h>
#include <HardwareSerial.h>

class Blowfish {
public:
    void SetKey(const  char* key, int byte_length);
    void Encrypt( char* dst, const  char* src, int byte_length) const;
    void Decrypt( char* dst, const  char* src, int byte_length) const;
    
private:
    void EncryptBlock(uint32_t *left, uint32_t *right) const;
    void DecryptBlock(uint32_t *left, uint32_t *right) const;
    uint32_t Feistel(uint32_t value) const;
    void CheckZero(uint32_t *block) const;
    
private:
    uint32_t pary_[18];
    uint32_t sbox_[4][256];
};

#endif /* defined(__blowfish__) */
